#include "Main.h"
void MakeWindow(HINSTANCE hinstance, HWND &hWnd, int nCmdShow)
{
    //���ڽṹ��
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

    //��Ҫע���
    //����ɫ
    cWin.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    //������
    cWin.lpszClassName = "Sort_demo_512";
    //���ڹ���
    cWin.lpfnWndProc = WndProc;

    //ע�ᴰ��
    RegisterClassExA(&cWin);

    //��������
    hWnd = CreateWindowExA(
        0,
        //������
        "Sort_demo_512",
        //���ڱ���
        "Sort_demo",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        //����λ��
        global::win_x,
        global::win_y,
        //���ڴ�С
        global::weight + global::blank * 2 + 16, //16�Ǵ��ڱ߿�Ŀ��
        global::height + global::blank * 2 + 38, //38�Ǵ��ڱ߿�ĸ߶�
        NULL,
        NULL,
        hinstance,
        NULL);

    if (!hWnd)
        exit(0);

    ShowWindow(hWnd, nCmdShow);

    //ˢ�´���
    UpdateWindow(hWnd);
}