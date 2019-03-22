/*
Target: 存款及利息处理
Author： Ray
Time: 20190320
*/
#include "public.h"

void interest()//利息计算
{
    int ntime();
    int DayCompute(int year_1,int month_1,int day_1,int year_2,int month_2,int day_2);
    int xianhou(int year_1,int month_1,int day_1,int year_2,int month_2,int day_2);

    ntime();
    Message temp = Mhead->next;
    int daytemp=0;
    float ratetemp=0;
    while(temp)
    {
        if(DayCompute(temp->lixiy[0],temp->lixim[0],temp->lixid[0],temp->lixiy[1],temp->lixim[1],temp->lixid[1])>=92)
        {
            temp->deposit[0]+=temp->lixi;
            temp->lixi=0;
            temp->lixiy[0]=temp->lixiy[1];
            temp->lixim[0]=temp->lixim[1];
            temp->lixid[0]=temp->lixid[1];
        }
        daytemp=DayCompute(temp->lixiy[1],temp->lixim[1],temp->lixid[1],YEAR,MONTH,DAY);
        if(daytemp>=1)
        {
            temp->lixi+=(((double)daytemp/365.0)*((double)rate.zero/100.0)*temp->deposit[0]);
            temp->lixiy[1]=YEAR;
            temp->lixim[1]=MONTH;
            temp->lixid[1]=DAY;
        }
        for(int i=1;i<3;i++)
        {
            if((xianhou((temp->year[i]+temp->lyear[i]),temp->month[i],temp->day[i],YEAR,MONTH,DAY)&&temp->lyear[i]!=-1)&&temp->lyear[i]!=0)
            {
                if(temp->lyear[i]==1)
                    ratetemp=rate.one;
                else if(temp->lyear[i]==2)
                    ratetemp=rate.two;
                else if(temp->lyear[i]==3)
                    ratetemp=rate.three;
                else if(temp->lyear[i]==5)
                    ratetemp=rate.five;
                temp->deposit[i]+=(((double)temp->lyear[i])*((double)ratetemp/100.0)*temp->deposit[i]);
                temp->lyear[i]=-1;
            }
        }
        temp = temp->next;
    }
    update();
}

int dingcheck()//定期到期检测
{
    Message temp = Mhead->next;
    while(temp)
    {
        if(0 == strcmp(temp->num,NUM))
        {
            if(temp->lyear[1]==-1&&temp->lyear[2]==-1)
            {
                return 3;
            }
            else if(temp->lyear[1]==-1)
            {
                return 1;
            }
            else if(temp->lyear[2]==-1)
            {
                return 2;
            }
            break;
        }
        temp = temp->next;
    }
    return 0;
}

void zhuancun(int i)//定期到期自动转活期
{
    Message temp = Mhead->next;
    while(temp)
    {
        if(0 == strcmp(temp->num,NUM))
        {
            break;
        }
        temp = temp->next;
    }
    if(i==3)
        {
            printf("您有两笔定期存款过期,将自动转为活期：\n");
            printf("本息合计              类型             存款时间\n");
            printf("%13.2f         定期          %4d年%2d月%2d日\n",temp->deposit[1],temp->year[1],temp->month[1],temp->day[1]);
            printf("%13.2f         定期          %4d年%2d月%2d日\n",temp->deposit[2],temp->year[2],temp->month[2],temp->day[2]);
            system("pause");
            temp->deposit[0]=temp->deposit[0]+temp->deposit[1]+temp->deposit[2];
            for(int h=1;h<3;h++)
            {
                temp->deposit[h]=0;
                temp->lyear[h]=0;
                temp->year[h]=0;
                temp->month[h]=0;
                temp->day[h]=0;
            }
            update();
            printf("转存成功\n");
            system("pause");
        }
        else
        {
            printf("您有一笔定期存款过期,将自动转为活期：\n");
            printf("本息合计              类型             存款时间\n");
            printf("%13.2f         定期          %4d年%2d月%2d日\n",temp->deposit[i],temp->year[i],temp->month[i],temp->day[i]);
            system("pause");
            temp->deposit[0]=temp->deposit[0]+temp->deposit[i];
            temp->deposit[i]=0;
            temp->lyear[i]=0;
            temp->year[i]=0;
            temp->month[i]=0;
            temp->day[i]=0;
            update();
            printf("转存成功\n");
            system("pause");
        }
}
