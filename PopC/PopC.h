#pragma once

#include <Windows.h>
#include <vector>
#include "window/Window.h"

class PopC
{
private:
	static std::vector<Window> WindowList;

public:
	static void AddWindow();
	static void AddWindow(LPCWSTR window_title, HICON icon, int x_position, int y_position, int width, int height);

	static Window& GetWindow(HWND hw);
};

