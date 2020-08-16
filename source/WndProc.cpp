#include "Main.h"
//窗口过程
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:
		//全局变量初始化
		global::delayTime = 3;
		global::hdc = GetDC(hWnd);
		global::data = new Data();
		global::redBrush = CreateSolidBrush(RGB(255, 0, 0));
		global::out.open("log",ofstream::app);
		return 0;
	case WM_PAINT:
	{
		// 释放hdc再创建,保证在任何时候都能使用
		PAINTSTRUCT ps;
		ReleaseDC(hWnd, global::hdc);
		global::hdc = BeginPaint(hWnd, &ps);
		global::data->Draw();
		EndPaint(hWnd, &ps);
		global::hdc = GetDC(hWnd);
	}
		return 0;
	case WM_KEYDOWN:
		if (wParam != VK_ESCAPE)
			break;//如果按的不是ESC就break
	case WM_DESTROY:
		//释放资源
		ReleaseDC(hWnd, global::hdc);
		PostQuitMessage(0);
		DeleteObject(global::redBrush);
		delete global::data;
		exit(0);
	default:
		break;
	}
	return (DefWindowProc(hWnd, msg, wParam, lParam));
}