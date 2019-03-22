/*
Target: 全局头文件
Author： Ray
Time: 20190308
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#define MES (Message)malloc(sizeof(message))

typedef struct clientmessage//用户信息
{
    char name[20];  //姓名
    char sex[10];  //性别
    char phone[12];  //电话号码
    char ID[20];  //身份证号
    char num[20];  //用户账号
    char password[7];  //密码
    double deposit[3];//存款
    int lyear[3];//存款时间
    //存款日期
    int year[3];
    int month[3];
    int day[3];
    //利息
    double lixi;
    int lixiy[2];
    int lixim[2];
    int lixid[2];
    struct clientmessage* next;
}message,*Message;

struct Rate//利率
{
    float zero;//活期
    float one;//定期1
    float two;//定期2
    float three;//定期3
    float five;//定期5
    //最后一次修改利率的日期
    int year;
    int month;
    int day;

}rate;

FILE *fp;//宏定义文件指针
Message Mhead;//宏定义链表
char NUM[20];//用于多函数间流通的账号信息
void update();//宏更新函数声明
int YEAR,MONTH,DAY;//当前日期存储
void test1();//宏测试函数声明
