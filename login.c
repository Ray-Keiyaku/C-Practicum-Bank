/*
Target: 用户登录
Author： Deng
Time: 20190311
*/
#include "public.h"

void login()
{
    int n,i=0;
    void menu();
    void userlogin();

    printf("                              **************************************************************");
    printf("\n");
    printf("                              *                                                            *");
    printf("\n");
    printf("                              *                  欢迎进入银行储蓄管理系统                  *");
    printf("\n");
    printf("                              *                                                            *");
    printf("\n");
    printf("                              *                        用户登陆界面                        *");
    printf("\n");
    printf("                              *                                                            *");
    printf("\n");
    printf("                              **************************************************************");
    if( NULL == Mhead -> next )
    {
        printf("\n\n                                        请您先完成注册才能登陆哦（输入1返回主菜单）\n");
        scanf("%d",&i);
        if( i == 1 )
        {
            menu();
        }
        else
        {
            do
            {
                printf("请输入1返回主菜单\n");
                scanf("%d",&i);
                if( i == 1 )
                {
                    menu();
                    break;
                }
            }while( i != 1 );
        }
    }
    char pass[7];

    printf("\n请输入您的账号:");
    scanf("%s",NUM);

    Message temp = Mhead->next;
    while(temp)
        {
            if( 0 == strcmp(temp->num,NUM) )
                break;
            temp = temp->next;
        }

    for( n = 0;n < 3;n ++ )
    {
        char c;
        int x = 0 ;
        printf("\n\n请输入您的6位密码:");
        fflush(stdin);

        while ( ( c = getch() ) != '\r' ) //密码加密处理
        {
            if (x<6 && isprint(c))
            {
                pass[x++] = c;
                printf("*");
            }
            else if (x>0 && c=='\b')
            {
                --x;
                putchar('\b');
                putchar(' ');
                putchar('\b');
            }
        }

        putchar('\n');
        pass[x] = '\0';
        fflush(stdin);
        if(!temp)
        {
            printf("您输入的账号不存在，请查证后重新登陆！\n");
            system("pause");
            menu();
            return;
        }
        if(0 == strcmp(temp->password,pass))
        {

            userlogin();
            return;
        }
        if( n == 2 )
        {
            printf("\n密码错误次数已达上限，退出系统\n");
            system("pause");
            menu();
        }
        else
        {
            printf("\n\n您输入的密码错误，请重新输入（本日输错次数达到3次则退出系统）\n");
        }
    }
}
