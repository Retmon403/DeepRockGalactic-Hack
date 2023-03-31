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
		printf("dll文件不存在...\n");
		error();
	}
	
	bool isfinderror = false;
	DWORD pid = 0;
	printf("等待游戏运行...\n");
	while (!GetWindowThreadProcessId(FindWindowA("UnrealWindow", "Deep Rock Galactic  "), &pid)) {
		isfinderror = true;
		Sleep(100);
	}
	printf("游戏已运行 -> Pid:%d\n", pid);
	if (isfinderror) {
		Sleep(2000);
	}
	bool result = DllInjectorByMemoryMap(pid, path_buf, sizeof(path_buf));
	printf(result ? "dll注入成功...\n" : "dll注入失败...\n");
	error();
	return 0;
}