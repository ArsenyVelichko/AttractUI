#pragma once

#include <memory>
#include <map>
#include <windows.h>

#include "Window.h"

class WindowRegister {
public:
	static WindowRegister* instance();

	HWND createPlatformWindow();

	void windowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

private:
	WindowRegister();
	const char* registerClass();

	std::map<HWND, Window*> m_windows;

	static std::unique_ptr<WindowRegister> m_instance;
};
