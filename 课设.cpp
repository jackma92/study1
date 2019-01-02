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
		printf("请输入需要进行的操作:");
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
	printf("初始化成功\n\n\n\n\n");
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
