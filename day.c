/*
Target: 日期计算及判断
Author： Ray
Time: 20181121
*/

#include "public.h"

int d1[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int d2[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int DayCompute(int year_1,int month_1,int day_1,int year_2,int month_2,int day_2)//计算两日期时间差
{
    int yearjudge(int);
    int monthday(int year_1, int month_1, int month_2, int day_1, int day_2);
            int days=0;
            if(year_1==year_2)
            {
                days = monthday(year_1, month_1, month_2, day_1, day_2);
            }
            if(year_2-year_1==1)
            {
                days = monthday(year_1, month_1, 12, day_1, 31);
                days += monthday(year_2, 1, month_2, 1, day_2)+1;
            }
            if(year_2-year_1>1)
            {
                days = monthday(year_1, month_1, 12, day_1, 31);
                for (int j = year_1 + 1; j < year_2;j++)
                {
                    if(yearjudge(j))
                        days += 366;
                    else
                        days += 365;
                }
                days += monthday(year_2, 1, month_2, 1, day_2) + 1;
            }
    return days;
}

int yearjudge(int year)//判断闰年
{
    if((year%4==0&&year%100!=0)||year%400==0)
        return 1;
    else
        return 0;
}
int monthday(int year_1,int month_1,int month_2,int day_1,int day_2)//计算一年内起止日期间天数
{
    int yearjudge(int year);
    int days=0;
    if(month_1==month_2)
    {
        days = day_2 - day_1;
    }
    else if(month_2-month_1==1)
    {
        if(!yearjudge(year_1))
            days=d1[month_1-1]-day_1+day_2;
        else if(yearjudge(year_1))
            days=d2[month_1-1]-day_1+day_2;
    }
    else
    {
        if(!yearjudge(year_1))
        {
            days = d1[month_1-1]-day_1+day_2;
            for(int i=month_1+1;i<=month_2-1;i++)
                days+=d1[i-1];
        }
        else if(yearjudge(year_1))
        {
            days = d2[month_1-1]-day_1+day_2;
            for(int i=month_1+1;i<=month_2-1;i++)
                days+=d2[i-1];
        }
    }
    return days;
}

int xianhou(int year_1,int month_1,int day_1,int year_2,int month_2,int day_2)//判断两日期前后
{
    if(year_1>=year_2)
    {
        if(month_1>=month_2||year_1>year_2)
        {
            if(day_1>=day_2||month_1>month_2||year_1>year_2)
                return 0;
        }
    }
        return 1;
}
