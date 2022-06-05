#pragma once
#include "Callback.h"
class Window
{
public:
	Window();
	//Window(const Window&) = delete;
	//Window& operator =(const Window&) = delete;
	~Window();

	void Paint();

	bool ProcessMessages();
private:
	HINSTANCE m_hInstance;
	HWND m_hWnd;
};

