#include <stdio.h>
#include <io.h>
#include <Windows.h>
#include <TlHelp32.h>
#include <Psapi.h>


typedef NTSTATUS(NTAPI* LdrGetProcedureAddressT)(IN PVOID DllHandle, IN PVOID ProcedureName OPTIONAL, IN ULONG ProcedureNumber OPTIONAL, OUT PULONG_PTR ProcedureAddress);
typedef VOID(NTAPI* RtlFreeUnicodeStringT)(_Inout_ PVOID UnicodeString);
typedef  VOID(NTAPI* RtlInitAnsiStringT)(_Out_    PVOID DestinationString, _In_opt_ PVOID         SourceString);
typedef NTSTATUS(NTAPI* RtlAnsiStringToUnicodeStringT)(_Inout_ PVOID DestinationString, _In_ PVOID SourceString, _In_ BOOLEAN AllocateDestinationString);
typedef NTSTATUS(NTAPI* LdrLoadDllT)(PWCHAR, PULONG, PVOID, PHANDLE);
typedef NTSTATUS(NTAPI* NtAllocateVirtualMemoryT)(IN HANDLE ProcessHandle, IN OUT PVOID* BaseAddress, IN ULONG ZeroBits, IN OUT PSIZE_T RegionSize, IN ULONG AllocationType, IN ULONG Protect);

typedef struct _PARAMX
{
    PVOID lpFileData;
    DWORD DataLength;
    LdrGetProcedureAddressT LdrGetProcedureAddress;
    NtAllocateVirtualMemoryT dwNtAllocateVirtualMemory;
    LdrLoadDllT pLdrLoadDll;
    RtlInitAnsiStringT RtlInitAnsiString;
    RtlAnsiStringToUnicodeStringT RtlAnsiStringToUnicodeString;
    RtlFreeUnicodeStringT RtlFreeUnicodeString;
}PARAMX, * PPARAMX;

bool DllInjectorByMemoryMap(DWORD ProcessId, PCHAR DllPath, SIZE_T PathSize);
bool DllInjectorByCreateThread(DWORD pid, PCHAR dll_path, SIZE_T size);