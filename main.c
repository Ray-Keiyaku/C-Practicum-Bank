/*
Target: 主函数
Author： Ray
Time: 20190308
*/
#include"public.h"

int main()
{
    //声明函数
    Message creatlist();
    void ReadToList( Message Mhead );
    void menu();
    void interest();
    void readRate();

    Mhead=creatlist();//建立链表
    //从文件读取
    ReadToList(Mhead);
    readRate();

    //test1();//测试函数
    interest();//计算利息

    menu();//主界面

    return 0;
}
