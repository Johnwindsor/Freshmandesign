#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
//*******���ú���******// 
struct student
{
  	char name[100];
    char sex[100];
    char single[100];
    long long num;
    long long age;
    struct student *next;
};
 void type();
 void namesearch();
 void numsearch();
 void agesearch();
 void order();
 void del();
 void open();
 void MY();
 void input();
 void allsearch();
 void deletenumber();
 void search(); 
 void administrate();
 void addnumber();
 void singlesearch();
 void seek();
 void cons();
 void inputcons(); 
 void deletename();
 
int main()
{
      //******����ϵͳ���ƽ���******//
      system("color 0e");
      int b,flag = 0; 
      struct student *head;
      head = (struct student*)malloc(sizeof(struct student));
      head -> next = NULL;
      time_t now;
      now = time (NULL);
     while(1) 
     {
           printf("\n\t\t\t   ��ӭ����֣�ݴ�ѧѧ������ϵͳ\n");
           printf("\n\t\t\t������Ա  ��֣���İ��ﳯ\n\n");
           printf("\t\t\t  -----------------------------\n\n"); 
           printf("\t\t1.ע��ѧ������Ϣ");
	       printf("\t\t2.��ѯѧ����Ϣ\n\n"); 
      	   printf("\t\t3.����Ůѧ������");
   		   printf("\t\t4.����ԱȨ��\n\n"); 
   		   printf("\t\t5.�ҵĸ�����Ϣ");
   		   printf("\t\t\t6.����ʮ������\n\n");
   		   printf("\t\t7.��������");
   		   printf("\t\t\t8.�оٵ���ѧ����Ϣ\n\n");
		   printf("\t\t9.���ֲ���")	;    
   		   printf("\t\t\t0.�˳�\n\n"); 
   		   printf("\t\t\t>>>>>>���������ѡ��:\n\n");
   		   printf("\t\t    made by sz,now time is %s\n",ctime(&now));
   		   printf("\t\t-----------------------------------------------------\n\n");
   		   scanf("%d",&b);
   		   switch(b)
   		  {
            case 1: input();
            break;
            case 2:search(head);
            break;
            case 3:seek(head);
            break;
            case 4:administrate(head);
            break;
            case 5:MY();
            break;
            case 6:inputcons();
            break;
            case 7:cons();
            break;
            case 8:singlesearch(head);
            break;
            case 9:system("d:\\567.mp3");
            break;	
            case 0:exit(0);
            break;     
            default:
                printf("����!");   
                break;     
          }
     }
     system("d:\\567.mp3");
     system("pause");
     return 0;
} 

/* ******����ѧ����Ϣ****** */ 
void input()
{
  system("CLS");
  struct student
  {
     char name[100];
     char sex[100];
     char single[100];
     long long num;
     long long age;
     struct student *next;    
  }bd[10];
   FILE *fp;
  if((fp = fopen("D:\\chengji.txt","at+")) == NULL)
  {
        printf("open the files error");
        system("pause");
        exit(0);
  }
  /*******��������*******/
  struct student *p,*q,*head;
  long long num,age;
  char name[100];
  char single[100];
  char sex[100];
  head = (struct student*)malloc(sizeof(struct student));
  q = head;
  while(1)
  {
   
    printf("please input the ѧ��:\n");
    scanf("%lld",&num);
    if(num == 0)
    break;
    printf("please input the ����:\n");
    scanf("%s",&name);
    printf("please input the ����:\n");
    scanf("%lld",&age);
    printf("please input the �Ա�:\n");
    scanf("%s",&sex);
    printf("please input �Ƿ���:\n"); 
    scanf("%s",&single);
    /**Ϊ�½ڵ������ڴ浥Ԫ**/ 
     p = (struct student*)malloc(sizeof(struct student));
     if(p == NULL)
     break;
     strcpy(p -> name,name);
     p -> num = num;
     p -> age = age;
     strcpy(p -> sex,sex);
     strcpy(p -> single,single);
     fprintf(fp,"%lld %s %lld %s %s\n",p -> num, p -> name,p -> age,p -> sex,p -> single);
     q -> next = p; 
     q = p;
     
  }
  q -> next =NULL;
  fclose(fp);
  system("CLS");
}

void numsearch(struct student *head)
{
       system("CLS");
       FILE *fp;
        //**************���ļ�**********************//    
    if((fp = fopen("D:\\chengji.txt","r")) == NULL)
    {
           printf("open file error");
           system("pause");
           exit(0);
    }
	   
//*************��ѯѧ�Ŷ�Ӧ��Ϣ**************************//
  
      struct student *p,*q;
      long long m;
      if(head == NULL)
      return;
      q = head;
      p = (struct student*)malloc(sizeof(struct student));
      q -> next = p;
	  printf("input the school number\n");
	  scanf("%lld",&m);  
	  char ch = 'a';
	  while(ch != EOF)
	  {
	  	fscanf(fp,"%lld%s%lld%s%s\n",&p -> num, p -> name,&p -> age,p -> sex,p -> single);
	  	if(p -> num == m)
	  	{
	  	  printf("ѧ�ţ�%lld ���֣�%s ���䣺%lld �Ա�%s ����%s\n",
			      p -> num, p -> name,p -> age,p -> sex,p -> single);
	  	  break;
	    }      
	    else
	      /*p = (struct student*)malloc(sizeof(struct student));*/
          q -> next = p;
          ch = fgetc(fp);
          fseek(fp, -1l, 1);
          q = p;
	  }  
	  if(ch == EOF)
	  printf("û��ƥ�䵽���\n"); 
      fclose(fp);
      system("pause");  
      system("CLS"); 
    
}
//*****�����ֲ�ѯ������Ϣ****//
void namesearch(struct student*head)
{
	system("CLS");
	FILE *fp;
	if((fp = fopen("D:\\chengji.txt","r")) == NULL)
	{
		printf("open file error");
		system("pause");
		exit(0);
	}
	struct student *p,*q;
	char a[100];
	if(head == NULL)
	return;
	q = head;
	p = (struct student*)malloc(sizeof(struct student));
	q->next = p;
	q = p;
	printf("please input the name\n");
	scanf("%s",a);
	char ch = 'a';
	while( ch != EOF )
	{      

	//	fscanf(fp,"ѧ�ţ�%lld ������ %s ���䣺%lld �Ա�%s ����%s\n",
	//	       &p -> num,p -> name,&p -> age,p -> sex,p -> single);
	fscanf(fp,"%lld%s%lld%s%s\n", &p -> num,p -> name,&p -> age,p -> sex,p -> single);
		if(strcmp(a,p -> name) == 0)
		{
			printf("ѧ�ţ�%lld ������ %s ���䣺%lld �Ա�%s ����%s\n",
		            p -> num,p -> name,p -> age,p -> sex,p -> single);
		    break;        
		}
		else
		{ 
		    q -> next = p;
		    ch = fgetc(fp);
		    q = p;
		}
	}
	if(ch == EOF)
	printf("û��ƥ�䵽���\n");
	fclose(fp);
	system("pause");
	system("CLS");	 
}
   //************�������ѯѧ��������Ϣ*********//
void agesearch(struct student *head)
{
	system("CLS");
	FILE *fp;
	int c;
	if((fp = fopen("D:\\chengji.txt","at+")) == NULL)
	{
		printf("open file error");
		system("pause");
		exit(0);
	}
	struct student *q,*p;
	if(head == NULL)
	return;
	q = head;
	p = (struct student*)malloc(sizeof(struct student));
	q -> next = p;
	q = p;
	printf("please input age\n");
	scanf("%d",&c);
	char ch = 'b';
	while(ch != EOF)
	{
		fscanf(fp,"%lld%s%lld%s%s",&p -> num,p -> name,&p -> age,p -> sex,p -> single);
		if(c == p -> age)
		{
			printf("ѧ�ţ�%lld ������ %s ���䣺%lld �Ա�%s ����%s\n",
		            p -> num,p -> name,p -> age,p -> sex,p -> single);
		     q -> next = p;
			 fseek(fp, 2l, 1);
		     ch = fgetc(fp);
		     q =p;
		}
		else
		{
			q -> next = p;
			ch = fgetc(fp);
			fseek(fp, 1l, 1);
			q = p;
		}
	}
	if(ch == EOF)
	printf("û��ƥ�䵽���");
	system("pause");
	system("CLS");
}    





//*****��ѯ����ѧ����Ϣ****// 
void allsearch()
{
	system("CLS");
    FILE *fp;
    char ch;
     if((fp = fopen("D:\\chengji.txt","at+")) == NULL)
       {
           printf("open the files error");
           system("pause");
           exit( 0);
       } 
     ch = fgetc(fp);
     while(ch != EOF)
     {
     	putchar(ch);
     	ch = fgetc(fp);
     }
     printf("\n������������ϼ�\n"); 
	 getchar(); 
     fclose(fp);
     system("pause");
     system("CLS");
}

/*��λ����*/
struct student*locate(struct student*head,int i)
{
	int pos = 0;
	struct student*p = head;
	while(p -> next != NULL && pos < i)
	{
		pos++;
		p = p -> next;
	}
	if(pos == i)
	return p;
	else
	return NULL;
}


//*******����ԱȨ��֮����ѧ��ɾ��ĳ����Ϣ******// 
void deletenumber(struct student*head)
{
	system("CLS");
	FILE *fp;
	if((fp = fopen("D:\\chengji.txt","rt+")) == NULL)
	{
		printf("open file error");
		system("pause");
		exit(0);
	}
	struct student *p,*q;
	char ch = 'a';
	int i = 0,j = 0;
	long long n;
	printf("please input num\n");
//	fflush(stdin);
	scanf("%lld",&n);
	q = head;
	while(ch != EOF)
	{
		p = (struct student*)malloc(sizeof(struct student));
		fscanf(fp,"%lld%s%lld%s%s\n",&p -> num,p -> name,&p -> age,p -> sex,p -> single);
		i++;
		if(n == p -> num) 
		{
		 j = i;
		 q -> next = p;
		 q = p;
		 ch = fgetc(fp);
	     fseek(fp,-1l,1);
		}
		else
	   {
		q -> next = p;
		ch = fgetc(fp);
		fseek(fp,-1l,1);
		q = p;
       }
	} 
	q->next=NULL;
	q = locate(head,j-1);
	if(q == NULL)
	{
		printf("ɾ��ʧ��");
		exit(0);
	}
	p = q -> next;
	if(p == NULL)
	{
		printf("ɾ��ʧ��");
		exit(0);
	}
	else
	{
		q -> next = p -> next;
		free(p);
		printf("ɾ���ɹ�");
	}
//	rewind(fp);
    fclose(fp);
    if((fp = fopen("D:\\chengji.txt","w+")) == NULL)
    {
    	printf("open file error");
    	system("pause");
    	exit(0);
    }
	p = head->next;
	/*char chs = 'b';*/
	i--;
	while(i--)
	{
	  fprintf(fp,"%lld %s %lld %s %s\n",p -> num, p -> name,p -> age,p -> sex,p -> single);
	  p = p -> next;
	  /*chs = fgetc(fp);
	  fseek(fp,-1l,1);*/
	}
	fclose(fp);
	system("pause");
	system("CLS");
}
//***********����ԱȨ��֮����ѧ������ɾ��ѧ��*****//
void deletename(struct student*head)
{
	system("CLS");
	FILE*fp;
	if((fp = fopen("D:\\chengji.txt","rt+")) == NULL)
	{
		printf("open file error");
		system("pause");
		exit(0);
	}
	struct student *p,*q;
	q = head;
	char a[100];
	int i = 0,j = 0;
	printf("����������Ҫɾ�������֣�\n");
	scanf("%s",a);
	while(!feof(fp))
	{
		p = (struct student*)malloc(sizeof(struct student));
		fscanf(fp,"%lld%s%lld%s%s\n",&p -> num,p -> name,&p -> age,p -> sex,p -> single);
		i++;
		if(strcmp(a,p -> name) == 0)
		{
			j = i;
			q -> next = p;
			q = p;
		}
		else
		{
			q -> next = p;
			q = p;
		}	
	}
	q->next=NULL;
	q = locate(head,j-1);
	if(q == NULL)
	{
		printf("ɾ��ʧ��");
		exit(0);
	}
	p = q -> next;
	if(p == NULL)
	{
		printf("ɾ��ʧ��");
		exit(0);
	}
	else
	{
		q -> next = p -> next;
		free(p);
		printf("ɾ���ɹ�");
	}
	fclose(fp);
     if((fp = fopen("D:\\chengji.txt","w+")) == NULL)
    {
    	printf("open file error");
    	system("pause");
    	exit(0);
    }
	p = head->next;
	/*char chs = 'b';*/
	i--;
	while(i--)
	{
	  fprintf(fp,"%lld %s %lld %s %s\n",p -> num, p -> name,p -> age,p -> sex,p -> single);
	  p = p -> next;
	  /*chs = fgetc(fp);
	  fseek(fp,-1l,1);*/
	}
	fclose(fp);
	system("pause");
	system("CLS");
}

//**********��ָ��ѧ�ŵ�ѧ���������ѧ��**********// 

/*void addnumbrer(struct student*head)
{
	system("CLS");
	FILE *fp;
	if((fp = fopen("D:\\chengji.txt","at+")) == NULL)
	{
		printf("open file error");
		system("pause");
		exit(0);
	}
	
	
}*/

void search(struct student*head)
{
	int a;
	system("CLS");
	time_t now;  
    now = time (NULL);
	while(1)
  {
		printf("\n\t\t\t\t��ӭ������ѯҳ��\n\t\n");
		printf("\t\t\t  -----------------------------\n\t\n");
		printf("\t\t\t1:��ѧ�Ų�ѯ������Ϣ\t\t\n\n");
		printf("\t\t\t2:��������ѯ������Ϣ\t\t\n\n");
		printf("\t\t\t3:�������о�ѧ����Ϣ\t\t\n\n");
		printf("\t\t\t4:�鿴����ѧ����Ϣ\t\t\n\n"); 
		printf("\t\t\t0:�����ϼ�\t\t\n\n"); 
		printf("\t\t   >>>>>>>>>>���������ѡ��\n\n"); 
		printf("\t\t\t  Made by Ice, now time is %s\n ",ctime(&now));
		printf("\t    ------------------------------------------------------------\n");
		scanf("%d",&a);
		switch(a)
	  {
		  case 1:numsearch(head);
		  break;
		  case 2:namesearch(head);
		  break;
		  case 3:agesearch(head);
		  break;
		  case 4:allsearch(head);
		  case 0: 
		  break;	
		  default :
		  printf("����");	
	  }
	if(a == 0)
	break;  
 }
 system("pause");
 system("CLS");
}

void administrate(struct student*head)
{
	int b;
	long long c;
	system("CLS");
	printf("���������Ա����\n");
	scanf("%lld",&c);
	if(c == 19940112)
 {
	system("CLS");
	time_t now;  
    now = time (NULL);
	while(1)
   {
		printf("\n\t\t\t\t����ԱȨ��ҳ��\n\t\n");
		printf("\t\t\t  -----------------------------\n\t\n");
		printf("\t\t\t1:��ѧ��ɾ��������Ϣ\t\t\n\n");
		printf("\t\t\t2:������ɾ��������Ϣ\t\t\n\n");
	//	printf("\t\t\t3:��ѧ������ѧ����Ϣ\t\t\n\n");
		printf("\t\t\t0:�����ϼ�\t\t\n\n"); 
		printf("\t\t   >>>>>>>>>>���������ѡ��\n\n"); 
		printf("\t\t\t  Made by Ice, now time is %s\n ",ctime(&now));
		printf("\t    ------------------------------------------------------------\n");
		scanf("%d",&b);
		  switch(b)
		{
		  case 1:deletenumber(head);
		  break;
		  case 2:deletename(head);
		  break;
		  case 3:
		  break;
		  case 0: 
		  break;	
		  default :
	 	  printf("����");	
	    }
	if(b == 0)
	break; 
   }
 }
 system("pause");
 system("CLS");		
}

void MY()
{
  system("CLS");
  long long m;	
  printf("please input password\n");	
  scanf("%lld",&m);
  if(m == 19940112)
  { 
  	system("CLS");
  	printf("\t\t\t---�ҵĸ�����Ϣ---\n\n");
  	printf("\t\t�������ﳯ\n\n");
  	printf("\t\t�Ա���\n\n");
  	printf("\t\t���ã����� ��«˿\n\n");
	printf("\t\t������Ħ��\n\n");
	printf("\t\t����״��������\n\n");   
	printf("\t\t���գ�19940112\n\n"); 
	printf("\t\tѧУרҵ��֣�ݴ�ѧ�������\n\n");
	printf("\t\t���ڳ��У�����ʡ֣����\n\n"); 
	printf("\t    ----------------------------------------------------\n\n"); 
  }
  else
  printf("�������\n\n");
  system("pause");
  system("CLS");
}

void singlesearch(struct student*head)
{
	system("CLS");
	FILE *fp;
	if((fp = fopen("D:\\chengji.txt","at+")) == NULL)
	{
		printf("open file error");
		system("pause");
		exit(0);
	}
	struct student*p,*q;
	q = head;
	p = (struct student*)malloc(sizeof(struct student));
	q -> next = p;
	q = p;
	char ch= 'a';
	int i = 0; 
	char a[100];
	printf("please input �Ƿ��� \n");
	scanf("%s",a);
	while( !feof(fp) )
	{
		fscanf(fp,"%lld%s%lld%s%s",&p -> num,p -> name,&p -> age,p -> sex,p -> single);
		if(strcmp(a,p -> single) == 0)
		{
			i++;
			printf("ѧ�ţ�%lld ������ %s ���䣺%lld �Ա�%s ����%s\n",
		            p -> num,p -> name,p -> age,p -> sex,p -> single);
		  q = p -> next;
		  q = p;
		  fseek(fp,2l,1);
		  ch = fgetc(fp);
		} 
		else
		{
		 q = p -> next;
		 q = p;
		 ch = fgetc(fp);
		}
	}
	if(i == 0)
	printf("û���ҵ�ƥ���ѧ����Ϣ\n");
	system("pause");
    system("CLS");
}

/**********����Ůѧ������**********/ 
void seek(struct student*head)
{
	system("CLS");
	FILE*fp;
	if((fp = fopen("D:\\chengji.txt","at+")) == NULL)
	{
		printf("open file error");
		system("pause");
		exit(0);
	}
	struct student *p,*q;
	q = head;
	p = (struct student*)malloc(sizeof(struct student));
	q -> next = p;
	q = p;
	char ch = 'a';
	char a[100];
	printf("��������ҵ��Ա��У�Ů��\n");
	scanf("%s",a);
	while(ch != EOF)
	{
	  fscanf(fp,"%lld%s%lld%s%s",&p -> num,p -> name,&p -> age,p -> sex,p -> single);
	  if(strcmp(a,p -> sex) == 0)
	  {
	    printf("ѧ�ţ�%lld ������ %s ���䣺%lld �Ա�%s ����%s\n",
		       p -> num,p -> name,p -> age,p -> sex,p -> single);
		q -> next = p;
		q = p;
		fseek(fp,2l,1);
		ch = fgetc(fp);       
	  }
	  else
	  {
	  	q -> next = p;
	  	q = p;
	  	ch = fgetc(fp);
	  }
	}
	system("pause");
	system("CLS");
}
/*******����12�����ĺ���******/ 
void inputcons()
{ 
  system("CLS");
  struct conste
  {
  	char name[100];
  }	b[100];
  FILE*fp;
  int i;
  if((fp = fopen("D:\\xingzuo.txt","at+")) == NULL)
  {
  	printf("open file error");
  	system("pause");
  	exit(0);
  }
  printf("����������\n"); 
  for(i = 0;i < 12;i++)
  scanf("%s",b[i].name); 
  for(i = 0;i < 12;i++)
  fprintf(fp,"%s ",b[i].name);
  rewind(fp);
  for(i = 0;i < 12;i++)
  {
  	fscanf(fp,"%s",b[i].name);
  	printf("%d",b[i].name); 
  }
  system("pause");
  system("CLS");	
}

void cons()
{
	system("CLS");
    struct conste
    {
  	    char name[100];
    }	b[100];
	FILE*fp;
	if((fp = fopen("D:\\xingzuo.txt","at+")) == NULL)
	{
		printf("open file error");
		system("pause");
		exit(0);
	}
	int i,j = 0,m = 0;
	int flag;
	char a[100];
	printf("�������������\n");
	scanf("%s",a);
	 
	for(i = 0;i < 12;i++)
	{	
	  fscanf(fp,"%s",b[i].name);
	  if(strcmp(a,b[i].name) == 0) 
	  {
	    m = i;
	    break;
	  }
	}
	if(m == 0)
	printf("�������������Ϊʨ����:---->����ָ��*****"); 
	else if(m == 1)
	printf("�������������ΪĦ����:---->����ָ��*****\n");
	else if(m == 2)
	printf("�������������Ϊˮƿ��:---->����ָ��****\n");
	else if(m == 3)
	printf("�������������Ϊ˫����:---->����ָ��****\n");
	else if(m == 4)
	printf("�������������Ϊ������:---->����ָ��*****\n");
	else if(m == 5)
	printf("�������������ΪĦ����:---->����ָ��****\n");
	else if(m == 6)
	printf("�������������Ϊˮƿ��:---->����ָ��*****\n");
	else if(m == 7)
	printf("�������������Ϊ��з��:---->����ָ��****\n");
	else if(m == 8)
	printf("�������������Ϊ������:---->����ָ��****\n");
	else if(m == 9)
	printf("�������������Ϊ��ţ��:---->����ָ��****\n");
	else if(m == 10)
	printf("�������������Ϊ�����:---->����ָ��****\n");
	else if(m == 11)
	printf("�������������Ϊ��з��:---->����ָ��****\n");
	system("pause");
	system("CLS");
}

 












