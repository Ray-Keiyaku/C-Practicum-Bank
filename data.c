/*
Target: 数据I/O
Author： Ray
Time: 201903012
*/
#include"public.h"

Message creatlist()//创建链表并返回头指针
{
    Message Mhead = MES;
    Mhead -> next = NULL;

    return Mhead;
}

void ReadToList( Message Mhead )//从文件读取
{
    fp = fopen("client.txt","r");
    if(NULL == fp)
    {
        fp = fopen("client.txt","a+");
        fp = fopen("client.txt","r");
    }
    Message p1,p2;
    p2 = Mhead;
    while(1)
    {
        p1=MES;
        if(!p1)
            exit(-1);
        //检测到录入完毕后将分配的空间清除掉
        if(fscanf(fp,"%s %s %s %s %s %s %lf %d %d %d %d %lf %d %d %d %d %lf %d %d %d %d %lf %d %d %d %d %d %d",
                     &p1->name[0],&p1->sex[0],&p1->phone[0],&p1->ID[0],&p1->num[0],&p1->password[0],
                     &p1->deposit[0],&p1->lyear[0],&p1->year[0],&p1->month[0],&p1->day[0],
                     &p1->deposit[1],&p1->lyear[1],&p1->year[1],&p1->month[1],&p1->day[1],
                     &p1->deposit[2],&p1->lyear[2],&p1->year[2],&p1->month[2],&p1->day[2],
                     &p1->lixi,&p1->lixiy[0],&p1->lixim[0],&p1->lixid[0],&p1->lixiy[1],&p1->lixim[1],&p1->lixid[1])<6)
        {
            free(p1);
            break;
        }
        p2->next=p1;
        p2=p1;
        p1->next=NULL;
    }

    fclose(fp);
}

void WriteToFile(Message Mhead)//写入文件
{
    FILE *fw = fopen("client.txt","w+");
    Message temp=Mhead->next;
    if(temp==NULL){
        return;
    }
    while(temp){
        fprintf(fw,temp->name);
        fprintf(fw,"\t");
        fprintf(fw,temp->sex);
        fprintf(fw,"\t");
        fprintf(fw,temp->phone);
        fprintf(fw,"\t");
        fprintf(fw,temp->ID);
        fprintf(fw,"\t");
        fprintf(fw,temp->num);
        fprintf(fw,"\t");
        fprintf(fw,temp->password);
        fprintf(fw,"\t");
        for(int h=0;h<3;h++)
        {
            fprintf(fw,"%f\t",temp->deposit[h]);
            fprintf(fw,"%d\t",temp->lyear[h]);
            fprintf(fw,"%d\t",temp->year[h]);
            fprintf(fw,"%d\t",temp->month[h]);
            fprintf(fw,"%d\t",temp->day[h]);
        }
        fprintf(fw,"%f\t",temp->lixi);
        for(int h=0;h<2;h++)
        {
            fprintf(fw,"%d\t",temp->lixiy[h]);
            fprintf(fw,"%d\t",temp->lixim[h]);
            fprintf(fw,"%d\t",temp->lixid[h]);
        }

        fprintf(fw,"\n");
        temp  = temp->next;
    }
    fclose(fw);
}

void update()//文件更新函数
{
    fp = fopen("client.txt","w");
    fclose(fp);
    WriteToFile(Mhead);
}

void updateRate()//利率更新函数
{
    fp = fopen("rate.txt","w");
    fclose(fp);
    FILE *fw = fopen("rate.txt","w+");
    fprintf(fw,"%f\t",rate.zero);
    fprintf(fw,"%f\t",rate.one);
    fprintf(fw,"%f\t",rate.two);
    fprintf(fw,"%f\t",rate.three);
    fprintf(fw,"%f\t",rate.five);
    fprintf(fw,"%d\t",rate.year);
    fprintf(fw,"%d\t",rate.month);
    fprintf(fw,"%d\t",rate.day);

    fclose(fw);
}

void readRate()//从文件读取利率
{
    fp = fopen("rate.txt","r");
    if(NULL == fp)
    {
        fp = fopen("rate.txt","a+");
        fp = fopen("rate.txt","r");
    }
    fscanf(fp,"%f%f%f%f%f%d%d%d",&rate.zero,&rate.one,&rate.two,&rate.three,&rate.five,&rate.year,&rate.month,&rate.day);

    fclose(fp);
}

int ntime(int argc, char **argv)//查询当前日期
{
    time_t tmpcal_ptr;
	struct tm *tmp_ptr = NULL;

	time(&tmpcal_ptr);
	//printf("tmpcal_ptr=%d\n", tmpcal_ptr);

	tmp_ptr = gmtime(&tmpcal_ptr);
	//printf("after gmtime, the time is:%d:%d:%d\n", tmp_ptr->tm_hour, tmp_ptr->tm_min, tmp_ptr->tm_sec);

	tmp_ptr = localtime(&tmpcal_ptr);
	//printf ("after localtime, the time is:%d.%d.%d ", (1900+tmp_ptr->tm_year), (1+tmp_ptr->tm_mon), tmp_ptr->tm_mday);
	//printf("%d:%d:%d\n", tmp_ptr->tm_hour, tmp_ptr->tm_min, tmp_ptr->tm_sec);

	YEAR=(1900+tmp_ptr->tm_year);
	MONTH=(1+tmp_ptr->tm_mon);
	DAY=(tmp_ptr->tm_mday);
	return 0;
}

