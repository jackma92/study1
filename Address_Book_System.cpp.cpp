#include "stdio.h"
#include <stdlib.h>
#include "conio.h"
#include "string.h"
/*----------------------��������ṹ�� ----------------------*/
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

address_book *first;//=NULL; //����ڵ�ͷ�ÿ� 

/*----------------------��������----------------------*/
void initialize();
void add_information ();
void show_information ();
void serch_information();
void delect_information();
void change_information();
void save_file();

/*----------------------������----------------------*/
int main()
{
	int choose;
	for(;;)
	{
	 
		printf("|======================|\n");
		printf("|                      |\n");
		printf("|     ϵͳ����ƽ̨     |\n");
		printf("|                      |\n");
		printf("|======================|\n");
		printf("|1.ϵͳ��ʼ��          |\n");
		printf("|                      |\n");
		printf("|2.�����ϵ����Ϣ      |\n");
		printf("|                      |\n");
		printf("|3.��ʾ��ϵ����Ϣ      |\n");
		printf("|                      |\n");
		printf("|4.������ϵ����Ϣ      |\n");
		printf("|                      |\n");
		printf("|5.ɾ����ϵ����Ϣ      |\n");
		printf("|                      |\n");
		printf("|6.�޸���ϵ����Ϣ      |\n");
		printf("|                      |\n");
		printf("|7.�ļ�����            |\n");
		printf("|                      |\n");
		printf("|8.�˳�                |\n");
		printf("|===================== |\n");
		printf(">>>>��������Ҫ���еĲ���:");
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
/*----------------------������----------------------*/

/*----------------------��ʼ������----------------------*/
void initialize()
{
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
	printf("�������ɹ�,��%d��\n",address_number);
	fp=fopen("data.txt","a+");
	struct _address_book *next_address,*new_address;
	first=next_address=new_address=(address_book*)malloc(sizeof(address_book));
	for(int i=0;i<address_number;i++)
	{
		fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",new_address->person.name,new_address->person.sex,new_address->person.birthday,new_address->person.phone,new_address->person.fax,new_address->person.address,new_address->person.postcode);
		//printf("%s\t%s\n",&new_address->person.name,&new_address->person.phone);
		new_address->next=next_address;
		new_address=next_address;
	}
	next_address->next=NULL;
	printf("��ʼ���ɹ�\n\n");
}
/*----------------------��ʼ������----------------------*/


/*----------------------�����Ϣ����----------------------*/
void add_information()
{
	address_book *last =NULL;
	address_book *new_address = (address_book *)malloc(sizeof(address_book));
	new_address->next=NULL;
	if(first==NULL)
	{
		first= new_address;
	}
	else
	{
		while(first->next!=NULL)
		{
			first=first->next;
		}
		first->next=new_address;
	}
	printf(">>>>����������:");
	scanf("%s",new_address->person.name);
	printf(">>>>�������Ա�:");
	scanf("%s",new_address->person.sex);
	printf(">>>>�������������:");
	scanf("%s",new_address->person.birthday);
	printf(">>>>�������ֻ�:");
	scanf("%s",new_address->person.phone);
	printf(">>>>�����봫��:");
	scanf("%s",new_address->person.fax);
	printf(">>>>�������ַ:");
	scanf("%s",new_address->person.address);
	printf(">>>>�������ʱ�:");
	scanf("%s",new_address->person.postcode);
	printf(">>>>�Ƿ��������?(Y���������������򷵻ز˵�"); 
	int input =getchar(); 
	if(input=='Y'||input =='y')
	{
		add_information();
	}
}
/*----------------------�����Ϣ����----------------------*/

/*----------------------��ʾ��Ϣ����----------------------*/
void show_information()
{
	int i=0;
	address_book *p =first;
	while(p!=NULL)
	{
		i++;
		printf("\n\n*******��%d����ϵ��*******\n",i);
		printf("����:%s\t�Ա�:%s\t����:%s\t�ֻ�%s\t����%s\t��ַ:%s\t�ʱ�:%s\n",p->person.name,p->person.sex,p->person.birthday,p->person.phone,p->person.fax,p->person.address,p->person.postcode);
		p=p->next;
	}
	if(i==0)
	{
		printf("wrong!\t");
	}
	printf("��������������˵�!\n");
	getch();
}
/*----------------------��ʾ��Ϣ����----------------------*/

/*----------------------��ѯ��Ϣ����----------------------*/
void serch_information()
{
	int count=0;
	char name[11]={0};
	address_book *p =first;
	printf(">>>>������Ҫ���ҵ���ϵ�����������10���ַ���:");
	scanf("%S",name);
	while(p!=NULL)
	{
		if(strcmp(p->person.name,name)==0)
		{
			printf("����:%s\t�Ա�:%s\t����:%s\t�ֻ�%s\t����%s\t��ַ:%s\t�ʱ�:%s\n",p->person.name,p->person.sex,p->person.birthday,p->person.phone,p->person.fax,p->person.address,p->person.postcode);
			count++;
		}
		p=p->next;
	}
	if(count ==0)
	{
		printf("û������Ϊ���û����ˣ�\n") ;
	}
	printf("�������\n") ;
	getch();
}
/*----------------------��ʾ��Ϣ����----------------------*/

/*----------------------ɾ����Ϣ����----------------------*/
void delect_information()
{
	int count=0;
	char name[11]={0};
	address_book *p=first;
	address_book *p1=NULL;
	printf(">>>>������Ҫɾ������ϵ�����������10���ַ���:");
	scanf("%S",name);
		while(p!=NULL)
	{
		if(strcmp(p->person.name,name)==0)
		{
			printf("����:%s\t�Ա�:%s\t����:%s\t�ֻ�%s\t����%s\t��ַ:%s\t�ʱ�:%s\n",p->person.name,p->person.sex,p->person.birthday,p->person.phone,p->person.fax,p->person.address,p->person.postcode);
			count++;
		}
		p=p->next;
	}
	if(count ==0)
	{
		printf("û������Ϊ���û����ˣ�\n") ;
	}
	else
	{
		printf("ȷ��Ҫɾ������ϵ��[%s]��\n",name);
		getchar(); 
		int input=getchar();
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
			printf("ɾ����ϣ�\n") ;
		}
	}
}
/*----------------------ɾ����Ϣ����----------------------*/


/*----------------------������Ϣ����----------------------*/
void change_information()
{
	
}
/*----------------------������Ϣ����----------------------*/


/*----------------------������Ϣ����----------------------*/
void save_file()
{
	FILE *fp;
	address_book *p =first;
	fp=fopen("data.txt","w+");
		while(p!=NULL)
	{
		fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",p->person.name,p->person.sex,p->person.birthday,p->person.phone,p->person.fax,p->person.address,p->person.postcode);
		p=p->next;
	}
	fclose(fp);
	printf("save success!");
}
/*----------------------������Ϣ����----------------------*/
