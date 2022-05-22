#pragma once

#include <Windows.h>
#include "WindowContent.h"
#include "../PopC.h"

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

class Window
{
public:
	Window();
	//Window();
	// class_name, window_title
	// style
	// x_position, y_position, width, height
	// Parent window
	// menu

	Window(LPCWSTR window_title, HICON icon, int x_position, int y_position, int width, int height);

	Window(const Window&) = delete;
	Window& operator =(const Window&) = delete;
	~Window();

	bool ProcessMessages();

	HWND Get_hWnd();
	WindowContent& GetContent();

private:
	HINSTANCE m_hInstance;
	HWND m_hWnd;
	WindowContent m_content;
};

