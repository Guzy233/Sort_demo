#ifndef __HEAD_H
#define __HEAD_H
#include <Windows.h>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

typedef INT32 Index; //�±�����
typedef INT16 type;  //����ʵ������
#define TYPE_MAX __INT_FAST16_MAX__

#include "global.h" //ȫ�ֱ���
#include "Data.h"   //������
//���ڹ���
LRESULT CALLBACK WndProc(
    HWND hwnd,
    UINT msg,
    WPARAM wparam,
    LPARAM lparam);
//��������
void MakeWindow(
    HINSTANCE hInstance,
    HWND &hWnd,
    int nCmdShow);
//������
DWORD WINAPI Sort(LPVOID lpParamter);
#endif