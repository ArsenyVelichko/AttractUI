#pragma once

#include <windows.h>

class Window {
public:
	Window();

	void show();

private:
	HWND m_handler;
};
