#include "Main.h"
//���ڹ���
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:
		//ȫ�ֱ�����ʼ��
		global::delayTime = 3;
		global::hdc = GetDC(hWnd);
		global::data = new Data();
		global::redBrush = CreateSolidBrush(RGB(255, 0, 0));
		global::out.open("log",ofstream::app);
		return 0;
	case WM_PAINT:
	{
		// �ͷ�hdc�ٴ���,��֤���κ�ʱ����ʹ��
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
			break;//������Ĳ���ESC��break
	case WM_DESTROY:
		//�ͷ���Դ
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