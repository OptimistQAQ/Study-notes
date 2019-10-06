#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef struct {
	int a[MAXSIZE];
	int size;
}s_list;

void init_s_list(s_list *slt)               //˳����ʼ��
{
	slt->size = 0;
}

void append_s_list(s_list *slt, int x)          //˳���ֵ
{
	if (slt->size == MAXSIZE) {
		printf("˳��������ģ�\n");
		exit(1);
	}
	slt->a[slt->size] = x;
	slt->size++;
}

void insert_s_list(s_list *slt,int x, int p)        //˳������ 
{
	if (slt->size == MAXSIZE)
	{
		printf("˳��������ģ�\n");
		exit(1);
	}
	if (p<0 || p>slt->size)
	{
		printf("ָ���Ĳ���λ�ò����ڣ�\n");
		exit(1);
	}
	for (int i = slt->size - 1; i >= p; i--)
		slt->a[i + 1] = slt->a[i];
	slt->a[p] = x;
	slt->size++;
}

void get(s_list *q,int b)    //������㣬���λ��
{
	int location,i;
	for (i = 0; i < q->size; i++)
	{
		if (q->a == &b)
		{
			location = i;
		}
	}
	if (i == q->size)
	{
		printf("˳�����û�иý�㣡\n");
	}
	else
	{
		printf("��˳����λ��Ϊ��%d\n",location);
	}
}

void del_s_list(s_list *slt, int del_p)    //ɾ��˳����е�del_pλ���ϵ�Ԫ��
{
	if (slt->size == 0)
	{
		printf("˳����ǿյģ�\n");
		exit(0);
	}
	if (del_p<0 || del_p>slt->size)
	{
		printf("ָ����ɾ��λ�ò����ڣ�\n");
		exit(0);
	}
	for (int i = del_p; i < slt->size - 1; i++)
	{
		slt->a[i] = slt->a[i + 1];
	}
	slt->size--;
}

void print_s_list(s_list *slt)        //���˳���
{
	if (!slt->size)
		printf("˳����ǿյģ�\n");
	else
		for (int i = 0; i < slt->size; i++) {
			printf("%5d", slt->a[i]);
		}
	printf("\n\n");
}

void sort_s_list(s_list *slt)   //���ڵ�i��Ԫ�أ�ʵ����ǰ���Ԫ�ض�����С����ߵ�Ԫ�ض�������
{
	int i, j, k; //i,jΪѭ��������k�����洢��i��Ԫ�ص�λ��
	int x, y;
	x = slt->a[0];
	k = 0;
	for (i = 1; i < slt->size; i++)
	{
		if (x > slt->a[i])
		{
			y = slt->a[i];
			for (j = i - 1; j >= k; j--)
				slt->a[j + 1] = slt->a[j];
			slt->a[j + 1] = y;
		}
	}
}

bool compare(int *a, int b)   //�Ƚ�����˳����е�Ԫ���Ƿ���ͬ
{
	if (*a == b)
		return true;
	else
		return false;
}

void merge(s_list *a,s_list *b,s_list *c)     //����������˳���ϲ�
{
	int i, j, k;
	i = j = k = 0;
	int x = 0, y = 0;  //x������¼b˳���ʼѭ����λ��,y������¼a��
	for (i = y; i < a->size; i++)
	{
		for (j = x; j < b->size; j++)
		{
			if (a->a[i] > b->a[j])
				c->a[k++] = b->a[j];
			else
			{
				x = j;
				break;
			}
		}
		c->a[k++] = a->a[i];
		y = i + 1;
		continue;
	}
	if (x < b->size)
		for (j = x; j < b->size; j++)
			c->a[k++] = b->a[j];
	c->size = k;
}

void merge_2(s_list *m, s_list *n, s_list *l)  //����˳���ϲ�
{

	int i = 0, j = 0, k = 0;
	while (i < m->size && j < n->size)
	{
		if (m->a[i] < n->a[j])
		{
			l->a[k++] = m->a[i++];
		}
		else
		{
			l->a[k++] = n->a[j++];
		}
	}
	while (i < m->size) l->a[k++] = m->a[i++];
	while (j < n->size) l->a[k++] = n->a[j++];
	l->size = k;
}


int main()
{
	s_list *q;
	q = (s_list *)malloc(sizeof(s_list));




	init_s_list(q);
	int total,a;   //total��ʾ��ʼʱ˳����е�����,����totalֵΪ3
	printf("������˳����ʼ���ܸ�����\n");
	scanf("%d", &total);
	for (int i = 0; i < total; i++)
	{
		scanf("%d", &a);
		append_s_list(q, a);
	}
	printf("�뽫��ʼ��˳������:\n\n");
	print_s_list(q);   //���



	//ʵ�ֲ������  �ڵ�2��λ���ϲ���x
	int x,p;
	p = 2;
	printf("������Ҫ��������ݣ�\n");
	scanf("%d", &x);
	insert_s_list(q, x, p);
	printf("�뽫������˳��������\n");
	print_s_list(q);     //�ٴ����




	//ʵ��ɾ������    ɾ��del_pλ�õ�Ԫ��
	int del_p;
	printf("������Ҫɾ����Ԫ�ص�λ�ã�\n");
	scanf("%d", &del_p);
	del_s_list(q, del_p);
	printf("�뽫ɾ�����˳��������\n");
	print_s_list(q);          //�ٴ����


	//ʵ������
	sort_s_list(q);
	printf("����������Ժ��˳���\n");
	print_s_list(q);  //�ٴ����




	//������˳���ϲ�   ����
	s_list *lq, *llq;
	lq = (s_list *)malloc(sizeof(s_list));
	llq = (s_list *)malloc(sizeof(s_list));
	init_s_list(lq);
	init_s_list(llq);
	for (int i = 0; i < total; i++)
	{
		scanf("%d", &a);
		append_s_list(lq, a);
	}
	printf("�뽫�ڶ���˳��������\n");
	print_s_list(lq);  //����ڶ���˳���

	//������˳���ϲ�����һ�����ϲ�����
	merge(q, lq, llq);   //����������˳���ϲ���forѭ��ʵ��
	//merge_2(q, lq, llq);    //����������˳���ϲ�,whileѭ��ʵ��

	printf("%d\n", llq->a[llq->size]);
	printf("�뽫�ϲ����˳��������\n");
	print_s_list(llq);

	return 0;
}