#include "DllInjector.hpp"

#pragma warning(disable : 4996)

void error() {
	Sleep(1500);
	exit(0);
}

int main()
{
	char dll_name[] = "\\DeepRockGalactic_dx11.dll";
	char path_buf[MAX_PATH] = { 0 };
	GetCurrentDirectoryA(MAX_PATH, path_buf);
	strcat(path_buf, dll_name);
	if (_access(path_buf, 0) == -1) {
		printf("dll�ļ�������...\n");
		error();
	}
	
	bool isfinderror = false;
	DWORD pid = 0;
	printf("�ȴ���Ϸ����...\n");
	while (!GetWindowThreadProcessId(FindWindowA("UnrealWindow", "Deep Rock Galactic  "), &pid)) {
		isfinderror = true;
		Sleep(100);
	}
	printf("��Ϸ������ -> Pid:%d\n", pid);
	if (isfinderror) {
		Sleep(2000);
	}
	bool result = DllInjectorByMemoryMap(pid, path_buf, sizeof(path_buf));
	printf(result ? "dllע��ɹ�...\n" : "dllע��ʧ��...\n");
	error();
	return 0;
}