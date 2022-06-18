#include "MainLoop.h"

MainLoop::MainLoop() {

}

int MainLoop::run() {
	MSG msg = {};

	while (WM_QUIT != msg.message) {

		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);

		} else {
			update();
		}
	}
	return msg.wParam;
}

void MainLoop::update() {

}
