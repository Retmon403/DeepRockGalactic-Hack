#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <d3d11.h>
#include <d3dcompiler.h>
#include <dxgi.h>
#include <iostream>
#include <sstream>

#include "Detours/include/detours.h"
#include "ImGui/imgui.h"
#include "ImGui/imgui_internal.h"
#include "ImGui/imgui_impl_dx11.h"
#include "ImGui/imgui_impl_win32.h"
#include "ImGui/baidu_font.hpp"


#include "dx11hk.h"


#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"d3dcompiler.lib")

#ifndef _WIN64
#pragma comment(lib,"Detours\\x86\\detours.lib")
#else
#pragma comment(lib,"Detours\\x64\\detours.lib")
#endif

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved);
void Init();
void load_game_addr();
extern HWND debug_window;