/*
Target: 初期链表测试（Debug）
Author： Ray
Time: 20190315
*/

#include "public.h"

void test1()//输出链表（用于测试）
{
    Message p1=Mhead->next;
    int i=0;
    while(p1)
    {
        printf("%%%d.  %s %s %s %s %s %s %f %d %d %d %d %f %d %d %d %d %f %d %d %d %d\n\n",i,
                     p1->name,p1->sex,p1->phone,p1->ID,p1->num,p1->password,
                     p1->deposit[0],p1->lyear[0],p1->year[0],p1->month[0],p1->day[0],
                     p1->deposit[1],p1->lyear[1],p1->year[1],p1->month[1],p1->day[1],
                     p1->deposit[2],p1->lyear[2],p1->year[2],p1->month[2],p1->day[2]);
        p1=p1->next;
        i++;
    }
}
