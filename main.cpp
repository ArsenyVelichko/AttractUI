#include <windows.h>

#include "Window.h"
#include "MainLoop.h"

int main(void) {
	MainLoop ml;
	Window w;

	w.show();

	return ml.run();
}