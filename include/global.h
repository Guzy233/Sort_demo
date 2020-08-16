class Data;

//全局类
class global
{
public:
    //窗口句柄
    static HWND hWnd;

    //绘图句柄
    static HDC hdc;

    //红色画刷
    static HBRUSH redBrush;

    //实际数据
    static Data *data;

    //每次操作的延时
    static DWORD delayTime;

    //输出错误信息
    static ofstream out;
    static void overflow(Index index,const char* sourse)
    {
        out << "error:overflow at " << index << " form " << sourse <<endl;
        PostMessage(hWnd,WM_DESTROY,0,0);
    }

    //数据总量,可以随意修改
    static const Index data_amount = 256;

    //单个数据在屏幕上的宽度
    static const DWORD unitWeight = 4;

    //每个相邻数据的差
    static const DWORD unitHeight = 2;

    //窗口初始位置
    static const DWORD win_x = 100;
    static const DWORD win_y = 50;

    //窗口的高度和宽度,由unitHeight和data_amount计算得来
    static const DWORD height = data_amount * unitHeight;
    static const DWORD weight = data_amount * unitWeight;

    //边缘留白
    static const DWORD blank = 50;
};