#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
}*p,*q,*h,*s;

void creatsort()
{
	int a;
	scanf("%d",&a);
	h=NULL;
	while(a>0)
	{
		s = (struct node*)malloc(sizeof(struct node));
		s->data=a;
		if(h==NULL)   //�ڿ�ͷ������
		{
			h=s;h->next=NULL;
		}
		else // ���м估��������
		{
			if(h->data>a)
			{
				s->next=h;h=s;
			}
			else // Ѱ��P��λ��
			{
				p=h;
				while(p->next!=NULL && p->next->data<a)
				{
					p=p->next;
				}
				s->next=p->next;
				p->next=s;
			}
		}
		//void print(); // ����
		//print();  //����
		scanf("%d",&a);
	}
}

void del()
{
	int b;
	scanf("%d",&b);
	while(b>0)
	{
		if(h==NULL)  // û���Ѿ�����������
			printf("delete faile!\n");
		else
		{
			if(h->data==b)   //  ɾ����ͷ�Ľ��
			{
				q=h;h=h->next;free(q);
			}
			else    //ɾ���м估�Ժ�Ľ��
			{
				p=h;
				q=h->next;
				while(q!=NULL && q->data!=b)  //Ѱ�ҽ���λ��
				{
					p=q;
					q=q->next;
				}
				if(!q)
					printf("no result,delete faile!\n");  // û��Ѱ�ҵ�
				else
				{
					p->next=q->next;
					free(q);
				}
			}
		}
		void print(); //����
		print();  //����
		scanf("%d",&b);
	}
}

void print()  // �������
{
	q=h;
	while(q!=NULL)
	{
		printf("%d->",q->data);
		q=q->next;
	}
}

int main()
{
	creatsort();  // ����
	print();  //����
	del();
	print();
	return 0;
}