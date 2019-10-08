#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Link_node {
	int tel[20];
	char sex[20];
	char name[20];
	struct Link_node* next;
}Node;

//初始化通讯录列表
Node *init()
{
	return NULL;
}

//输出通讯录中所有人的信息
void  Print_all(Node *head)
{
	Node *p = head;
	if (!p)
	{
		printf("链表是空的！\n");
	}
	else
	{
		printf("姓名：%s,电话号码：%s,性别：%s \n", p->name, p->tel, p->sex);
		p = p->next;
		while (p)
		{
			printf("姓名：%s,电话号码：%s,性别：%s\n ", p->name, p->tel, p->sex);
			p = p->next;
		}
	}
}

//输出通讯录中姓名为xx的通讯录信息
void Print_one(Node *head)
{

	char n[20];
	Node *p, *pre;
	p = head;
	printf("请输入要查找的姓名\n");
	scanf("%s", n);
	if (!head)
	{
		printf("通讯录为空\n");
	}
	else
	{
		while (p && strcmp(p->name, n))
		{
			p = p->next;
		}
		if (p == NULL)
		{
			printf("通讯录中无此人名字");
		}
		else
		{
			printf("姓名：%s,电话号码：%s,性别：%s \n", p->name, p->tel, p->sex);
		}
	}
}

//插入信息某位同学的通讯录信息
Node *Front_Insert(Node *head)
{
	Node *p = (Node *)malloc(sizeof(Node));
	printf("请输入姓名：\n");
	scanf("%s", p->name);
	printf("请输入%s的电话号码：\n", p->name);
	scanf("%s", p->tel);
	printf("请输入%s的性别\n", p->name);
	scanf("%s", p->sex);
	if (!head)//插入第一个结点
	{
		p->next = NULL;
		head = p;
	}
	else
	{
		p->next = head;
		head = p;
	}
	return head;
}

//删除姓名为xx的通讯录信息
Node *Del(Node *head)
{
	Node *p, *pre;
	p = head;
	pre = NULL;
	char na[20];
	printf("请输入要删除的姓名：\n");
	scanf("%s", na);
	if (!p)
	{
		printf("通讯录为空！\n");
		return head;
	}
	else
	{
		while (p && strcmp(p->name, na))//while(p)判断的是有没有结点的情况 
		{
			pre = p;
			p = p->next;
		}
		if (p)
		{
			if (pre == NULL)//删除的是第一个结点
			{
				head = p->next;
			}
			else
			{
				pre->next = p->next;
			}
			free(p);
		}
	}
	return head;
}

int main()
{
	Node *head;
	printf("\n\t\t********欢迎进入通讯录查询系统********\n");
	printf("  \t\t*信息录入，请按1                     *   ");
	printf("\n\t\t*查找某人的信息，请按2               *");
	printf("\n\t\t*删除信息，请按3                     *");
	printf("\n\t\t*查看所有信息，请按4                 *");
	printf("\n\t\t*退出，请按0                         *\n");
	printf("\t\t**************************************\n\n");
	printf("Please select(0--4):");
	head = init();
	int i;
	while (scanf("%d",&i) != EOF)
	{
		switch (i)
		{
		case 1:
			head = Front_Insert(head);
			break;
		case 2:
			Print_one(head);
			break;
		case 3:
			head = Del(head);
			break;
		case 4:
			Print_all(head);
			break;
		case 0:
			exit(0);
		}
		printf("Please select(0--4):");
	}
	return 0;
}