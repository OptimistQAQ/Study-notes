#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

typedef struct {
	int a[MAXSIZE];
	int size;
}s_list;

void init_s_list(s_list *slt)               //顺序表初始化
{
	slt->size = 0;
}

void append_s_list(s_list *slt, int x)          //顺序表赋值
{
	if (slt->size == MAXSIZE) {
		printf("顺序表是满的！\n");
		exit(1);
	}
	slt->a[slt->size] = x;
	slt->size++;
}

void insert_s_list(s_list *slt,int x, int p)        //顺序表插入 
{
	if (slt->size == MAXSIZE)
	{
		printf("顺序表是满的！\n");
		exit(1);
	}
	if (p<0 || p>slt->size)
	{
		printf("指定的插入位置不存在！\n");
		exit(1);
	}
	for (int i = slt->size - 1; i >= p; i--)
		slt->a[i + 1] = slt->a[i];
	slt->a[p] = x;
	slt->size++;
}

void get(s_list *q,int b)    //给出结点，获得位置
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
		printf("顺序表中没有该结点！\n");
	}
	else
	{
		printf("该顺序表的位置为：%d\n",location);
	}
}

void del_s_list(s_list *slt, int del_p)    //删除顺序表中第del_p位置上的元素
{
	if (slt->size == 0)
	{
		printf("顺序表是空的！\n");
		exit(0);
	}
	if (del_p<0 || del_p>slt->size)
	{
		printf("指定的删除位置不存在！\n");
		exit(0);
	}
	for (int i = del_p; i < slt->size - 1; i++)
	{
		slt->a[i] = slt->a[i + 1];
	}
	slt->size--;
}

void print_s_list(s_list *slt)        //输出顺序表
{
	if (!slt->size)
		printf("顺序表是空的！\n");
	else
		for (int i = 0; i < slt->size; i++) {
			printf("%5d", slt->a[i]);
		}
	printf("\n\n");
}

void sort_s_list(s_list *slt)   //对于第i个元素，实现它前面的元素都比它小，后边的元素都比它大
{
	int i, j, k; //i,j为循环变量，k用来存储第i个元素的位置
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

bool compare(int *a, int b)   //比较两个顺序表中的元素是否相同
{
	if (*a == b)
		return true;
	else
		return false;
}

void merge(s_list *a,s_list *b,s_list *c)     //将两个有序顺序表合并
{
	int i, j, k;
	i = j = k = 0;
	int x = 0, y = 0;  //x用来记录b顺序表开始循环的位置,y用来记录a的
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

void merge_2(s_list *m, s_list *n, s_list *l)  //有序顺序表合并
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
	int total,a;   //total表示开始时顺序表中的总数,假设total值为3
	printf("请输入顺序表初始的总个数：\n");
	scanf("%d", &total);
	for (int i = 0; i < total; i++)
	{
		scanf("%d", &a);
		append_s_list(q, a);
	}
	printf("请将初始的顺序表输出:\n\n");
	print_s_list(q);   //输出



	//实现插入操作  在第2个位置上插入x
	int x,p;
	p = 2;
	printf("请输入要插入的数据：\n");
	scanf("%d", &x);
	insert_s_list(q, x, p);
	printf("请将插入后的顺序表输出：\n");
	print_s_list(q);     //再次输出




	//实现删除操作    删除del_p位置的元素
	int del_p;
	printf("请输入要删除的元素的位置：\n");
	scanf("%d", &del_p);
	del_s_list(q, del_p);
	printf("请将删除后的顺序表输出：\n");
	print_s_list(q);          //再次输出


	//实现排序
	sort_s_list(q);
	printf("请输出排序以后的顺序表：\n");
	print_s_list(q);  //再次输出




	//将两个顺序表合并   排序
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
	printf("请将第二个顺序表输出：\n");
	print_s_list(lq);  //输出第二个顺序表

	//将两个顺序表合并到第一个表上并排序
	merge(q, lq, llq);   //将两个有序顺序表合并，for循环实现
	//merge_2(q, lq, llq);    //将两个有序顺序表合并,while循环实现

	printf("%d\n", llq->a[llq->size]);
	printf("请将合并后的顺序表输出：\n");
	print_s_list(llq);

	return 0;
}