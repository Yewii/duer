#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct student)

struct student 
{
	char name[10];	//���� 
	int num;	//ѧ�� 
	int call;	//ѧ����¼	
	int exam;	//���Լ�¼
	struct student *next;       //ָ����һ�ڵ��ָ��  
};



/* 
=========================== 
 ���ܣ���������
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
        printf ("\n���ܴ�������������\n");  
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
 ���ܣ����ȫ��ѧ�� 
=========================== 
*/  
void Print(struct student *head)  
{  
    struct student *p;  
    printf ("\n���๲��%d��ѧ��", n);
	printf("\nѧ������ ѧ�� ѧ������δ��������ѧ����¼�� ���Ա�־ \n");  
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
 ���ܣ����е����
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
		printf("������? (�˴��������Ĭ��Ϊn)\t\ty/n?: ");
		//		char ch = ' ';
		scanf("%c",&ch);
		scanf("%c",&ch);
		if (ch == 'y') /*�������Y*/
		{
			printf("������!\n");/*��ʾ������*/
		}
		else/*����*/
		{
			p->call ++;
			printf("��û����!\n");/*��ʾ��û��*/
		}
		p = p->next;
	} while (p != 0);  
}



/* 
=========================== 
 ���ܣ�ͳ�Ƶ���
 =========================== 
*/  
void countskip(struct student *head,int num)
{
	struct student *p;
	p = head;
	do
	{
		if (p->call >= 3) /*ȱϯ��������3*/
		{
			p->exam = 0;/*���Ա�ʾ��ʾ0*/
		}
		else
		{
			p->exam = 1;/*������ʾ1*/
		}
		p = p->next;
	}while (p != 0);
}


/* 
=========================== 
 ���ܣ�����������κ���������δ��ѧ��
 =========================== 
*/  
void outputexamstudentskip0(struct student *head,int num)
{
	struct student *p;
	p = head;
	
	printf("ȱϯ��������3�ε�ͬѧΪ��\n");
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
		printf("û�г�������δ����ͬѧ.\n");
	}
}





/* 
=========================== 
 ���ܣ��������ȫ�ڻ���������δ��ѧ��
 =========================== 
*/  
void outputexamstudentskip1(struct student *head,int num)
{
	struct student *p;
	p = head;
	
	printf("ȫ�ڻ�ȱϯ��������3�ε�ͬѧΪ��\n");
	
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
		printf("û��ȫ�ں�ȱϯ��������3�ε�ͬѧ\n");
	}
}






/* 
=========================== 
 ���ܣ�����ѧ��������ѯ
 =========================== 
*/  
void searchstudentname(struct student *head,int num)
{
	struct student *p;
	p = head;
	char ch[10];
	printf("�����������ѯѧ����������\n");
	scanf("%s",ch);


	do
	{
		if (strcmp(ch,p->name) == 0) 
		{
			printf("\nѧ������ ѧ�� ѧ������δ��������ѧ����¼�� ���Ա�־ \n");
			printf("%s \t %d \t\t%d \t\t\t %d\n",p->name,p->num,p->call,p->exam);
			
		}
		p = p->next;
	}while (p != 0);

}

/* 
=========================== 
 ���ܣ�����ѧ��ѧ�Ų�ѯ
 =========================== 
*/  
void searchstudentnum(struct student *head,int num)
{
	struct student *p;
	p = head;
	int no;
	printf("�����������ѯѧ����ѧ�ţ�\n");
	scanf("%d",&no);


	do
	{
		if (no == (p->num)) 
		{
			printf("\nѧ������ ѧ�� ѧ������δ��������ѧ����¼�� ���Ա�־ \n");
			printf("%s \t %d \t\t%d \t\t\t %d\n",p->name,p->num,p->call,p->exam);
			
		}
		else printf ("\n��ѧ����Ϣ!\n");  
		p = p->next;
	}while (p != 0);

}

/* 
========================== 
 ���ܣ�ɾ��ָ��ѧ����Ϣ 
========================== 
*/  
struct student *Del (struct student *head, int num)  
{  
    struct student *p1;        
    struct student *p2;       
    if (head == 0)         
    {  
        printf ("\n��ѧ����Ϣ!\n");  
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
        printf ("\nɾ��ѧ��%ldѧ���ɹ�!\n", num);  
        n -= 1;            
    }  
    else                   
    {  
        printf ("\nѧ��%ldѧ��δ�ҵ�!\n", num);  
    }  
  
    
}  


/* 
=========================== 
 ������ 
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
	printf("			*                   �༶����ϵͳ                     *\n");
	printf("			*                                                    *\n");
	printf("			******************************************************\n\n\n");

	
	printf("			******************************************************\n");
	printf("			*        ������ѧ����Ϣ����ʽ����                    *\n");
	printf("			*                                                    *\n");
	printf("			*        ����   ѧ��  ѧ����¼ ���Լ�¼              *\n");
	printf("			*        wang  200201    0         1                 *\n");
	printf("			*        zhang 200202    0         1                 *\n");
	printf("			*                                                    *\n");
	printf("			*       �����Ǹտ�ѧ�����Գ��Ե�ѧ����¼Ӧ��Ϊ0      *\n");
	printf("			*       ���Լ�¼Ӧ��Ϊ1                              *\n");
	printf("			*       ȫ�����롮0 ����������ʽ����                 *\n");
	printf("			*                                                    *\n");
	printf("			*       ����   ѧ��  ѧ����¼ ���Լ�¼               *\n");
	printf("			*        0       0       0         0                 *\n");
	printf("			******************************************************\n");
	
	
	
	
	printf("������ѧ����Ϣ��\n");
	head = Create();



	while (over == 1) 
	{
		
		
		printf("			******************************************************\n");
		printf("			*   1.����                                           *\n");
		printf("			*   2.����������κ���������δ��ѧ��                 *\n");
		printf("			*   3.�������ȫ�ڻ���������δ��ѧ��                 *\n");
		printf("			*   4.����ѧ������������ѯ                           *\n");
		printf("			*   5.����ѧ����ѧ�š���ѯ                           *\n");
		printf("			*   6.ɾ��ĳѧ��ѧ��                                 *\n");
		printf("			*   7.���ȫ��ѧ����Ϣ                               *\n");
		printf("			*                                                    *\n");
		printf("			*   ��ѡ��������еĲ�����                           *\n");
		printf("			******************************************************\n");
		scanf("%d",&docontrol);
		printf("\n");
		switch(docontrol) 
		{
		case 1:{ 
			printf("			******************************************************\n");
			printf("			*   1.����                                           *\n");
			printf("			******************************************************\n");
			call(head,n);
			break;} 
		case 2:{ 
			printf("			******************************************************\n");
			printf("			*   2.����������κ���������δ��ѧ��                 *\n");
			printf("			******************************************************\n");
			countskip(head,n);
			outputexamstudentskip0(head,n);
			break;} 
		case 3:{ 
			
			printf("			******************************************************\n");
			printf("			*   3.�������ȫ�ڻ���������δ��ѧ��                 *\n");
			printf("			******************************************************\n");
			countskip(head,n);
			outputexamstudentskip1(head,n);
			break;} 
		case 4:{ 
			printf("			******************************************************\n");
			printf("			*   4.����ѧ������������ѯ                           *\n");
			printf("			******************************************************\n");
			countskip(head,n);
			searchstudentname(head,n);
			break;} 
		case 5:{ 
			printf("			******************************************************\n");
			printf("			*   5.����ѧ����ѧ�š���ѯ                           *\n");
			printf("			******************************************************\n");
			countskip(head,n);
			searchstudentnum(head,n);
			break;} 
		case 6:{
			printf("			******************************************************\n");
			printf("			*   6.ɾ��ĳѧ��ѧ��                                 *\n");
			printf("			******************************************************\n");
			countskip(head,n);
			printf("\n������ɾ��ѧ��ѧ��: ");
			scanf("%d",&thenumber);  
			 Del(head,thenumber);  
			break;}
		case 7:{
			countskip(head,n);
			Print(head); } 
		 
		default:
			break;
		}
		printf("\n\n�Ƿ��������y/n:");
		char ch;
		scanf("%c",&ch);
		scanf("%c",&ch);
	//	cin>>ch;
		
		if (ch == 'y') 
		{
			printf("			******************************************************\n");
			printf("			*  �����ߣ�����μ  15180110005                       *\n"); 
			printf("			*  �����ߣ������  15180110007                       *\n");
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


