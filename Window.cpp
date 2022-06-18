#include "Window.h"

#include "WindowRegister.h"

Window::Window() {
	m_handler = WindowRegister::instance()->createPlatformWindow();
}

void Window::show() {
	ShowWindow(m_handler, SW_SHOWDEFAULT);
}

