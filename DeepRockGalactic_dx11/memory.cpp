#include "memory.h"

//����hook��������
ULONG Memory::GetHookLength() {
	ULONG result = 0;
	for (size_t i = 0; i < sizeof(hook) / sizeof(MemoryHook); i++) {
		if (hook[i].is_hook) {
			result++;
		}
	}
	return result;
}

//ͨ��һ����ַ����ѯ�Ƿ��������ص�hook��Ϣ��û�з���0���ɹ�����hookjump�ĵ�ַ
//result_i=λ�������е��±�
PVOID Memory::QueryHookInfo(PVOID addr, PULONG result_i = nullptr) {
	if (addr) {
		for (size_t i = 0; i < sizeof(hook) / sizeof(MemoryHook); i++) {
			if (hook[i].is_hook && hook[i].old_addr == addr) {
				if (result_i) {
					*result_i = i;
				}
				return hook[i].new_addr;
			}
		}
	}
	return nullptr;
}

bool Memory::InsertHook(PVOID old_addr, PVOID new_addr, PUCHAR old_byte, ULONG old_byte_size) {
	for (size_t i = 0; i < sizeof(hook) / sizeof(MemoryHook); i++) {
		if (!hook[i].is_hook) {
			hook[i].is_hook = true;
			hook[i].new_addr = new_addr;
			hook[i].old_addr = old_addr;
			memcpy(hook[i].old_byte, old_byte, old_byte_size);
			hook[i].old_byte_size = old_byte_size;
			return true;
		}
	}
	return false;
}

//ж��hook�ĵ�ַ
bool Memory::UnHookByLongJump(PVOID hook_addr) {
	ULONG i = 0;
	PVOID new_addr = QueryHookInfo(hook_addr, &i);
	if (new_addr) {
		if (Write(hook_addr, hook[i].old_byte, hook[i].old_byte_size)) {
			VirtualFreeEx(hProcess, new_addr, 0, MEM_RELEASE);
			memset(&(hook[i]), 0, sizeof(MemoryHook));
			return true;
		}
	}
	return false;
}

//ͨ��jump����hookһ����ַ���ɹ������µ�ַ��ʧ�ܷ���nullptr
//������hook�Ѿ����ڣ���ֱ�ӷ��أ������ظ�hook
//jumpsize �������滻���ֽ���������߻����14�ֽ�
PVOID Memory::SetHookByLongJump(PVOID hook_addr, ULONG jumpsize, PUCHAR shell_code, SIZE_T shell_size) {
	UCHAR jump_shell[] = { 0xff,0x25,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0 };
	PVOID result = nullptr;
	PVOID temp = QueryHookInfo(hook_addr);
	if (temp) {
		return temp;
	}
	if (jumpsize < 14) {
		return result;
	}
	//�����ڴ��������ַ���ֽڶ�����
	PVOID old_byte = malloc(jumpsize);
	PVOID new_addr = nullptr;
	if (!Read(hook_addr, old_byte, jumpsize)) {
		goto end;
	}
	new_addr = VirtualAllocEx(hProcess, 0, shell_size + jumpsize + 50 , MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	if (!new_addr) {
		goto end;
	}
	*(PULONG64)(jump_shell + 6) = (ULONG64)hook_addr + jumpsize;
	//д�����ݵ����ڴ�
	if (!Write(new_addr, shell_code, shell_size) ||
		!Write((PVOID)((PCHAR)new_addr + shell_size), old_byte, jumpsize) ||
		!Write((PVOID)((PCHAR)new_addr + shell_size + jumpsize), jump_shell, sizeof(jump_shell))) {
		goto free;
	}
	*(PULONG64)(jump_shell + 6) = (ULONG64)new_addr;
	//��jumpд��������ַ
	//����ֽڴ���14�������0x90
	if (Write(hook_addr, jump_shell, sizeof(jump_shell)) &&
		WriteHex0x90((PVOID)((PCHAR)hook_addr + 14), jumpsize - 14)) {
		InsertHook(hook_addr, new_addr, (PUCHAR)old_byte, jumpsize);
		result = new_addr;
		goto end;
	}
free:
	VirtualFreeEx(hProcess, new_addr, 0, MEM_RELEASE);
end:
	free(old_byte);
	return result;
}


PUCHAR Memory::Search(PUCHAR search, SIZE_T size) {
	return SearchHex(modbase, modsize, search, size);
}

PUCHAR Memory::SearchHex(PVOID start_addr, SIZE_T size, PUCHAR search_code, SIZE_T search_size) {
	PUCHAR p = (PUCHAR)start_addr;
	for (size_t i = 0; i < size; i++) {
		ULONG equal = 0;
		for (size_t u = 0; u < search_size; u++) {
			if (search_code[u] == (UCHAR)0) {
				equal++;
				continue;
			}
			if (*(PUCHAR)(p + u) != search_code[u]) {
				break;
			}
			equal++;
		}
		if (equal == search_size) {
			return p;
		}
		p++;
	}
	return NULL;
}

bool Memory::WriteHex0x90(PVOID addr, SIZE_T write_size) {
	void* buf = malloc(write_size);
	if (!buf) {
		return false;
	}
	memset(buf, 0x90, write_size);
	bool results = Write(addr, buf, write_size);
	free(buf);
	return results;
}

HMODULE Memory::GetModInfo(const char* modname, PDWORD result_size) {
	HMODULE base = GetModuleHandleA(modname);
	if (!base) {
		return 0;
	}
	MODULEINFO info = { 0 };
	if (GetModuleInformation(hProcess, base, &info, sizeof(info))) {
		if (result_size) {
			*result_size = info.SizeOfImage;
		}
		return base;
	}
	return 0;
}

bool Memory::CloseProcess(DWORD pid) {
	HANDLE hp = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
	bool result = false;
	if (hp) {
		if (TerminateProcess(hp, 0)) {
			result = true;
		}
		CloseHandle(hp);
		return result;
	}
	return result;
}

DWORD Memory::GetParentPID(DWORD pid) {
	DWORD result = 0;
	HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (snap == INVALID_HANDLE_VALUE) {
		return result;
	}
	PROCESSENTRY32 info = { 0 };
	info.dwSize = sizeof(PROCESSENTRY32);
	if (!Process32First(snap, &info)) {
		goto end;
	}
	do
	{
		if (pid == info.th32ProcessID) {
			result = info.th32ParentProcessID;
			break;
		}
	} while (Process32Next(snap,&info));
end:
	CloseHandle(snap);
	return result;
}

bool Memory::Read(PVOID addr, PVOID buf, SIZE_T size) {
	return ReadProcessMemory(hProcess, addr, buf, size, NULL);
}

bool Memory::Write(PVOID addr, PVOID buf, SIZE_T size) {
	return WriteProcessMemory(hProcess, addr, buf, size, NULL);
}

Memory::Memory() {
	if (!isnew) {
		isnew = true;
		hProcess = GetCurrentProcess();
		ProcessId = GetCurrentProcessId();
		modbase = GetModInfo("FSD-Win64-Shipping.exe", &modsize);
		if (!modbase || !modsize) {
			printf("GetGameModBase Failed...\n");
		}
		else {
			printf("GameModBase -> %p  Size ->%X\n", modbase, modsize);
		}
	}
}

Memory::~Memory() {
}