#pragma once
#include <wtypes.h>
#include <vector>

struct WindowCoordinate {
	int x;
	int y;
};

class WindowContent
{
private:
	// List of pixel
	std::vector<std::vector<COLORREF>> content;

	// List of changed pixel
	std::vector<WindowCoordinate> UpdatedPixelList;

	//Window Size
	WindowCoordinate windowSize;
	
public:
	void ResizeContent(int x, int y);

	void SetPixel(int x, int y, COLORREF color);

	void ClearUpdatedPixelList();

	// Getter
	WindowCoordinate GetSize();
	std::vector<WindowCoordinate> GetUpdatedPixelList();
	COLORREF GetColorAt(int x, int y);
};

