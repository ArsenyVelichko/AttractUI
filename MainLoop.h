#pragma once

#include <windows.h>

class MainLoop {
public:
	MainLoop();

	int run();

private:
	void update();
};
