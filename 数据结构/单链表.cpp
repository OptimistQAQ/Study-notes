#include<stdio.h>
#include<stdlib.h>

typedef struct link_node {
	int info;
	struct link_node *next;
}Node;

//����
Node *init()
{
	return NULL;
}

//ǰ��
Node *qian_creat(int len)
{
	Node *head, *p;
	int i, a;
	for (i = 0; i < len; i++) {
		scanf("%d", &a);
		p = (Node *)malloc(sizeof(Node));   //�����ռ�
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

//���
void print(Node *head) 
{
	Node *p = head;
	if (!p)
		printf("\n�����ǿյģ�");
	else {
		while (p) {
			printf("%d->", p->info);
			p = p->next;
		}
	}
	printf("\n");
}

//����
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

//����
Node *insert(Node *head, int x, int i)
{
	Node *p, *q;
	q = find(head, i); //���ҵ�i���ڵ�
	if (!q && i != 0)
		printf("\n�Ҳ�����%d���ڵ㣬���ܲ���%d��", i, x);
	else {
		p = (Node *)malloc(sizeof(Node));     //����ռ�
		p->info = x;   //�����½ڵ�
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

//ɾ��
Node *del(Node *head, int x)
{
	Node *pre = NULL, *p;
	if (!head)
	{
		printf("\n�������ǿյģ�");
		return head;
	}
	p = head;
	while (p && p->info != x) {   //û���ҵ�����û������
		pre = p;
		p = p->next;
	}
	if (p)
	{
		if (!pre)	//Ҫɾ�����ǵ�һ���ڵ�
			head = head->next;
		else
			pre->next = p->next;
		free(p);  //�ͷſռ�
	}
	return head;
}

//����ԭ�пռ佫������
Node *dao_xu(Node *head)
{
	Node *p, *q, *h;
	p = head; q = p->next;
	while (q->next != NULL)   //�ҵ����һ���ڵ�
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

//������Ľڵ����
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
	int sum;  //sumΪ��ʼ�Ľڵ�����

	//����
	head = init();

	//ǰ��
	printf("�����뿪ʼ�Ľڵ�������\n");
	scanf("%d", &sum);
	head = qian_creat(sum);   //ǰ�崴������
	print(head);   //���������������

	//����
	printf("������Ҫ���ҵڼ����ڵ㣺\n");
	int f;
	scanf("%d", &f);
	p = find(head, f);    //����
	if (p)
		printf("%d\n", p->info);
	else
		printf("û���ҵ�\n");

	//����
	printf("������Ҫ����Ľڵ��Լ�λ�ã�\n");
	int insert_data, insert_lo;
	scanf("%d%d", &insert_data, &insert_lo);
	head = insert(head, insert_data, insert_lo);
	printf("���������������:\n");
	print(head);

	//ɾ��
	printf("������Ҫɾ���Ľڵ㣺\n");
	int del_data;
	scanf("%d", &del_data);
	head = del(head, del_data);
	printf("�����ɾ���������\n");
	print(head);

	//����ԭ�пռ佫������
	head = dao_xu(head);
	printf("���������������\n");
	print(head);

	//������Ľڵ����
	int c;
	printf("������ڵ�ĸ�����\n");
	c = ge_shu(head);
	printf("%d\n", c);
	return 0;
}