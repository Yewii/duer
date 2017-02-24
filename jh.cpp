#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct student)

struct student 
{
	char name[10];	//姓名 
	int num;	//学号 
	int call;	//学生记录	
	int exam;	//考试记录
	struct student *next;       //指向下一节点的指针  
};



/* 
=========================== 
 功能：创建链表
 =========================== 
*/  
int n;    

struct student *Create()  
{  
    struct student *head;        
    struct student *p1 = 0;   
    struct student *p2 = 0;    
  
    n = 0;           
    p1 = (struct student *) malloc (LEN);    
    p2 = p1;            
  
    if(p1==0)         
    {  
        printf ("\n不能创建链表，请重试\n");  
        return 0;  
    }  
    else                   
    {  
        head = 0;           
         
		scanf("%s%d%d%d",&(p1->name),&(p1->num),&(p1->call),&(p1->exam));
    }  
    while(p1->num != 0)       
    {  
        n += 1;           
        if(n == 1)      
        {  
            head = p1;  
            p2->next = 0;    
        }  
        else  
        {  
            p2->next = p1;    
        }  
  
        p2 = p1;               
  
        p1 = (struct student *) malloc (LEN);  
        scanf("%s%d%d%d",&(p1->name),&(p1->num),&(p1->call),&(p1->exam));
    }  
     
    p2->next = 0;      
  
    free(p1);            
    p1 = 0;             
    return head;          
}  

/* 
=========================== 
 功能：输出全部学生 
=========================== 
*/  
void Print(struct student *head)  
{  
    struct student *p;  
    printf ("\n本班共有%d名学生", n);
	printf("\n学生名字 学号 学生点名未到次数（学生记录） 考试标志 \n");  
    p = head;  
    if(head != NULL)        
    {  
        do  
        { 
			printf("%s \t %d \t\t%d \t\t\t %d\n",p->name,p->num,p->call,p->exam);
            p = p->next;    
        }  
        while (p != NULL);  
    }  
}  

/* 
=========================== 
 功能：进行点点名
 =========================== 
*/  
void call(struct student *head, int num)
{
	struct student *p;
	p = head;
	do  
	{
		char ch = ' ';
		printf("%s ",p->name);
		printf("来了吗? (此处错误输出默认为n)\t\ty/n?: ");
		//		char ch = ' ';
		scanf("%c",&ch);
		scanf("%c",&ch);
		if (ch == 'y') /*如果输入Y*/
		{
			printf("他来了!\n");/*显示他来了*/
		}
		else/*否则*/
		{
			p->call ++;
			printf("他没有来!\n");/*显示他没来*/
		}
		p = p->next;
	} while (p != 0);  
}



/* 
=========================== 
 功能：统计点名
 =========================== 
*/  
void countskip(struct student *head,int num)
{
	struct student *p;
	p = head;
	do
	{
		if (p->call >= 3) /*缺席次数大于3*/
		{
			p->exam = 0;/*则考试表示显示0*/
		}
		else
		{
			p->exam = 1;/*否则显示1*/
		}
		p = p->next;
	}while (p != 0);
}


/* 
=========================== 
 功能：输出点名三次和三次以上未到学生
 =========================== 
*/  
void outputexamstudentskip0(struct student *head,int num)
{
	struct student *p;
	p = head;
	
	printf("缺席次数大于3次的同学为：\n");
	int is_have = 0;
	do
	{
		if (p->exam == 0) 
		{
			printf("%s\n",p->name);
			is_have ++;
		}
		p = p->next;
	}while (p != 0);
	if (is_have == 0) 
	{
		printf("没有超过三次未到的同学.\n");
	}
}





/* 
=========================== 
 功能：输出点名全勤或三次以下未到学生
 =========================== 
*/  
void outputexamstudentskip1(struct student *head,int num)
{
	struct student *p;
	p = head;
	
	printf("全勤或缺席次数不到3次的同学为：\n");
	
	int is_have = 0;
	do
	{
		if (p->exam == 1) 
		{
			printf("%s\n",p->name);
			is_have ++;
		}
		p = p->next;
	}while (p != 0);
	if (is_have == 0) 
	{
		printf("没有全勤和缺席次数不到3次的同学\n");
	}
}






/* 
=========================== 
 功能：单个学生姓名查询
 =========================== 
*/  
void searchstudentname(struct student *head,int num)
{
	struct student *p;
	p = head;
	char ch[10];
	printf("请输入你想查询学生的姓名：\n");
	scanf("%s",ch);


	do
	{
		if (strcmp(ch,p->name) == 0) 
		{
			printf("\n学生名字 学号 学生点名未到次数（学生记录） 考试标志 \n");
			printf("%s \t %d \t\t%d \t\t\t %d\n",p->name,p->num,p->call,p->exam);
			
		}
		p = p->next;
	}while (p != 0);

}

/* 
=========================== 
 功能：单个学生学号查询
 =========================== 
*/  
void searchstudentnum(struct student *head,int num)
{
	struct student *p;
	p = head;
	int no;
	printf("请输入你想查询学生的学号：\n");
	scanf("%d",&no);


	do
	{
		if (no == (p->num)) 
		{
			printf("\n学生名字 学号 学生点名未到次数（学生记录） 考试标志 \n");
			printf("%s \t %d \t\t%d \t\t\t %d\n",p->name,p->num,p->call,p->exam);
			
		}
		else printf ("\n无学生信息!\n");  
		p = p->next;
	}while (p != 0);

}

/* 
========================== 
 功能：删除指定学生信息 
========================== 
*/  
struct student *Del (struct student *head, int num)  
{  
    struct student *p1;        
    struct student *p2;       
    if (head == 0)         
    {  
        printf ("\n无学生信息!\n");  
        //return head;  
    }  
  
      
    p1 = head;  
    while (p1->num != num && p1->next != NULL)     
    {  
        p2 = p1;              
        p1 = p1->next;        
    }  
  
    if(p1->num==num)        
    {  
        if (p1 == head)        
        {  
            head = p1->next;  
        }  
        else              
        {  
            p2->next = p1->next;  
        }  
  
        free (p1);        
        p1 = NULL;  
        printf ("\n删除学号%ld学生成功!\n", num);  
        n -= 1;            
    }  
    else                   
    {  
        printf ("\n学号%ld学生未找到!\n", num);  
    }  
  
    
}  


/* 
=========================== 
 主函数 
 =========================== 
*/  
int main()
{
	struct student *head;  
    struct student *les;  
    int thenumber;
	
	int over = 1;
	int studentnumber = 0;
	int docontrol = 0;
	
	printf("			******************************************************\n");
	printf("			*                                                    *\n");
	printf("			*                   班级点名系统                     *\n");
	printf("			*                                                    *\n");
	printf("			******************************************************\n\n\n");

	
	printf("			******************************************************\n");
	printf("			*        请输入学生信息，格式如下                    *\n");
	printf("			*                                                    *\n");
	printf("			*        姓名   学号  学生记录 考试记录              *\n");
	printf("			*        wang  200201    0         1                 *\n");
	printf("			*        zhang 200202    0         1                 *\n");
	printf("			*                                                    *\n");
	printf("			*       由于是刚开学，所以初试的学生记录应该为0      *\n");
	printf("			*       考试记录应该为1                              *\n");
	printf("			*       全部输入‘0 ’结束，格式如下                 *\n");
	printf("			*                                                    *\n");
	printf("			*       姓名   学号  学生记录 考试记录               *\n");
	printf("			*        0       0       0         0                 *\n");
	printf("			******************************************************\n");
	
	
	
	
	printf("请输入学生信息：\n");
	head = Create();



	while (over == 1) 
	{
		
		
		printf("			******************************************************\n");
		printf("			*   1.点名                                           *\n");
		printf("			*   2.输出点名三次和三次以上未到学生                 *\n");
		printf("			*   3.输出点名全勤或三次以下未到学生                 *\n");
		printf("			*   4.单个学生“姓名”查询                           *\n");
		printf("			*   5.单个学生“学号”查询                           *\n");
		printf("			*   6.删除某学号学生                                 *\n");
		printf("			*   7.输出全部学生信息                               *\n");
		printf("			*                                                    *\n");
		printf("			*   请选择你想进行的操作：                           *\n");
		printf("			******************************************************\n");
		scanf("%d",&docontrol);
		printf("\n");
		switch(docontrol) 
		{
		case 1:{ 
			printf("			******************************************************\n");
			printf("			*   1.点名                                           *\n");
			printf("			******************************************************\n");
			call(head,n);
			break;} 
		case 2:{ 
			printf("			******************************************************\n");
			printf("			*   2.输出点名三次和三次以上未到学生                 *\n");
			printf("			******************************************************\n");
			countskip(head,n);
			outputexamstudentskip0(head,n);
			break;} 
		case 3:{ 
			
			printf("			******************************************************\n");
			printf("			*   3.输出点名全勤或三次以下未到学生                 *\n");
			printf("			******************************************************\n");
			countskip(head,n);
			outputexamstudentskip1(head,n);
			break;} 
		case 4:{ 
			printf("			******************************************************\n");
			printf("			*   4.单个学生“姓名”查询                           *\n");
			printf("			******************************************************\n");
			countskip(head,n);
			searchstudentname(head,n);
			break;} 
		case 5:{ 
			printf("			******************************************************\n");
			printf("			*   5.单个学生“学号”查询                           *\n");
			printf("			******************************************************\n");
			countskip(head,n);
			searchstudentnum(head,n);
			break;} 
		case 6:{
			printf("			******************************************************\n");
			printf("			*   6.删除某学号学生                                 *\n");
			printf("			******************************************************\n");
			countskip(head,n);
			printf("\n请输入删除学生学号: ");
			scanf("%d",&thenumber);  
			 Del(head,thenumber);  
			break;}
		case 7:{
			countskip(head,n);
			Print(head); } 
		 
		default:
			break;
		}
		printf("\n\n是否想结束？y/n:");
		char ch;
		scanf("%c",&ch);
		scanf("%c",&ch);
	//	cin>>ch;
		
		if (ch == 'y') 
		{
			printf("			******************************************************\n");
			printf("			*  制作者：于沂渭  15180110005                       *\n"); 
			printf("			*  制作者：闫瑞驰  15180110007                       *\n");
			printf("			******************************************************\n");
			over = 0;
		}
		else
		{
			over = 1;
		}
	}
	
	return 0; 

}


