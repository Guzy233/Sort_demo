#include "Main.h"

//ȫ�ֱ����Ķ���
HDC global::hdc;
DWORD global::delayTime=3;
Data* global::data;
HBRUSH global::redBrush;
ofstream global::out;
HWND global::hWnd;

// WinMain����
int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hprevinstance,
    LPSTR lpcmdline,
    int nCmdShow)
{
    //��������
    MakeWindow(hInstance, global::hWnd, nCmdShow);
    //���������߳�
    CreateThread(NULL, 0, Sort, NULL, 0, NULL);
    // ��Ϣ
    MSG msg;
    //��Ϣѭ��
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (msg.wParam);
}