#include "Window.h"

#include "WindowRegister.h"

Window::Window() {
	m_handler = WindowRegister::instance()->createPlatformWindow();
}

void Window::show() {
	ShowWindow(m_handler, SW_SHOWDEFAULT);
}

bool Window::event(UINT uMsg, WPARAM wParam, LPARAM lParam) {
	return false;
}

