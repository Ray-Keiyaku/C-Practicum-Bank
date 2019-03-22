/*
Target: 菜单及界面
Author： Deng
Time: 20190312
*/
#include "public.h"

void menu()//主菜单
{
    void CHOICEmenu(int);
	int chose1=0;
    system("cls");
    printf("                              **************************************************************");
    printf("\n");
    printf("                              *                                                            *");
    printf("\n");
    printf("                              *                  欢迎进入银行储蓄管理系统                  *");
    printf("\n");
    printf("                              *                                                            *");
    printf("\n");
    printf("                              *                           主菜单                           *");
    printf("\n");
    printf("                              *                                                            *");
    printf("\n");
    printf("                              *          1.注册                            2.登录          *");
    printf("\n");
    printf("                              *                                                            *");
    printf("\n");
    printf("                              *          3.用户服务                        4.管理员登陆    *");
    printf("\n");
    printf("                              *                                                            *");
    printf("\n");
    printf("                              *                                                            *");
    printf("\n");
    printf("                              *                                                            *");
    printf("\n");
    printf("                              *                                                            *");
    printf("\n");
    printf("                              *                                            5.退出系统      *");
    printf("\n");
    printf("                              *                                                            *");
    printf("\n");
    printf("                              **************************************************************\n");
    printf("                                                   请输入你的选择(1~4)\n");
    fflush(stdin);
    scanf("%d",&chose1);
    while( chose1 != 1 && chose1 !=2 && chose1 != 3 && chose1 != 4 && chose1 != 5 )
    {
        printf("您的输入错误，请重新输入\n");
        scanf("%d",&chose1);
    }
	CHOICEmenu(chose1);
}

void CHOICEmenu(int choicem)//主菜单后台
{
    void addclient( Message head );
    void login();
    void userservice();
    void adminlogin();

    system("CLS");
    switch(choicem)
    {
        case 1:
			printf("                                                    客户注册账号                        ");
		    printf("\n");
			addclient(Mhead);
			break;
        case 2:
            login(Mhead);
            break;
        case 3:
            userservice();
            break;
        case 4:
            adminlogin();
            break;
        case 5:
            printf("退出系统成功，感谢您的使用\n");
            break;
    }
}

void userservice()//用户服务菜单
{
    void CHOICEservice(int);
    int choose2;
    system("cls");
    printf("                              **************************************************************");
    printf("\n");
    printf("                              *                                                            *");
    printf("\n");
    printf("                              *                  欢迎进入银行储蓄管理系统                  *");
    printf("\n");
    printf("                              *                                                            *");
    printf("\n");
    printf("                              *                        用户服务界面                        *");
    printf("\n");
    printf("                              *                                                            *");
    printf("\n");
    printf("                              *          1.找回密码                       2.修改密码       *");
    printf("\n");
    printf("                              *                                                            *");
    printf("\n");
    printf("                              *          3.撤销账户                       4.返回主菜单     *");
    printf("\n");
    printf("                              *                                                            *");
    printf("\n");
    printf("                              **************************************************************\n");
    printf("                                                   请输入你的选择(1~4)\n");
    fflush(stdin);
    scanf("%d",&choose2);
    while( choose2 != 1 && choose2 !=2 && choose2 != 3 && choose2 != 4 )
    {
        printf("您的输入错误，请重新输入\n");
        scanf("%d",&choose2);
    }
	CHOICEservice(choose2);
}

void CHOICEservice(int choices)//用户服务菜单后台
{
    void change( Message Mhead );
    void find();
    void cancel();

    switch(choices)
    {
        case 1:
			system("cls");
			find(Mhead);
			break;
        case 2:
            system("cls");
            change( Mhead );
            break;
        case 3:
            system("cls");
            cancel( Mhead );
            break;
        case 4:
            system("cls");
            menu();
            break;
    }
}

void userlogin()//用户登录菜单
{
    void CHOICElogin(int);
    int choose3;
    int dingcheck();
    void zhuancun(int);

    if(dingcheck())
    {
        zhuancun(dingcheck());
    }
    system("cls");
    printf("                              **************************************************************");
    printf("\n");
    printf("                              *                                                            *");
    printf("\n");
    printf("                              *                       恭喜您已登陆成功                     *");
    printf("\n");
    printf("                              *                                                            *");
    printf("\n");
    printf("                              *                      请选择以下几种业务                    *");
    printf("\n");
    printf("                              *                                                            *");
    printf("\n");
    printf("                              *          1.查询余额                       2.存款           *");
    printf("\n");
    printf("                              *                                                            *");
    printf("\n");
    printf("                              *          3.取款                           4.退出登录       *");
    printf("\n");
    printf("                              *                                                            *");
    printf("\n");
    printf("                              **************************************************************\n");
    printf("                                                   请输入你的选择(1~4)\n");
    fflush(stdin);
    scanf("%d",&choose3);
    while( choose3 != 1 && choose3 !=2 && choose3 != 3 && choose3 != 4 )
    {
        printf("您的输入错误，请重新输入\n");
        scanf("%d",&choose3);
    }
	CHOICElogin(choose3);
}

void adminlogin()//管理员登录菜单
{
    void adminchoice();

    printf("                              **************************************************************");
    printf("\n");
    printf("                              *                                                            *");
    printf("\n");
    printf("                              *                  欢迎进入银行储蓄管理系统                  *");
    printf("\n");
    printf("                              *                                                            *");
    printf("\n");
    printf("                              *                        管理员登陆界面                      *");
    printf("\n");
    printf("                              *                                                            *");
    printf("\n");
    printf("                              **************************************************************\n");
    int i;
    for( i = 0;i < 3;i++ )
    {
        printf("                                                       请输入您的密码\n");
        fflush(stdin);
        char c;
        int x = 0;
        char pass[10] = {NULL} ;
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
        if( strcmp(pass,"123456") == 0 )
        {
            system("cls");
            adminchoice();
            return;
        }
         if( i == 2 )
        {
            printf("\n密码错误次数已达上限，退出系统\n");
            system("pause");
            menu();
            return;
        }
        else
        {
            printf("\n\n您输入的密码错误，请重新输入（本日输错次数达到3次则退出系统）\n\n\n");
        }
    }
}

void adminchoice()//管理员操作菜单
{
    void editRate();
    void chaxun();

            int n;
            printf("                              **************************************************************");
            printf("\n");
            printf("                              *                                                            *");
            printf("\n");
            printf("                              *                       恭喜您已登陆成功                     *");
            printf("\n");
            printf("                              *                                                            *");
            printf("\n");
            printf("                              *                      请选择以下几种业务                    *");
            printf("\n");
            printf("                              *                                                            *");
            printf("\n");
            printf("                              *          1.修改利率                       2.查询信息       *");
            printf("\n");
            printf("                              *                                                            *");
            printf("\n");
            printf("                              *          3.退出登录                                        *");
            printf("\n");
            printf("                              *                                                            *");
            printf("\n");
            printf("                              **************************************************************\n");
            printf("                                                   请输入你的选择(1~3)\n");
            fflush(stdin);
            scanf("%d",&n);
            while( n != 1 && n !=2 && n != 3 )
            {
                printf("您的输入错误，请重新输入\n");
                scanf("%d",&n);
            }
            switch(n)
            {
                case 1:
                    system("cls");
                    editRate();
                    system("cls");
                    adminchoice();
                    break;
                case 2:
                    system("cls");
                    chaxun();
                    system("cls");
                    return;
                case 3:
                    system("cls");
                    menu();
                    return;
            }
}

void CHOICElogin(int choicel)//用户登录菜单后台
{
    void menu();
    void inquiry();
    void save();
    void withdraw();
    switch(choicel)
    {
        case 1:
			system("cls");
			inquiry(Mhead);
			break;
        case 2:
            system("cls");
            save(Mhead);
            break;
        case 3:
            system("cls");
            withdraw();
            break;
        case 4:
            system("cls");
            menu();
            break;
    }
}

int saveface()//存款菜单
{
    int x;
    void userlogin();
    printf("                              **************************************************************");
    printf("\n");
    printf("                              *                                                            *");
    printf("\n");
    printf("                              *                           存款系统                         *");
    printf("\n");
    printf("                              *                                                            *");
    printf("\n");
    printf("                              *                      请选择以下几种业务                    *");
    printf("\n");
    printf("                              *                                                            *");
    printf("\n");
    printf("                              *          1.活期存款                       2.定期存款       *");
    printf("\n");
    printf("                              *                                                            *");
    printf("\n");
    printf("                              *          3.活期转定期                     4.定期转活期     *");
    printf("\n");
    printf("                              *                                                            *");
    printf("\n");
    printf("                              *          5.返回                                            *");
    printf("\n");
    printf("                              *                                                            *");
    printf("\n");
    printf("                              **************************************************************\n");
    printf("                                                   请输入你的选择(1~4)\n");
    fflush(stdin);
    scanf("%d",&x);
    while( x != 1 && x !=2 && x != 3 && x!=4 && x!=5 )
    {
        printf("您的输入错误，请重新输入\n");
        scanf("%d",&x);
        if(x==5)
        {
            userlogin();
            exit(0);
        }
    }
    return x;
}
