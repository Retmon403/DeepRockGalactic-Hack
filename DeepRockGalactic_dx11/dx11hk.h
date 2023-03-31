#pragma once
#include "define.h"
#include "gui.h"

#define DEBUG_TEST 1

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

typedef HRESULT(WINAPI*_Present)(IDXGISwapChain* pSwapChain, UINT SysInterval, UINT Flags);
typedef HRESULT(WINAPI* _ResizeBuffers) (IDXGISwapChain* pSwapChain, UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags);

DWORD Init(LPVOID lp);
void HookFunction(PVOID* oFunction, PVOID Function, bool ishk);
void SetConsoleStatus(bool iscreate);

extern HWND g_hwnd;
extern ID3D11Device* g_pDevice;
extern ID3D11DeviceContext* g_pContext;