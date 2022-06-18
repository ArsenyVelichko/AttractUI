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

void Window::resize(int width, int height) {
//	RECT clientRect;
//	GetClientRect(m_handler, &clientRect);
//
//	clientRect.right = clientRect.left + width;
//	clientRect.bottom = clientRect.top + height;
//	AdjustWindowRect(&clientRect, WS_OVERLAPPEDWINDOW, FALSE);
//
//	SetWindowPos(m_handler, nullptr,
//				 0, 0,
//				 clientRect.right - clientRect.left,
//				 clientRect.bottom - clientRect.top,
//				 SWP_NOMOVE|SWP_NOZORDER);
}

