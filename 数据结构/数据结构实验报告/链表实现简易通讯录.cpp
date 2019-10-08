#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Link_node {
	int tel[20];
	char sex[20];
	char name[20];
	struct Link_node* next;
}Node;

//��ʼ��ͨѶ¼�б�
Node *init()
{
	return NULL;
}

//���ͨѶ¼�������˵���Ϣ
void  Print_all(Node *head)
{
	Node *p = head;
	if (!p)
	{
		printf("�����ǿյģ�\n");
	}
	else
	{
		printf("������%s,�绰���룺%s,�Ա�%s \n", p->name, p->tel, p->sex);
		p = p->next;
		while (p)
		{
			printf("������%s,�绰���룺%s,�Ա�%s\n ", p->name, p->tel, p->sex);
			p = p->next;
		}
	}
}

//���ͨѶ¼������Ϊxx��ͨѶ¼��Ϣ
void Print_one(Node *head)
{

	char n[20];
	Node *p, *pre;
	p = head;
	printf("������Ҫ���ҵ�����\n");
	scanf("%s", n);
	if (!head)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		while (p && strcmp(p->name, n))
		{
			p = p->next;
		}
		if (p == NULL)
		{
			printf("ͨѶ¼���޴�������");
		}
		else
		{
			printf("������%s,�绰���룺%s,�Ա�%s \n", p->name, p->tel, p->sex);
		}
	}
}

//������Ϣĳλͬѧ��ͨѶ¼��Ϣ
Node *Front_Insert(Node *head)
{
	Node *p = (Node *)malloc(sizeof(Node));
	printf("������������\n");
	scanf("%s", p->name);
	printf("������%s�ĵ绰���룺\n", p->name);
	scanf("%s", p->tel);
	printf("������%s���Ա�\n", p->name);
	scanf("%s", p->sex);
	if (!head)//�����һ�����
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

//ɾ������Ϊxx��ͨѶ¼��Ϣ
Node *Del(Node *head)
{
	Node *p, *pre;
	p = head;
	pre = NULL;
	char na[20];
	printf("������Ҫɾ����������\n");
	scanf("%s", na);
	if (!p)
	{
		printf("ͨѶ¼Ϊ�գ�\n");
		return head;
	}
	else
	{
		while (p && strcmp(p->name, na))//while(p)�жϵ�����û�н������ 
		{
			pre = p;
			p = p->next;
		}
		if (p)
		{
			if (pre == NULL)//ɾ�����ǵ�һ�����
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
	printf("\n\t\t********��ӭ����ͨѶ¼��ѯϵͳ********\n");
	printf("  \t\t*��Ϣ¼�룬�밴1                     *   ");
	printf("\n\t\t*����ĳ�˵���Ϣ���밴2               *");
	printf("\n\t\t*ɾ����Ϣ���밴3                     *");
	printf("\n\t\t*�鿴������Ϣ���밴4                 *");
	printf("\n\t\t*�˳����밴0                         *\n");
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