# Sort_demo

## 这是一个简单的排序算法演示程序,绘图使用Windows GDI

***

### 各文件介绍

* main.h:主头文件,包含一些include和函数声明  
* global.h:全局变量类,包含一些全局变量的声明  
* data.h:实际数据类  
* data.cpp:data类的成员实现,包含了绘图代码  
* main.cpp:程序入口函数,进行一部分初始化  
* wndproc.cpp:窗口过程函数,进行一部分初始化  
* sort.cpp:算法实现

***

如果手动编译出错请尝试-mwindows编译选项

`g++ source\*.cpp -I include -mwindows`
