#include "PopC.h"

PopC PopC::instance;

PopC::PopC()
{
}

PopC::~PopC()
{
}

PopC& PopC::Instance()
{
	return instance;
}

void PopC::Setup(char window_title_p, HICON icon_p, int x_position_p, int y_position_p, int width_p, int height_p)
{
	window_title = window_title_p;
	icon = icon_p;
	x_position = x_position_p;
	y_position = y_position_p;
	width = width_p;
	height = height_p;
}

void PopC::Start()
{
	win_instance = Window();
}

void PopC::Paint()
{
}

void PopC::Stop()
{
	win_instance.~Window();
}

void PopC::HideConsole()
{
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

void PopC::ShowConsole()
{
	::ShowWindow(::GetConsoleWindow(), SW_SHOW);
}

bool PopC::IsConsoleVisible()
{
	return ::IsWindowVisible(::GetConsoleWindow()) != FALSE;
}
