#pragma once

#include <windows.h>

class Window {
public:
	Window();

	void show();

	bool event(UINT uMsg, WPARAM wParam, LPARAM lParam);

private:
	HWND m_handler;
};
