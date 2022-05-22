#include "WindowContent.h"

void WindowContent::ResizeContent(int x, int y)
{
	windowSize.x = x;
	windowSize.y = y;

	content.resize(x);
	for (int i = 0; i < x; i++) content.at(i).resize(y);

	UpdatedPixelList.clear();
}

void WindowContent::SetPixel(int x, int y, COLORREF color)
{
	if (color == content.at(x).at(y)) return;

	content.at(x).at(y) = color;

	WindowCoordinate newPixel;
	newPixel.x = x;
	newPixel.y = y;
	UpdatedPixelList.push_back(newPixel);
}

void WindowContent::ClearUpdatedPixelList()
{
	UpdatedPixelList.clear();
}

WindowCoordinate WindowContent::GetSize()
{
	return windowSize;
}

std::vector<WindowCoordinate> WindowContent::GetUpdatedPixelList()
{
	return UpdatedPixelList;
}

COLORREF WindowContent::GetColorAt(int x, int y)
{
	return content.at(x).at(y);
}
