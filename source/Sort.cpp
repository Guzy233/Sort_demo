#include "Main.h"
#include <vector>
//插入排序
void InsertSort(Data &a, Index l, Index r)
{
    for (int i = l + 1; i < r; i++)
    {
        auto t = a[i];
        Index j;
        for (j = i - 1; j >= l && a[j] > t; j--)
            a.Set(j + 1, j);
        a.Set(j + 1, t);
    }
}

//划分
Index Partition(Data &a, Index l, Index r)
{
    auto t = a[r];
    for (Index j = l; j < r; j++)
        if (a[j] < t)
            a.swap(j, l++);
    a.swap(l, r);
    return l;
}
//另一个版本的划分
Index H_Partition(Data &a, Index l, Index r)
{
    short temp = a[l], t;
    Index i = l, j = r + 1;
    while (true)
    {
        while (a[++i] < temp && i <= r)
            ;
        while (a[--j] > temp)
            ;
        if (i >= j)
            break;
        a.swap(i, j);
    }
    a.Set(l, j);
    a.Set(j, temp);
    return j;
}
//快速排序
void QuickSort(Data &a, Index l, Index r)
{
    if (r - l > 8)
    {
        Index q = H_Partition(a, l, r - 1);
        QuickSort(a, l, q);
        QuickSort(a, q + 1, r);
    }
    else
        InsertSort(a, l, r);
}

//冒泡排序
void BubbleSort(Data &a, Index l, Index r)
{
    r--;
    for (Index i = l; i < r; i++)
    {
        for (Index j = r; j > i; --j)
        {
            if (a[j] < a[j - 1])
            {
                a.swap(j, j - 1);
            }
        }
    }
}

//选择排序
void SelectSort(Data &data, Index l, Index r)
{
    for (Index i = l; i < r; i++)
    {
        Index min = i;
        for (Index j = i; j < r; j++)
            if (data[min] > data[j])
                min = j;
        data.swap(min, i);
    }
}

//合并
void Merge(Data &a, Index l, Index q, Index r)
{
    //构造vector
    vector<type> L(&a[l], &a[q + 1]), R(&a[q + 1], &a[r]);
    //哨兵
    L.push_back(TYPE_MAX);
    R.push_back(TYPE_MAX);
    for (auto i = l; i < q; i++)
        a.Draw(i);
    for (auto i = q; i < r; i++)
        a.Draw(i);
    auto itL = L.begin(), itR = R.begin();
    while (l < r)
    {
        if (*itL < *itR)
            a.Set(l, *itL++);
        else
            a.Set(l, *itR++);
        l++;
        a.Draw(l);
    }
}
//归并排序
void MergeSort(Data &a, Index l, Index r)
{
    if (r - l > 8)
    {
        auto q = (l + r) / 2;
        MergeSort(a, l, q + 1);
        MergeSort(a, q + 1, r);
        Merge(a, l, q, r);
    }
    else
        InsertSort(a, l, r);
}

//最大堆
void MaxHeap(Data &a, Index i, Index heap_size)
{
    auto s = a[i];
    do
    {
        auto l = a[i * 2], r = a[i * 2 + 1];
        if (l > r)
        {
            if (s > l)
                break;
            a.swap(i * 2, i);
            i *= 2;
        }
        else
        {
            if (s > r)
                break;
            a.swap(i, i * 2 + 1);
            i *= 2;
            i += 1;
        }
    } while (i * 2 + 1 < heap_size);
}
//建堆
Index BuildMaxHeap(Data &a, Index l, Index r)
{
    auto heap_size = r - l - 1;
    for (int i = (l + r - 1) / 2; i >= l; i--)
        MaxHeap(a, i, heap_size);
    return heap_size;
}
//堆排序
void HeapSort(Data &a, Index l, Index r)
{
    for (
        auto heap_size = BuildMaxHeap(a, l, r);
        heap_size > 2;
        heap_size--)
    {
        a.swap(l + heap_size, l);
        MaxHeap(a, l, heap_size);
    }
    InsertSort(a,0,3);
}

DWORD WINAPI Sort(LPVOID lpParamter)
{
    auto &data = *global::data;

    while (true)
    {
        global::delayTime = 3;

        {
            // { //堆排
            //     data.mix();
            //     HeapSort(data, 0, global::data_amount);
            //     data.Draw();
            //     Sleep(2000);
            // }
            // { //归并
            //     data.mix();
            //     MergeSort(data, 0, global::data_amount);
            //     data.Draw();
            //     Sleep(2000);
            // }
            // { //快排
            //     data.mix();
            //     QuickSort(data, 0, global::data_amount);
            //     data.Draw();
            //     Sleep(2000);
            // }
        }

        global::delayTime = 1;
        {
            // { //插排
            //     data.mix();
            //     InsertSort(data, 0, global::data_amount);
            //     data.Draw();
            //     Sleep(2000);
            // }
            // { //选排
            //     data.mix();
            //     SelectSort(data, 0, global::data_amount);
            //     data.Draw();
            //     Sleep(2000);
            // }
            { //冒泡
                Sleep(2000);
                data.mix();
                // Sleep(2000);
                BubbleSort(data, 0, global::data_amount);
                data.Draw();
                Sleep(2000);
            }
        }
    }
    return 0;
}