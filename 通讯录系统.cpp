#include "stdio.h"
#include "stdlib.h"

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

address_book *first;//=NULL; //链表节点头置空 


void  initialization() //初始化函数 
{
	FILE *fp;
	fp=fopen("data.txt","a");
	struct _address_book *next_address,*new_address;
	first=next_address=new_address=(address_book*)malloc(sizeof(address_book));
	fscanf(fp,"%d\n",&address_number);
	for(int i=address_number;i>0;i--)
	{
		fscanf(fp,"%s\t%s\n",new_address->person.name,new_address->person.phone);
		//printf("%s\t%s\n",new_address->person.name,new_address->person.phone);
		new_address->next=next_address;
		new_address=next_address;
	}
	next_address->next=NULL;
}

void add_information()
{
	
	
}

void show_information()
{
	int i=0;
	address_book *p =first;
	while(p!=NULL)
	{
		i++;
		printf("*****第%d个联系人*****\n",i);
		printf("姓名:%s\t 电话:%s\t",&p->person.name,&p->person.phone);
		p=p->next;
	}
	if(i==0)
	{
		printf("wrong!\t");
	}
	
}

void save_information()
{
	FILE *fp;
	address_book *p =first;
	fp=fopen("data.txt","w+");
		while(p!=NULL)
	{
		fprintf(fp,"%s,%s,%s,%s,%s,%s,%s,\n",p->person.name,p->person.sex,p->person.birthday,p->person.phone,p->person.fax,p->person.address,p->person.postcode);
		p=p->next;
	}
	fclose(fp);
	printf("save success!");
}

int main()
{
	initialization();
	show_information();
}
