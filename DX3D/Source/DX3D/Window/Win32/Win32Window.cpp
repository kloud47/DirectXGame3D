#include <DX3D/Window/Window.h>
#include <Windows.h>

// Because the Windows API is a C-style API, it does not understand C++ object instances 
static LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
	switch (msg)
	{
	case WM_CLOSE:
	{
		PostQuitMessage(0);
		break;
	}
	default: return DefWindowProc(hwnd, msg, wparam, lparam);
	}
	return 0;
}

dx3dEngine::Window::Window(const WindowDesc& desc) : Base(desc.base)
{
	auto registerWindowClassFunction = []() // modern C++ way to make code self contained:
		{
			// Here we are creating a Win32 window using the Windows API.
			WNDCLASSEX wc{};// Brace Initialization for Windows Class
			wc.cbSize = sizeof(WNDCLASSEX);
			wc.lpszClassName = L"DX3DWindow";
			wc.lpfnWndProc = &WindowProcedure; // Default Window Procedure
			return RegisterClassEx(&wc);
		};

	static const auto windowClassId = std::invoke(registerWindowClassFunction);

	if (!windowClassId) DX3DLogErrorAndThrow("RegisterCLassEx failed.");
		
	RECT rc{0, 0, 1280, 720};
	AdjustWindowRect(&rc, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, false);

	m_handle = CreateWindowEx(NULL, MAKEINTATOM(windowClassId), L"Kloud47 | C++ 3D Game from Scratch",
		WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT,
		rc.right - rc.left, rc.bottom - rc.top, 
		nullptr, nullptr, nullptr, nullptr);

	if (!m_handle) DX3DLogErrorAndThrow("CreateWindowEx failed.");

    ShowWindow(static_cast<HWND>(m_handle), SW_SHOW);

	m_logger.log(Logger::LogLevel::Info, "Window Initialized.");
}

dx3dEngine::Window::~Window()
{
	DestroyWindow(static_cast<HWND>(m_handle));
}
