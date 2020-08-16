#ifndef __HEAD_H
#define __HEAD_H
#include <Windows.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

typedef INT32 Index; //下标类型
typedef INT16 type;  //数据实际类型
#define TYPE_MAX __INT_FAST16_MAX__

#include "global.h" //全局变量
#include "Data.h"   //数据类
//窗口过程
LRESULT CALLBACK WndProc(
    HWND hwnd,
    UINT msg,
    WPARAM wparam,
    LPARAM lparam);
//创建窗口
void MakeWindow(
    HINSTANCE hInstance,
    HWND &hWnd,
    int nCmdShow);
//排序函数
DWORD WINAPI Sort(LPVOID lpParamter);
#endif