#include "PopC.h"

void PopC::AddWindow()
{
	WindowList.push_back(Window());
}

void PopC::AddWindow(LPCWSTR window_title, HICON icon, int x_position, int y_position, int width, int height)
{
	WindowList.push_back(Window(window_title, icon, x_position, y_position, width, height));
}

Window& PopC::GetWindow(HWND hw)
{
	for (int i = 0; i < WindowList.size(); i++)
	{
		if (WindowList.at(i).Get_hWnd() == hw) { return WindowList.at(i); }
	}
}
