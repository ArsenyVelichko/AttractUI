#include "WindowRegister.h"

#include <iostream>

std::unique_ptr<WindowRegister> WindowRegister::m_instance;

WindowRegister* WindowRegister::instance() {
	if (!m_instance) {
		auto rawPtr = new WindowRegister();
		m_instance = std::unique_ptr<WindowRegister>(rawPtr);
	}
	return m_instance.get();
}

WindowRegister::WindowRegister() {

}

static LRESULT CALLBACK wndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	return WindowRegister::instance()->windowProc(hwnd, uMsg, wParam, lParam);
}

const char* WindowRegister::registerClass() {
	static bool registered = false;
	const char* className = "Window class";

	if (registered) { return className; }

	WNDCLASS wc = { };

	wc.lpfnWndProc   = wndProc;
	wc.hInstance     = GetModuleHandle(nullptr);
	wc.lpszClassName = className;

	RegisterClass(&wc);

	registered = true;
	return className;
}

HWND WindowRegister::createPlatformWindow() {
	const char* className = registerClass();

	HWND handler = CreateWindow(
			className,				   // Window class
			"",                        // Window text
			WS_OVERLAPPEDWINDOW,       // Window style

			// Size and position
			CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

			nullptr,                   // Parent window
			nullptr,                   // Menu
			GetModuleHandle(nullptr),  // Instance handle
			nullptr                    // Additional application data
	);

	return handler;
}

LRESULT WindowRegister::windowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	auto window = m_windows[hwnd];
	bool handled = window->event(uMsg, wParam, lParam);

	if (uMsg == WM_DESTROY) {
		m_windows.erase(hwnd);

		if (m_windows.empty()) {
			PostQuitMessage(0);
			handled = true;
		}
	}

	if (handled) { return 0; }
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

