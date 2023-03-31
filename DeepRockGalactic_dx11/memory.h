#pragma once

#include "define.h"
#include <TlHelp32.h>
#include <Psapi.h>

#define debug_printf_red(format, ...)\
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);\
	printf(format,##__VA_ARGS__);\

#define debug_printf_green(format, ...)\
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);\
	printf(format,##__VA_ARGS__);\

#define debug_printf_yellow(format, ...)\
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN|FOREGROUND_RED);\
	printf(format,##__VA_ARGS__);\

typedef struct {
	PVOID old_addr;
	PVOID new_addr;
	UCHAR old_byte[50];
	ULONG old_byte_size;
	bool is_hook;
}MemoryHook,*PMemoryHook;

class Memory
{
public:
	Memory();
	~Memory();
	bool WriteHex0x90(PVOID addr, SIZE_T write_size);
	PUCHAR SearchHex(PVOID start_addr, SIZE_T size, PUCHAR search_code, SIZE_T search_size);
	PUCHAR Search(PUCHAR search, SIZE_T size);
	HMODULE GetModInfo(const char* modname, PDWORD result_size);
	bool Read(PVOID addr, PVOID buf, SIZE_T size);
	bool Write(PVOID addr, PVOID buf, SIZE_T size);
	bool UnHookByLongJump(PVOID hook_addr);
	PVOID SetHookByLongJump(PVOID hook_addr, ULONG jumpsize, PUCHAR shell_code, SIZE_T shell_size);
	ULONG GetHookLength();
	PVOID QueryHookInfo(PVOID addr, PULONG result_i);
	bool InsertHook(PVOID old_addr, PVOID new_addr, PUCHAR old_byte, ULONG old_byte_size);

	DWORD GetParentPID(DWORD pid);
	bool CloseProcess(DWORD pid);
public:
	DWORD ProcessId = 0;
	HANDLE hProcess = 0;

	bool isnew = false;
	PVOID modbase = nullptr;
	DWORD modsize = 0;
public:
	MemoryHook hook[50] = { 0 };
};


struct FUNC_BOX
{
	bool box_1;
	bool box_2;
	bool box_3;
	bool box_4;
	bool box_5;
	bool box_6;
	bool box_7;
	bool box_8;
	bool box_9;
	bool box_10;
};



struct GAME_MEMORY_ADDR
{
	ULONG64 lighting;
	ULONG64 lighting_cd;
	ULONG64 grenades;
	ULONG64 grapple_gun_cd;
	ULONG64 grapple_gun_distance;
	ULONG64 pistol_bullet;
	ULONG64 bullet_Gunman_1;
	ULONG64 bullet_Gunman_2;
	ULONG64 bullet_Gunman_3;
	ULONG64 drilling_bit;
	ULONG64 engineer_quick_install_artillery;
	ULONG64 engineer_artillery_bullet;
	ULONG64 engineer_artillery_limit;
};

struct GAME_MEMORY_HOOK
{
	ULONG64 jump_plus;
	ULONG64 bullet_speed;
};
extern GAME_MEMORY_ADDR g_memory_addr;
extern GAME_MEMORY_HOOK g_memory_hook;
extern FUNC_BOX g_box;
extern ULONG64 g_modbase;
extern DWORD g_modsize;
extern FLOAT g_hook_bullet_speed;
extern bool loading_addr;