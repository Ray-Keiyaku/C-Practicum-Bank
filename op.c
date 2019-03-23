/*
Target: 功能实现
Author： Ray&Deng
Time: 20190308
*/
#include "public.h"

void addclient( Message head )
{
    void menu();

    int i;
    FILE *fw = fopen("client.txt","a+");
	Message temp = head->next;
	//Message temp2=head->next; //编号查重指针
    //当表中无用户直接在头结点后注册
    if(!temp)
    {
        temp = MES;
        head->next = temp;
    }
    else
    {
        //表中有用户则在最后一个节点后生成新节点
        while(temp->next)
        {
            temp = temp->next;
        }
        Message last = MES;
        temp->next = last;
        temp = last;
    }
	char temporary1[7];
	char temporary2[7];
	int j;
    fflush(stdin);
    printf("请输入您的姓名\n");
    fflush(stdin);
    scanf("%s",temp->name);
    fflush(stdin);
    fprintf(fw,temp->name);
    fprintf(fw,"\t");
    do
	{
		printf("\n\n请输入您的性别(male/female):\n");
		fflush(stdin);
		scanf("%s",temp->sex);
		fflush(stdin);
		if( strcmp( temp->sex,"male" ) != 0 && strcmp( temp->sex,"female" ) != 0 )
        {
            printf("\n\n您的性别输入错误，请重新输入\n");
			fflush(stdin);
        }
	}while( strcmp( temp->sex,"male" ) != 0 && strcmp( temp->sex,"female" ) != 0 );
	fprintf(fw,temp->sex);
    fprintf(fw,"\t");

    do
	{
		fflush(stdin);
		printf("\n\n请输入您的电话号码\n");
		fflush(stdin);
		scanf("%s",temp->phone);
		fflush(stdin);
		if( strlen( temp->phone ) != 11 )
			printf("\n\n您的电话号码输入错误，请重新输入\n");
	}while( strlen( temp->phone) != 11 );
	fprintf(fw,temp->phone);
    fprintf(fw,"\t");

    do
	{
		fflush(stdin);
		printf("\n\n请输入您的身份证号\n");
		fflush(stdin);
		scanf("%s",temp->ID);
		fflush(stdin);
		if( strlen( temp->ID ) != 18 )
			printf("\n\n您的身份证号输入错误，请重新输入\n");
	}while( strlen( temp->ID ) != 18 );
	fprintf(fw,temp->ID);
    fprintf(fw,"\t");
	fflush(stdin);

    do
	{
		fflush(stdin);
		printf("\n\n请输入银行卡号码(19位)\n");
		fflush(stdin);
		scanf("%s",temp->num);
		fflush(stdin);
		if( strlen( temp->num ) != 19 )
			printf("\n\n您的银行卡号码输入错误，请重新输入\n");
	}while( strlen( temp->num) != 19 );
	fprintf(fw,temp->num);
    fprintf(fw,"\t");
	do
    {
        char c;
        int x = 0;
        printf("\n\n请输入您的6位密码\n");
        fflush(stdin);
        while ( ( c = getch() ) != '\r' ) //密码加密处理
        {
            if (x<6 && isprint(c))
            {
                temporary1[x++] = c;
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
        temporary1[x]='\0';
        fflush(stdin);
        printf("\n\n请再次确认您的密码\n");
        fflush(stdin);
        x = 0;
		while ( ( c = getch() ) != '\r' ) //密码加密处理
        {
            if (x<6 && isprint(c))
            {
                temporary2[x++] = c;
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
        temporary2[x]='\0';
		fflush(stdin);
		if( strcmp(temporary1,temporary2) != 0 )
			printf("\n\n您输入的密码与之前不一致，请重新输入\n");
	}while( strcmp(temporary1,temporary2) != 0 );

	for( j = 0;j < 7;j ++ )
    {
        temp->password[j] = temporary1[j];
    }
    fprintf(fw,temp->password);
    fprintf(fw,"\t");
    for(int h=0;h<3;h++)
    {
        temp->deposit[h]=0;
        temp->lyear[h]=0;
        temp->year[h]=0;
        temp->month[h]=0;
        temp->day[h]=0;
        fprintf(fw,"%f\t",temp->deposit[h]);
        fprintf(fw,"%d\t",temp->lyear[h]);
        fprintf(fw,"%d\t",temp->year[h]);
        fprintf(fw,"%d\t",temp->month[h]);
        fprintf(fw,"%d\t",temp->day[h]);
    }
    temp->lixi=0;
    fprintf(fw,"%f\t",temp->lixi);
    for(int h=0;h<2;h++)
    {
        temp->lixiy[h]=0;
        temp->lixiy[h]=0;
        temp->lixid[h]=0;
        fprintf(fw,"%d\t",temp->lixiy[h]);
        fprintf(fw,"%d\t",temp->lixim[h]);
        fprintf(fw,"%d\t",temp->lixid[h]);
    }

    fprintf(fw,"\n");

    fclose(fw);
    temp->next = NULL;
    printf("恭喜您成功成为我们银行客户中的一员,请输入1返回主菜单\n");
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

void find(Message Mhead)//找回密码
{
    void userservice();
    void menu();

    char num[20];
    char id[20];
    char phone[12];
    int i,flag;
    printf("请输入您想找回密码的账号：");
    Message temp1 = Mhead->next;
    do
    {
        flag=0;
        scanf("%s",num);
        while(temp1)
        {
            if( 0 == strcmp(temp1->num,num) )
            {
                flag=1;
                break;
            }
            temp1 = temp1->next;
        }
        if(!flag)
        {
            printf("该账号未注册，若要返回请按1，重新输入请按2");
            scanf("%d",&i);
            if(i==1)
                {
                    userservice();
                    return;
                }
        }
    }while(!flag);
    printf("\n\n我们需要核对您其他的信息。");
    printf("\n\n请输入您的身份证号：");
    scanf("%s",id);
    printf("\n\n请输入您的电话号码：");
    scanf("%s",phone);
    char temporary1[7],temporary2[7];
    if( 0 == strcmp(temp1->num,num) && 0 == strcmp(temp1->ID,id) && 0 == strcmp(temp1->phone,phone) )
        {
            system("CLS");
            printf("信息核对正确，请重新设置密码：\n");

            do
            {
                char c;
                int x = 0;
                printf("\n\n请输入您的6位密码\n");
                fflush(stdin);
                while ( ( c = getch() ) != '\r' ) //密码加密处理
                {
                    if (x<6 && isprint(c))
                    {
                        temporary1[x++] = c;
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
                temporary1[x]='\0';
                fflush(stdin);
                printf("\n\n请再次确认您的密码\n");
                fflush(stdin);
                x = 0;
                while ( ( c = getch() ) != '\r' ) //密码加密处理
                {
                    if (x<6 && isprint(c))
                    {
                        temporary2[x++] = c;
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
                temporary2[x]='\0';
                fflush(stdin);
                if( strcmp(temporary1,temporary2) != 0 )
                    printf("\n\n您输入的密码与之前不一致，请重新输入\n");
            }while( strcmp(temporary1,temporary2) != 0 );
            for(int j = 0;j < 7;j ++ )
            {
                temp1->password[j] = temporary1[j];
            }
            update();
            printf("重置密码成功！\n");
        }
    else
        {
            printf("信息不正确，");
            system("pause");
            userservice();
            return;
        }
    printf("\n\n请输入1返回主菜单");
    scanf("%d",&i);
    if( i == 1 )
    {
        menu();
        return;
    }
    else
    {
        do
        {
            system("CLS");
            printf("密码重设成功，请输入1返回主菜单\n");
            scanf("%d",&i);
            if( i == 1 )
            {
                menu();
                break;
            }
        }while( i != 1 );
    }
}

void change( Message Mhead )//修改密码
{
    void menu();

    int n,t;
    char num[20];
    printf("\n请输入您想修改密码的账号:");
    scanf("%s",num);
    for( n = 0;n < 3;n ++ )
    {
        printf("\n\n请输入您初始的密码:");
        char c;
        int x = 0 ;
        char pass[7] ;
        fflush(stdin);
        while ( ( c = getch() ) != '\r' )
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
        Message temp1 = Mhead->next;
        while(temp1)
        {
            if( 0 == strcmp(temp1->num,num) && 0 == strcmp(temp1->password,pass) )
            {
                break;
            }
            temp1 = temp1->next;
        }
        if( temp1 )
        {
            printf("\n\n验证成功\n");
            break;
        }
        else
        {
            printf("\n\n您输入的账号或密码错误，请重新输入（本日输错次数达到3次则退出系统）\n");
        }
    }
    if( n == 3 )
    {
        printf("\n密码错误次数已达上限，退出系统\n");
        system("pause");
        menu();
        return;
    }
            fflush(stdin);
            printf("\n\n请输入您新的密码：");
            fflush(stdin);
            char c;
            int x = 0 ;
            char temporary1[7] ;
            fflush(stdin);
            while ( ( c = getch() ) != '\r' )
            {
                if (x<6 && isprint(c))
                {
                    temporary1[x++] = c;
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
            temporary1[x] = '\0';
            printf("\n\n请再次确认您的密码\n");
            char temporary2[7] ;
            do
            {
                fflush(stdin);
                char c;
                int x = 0 ;
                fflush(stdin);
                while ( ( c = getch() ) != '\r' )
                {
                    if (x<6 && isprint(c))
                    {
                        temporary2[x++] = c;
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
                temporary2[x] = '\0';
                if( strcmp(temporary1,temporary2) != 0 )
                    {
                        printf("\n\n您输入的密码与之前不一致，请重新输入\n");
                    }
            }while( strcmp(temporary1,temporary2) != 0 );
            if( strcmp(temporary1,temporary2) == 0 )
            {
                printf("\n\n修改成功！\n");
            Message temp1 = Mhead->next;
            while(temp1)
            {
                if( 0 == strcmp(temp1->num,num) )
                {
                    break;
                }
                temp1 = temp1->next;
            }
            for( int j = 0;j < 7;j ++ )  //记录新的密码
            {
                temp1->password[j] = temporary1[j];
            }
            update();
                do
                {
                    printf("请输入1返回主菜单\n");
                    scanf("%d",&t);
                    if( t == 1 )
                    {
                        menu();
                        break;
                    }
                }while( t != 1 );
            }
            else
            {
                printf("\n\n您输入的账号或密码错误，请重新输入（本日输错次数达到3次则退出系统）\n");
            }
}
void cancel( Message Mhead )//销户
{
    void menu();

    int n,t;
    char num[20];
    printf("\n请输入您想撤销的账号:");
    scanf("%s",num);
    for( n = 0;n < 3;n ++ )
    {
        printf("\n\n请输入您的密码:");
        char c;
        int x = 0 ;
        char pass[7] ;
        fflush(stdin);
        while ( ( c = getch() ) != '\r' )
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
        Message temp1 = Mhead->next;
        while(temp1)
        {
            if( 0 == strcmp(temp1->num,num) && 0 == strcmp(temp1->password,pass) )
            {
                break;
            }
            temp1 = temp1->next;
        }
        if( temp1 )
        {
            printf("\n\n验证成功\n");
            break;
        }
        else
        {
            printf("\n\n您输入的账号或密码错误，请重新输入（本日输错次数达到3次则退出系统）\n");
        }
    }
    if( n == 3 )
    {
        printf("\n密码错误次数已达上限，退出系统\n");
        system("pause");
        menu();
        return;
    }
    printf("\n\n是否确认撤销该账户（记得在撤销账户之前将账户里钱取出哦）\n");
    printf("\n  1. 确认      2.取消并返回主菜单\n");
    fflush(stdin);
    scanf("%d",&t);
    if( t == 1 )
    {
        fp = fopen("client.txt","w");
        fclose(fp);
        Message temp1 = Mhead;
        Message temp2;
        while(temp1)
        {
            if( 0 == strcmp(temp1->next->num,num) )
            {
                break;
            }
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        free(temp1);
        update();
        printf("\n\n撤销账户成功，感谢您的使用\n");
        system("pause");
        menu();
        return;
    }
    if( t == 2 )
    {
        system("cls");
        menu();
        return;
    }
}

void inquiry(Message Mhead)//查询存款
{
    void userlogin();

    int i;
    Message temp1 = Mhead->next;
    while(temp1)
    {
        if( 0 == strcmp(temp1->num,NUM) )
        {
            break;
        }
        temp1 = temp1->next;
    }
    printf("您的存款为：\n");
    printf("存款              类型             存款时间                 到期时间\n");
    printf("%13.2f     活期          %4d年%2d月%2d日\n",temp1->deposit[0],temp1->year[0],temp1->month[0],temp1->day[0]);
    if(temp1->lyear[1]!=0)
    {
        printf("%13.2f     定期          %4d年%2d月%2d日          %4d年%2d月%2d日\n",temp1->deposit[1],temp1->year[1],temp1->month[1],temp1->day[1],(temp1->year[1]+temp1->lyear[1]),temp1->month[1],temp1->day[1]);
    }
    if(temp1->lyear[2]!=0)
    {
        printf("%13.2f     定期          %4d年%2d月%2d日          %4d年%2d月%2d日\n",temp1->deposit[2],temp1->year[2],temp1->month[2],temp1->day[2],(temp1->year[2]+temp1->lyear[2]),temp1->month[2],temp1->day[2]);
    }
    do
    {
        printf("\n\n请输入1返回\n");
        scanf("%d",&i);
        if( i == 1 )
        {
            userlogin();
            break;
        }
    }while( i != 1 );
}

void withdraw()//取款
{
    void userlogin();

    double money;
    int i;
    Message temp = Mhead->next;
    while(temp)
    {
        if( 0 == strcmp(temp->num,NUM) )
        {
            break;
        }
        temp = temp->next;
    }
    printf("请输入您想取出的金额：");
    scanf("%lf",&money);
    if( money > temp->deposit[0] )
    {
        printf("\n\n取出金额超出存款金额\n\n");
        system("pause");
        userlogin();
        return;
    }
    temp->deposit[0] -= money;
    printf("\n\n取款成功\n\n");
    update();
    do
    {
        printf("\n\n请输入1返回\n");
        scanf("%d",&i);
        if( i == 1 )
        {
            userlogin();
            break;
        }
    }while( i != 1 );
}


void save(Message Mhead)//存款
{
    int saveface();
    void userlogin();
    int ntime();

    int i,j,s=1;
    double cumo=0;
    Message temp1 = Mhead->next;
    while(temp1)
    {
        if( 0 == strcmp(temp1->num,NUM) )
        {
            break;
        }
        temp1 = temp1->next;
    }
    i=saveface();
    system("CLS");
    if(i==1)//活期存款
    {
        printf("当前活期利率：%.2f%%\n",rate.zero);
        printf("请输入存款金额：\n");
        scanf("%lf",&cumo);
        if(cumo<=0)
            {
                printf("存款金额错误！");
                system("pause");
                userlogin();
                return;
            }
        if(temp1->deposit[0]==0)
        {
            temp1->lixiy[0]=YEAR;
            temp1->lixim[0]=1;
            temp1->lixid[0]=1;
        }
        temp1->deposit[0]+=cumo;
        ntime();
        temp1->year[0]=YEAR;
        temp1->month[0]=MONTH;
        temp1->day[0]=DAY;
        temp1->lixiy[1]=YEAR;
        temp1->lixim[1]=MONTH;
        temp1->lixid[1]=DAY;
        update();
        printf("\n\n存款成功！\n");
        system("pause");
    }
    else if(i==2)//定期存款
    {
        if(temp1->lyear[1]==0)
            s=1;
        else if(temp1->lyear[2]==0)
            s=2;
        else
        {
            printf("存款数量上限");
            system("pause");
            userlogin();
            return;
        }
        printf("请选择存款时间：\n");
        printf("1.一年（%.2f%%）\n",rate.one);
        printf("2.二年（%.2f%%）\n",rate.two);
        printf("3.三年（%.2f%%）\n",rate.three);
        printf("4.五年（%.2f%%）\n",rate.five);
        scanf("%d",&j);
        printf("请输入存款金额：\n");
        scanf("%lf",&cumo);
        if(cumo<=0)
            {
                printf("存款金额错误！\n");
                system("pause");
                userlogin();
                return;
            }
        ntime();
        if(j==4)
            j++;
        temp1->deposit[s]+=cumo;
        temp1->lyear[s]=j;
        temp1->year[s]=YEAR;
        temp1->month[s]=MONTH;
        temp1->day[s]=DAY;
        update();
        printf("\n\n存款成功！\n");
        system("pause");
    }
    else if(i==3)
    {
        if(temp1->lyear[1]==0)
            s=1;
        else if(temp1->lyear[2]==0)
            s=2;
        else
        {
            printf("存款数量上限");
            system("pause");
            userlogin();
            return;
        }
        printf("您当前活期存款数目为：%.2f\n",temp1->deposit[0]);
        printf("请选择存款时间：\n");
        printf("1.一年（%.2f%%）\n",rate.one);
        printf("2.二年（%.2f%%）\n",rate.two);
        printf("3.三年（%.2f%%）\n",rate.three);
        printf("4.五年（%.2f%%）\n",rate.five);
        scanf("%d",&j);
        do
        {
            printf("请输入转存存金额：\n");
            scanf("%lf",&cumo);
            if(cumo<=0)
            {
                printf("存款金额错误！\n");
                system("pause");
                userlogin();
                return;
            }
            if(cumo>temp1->deposit[0])
                printf("转存金额不能超过存款额！\n");
        }while(cumo>temp1->deposit[0]);
        ntime();
        if(j==4)
            j++;
        temp1->deposit[0]-=cumo;
        temp1->deposit[s]+=cumo;
        temp1->lyear[s]=j;
        temp1->year[s]=YEAR;
        temp1->month[s]=MONTH;
        temp1->day[s]=DAY;
        update();
        printf("\n\n转存成功！\n");
        system("pause");
    }
    else if(i==4)
    {
        int flag1=0,flag2=0;
        printf("您当前定期存款有：");
        printf("   存款              类型             存款时间                 到期时间\n");
        printf("   %13.2f     活期          %4d年%2d月%2d日\n",temp1->deposit[0],temp1->year[0],temp1->month[0],temp1->day[0]);
        if(temp1->lyear[1]!=0)
        {
            printf("1. %13.2f     定期          %4d年%2d月%2d日          %4d年%2d月%2d日\n",temp1->deposit[1],temp1->year[1],temp1->month[1],temp1->day[1],(temp1->year[1]+temp1->lyear[1]),temp1->month[1],temp1->day[1]);
            flag1=1;
        }
        if(temp1->lyear[2]!=0)
        {
            printf("2. %13.2f     定期          %4d年%2d月%2d日          %4d年%2d月%2d日\n",temp1->deposit[2],temp1->year[2],temp1->month[2],temp1->day[2],(temp1->year[2]+temp1->lyear[2]),temp1->month[2],temp1->day[2]);
            flag2=1;
        }
        if(flag1==1&&flag2==1)
        {
            printf("\n请选择要转入活期的存款编号（1/2）：\n");
            do
            {
                scanf("%d",&j);
                if(j!=1&&j!=2)
                    printf("输入错误，请重新输入：\n");
            }while(j!=1&&j!=2);
        }
        else if(flag1==1&&flag2==0)
        {
            printf("\n");
            system("pause");
            j=1;
        }
        else if(flag1==0&&flag2==1)
        {
            printf("\n");
            system("pause");
            j=2;
        }
        else if(flag1==0&&flag2==0)
        {
            printf("您当前没有定期存款！\n");
            system("pause");
            userlogin();
            return;
        }
        system("CLS");
        printf("\n\n确定要转入活期么？（定期未到期将不会计算利息）\n");
        printf("1.确认   2.取消\n");
        do
        {
            scanf("%d",&s);
            if(s!=1&&s!=2)
                printf("输入错误，请重新输入：\n");
        }while(s!=1&&s!=2);
        if(i==2)
        {
            userlogin();
            return;
        }
        ntime();
        temp1->deposit[0]+=temp1->deposit[j];
        temp1->deposit[j]=0;
        temp1->lyear[j]=0;
        temp1->year[j]=0;
        temp1->month[j]=0;
        temp1->day[j]=0;
        temp1->year[0]=YEAR;
        temp1->month[0]=MONTH;
        temp1->day[0]=DAY;
        update();
        printf("\n\n转存成功！\n");
        system("pause");
    }

    userlogin();
    return;
}

void chaxun()//管理员查询
{
    void adminchoice();

     int i,n,j;
     n = 1;
     char id[20];
     Message temp = Mhead->next;
     printf("姓名\t\t身份证号\n");
     while(temp)
    {
        printf("%s\t\t%s\n",temp->name,temp->ID);
        temp = temp->next;
    }

    do
    {
        printf("\n\n输入1继续查询，输入2返回\n\n");
        scanf("%d",&j);
        if(j == 1)
        {
            printf("\n\n请输入您想查看的账户的身份证号：");
            scanf("%s",id);
            temp = Mhead -> next;
            while(temp)
            {
                if( strcmp(id,temp->ID) == 0 )
                {
                    break;
                }
                temp = temp->next;
            }
            if(!temp)
            {
                printf("你输入的用户身份证号不存在，请查证后重新输入");
                system("pause");
                system("cls");
                adminchoice();
                return;
            }
            system("cls");
            temp = Mhead -> next;
            while(temp)
            {
                if( strcmp(id,temp->ID) == 0 )
                {
                    printf("该用户的所有账户信息为:\n");
                    printf("\n\n卡号%d：%s\n\n",n++,temp->num);
                    printf("存款              类型             存款时间                 到期时间\n");
                    printf("%13.2f     活期          %4d年%2d月%2d日\n",temp->deposit[0],temp->year[0],temp->month[0],temp->day[0]);
                    if(temp->lyear[1]!=0)
                    {
                        printf("%13.2f     定期          %4d年%2d月%2d日          %4d年%2d月%2d日\n",temp->deposit[1],temp->year[1],temp->month[1],temp->day[1],(temp->year[1]+temp->lyear[1]),temp->month[1],temp->day[1]);
                    }
                    if(temp->lyear[2]!=0)
                    {
                        printf("%13.2f     定期          %4d年%2d月%2d日          %4d年%2d月%2d日\n",temp->deposit[2],temp->year[2],temp->month[2],temp->day[2],(temp->year[2]+temp->lyear[2]),temp->month[2],temp->day[2]);
                    }

                }
                temp = temp->next;
            }
            do
            {
                printf("\n\n请输入1返回\n");
                scanf("%d",&i);
                if( i == 1 )
                {
                    system("cls");
                    adminchoice();
                    break;
                }
            }while( i != 1 );
        }
        else if( j == 2 )
        {
            system("cls");
            adminchoice();
            break;
        }
        else
        {
            printf("您的输入错误，请重新输入\n");
        }
    }while( j !=1 && j != 2 );
}

void editRate()//管理员修改利率
{
    void updateRate();
    int ntime();
    int h;
    printf("当前利率为：（修改于%4d年%2d月%2d日）\n\n",rate.year,rate.month,rate.day);
    printf("活期：%.2f%%\n一年：%.2f%%\n两年：%.2f%%\n三年：%.2f%%\n五年：%.2f%%\n\n",rate.zero,rate.one,rate.two,rate.three,rate.five);
    printf("是否修改？\n1.修改\t2.返回\n");
    scanf("%d",&h);
    while(h!=1&&h!=2)
    {
        printf("输入错误，请重新输入\n");
        scanf("%d",&h);
    }
    if(h==1)
    {
        printf("请输入新利率：");
        //给行末添加百分号
        printf("\n活期：    %%\b\b\b\b\b");
        scanf("%f",&rate.zero);
        printf("\n一年：    %%\b\b\b\b\b");
        scanf("%f",&rate.one);
        printf("\n两年：    %%\b\b\b\b\b");
        scanf("%f",&rate.two);
        printf("\n三年：    %%\b\b\b\b\b");
        scanf("%f",&rate.three);
        printf("\n五年：    %%\b\b\b\b\b");
        scanf("%f",&rate.five);
        ntime();
        rate.year=YEAR;
        rate.month=MONTH;
        rate.day=DAY;
        updateRate();
        system("CLS");
        printf("修改成功！修改后利率为：\n\n");
        printf("活期：%.2f%%\n一年：%.2f%%\n两年：%.2f%%\n三年：%.2f%%\n五年：%.2f%%\n\n",rate.zero,rate.one,rate.two,rate.three,rate.five);

    }
}
