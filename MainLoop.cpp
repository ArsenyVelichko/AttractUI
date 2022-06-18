#include "MainLoop.h"

MainLoop::MainLoop() {

}

int MainLoop::run() {
	MSG msg = { };
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
