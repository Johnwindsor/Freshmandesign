#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
//*******所用函数******// 
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
      //******交友系统友善界面******//
      system("color 0e");
      int b,flag = 0; 
      struct student *head;
      head = (struct student*)malloc(sizeof(struct student));
      head -> next = NULL;
      time_t now;
      now = time (NULL);
     while(1) 
     {
           printf("\n\t\t\t   欢迎来到郑州大学学生交友系统\n");
           printf("\n\t\t\t编制人员  ：郑大四班孙朝\n\n");
           printf("\t\t\t  -----------------------------\n\n"); 
           printf("\t\t1.注册学生的信息");
	       printf("\t\t2.查询学生信息\n\n"); 
      	   printf("\t\t3.按男女学生分类");
   		   printf("\t\t4.管理员权限\n\n"); 
   		   printf("\t\t5.我的个人信息");
   		   printf("\t\t\t6.保存十二星座\n\n");
   		   printf("\t\t7.星座速配");
   		   printf("\t\t\t8.列举单身学生信息\n\n");
		   printf("\t\t9.音乐播放")	;    
   		   printf("\t\t\t0.退出\n\n"); 
   		   printf("\t\t\t>>>>>>请输入你的选择:\n\n");
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
                printf("错误!");   
                break;     
          }
     }
     system("d:\\567.mp3");
     system("pause");
     return 0;
} 

/* ******输入学生信息****** */ 
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
  /*******创建链表*******/
  struct student *p,*q,*head;
  long long num,age;
  char name[100];
  char single[100];
  char sex[100];
  head = (struct student*)malloc(sizeof(struct student));
  q = head;
  while(1)
  {
   
    printf("please input the 学号:\n");
    scanf("%lld",&num);
    if(num == 0)
    break;
    printf("please input the 名字:\n");
    scanf("%s",&name);
    printf("please input the 年龄:\n");
    scanf("%lld",&age);
    printf("please input the 性别:\n");
    scanf("%s",&sex);
    printf("please input 是否单身:\n"); 
    scanf("%s",&single);
    /**为新节点申请内存单元**/ 
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
        //**************打开文件**********************//    
    if((fp = fopen("D:\\chengji.txt","r")) == NULL)
    {
           printf("open file error");
           system("pause");
           exit(0);
    }
	   
//*************查询学号对应信息**************************//
  
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
	  	  printf("学号：%lld 名字：%s 年龄：%lld 性别：%s 单身：%s\n",
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
	  printf("没有匹配到结果\n"); 
      fclose(fp);
      system("pause");  
      system("CLS"); 
    
}
//*****按名字查询个人信息****//
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

	//	fscanf(fp,"学号：%lld 姓名： %s 年龄：%lld 性别：%s 单身：%s\n",
	//	       &p -> num,p -> name,&p -> age,p -> sex,p -> single);
	fscanf(fp,"%lld%s%lld%s%s\n", &p -> num,p -> name,&p -> age,p -> sex,p -> single);
		if(strcmp(a,p -> name) == 0)
		{
			printf("学号：%lld 姓名： %s 年龄：%lld 性别：%s 单身：%s\n",
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
	printf("没有匹配到结果\n");
	fclose(fp);
	system("pause");
	system("CLS");	 
}
   //************按年龄查询学生个人信息*********//
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
			printf("学号：%lld 姓名： %s 年龄：%lld 性别：%s 单身：%s\n",
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
	printf("没有匹配到结果");
	system("pause");
	system("CLS");
}    





//*****查询所有学生信息****// 
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
     printf("\n按任意键返回上级\n"); 
	 getchar(); 
     fclose(fp);
     system("pause");
     system("CLS");
}

/*定位函数*/
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


//*******管理员权限之根据学号删除某人信息******// 
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
		printf("删除失败");
		exit(0);
	}
	p = q -> next;
	if(p == NULL)
	{
		printf("删除失败");
		exit(0);
	}
	else
	{
		q -> next = p -> next;
		free(p);
		printf("删除成功");
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
//***********管理员权限之根据学生姓名删除学生*****//
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
	printf("请输入您想要删除的名字：\n");
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
		printf("删除失败");
		exit(0);
	}
	p = q -> next;
	if(p == NULL)
	{
		printf("删除失败");
		exit(0);
	}
	else
	{
		q -> next = p -> next;
		free(p);
		printf("删除成功");
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

//**********在指定学号的学生后面添加学生**********// 

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
		printf("\n\t\t\t\t欢迎来到查询页面\n\t\n");
		printf("\t\t\t  -----------------------------\n\t\n");
		printf("\t\t\t1:按学号查询个人信息\t\t\n\n");
		printf("\t\t\t2:按姓名查询个人信息\t\t\n\n");
		printf("\t\t\t3:按年龄列举学生信息\t\t\n\n");
		printf("\t\t\t4:查看所有学生信息\t\t\n\n"); 
		printf("\t\t\t0:返回上级\t\t\n\n"); 
		printf("\t\t   >>>>>>>>>>请输入你的选择\n\n"); 
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
		  printf("错误");	
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
	printf("请输入管理员密码\n");
	scanf("%lld",&c);
	if(c == 19940112)
 {
	system("CLS");
	time_t now;  
    now = time (NULL);
	while(1)
   {
		printf("\n\t\t\t\t管理员权限页面\n\t\n");
		printf("\t\t\t  -----------------------------\n\t\n");
		printf("\t\t\t1:按学号删除个人信息\t\t\n\n");
		printf("\t\t\t2:按姓名删除个人信息\t\t\n\n");
	//	printf("\t\t\t3:按学号增加学生信息\t\t\n\n");
		printf("\t\t\t0:返回上级\t\t\n\n"); 
		printf("\t\t   >>>>>>>>>>请输入你的选择\n\n"); 
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
	 	  printf("错误");	
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
  	printf("\t\t\t---我的个人信息---\n\n");
  	printf("\t\t姓名：孙朝\n\n");
  	printf("\t\t性别：男\n\n");
  	printf("\t\t爱好：二胡 葫芦丝\n\n");
	printf("\t\t星座：摩羯\n\n");
	printf("\t\t个人状况：单身\n\n");   
	printf("\t\t生日：19940112\n\n"); 
	printf("\t\t学校专业：郑州大学软件工程\n\n");
	printf("\t\t所在城市：河南省郑州市\n\n"); 
	printf("\t    ----------------------------------------------------\n\n"); 
  }
  else
  printf("密码错误\n\n");
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
	printf("please input 是否单身 \n");
	scanf("%s",a);
	while( !feof(fp) )
	{
		fscanf(fp,"%lld%s%lld%s%s",&p -> num,p -> name,&p -> age,p -> sex,p -> single);
		if(strcmp(a,p -> single) == 0)
		{
			i++;
			printf("学号：%lld 姓名： %s 年龄：%lld 性别：%s 单身：%s\n",
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
	printf("没有找到匹配的学生信息\n");
	system("pause");
    system("CLS");
}

/**********按男女学生分类**********/ 
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
	printf("请输入查找的性别（男，女）\n");
	scanf("%s",a);
	while(ch != EOF)
	{
	  fscanf(fp,"%lld%s%lld%s%s",&p -> num,p -> name,&p -> age,p -> sex,p -> single);
	  if(strcmp(a,p -> sex) == 0)
	  {
	    printf("学号：%lld 姓名： %s 年龄：%lld 性别：%s 单身：%s\n",
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
/*******输入12星座的函数******/ 
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
  printf("请输入星座\n"); 
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
	printf("请输入你的星座\n");
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
	printf("与您绝配的星座为狮子座:---->绝配指数*****"); 
	else if(m == 1)
	printf("与您绝配的星座为摩羯座:---->绝配指数*****\n");
	else if(m == 2)
	printf("与您绝配的星座为水瓶座:---->绝配指数****\n");
	else if(m == 3)
	printf("与您绝配的星座为双鱼座:---->绝配指数****\n");
	else if(m == 4)
	printf("与您绝配的星座为白羊座:---->绝配指数*****\n");
	else if(m == 5)
	printf("与您绝配的星座为摩羯座:---->绝配指数****\n");
	else if(m == 6)
	printf("与您绝配的星座为水瓶座:---->绝配指数*****\n");
	else if(m == 7)
	printf("与您绝配的星座为巨蟹座:---->绝配指数****\n");
	else if(m == 8)
	printf("与您绝配的星座为白羊座:---->绝配指数****\n");
	else if(m == 9)
	printf("与您绝配的星座为金牛座:---->绝配指数****\n");
	else if(m == 10)
	printf("与您绝配的星座为天秤座:---->绝配指数****\n");
	else if(m == 11)
	printf("与您绝配的星座为巨蟹座:---->绝配指数****\n");
	system("pause");
	system("CLS");
}

 












