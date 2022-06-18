#include <windows.h>

#include "Window.h"

int main(void) {
	Window w;

	w.show();

	MSG msg = { };
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}