#include "stdio.h"
#include <stdlib.h>
#include "conio.h"
#include "string.h"
/*----------------------定义变量结构体 ----------------------*/
int address_number;

typedef struct _information
{
	char name[50];
	char sex[3];
	char birthday[9];
	char phone[21];
	char fax[21];
	char address[101];
	char postcode[7];
}information;

typedef struct _address_book
{
	information person;
	struct _address_book *next;
}address_book;

address_book *first=NULL; //链表节点头置空 

/*----------------------声明函数----------------------*/
void initialize();
void add_information ();
void show_information ();
void serch_information();
void delect_information();
void change_information();
void save_file();

/*----------------------主函数----------------------*/
int main()
{
	system("cls");
	int choose;
	for(;;)
	{
	 
		printf("|======================|\n");
		printf("|                      |\n");
		printf("|     系统主控平台     |\n");
		printf("|                      |\n");
		printf("|======================|\n");
		printf("|1.系统初始化          |\n");
		printf("|                      |\n");
		printf("|2.添加联系人信息      |\n");
		printf("|                      |\n");
		printf("|3.显示联系人信息      |\n");
		printf("|                      |\n");
		printf("|4.查找联系人信息      |\n");
		printf("|                      |\n");
		printf("|5.删除联系人信息      |\n");
		printf("|                      |\n");
		printf("|6.修改联系人信息      |\n");
		printf("|                      |\n");
		printf("|7.文件保存            |\n");
		printf("|                      |\n");
		printf("|8.退出                |\n");
		printf("|===================== |\n");
		printf(">>>>请输入需要进行的操作:");
		scanf("%d",&choose);
			switch(choose)
			{
				case 1:initialize();break;
				case 2:add_information();break;
				case 3:show_information();break;
				case 4:serch_information();break;
				case 5:delect_information();break;
				case 6:change_information();break;
				case 7:save_file();break;
				case 8:exit(EXIT_SUCCESS);break;
			}
	}
	return 0;
}
/*----------------------主函数----------------------*/

/*----------------------初始化函数----------------------*/
void initialize()
{
	system("cls");
	FILE *fp=NULL;
	char ch;
	fp=fopen("data.txt","r");
	while((ch=fgetc(fp))!=EOF)
	{
		if(ch =='\n')
		{
			address_number++;
		}
	}
	printf("读行数成功,共%d行\n",address_number);
	fp=fopen("data.txt","a+");
	struct _address_book *next_address,*new_address;
	new_address=(address_book*)malloc(sizeof(address_book));
	first=new_address;
	for(int i=0;i<address_number&&!feof(fp);i++)
	{
		fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",new_address->person.name,new_address->person.sex,new_address->person.birthday,new_address->person.phone,new_address->person.fax,new_address->person.address,new_address->person.postcode);
		//printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\n",new_address->person.name,new_address->person.sex,new_address->person.birthday,new_address->person.phone,new_address->person.fax,new_address->person.address,new_address->person.postcode);
		if(i!=address_number-1)
		{
			new_address->next=next_address=(address_book*)malloc(sizeof(address_book));
		}
		else
		{
			new_address->next=next_address;
		}
		new_address=new_address->next;
	}
	new_address->next=NULL;
	//printf("\n%d\n",new_address->next);
	printf("初始化成功\n");
	printf("按任意键返回主菜单!\n");
	getch();
	system("cls"); 
}
/*----------------------初始化函数----------------------*/


/*----------------------添加信息函数----------------------*/
void add_information()
{
	system("cls");
	address_book *last =NULL;
	address_book *new_address = (address_book *)malloc(sizeof(address_book));
	new_address->next=NULL;
	address_book *_first;
	_first=first;
	if(_first==NULL)
	{
		first=new_address;
	}
	else
	{
		while(_first->next!=NULL)
		{
			_first=_first->next;
		}
		_first->next=new_address;
	}
	printf(">>>>请输入姓名:");
	scanf("%s",new_address->person.name);
	printf(">>>>请输入性别:");
	scanf("%s",new_address->person.sex);
	printf(">>>>请输入出生日期:");
	scanf("%s",new_address->person.birthday);
	printf(">>>>请输入手机:");
	scanf("%s",new_address->person.phone);
	printf(">>>>请输入传真:");
	scanf("%s",new_address->person.fax);
	printf(">>>>请输入地址:");
	scanf("%s",new_address->person.address);
	printf(">>>>请输入邮编:");
	scanf("%s",new_address->person.postcode);
	printf(">>>>是否继续输入?(Y继续，其他输入则返回菜单"); 
	getchar();
	char input =getchar(); 
	if(input=='Y'||input =='y')
	{
		add_information();
	}
	printf("按任意键返回主菜单!\n");
	getch();
	system("cls"); 
}
/*----------------------添加信息函数----------------------*/

/*----------------------显示信息函数----------------------*/
void show_information()
{
	//system("cls");
	int i=0;
	address_book *p =first;
	while(p!=NULL)
	{
		i++;
		printf("*******第%d个联系人*******\n",i);
		printf("姓名:%s\t性别:%s\t生日:%s\t手机%s\t传真%s\t地址:%s\t邮编:%s\n",p->person.name,p->person.sex,p->person.birthday,p->person.phone,p->person.fax,p->person.address,p->person.postcode);
		p=p->next;
	}
	if(i==0)
	{
		printf("wrong!\t");
	}
	printf("按任意键返回主菜单!\n");
	getch();
	system("cls");
}
/*----------------------显示信息函数----------------------*/

/*----------------------查询信息函数----------------------*/
void serch_information()
{
	system("cls");
	int count=0;
	char name[11]={0};
	address_book *p =first;
	printf(">>>>请输入要查找的联系人姓名（最大10个字符）:");
	scanf("%s",name);
	while(p!=NULL)
	{
		if(strcmp(p->person.name,name)==0)
		{
			printf("姓名:%s\t性别:%s\t生日:%s\t手机%s\t传真%s\t地址:%s\t邮编:%s\n",p->person.name,p->person.sex,p->person.birthday,p->person.phone,p->person.fax,p->person.address,p->person.postcode);
			count++;
		}
		p=p->next;
	}
	if(count ==0)
	{
		printf("没有姓名为该用户的人！\n") ;
	}
	printf("查找完毕\n") ;
	printf("按任意键返回主菜单!\n");
	getch();
	system("cls");
}
/*----------------------显示信息函数----------------------*/

/*----------------------删除信息函数----------------------*/
void delect_information()
{
	system("cls");
	int count=0;
	char name[11]={0};
	address_book *p=first;
	address_book *p1=NULL;
	printf(">>>>请输入要删除的联系人姓名（最大10个字符）:");
	scanf("%s",name);
		while(p!=NULL)
	{
		if(strcmp(p->person.name,name)==0)
		{
			printf("姓名:%s\t性别:%s\t生日:%s\t手机%s\t传真%s\t地址:%s\t邮编:%s\n",p->person.name,p->person.sex,p->person.birthday,p->person.phone,p->person.fax,p->person.address,p->person.postcode);
			count++;
			printf("确认要删除该联系人[%s]吗？(输入Y确认)\n",name);
			getchar(); 
			char input=getchar();
			if(input=='Y'||input =='y')
			{
				if(p==first)
				{
					first=p->next;
				}
				else
				{
					p1=first;
					while(p1!=NULL)
					{
						if(p1->next==p)
						{
							p1->next=p->next;
							break;
						}
						p1 = p1->next;
					}
				}		
				free(p);
				printf("删除完毕！\n") ;
			}
			}
			p=p->next;
		}
	if(count ==0)
	{
		printf("没有姓名为该用户的人！\n") ;
	}
	else if(count ==0)
	{
		printf("没有姓名为该用户的人！\n") ;
	}
	printf("按任意键返回主菜单!\n");
	getch();
	system("cls");
}
/*----------------------删除信息函数----------------------*/


/*----------------------更新信息函数----------------------*/
void change_information()
{
	system("cls");
	int count=0;
	char name[11]={0};
	address_book *p =first;
	printf(">>>>请输入要修改的联系人姓名（最大10个字符）:");
	scanf("%s",name);
	while(p!=NULL)
	{
		if(strcmp(p->person.name,name)==0)
		{
			printf("姓名:%s\t性别:%s\t生日:%s\t手机%s\t传真%s\t地址:%s\t邮编:%s\n",p->person.name,p->person.sex,p->person.birthday,p->person.phone,p->person.fax,p->person.address,p->person.postcode);
			printf("是否修改该用户信息:") ;
			getchar(); 
			int input =getchar(); 
			if(input=='Y'||input =='y')
			{
				printf("请输入修改的信息:") ;
				int choose;
				scanf("%d",&choose);
				switch(choose)
				{
					case 1:{
					printf(">>>>请输入姓名:");
					scanf("%s",p->person.name);
					break;
				} 
					case 2:{
					printf(">>>>请输入性别:");
					scanf("%s",p->person.sex);
					break;
				} 
					case 3:{
					printf(">>>>请输入出生日期:");
					scanf("%s",p->person.birthday);
					break;
				} 
					case 4:{
					printf(">>>>请输入手机:");
					scanf("%s",p->person.phone);
					break;
				} 
					case 5:{
					printf(">>>>请输入传真:");
					scanf("%s",p->person.fax);
					break;
				} 
		  	  		case 6:{
			 		printf(">>>>请输入地址:");
			    	scanf("%s",p->person.address);
					break;
				} 
					case 7:{
					printf(">>>>请输入邮编:");
					scanf("%s",p->person.postcode);
					break;
					} 
				}
			}
			count++;	
		}
		p=p->next;
	}
	if(count ==0)
	{
		printf("没有姓名为该用户的人！\n") ;
	}
	printf("按任意键返回主菜单!\n");
	getch();
	system("cls");
}	
/*----------------------更新信息函数----------------------*/

/*----------------------保存信息函数----------------------*/
void save_file()
{
	system("cls");
	FILE *fp;
	address_book *p =first;
	fp=fopen("data.txt","w+");
	while(p!=NULL)
	{
		fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",p->person.name,p->person.sex,p->person.birthday,p->person.phone,p->person.fax,p->person.address,p->person.postcode);
		p=p->next;
	}
	fclose(fp);
	printf("保存成功！\n");
	printf("按任意键返回主菜单!\n");
	getch();
	system("cls");
}
/*----------------------保存信息函数----------------------*/
