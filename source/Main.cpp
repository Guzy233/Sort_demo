#include "Main.h"

//全局变量的定义
HDC global::hdc;
DWORD global::delayTime=3;
Data* global::data;
HBRUSH global::redBrush;
ofstream global::out;
HWND global::hWnd;

// WinMain函数
int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hprevinstance,
    LPSTR lpcmdline,
    int nCmdShow)
{
    //创建窗口
    MakeWindow(hInstance, global::hWnd, nCmdShow);
    //创建排序线程
    CreateThread(NULL, 0, Sort, NULL, 0, NULL);
    // 消息
    MSG msg;
    //消息循环
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (msg.wParam);
}