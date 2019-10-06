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

//  ǰ��
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
	q = h;  //q ��Զָ��Ҫ�ҵ���һ���ڵ��ǰһ�����
	p = h->next;  //   p��Զָ��q�ĺ�һ�����
	////    Ȼ��ʼ��������
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

///////////�ͷŴ洢�ռ�
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
	/////////  ǰ�崴������
	printf("����������ĳ��ȣ�\n");
	int b,c;
	scanf("%d", &b);
	qian_creat(b);
	print();

	////  ǰ�������
	printf("��ĳ��ǰ�����ĳ����\n");
	int data,ins;
	scanf("%d%d", &data, &ins);
	qian_cha(data, ins);
	print();


	free_node();
	return 0;
}