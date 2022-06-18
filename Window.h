#pragma once

#include <windows.h>

class Window {
public:
	Window();

	void show();
	void resize(int width, int height);

	bool event(UINT uMsg, WPARAM wParam, LPARAM lParam);

private:
	HWND m_handler;
};
