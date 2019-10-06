#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}N;

N *h;

void qian_creat(int len) 
{
	N *p;
	int i, a;
	for (i = 0; i < len; i++) {
		scanf("%d", &a);
		p = (N*)malloc(sizeof(N));
		p->data = a;
		if (i == 0) {
			p->next = NULL;
			h = p;
		}
		else {
			p->next = h;
			h = p;
		}
	}
	return;
}

//void hou_creat(int len) 
//{
//	N *p, *q;
//	int i, a;
//	for (i = 0; i < len; i++)
//	{
//		scanf("%d", &a);
//		p = (N*)malloc(sizeof(N));
//		if (i == 0) {
//			h = p;
//			q = p;
//		}
//		else
//		{
//			q->next = p;
//			q = p;
//		}
//		p->next = NULL;
//	}
//}

//  前插
void qian_cha(int data, int newdata) 
{
	N *p, *q, *p1;
	if (h->data == data)
	{
		p = (N*)malloc(sizeof(N));
		p->data = newdata;
		p->next = h;
		h = p;
		return;
	}
	q = h;  //q 永远指向要找的那一个节点的前一个结点
	p = h->next;  //   p永远指向q的后一个结点
	////    然后开始遍历查找
	while (p)
	{
		if (p->data == data)
		{
			p1 = (N*)malloc(sizeof(N));
			p1->data = newdata;
			p1->next = p;
			q->next = p1;
			return;
		}
		else
		{
			q = p;
			p = p->next;
		}
	}
}

void print()
{
	N *p = h;
	while (p) {
		printf("%d  ", p->data);
		p = p->next;
	}
	printf("\n");
}

///////////释放存储空间
void free_node()
{
	N *p;
	while (h != NULL)
	{
		p = h;
		h = h->next;
		free(p);
	}
	return;
}

int main() 
{
	/////////  前插创建链表
	printf("请输入链表的长度：\n");
	int b,c;
	scanf("%d", &b);
	qian_creat(b);
	print();

	////  前插插入结点
	printf("在某数前面插入某数：\n");
	int data,ins;
	scanf("%d%d", &data, &ins);
	qian_cha(data, ins);
	print();


	free_node();
	return 0;
}