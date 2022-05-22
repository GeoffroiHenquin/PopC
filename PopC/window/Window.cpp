#include "Window.h"

LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_SIZE:
		PopC::GetWindow(hWnd).GetContent().ResizeContent(LOWORD(lParam), HIWORD(lParam));
		return 0;
	case WM_PAINT:

		WindowContent& c = PopC::GetWindow(hWnd).GetContent();

		HDC hdc;
		PAINTSTRUCT ps;
		HWND hw;

		hdc = BeginPaint(hWnd, &ps);

		HBRUSH hbrush;
		HPEN hpen;

		for (int i = 0; i < c.GetUpdatedPixelList().size(); i++) 
		{
			RECT rect = { c.GetUpdatedPixelList().at(i).x, c.GetUpdatedPixelList().at(i).y, c.GetUpdatedPixelList().at(i).x, c.GetUpdatedPixelList().at(i).y };
			hbrush = CreateSolidBrush(c.GetColorAt(c.GetUpdatedPixelList().at(i).x, c.GetUpdatedPixelList().at(i).y));
			FillRect(hdc, &rect, hbrush);
		}

		EndPaint(hWnd, &ps);

		return 0;
		break;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

Window::Window()
	: m_hInstance(GetModuleHandle(nullptr))
{
	const wchar_t* CLASS_NAME = L"My Window Class";

	WNDCLASS wndClass = {};
	wndClass.lpszClassName = CLASS_NAME;
	wndClass.hInstance = m_hInstance;
	wndClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.lpfnWndProc = WindowProc;

	RegisterClass(&wndClass);

	DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU | WS_SIZEBOX;

	int width = 640;
	int height = 480;

	RECT rect;
	rect.left = 250;
	rect.top = 250;
	rect.right = rect.left + width;
	rect.bottom = rect.top + height;

	AdjustWindowRect(&rect, style, false);

	m_hWnd = CreateWindowEx(
		0,
		CLASS_NAME,
		L"Title",
		style,
		rect.left,
		rect.top,
		rect.right - rect.left,
		rect.bottom - rect.top,
		NULL,
		NULL,
		m_hInstance,
		NULL
	);

	ShowWindow(m_hWnd, SW_SHOW);
}

Window::Window(LPCWSTR window_title, HICON icon, int x_position, int y_position, int width, int height)
	: m_hInstance(GetModuleHandle(nullptr))
{
	const wchar_t* CLASS_NAME = L"My Window Class";

	WNDCLASS wndClass = {};
	wndClass.lpszClassName = CLASS_NAME;
	wndClass.hInstance = m_hInstance;
	wndClass.hIcon = icon;
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.lpfnWndProc = WindowProc;

	RegisterClass(&wndClass);

	DWORD style = WS_CAPTION | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU | WS_SIZEBOX;

	RECT rect;
	rect.left = x_position;
	rect.top = y_position;
	rect.right = rect.left + width;
	rect.bottom = rect.top + height;

	AdjustWindowRect(&rect, style, false);

	m_hWnd = CreateWindowEx(
		0,
		CLASS_NAME,
		window_title,
		style,
		rect.left,
		rect.top,
		rect.right - rect.left,
		rect.bottom - rect.top,
		NULL,
		NULL,
		m_hInstance,
		NULL
	);

	ShowWindow(m_hWnd, SW_SHOW);
}

Window::~Window()
{
	const wchar_t* CLASS_NAME = L"My Window Class";

	UnregisterClass(CLASS_NAME, m_hInstance);
}

/*void Window::updateTest()
{
	//UpdateWindow(m_hWnd);

	RedrawWindow(m_hWnd, NULL, NULL, WM_PAINT);
}*/

bool Window::ProcessMessages()
{
	MSG msg = {};

	while (PeekMessage(&msg, nullptr, 0u, 0u, PM_REMOVE))
	{
		if (msg.message == WM_QUIT)
		{
			return false;
		}

		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return true;
}

HWND Window::Get_hWnd()
{
	return m_hWnd;
}

WindowContent& Window::GetContent()
{
	return m_content;
}
