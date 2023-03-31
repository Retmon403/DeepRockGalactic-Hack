#include "dx11hk.h"
#include "hacker.h"


ID3D11Device* g_pDevice = nullptr;
ID3D11DeviceContext* g_pContext = nullptr;
IDXGISwapChain* g_pSwapChain = nullptr;
DWORD_PTR* pSwapChainVTable = nullptr;
DWORD_PTR* pDeviceVTable = nullptr;
DWORD_PTR* pDeviceContextVTable = nullptr;
ID3D11RenderTargetView* g_pRenderTargetView;
HWND g_hwnd = 0;

_Present oPresent = nullptr;
_ResizeBuffers oResizeBuffers = nullptr;
WNDPROC oWndProc = nullptr;

#define SAFE_RELEASE(x) if (x) { x->Release(); x = NULL; }

void HookFunction(PVOID* oFunction, PVOID Function, bool ishk) {
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	ishk ? DetourAttach(oFunction, Function) : DetourDetach(oFunction, Function);
	DetourTransactionCommit();
}

LRESULT WINAPI WndProc(const HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	POINT mousePosition;
	GetCursorPos(&mousePosition);
	ScreenToClient(g_hwnd, &mousePosition);
	ImGuiIO& io = ImGui::GetIO();
	io.MousePos.x = (float)mousePosition.x;
	io.MousePos.y = (float)mousePosition.y;
	if (uMsg == WM_KEYUP) {
		if (wParam == VK_HOME) {
			g_is_show = !g_is_show;
			io.MouseDrawCursor = g_is_show;
		}
	}
	if (g_is_show) {
		ImGui_ImplWin32_WndProcHandler(hWnd, uMsg, wParam, lParam);
		return true;
	}
end:
	return CallWindowProc(oWndProc, hWnd, uMsg, wParam, lParam);
}

HRESULT WINAPI hkResizeBuffers(IDXGISwapChain* pSwapChain, UINT BufferCount, UINT Width, UINT Height, DXGI_FORMAT NewFormat, UINT SwapChainFlags) {
	ImGui_ImplDX11_InvalidateDeviceObjects();
	if (g_pRenderTargetView) { 
		g_pRenderTargetView->Release(); 
		g_pRenderTargetView = nullptr; 
	}
	HRESULT result = oResizeBuffers(pSwapChain, BufferCount, Width, Height, NewFormat, SwapChainFlags);
	ImGui_ImplDX11_CreateDeviceObjects();
	return result;
}
	
void InitImGui() {
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::GetIO().WantCaptureMouse || ImGui::GetIO().WantTextInput || ImGui::GetIO().WantCaptureKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;
	io.WantSaveIniSettings = false;
	ImFontConfig f_cfg;
	f_cfg.FontDataOwnedByAtlas = false;
	const ImFont* font = io.Fonts->AddFontFromMemoryTTF((void*)baidu_font_data, baidu_font_size, 16.0f, &f_cfg, io.Fonts->GetGlyphRangesChineseFull());
	io.LogFilename = nullptr;
	io.IniFilename = nullptr;
	ImGui::GetIO().ImeWindowHandle = g_hwnd;
	oWndProc = (WNDPROC)SetWindowLongPtr(g_hwnd, GWLP_WNDPROC, (LONG_PTR)WndProc);
	ImGui_ImplWin32_Init(g_hwnd);
	ImGui_ImplDX11_Init(g_pDevice, g_pContext);
}

HRESULT WINAPI hkPresent(IDXGISwapChain* pSwapChain, UINT SysInterval, UINT Flags) {
	static bool firstcall = true;
	if (firstcall) {
		firstcall = false;
		if (SUCCEEDED(pSwapChain->GetDevice(__uuidof(ID3D11Device), (void**)&g_pDevice))) {
			pSwapChain->GetDevice(__uuidof(g_pDevice), (void**)&g_pDevice);
			g_pDevice->GetImmediateContext(&g_pContext);
		}
		ID3D11Texture2D* renderTargetTexture = nullptr;
		if (SUCCEEDED(pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&renderTargetTexture))){
			g_pDevice->CreateRenderTargetView(renderTargetTexture, NULL, &g_pRenderTargetView);
			renderTargetTexture->Release();
		}
		printf("Loading Menu...\n");
		InitImGui();
	}
	if (!g_pRenderTargetView) {
		ID3D11Texture2D* backbuffer = NULL;
		HRESULT hr = pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&backbuffer);
		if (FAILED(hr)) {
			printf("Failed to get BackBuffer\n");
			return hr;
		}
		hr = g_pDevice->CreateRenderTargetView(backbuffer, NULL, &g_pRenderTargetView);
		backbuffer->Release();
		if (FAILED(hr)) {
			printf("Failed to get RenderTarget\n");
			return hr;
		}
	}
	else {
		g_pContext->OMSetRenderTargets(1, &g_pRenderTargetView, NULL);
	}
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	GuiMenu();
	ImGui::EndFrame();
	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	return oPresent(pSwapChain, SysInterval, Flags);
}

DWORD Init(LPVOID lp) {
	g_hwnd = FindWindowA("UnrealWindow", "Deep Rock Galactic  ");
	if (!g_hwnd) {
		printf("find game window failed!\n");
		return 0;
	}
	SetForegroundWindow(g_hwnd);
	D3D_FEATURE_LEVEL levels[] = { D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_1 };
	D3D_FEATURE_LEVEL obtainedLevel;
	DXGI_SWAP_CHAIN_DESC sd = { 0 };
	sd.BufferCount = 1;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
	sd.OutputWindow = g_hwnd;
	sd.SampleDesc.Count = 1;
	sd.Windowed = ((GetWindowLongPtr(g_hwnd, GWL_STYLE) & WS_POPUP) != 0) ? false : true;
	sd.BufferDesc.Width = 1;
	sd.BufferDesc.Height = 1;
	sd.BufferDesc.RefreshRate.Numerator = 0;
	sd.BufferDesc.RefreshRate.Denominator = 1;
	if (D3D11CreateDeviceAndSwapChain(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0,
		levels, sizeof(levels) / sizeof(D3D_FEATURE_LEVEL), D3D11_SDK_VERSION, &sd, &g_pSwapChain,
		&g_pDevice, &obtainedLevel, &g_pContext) != S_OK) {
		printf("create device failed!\n");
		return 0;
	}
	pSwapChainVTable = (DWORD_PTR*)g_pSwapChain;
	pSwapChainVTable = (DWORD_PTR*)pSwapChainVTable[0];
	oPresent = (_Present)pSwapChainVTable[8];
	oResizeBuffers = (_ResizeBuffers)pSwapChainVTable[13];
	printf("oPresent:%p oResizeBuffers:%p\n", oPresent, oResizeBuffers);
	HookFunction((PVOID*)(&oPresent), hkPresent, true);
	HookFunction((PVOID*)(&oResizeBuffers), hkResizeBuffers, true);
	g_pDevice->Release();
	g_pContext->Release();
	g_pSwapChain->Release();
	InitHacker();
	return 0;
}

void SetConsoleStatus(bool iscreate) {
	static HWND debug_window = 0;
	if (!iscreate) {
		FreeConsole();
		EnableMenuItem(GetSystemMenu(debug_window, false), SC_CLOSE, MF_ENABLED | MF_BYCOMMAND);
		SendMessage(debug_window, WM_CLOSE, 0, 0);
		return;
	}
	FILE* file = nullptr;
	AllocConsole();
	freopen_s(&file, "CON", "r", stdin);
	freopen_s(&file, "CON", "w", stdout);
	SetConsoleTitleA("debug window");
	debug_window = GetConsoleWindow();
	EnableMenuItem(GetSystemMenu(debug_window, false), SC_CLOSE, MF_GRAYED | MF_BYCOMMAND);
}

DWORD DebugTest(LPVOID lp) {

	InitHacker();



	return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
	if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
		SetConsoleStatus(true);
#if !DEBUG_TEST
		printf("DebugTest...\n");
		CreateThread(0, 0, DebugTest, 0, 0, 0);
		return TRUE;
#endif // 0
		printf("Init...\n");
		InitHookConfig();
		CreateThread(0, 0, Init, 0, 0, 0);
	}
	return TRUE;
}