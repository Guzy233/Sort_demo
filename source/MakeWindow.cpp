#include "Main.h"
void MakeWindow(HINSTANCE hinstance, HWND &hWnd, int nCmdShow)
{
    //窗口结构体
    WNDCLASSEXA cWin;
    cWin.cbSize = sizeof(WNDCLASSEX);
    cWin.style = CS_VREDRAW | CS_HREDRAW | CS_OWNDC | CS_DBLCLKS;
    cWin.cbClsExtra = 0;
    cWin.cbWndExtra = 0;
    cWin.hInstance = hinstance;
    cWin.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    cWin.hCursor = LoadCursor(NULL, IDC_ARROW);
    cWin.lpszMenuName = NULL;
    cWin.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    //需要注意的
    //背景色
    cWin.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    //窗口名
    cWin.lpszClassName = "Sort_demo_512";
    //窗口过程
    cWin.lpfnWndProc = WndProc;

    //注册窗口
    RegisterClassExA(&cWin);

    //创建窗口
    hWnd = CreateWindowExA(
        0,
        //窗口名
        "Sort_demo_512",
        //窗口标题
        "Sort_demo",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        //窗口位置
        global::win_x,
        global::win_y,
        //窗口大小
        global::weight + global::blank * 2 + 16, //16是窗口边框的宽度
        global::height + global::blank * 2 + 38, //38是窗口边框的高度
        NULL,
        NULL,
        hinstance,
        NULL);

    if (!hWnd)
        exit(0);

    ShowWindow(hWnd, nCmdShow);

    //刷新窗口
    UpdateWindow(hWnd);
}