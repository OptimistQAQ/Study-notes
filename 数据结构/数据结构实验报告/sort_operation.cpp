#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int maxsize = 101;

typedef struct {
	char name[20];   //姓名
	char info_num[20];   //学号
	char department[20]; //系别
	char class_num[20]; //班号
	char card_num[20];   //卡号
}grade;

typedef struct
{
	grade r[maxsize];
	int len;
}table;

//读取文件中的信息
table creat(table tab, char *filename)
{
	FILE *fp = fopen(filename, "r");
	if (fp)
	{
		fscanf(fp, "%d", &tab.len);  //读取借书证的个数
		for (int i = 1; i <= tab.len; i++)
		{
			fscanf(fp, "%s", tab.r[i].name);
			fscanf(fp, "%s", tab.r[i].info_num);
			fscanf(fp, "%s", tab.r[i].department);
			fscanf(fp, "%s", tab.r[i].class_num);
			fscanf(fp, "%s", tab.r[i].card_num);
		}
		printf("读取成功！\n");
	}
	else {
		printf("打开文件失败！\n");
	}
	return tab;
}

//输出所有的录入信息
void output(table tab)
{
	if (tab.len != 0)
	{
		printf("输出所有的学生信息：\n");
		printf("%21s%21s%21s%21s%21s\n", "姓名", "学号", "系别", "班号", "卡号");
		for (int i = 1; i <= tab.len; i++)
		{
			printf("%21s%21s%21s%21s%21s\n", tab.r[i].name, tab.r[i].info_num, tab.r[i].department, tab.r[i].class_num, tab.r[i].card_num);
		}
	}
	else {
		printf("error!\n");
	}
}

//对卡号进行排序
table shellinsertsort(table tab)
{
	int i,j,d;
	d = tab.len / 2;
	while(d >= 1)
	{
		for(i = d+1; i<=tab.len; i++)
		{
			tab.r[0] = tab.r[i];
			j = i-d;
			while(j > 0 && strcmp(tab.r[0].card_num,tab.r[j].card_num) < 0)
			{
				tab.r[j+d] = tab.r[j];
				j = j-d;
			}
			tab.r[j+d] = tab.r[0];
		}
		d = d/2;
	}
	return tab;
}

//对学号排序，插入
table insertsort(table tab)
{
	int i,j;
	for(i=1; i<=tab.len; i++)
	{
		j = i-1;
		tab.r[0] = tab.r[i];
		while(strcmp(tab.r[0].info_num,tab.r[j].info_num) < 0)
		{
			tab.r[j+1] = tab.r[j];
			j = j-1;
		}
		tab.r[j+1] = tab.r[0];
	}
	return tab;
}

table sort(table tab)
{
	int input = 0;  //输入想要选择的步骤
	printf("\n1.借书证卡号\n");
	printf("2.学号\n");
	printf("请输入你想要排序的数据：\n");
	scanf("%d",&input);
	switch (input)
	{
	case 1:
	{
		tab = shellinsertsort(tab);
		printf("借书证卡号排序成功！！\n");
		break;
	}
	case 2:
	{
		tab = insertsort(tab);
		printf("学号排序成功！！\n");
		break;	
	}
	default:
		break;
	}
	return tab;
}

//通过卡号查询其他信息，二分法
int search(table tab, char *key)
{
	int low = 1,high = tab.len+1, mid;
	while(low <= high)
	{
		mid = (low + high)/2;
		if(strcmp(tab.r[mid].card_num,key) == 0)
			return mid;
		if(strcmp(tab.r[mid].card_num,key) > 0)
			high = mid-1;
		else
			low = mid+1;
	}
	return -1;
}

//通过系别查询卡号
void depement_search(table tab)
{
	getchar();
	char depe_info[20] = "";
	printf("请输入要查询的系别：\n");
	gets(depe_info);
	printf("查询结果：\n");
	for(int i=1;i<=tab.len;i++)
	{
		if(strcmp(tab.r[i].department,depe_info) == 0)
		{
			printf("%21s\n",tab.r[i].card_num);
		}
	}
}

int main()
{
	printf("\t\t------------借书证信息查询系统----------\n");
	printf("\t\t         1.从文件中读取信息             \n");
	printf("\t\t         2.对信息进行排序               \n");
	printf("\t\t         3.查找借书证信息               \n");
	printf("\t\t         4.输出所有借书信息记录         \n");
	printf("\t\t         5.通过系别查找卡号             \n");
	printf("\t\t---------------------------------------\n");
	int c = 0;  //从键盘上读取的命令
	table tab;
	tab.len = 0;
	char filename[30] = "D:\\InfoBook.txt";
	while (1) {
		printf("请输入操作命令：\n");
		scanf("%d", &c);
		switch (c)
		{
		case 1:
		{
			tab = creat(tab, filename);
			break;
		}
		case 2:
		{
			tab = sort(tab);
			break;
		}
		case 3:
		{
			getchar();
			char infonum[20] = "";
			printf("请输入要查询的卡号：\n");
			gets(infonum);
			printf("查询结果：\n");
			tab = shellinsertsort(tab);
			int result = search(tab,infonum);
			if(result != -1)
			{
				printf("%21s%21s%21s%21s%21s\n", "姓名", "学号", "系别", "班号", "卡号");
				printf("%21s%21s%21s%21s%21s\n", tab.r[result].name, tab.r[result].info_num, tab.r[result].department, tab.r[result].class_num, tab.r[result].card_num);
			}
			else
				printf("没有找到！\n");
			break;
		}
		case 4:
			output(tab);
			break;
		case 5:
			{
				depement_search(tab);
				break;
			}

		default:
			printf("输入错误! \n");
			exit(0);
			break;
		}
	}
	return 0;
}