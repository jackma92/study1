#include "stdio.h"
#include <stdlib.h>

int initialize();
int add_information ();
int show_information ();
int serch_information();
int delect_information();
int change_information();
int save_file();



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
		printf("��������Ҫ���еĲ���:");
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

int initialize()
{
	printf("��ʼ���ɹ�\n\n\n\n\n");
}


int add_information()
{
	
}

int show_information()
{
	
}

int serch_information()
{
	
}

int delect_information()
{
	
}

int change_information()
{
	
}

int save_file()
{
	
}
