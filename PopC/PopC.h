#pragma once
#include "window/Window.h"
class PopC
{
public:
	PopC();
	~PopC();
	static PopC& Instance();
private:
	static PopC instance;
	Window win_instance;
private:
	// Data to create a window
	char window_title;
	HICON icon;
	int x_position;
	int y_position;
	int width;
	int height;
public:
	void Setup(char window_title, HICON icon, int x_position, int y_position, int width, int height);
	void Start();
	void Paint();
	void Stop();

	// Hide and show the console
	void HideConsole();
	void ShowConsole();
	bool IsConsoleVisible();

	// Add graphics to the window
};

