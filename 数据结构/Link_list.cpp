#include<stdio.h>
#include<stdlib.h>

typedef struct link_node {
	int info;
	struct link_node *next;
}Node;

//建空
Node *init()
{
	return NULL;
}

//前插
Node *qian_creat(int len)
{
	Node *head, *p;
	int i, a;
	for (i = 0; i < len; i++) {
		scanf("%d", &a);
		p = (Node *)malloc(sizeof(Node));   //创建空间
		p->info = a;
		if (i == 0) {
			p->next = NULL;
			head = p;
		}
		else {
			p->next = head;
			head = p;
		}
	}
	return head;
}

//输出
void print(Node *head) 
{
	Node *p = head;
	if (!p)
		printf("\n链表是空的！");
	else {
		while (p) {
			printf("%d->", p->info);
			p = p->next;
		}
	}
	printf("\n");
}

//查找
Node *find(Node *head, int i)
{
	int j = 1;
	Node *p = head;
	if (i < 1) return NULL;
	while (p && i != j) {
		p = p->next; 
		j++;
	}
	return p;
}

//插入
Node *insert(Node *head, int x, int i)
{
	Node *p, *q;
	q = find(head, i); //查找第i个节点
	if (!q && i != 0)
		printf("\n找不到第%d个节点，不能插入%d！", i, x);
	else {
		p = (Node *)malloc(sizeof(Node));     //分配空间
		p->info = x;   //设置新节点
		if (i == 0) {
			p->next = head;
			head = p;
		}
		else {
			p->next = q->next;
			q->next = p;
		}
	}
	return head;
}

//删除
Node *del(Node *head, int x)
{
	Node *pre = NULL, *p;
	if (!head)
	{
		printf("\n单链表是空的！");
		return head;
	}
	p = head;
	while (p && p->info != x) {   //没有找到并且没有找完
		pre = p;
		p = p->next;
	}
	if (p)
	{
		if (!pre)	//要删除的是第一个节点
			head = head->next;
		else
			pre->next = p->next;
		free(p);  //释放空间
	}
	return head;
}

//利用原有空间将链表倒序
Node *dao_xu(Node *head)
{
	Node *p, *q, *h;
	p = head; q = p->next;
	while (q->next != NULL)   //找到最后一个节点
	{
		p = p->next;
		q = q->next;
	}
	h = q;
	q->next = p;
	q = p;
	p = head;
	while (q != head)
	{
		while (p->next != q)
		{
			p = p->next;
		}
		q->next = p;
		q = p;
		p = head;
	}
	q->next = NULL;
	return h;
}

//求单链表的节点个数
int ge_shu(Node *head)
{
	int count = 0;
	Node *p = head;
	while (p) {
		count++;
		p = p->next;
	}
	return count;
}

int main()
{
	Node *head, *p;
	int sum;  //sum为开始的节点总数

	//建空
	head = init();

	//前插
	printf("请输入开始的节点总数：\n");
	scanf("%d", &sum);
	head = qian_creat(sum);   //前插创建链表
	print(head);   //输出所创建的链表

	//查找
	printf("请输入要查找第几个节点：\n");
	int f;
	scanf("%d", &f);
	p = find(head, f);    //查找
	if (p)
		printf("%d\n", p->info);
	else
		printf("没有找到\n");

	//插入
	printf("请输入要插入的节点以及位置：\n");
	int insert_data, insert_lo;
	scanf("%d%d", &insert_data, &insert_lo);
	head = insert(head, insert_data, insert_lo);
	printf("请输出插入后的链表:\n");
	print(head);

	//删除
	printf("请输入要删除的节点：\n");
	int del_data;
	scanf("%d", &del_data);
	head = del(head, del_data);
	printf("请输出删除后的链表：\n");
	print(head);

	//利用原有空间将链表倒序
	head = dao_xu(head);
	printf("请输出倒序后的链表：\n");
	print(head);

	//求单链表的节点个数
	int c;
	printf("请输出节点的个数：\n");
	c = ge_shu(head);
	printf("%d\n", c);
	return 0;
}