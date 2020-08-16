#include "Main.h"
//交换数据
void Data::swap(Index index_1, Index index_2)
{
    if (index_1 < global::data_amount &&
        index_2 < global::data_amount)
    {
        //交换
        auto temp = data[index_1];
        data[index_1] = data[index_2];
        data[index_2] = temp;
        //画出来
        Draw(index_1);
        Draw(index_2);
    }
    else
        global::overflow(
            index_1 >= global::data_amount ? index_1 : index_2, __func__);
}
//随机混合
void Data::mix()
{
    srand(time(NULL));
    for (Index i = 0; i < global::data_amount; i++)
    {
        swap(i, rand() % global::data_amount);
    }
}
//构造函数
Data::Data()
{
    for (Index i = 0; i < global::data_amount; i++)
    {
        data[i] = i;
    }
    Draw();
}
#define DrawBlack(rect) FillRect(global::hdc, &rect, (HBRUSH)GRAY_BRUSH)
#define DrawRed(rect) FillRect(global::hdc, &rect, global::redBrush)
#define DrawWhite(rect) FillRect(global::hdc, &rect, (HBRUSH)WHITE_BRUSH)
//画单个数据(有延时)
void Data::Draw(Index index)
{
    RECT rect;
    rect.left = index * global::unitWeight + global::blank;
    rect.right = rect.left + global::unitWeight;
    rect.bottom = global::height + global::blank - data[index] * global::unitHeight;
    rect.top = 0;

    //画黑色
    DrawBlack(rect);

    rect.top = rect.bottom;
    rect.bottom = global::height + global::blank;
    //画红色
    DrawRed(rect);
    //延时
    Sleep(global::delayTime);
    //画白色
    DrawWhite(rect);
}
//画全部数据(无延时)
void Data::Draw()
{
    RECT rect;
    for (Index index = 0; index < global::data_amount; index++)
    {
        rect.left = index * global::unitWeight + global::blank;
        rect.right = rect.left + global::unitWeight;
        rect.bottom = global::height + global::blank - data[index] * global::unitHeight;
        rect.top = 0;

        // 画黑色
        DrawBlack(rect);

        rect.top = rect.bottom;
        rect.bottom = global::blank + global::height;

        // 画白色
        DrawWhite(rect);
    }
}