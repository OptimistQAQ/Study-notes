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
		if(h==NULL)   //在开头插入结点
		{
			h=s;h->next=NULL;
		}
		else // 在中间及最后插入结点
		{
			if(h->data>a)
			{
				s->next=h;h=s;
			}
			else // 寻找P的位置
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
		//void print(); // 声明
		//print();  //调用
		scanf("%d",&a);
	}
}

void del()
{
	int b;
	scanf("%d",&b);
	while(b>0)
	{
		if(h==NULL)  // 没有已经建立的链表
			printf("delete faile!\n");
		else
		{
			if(h->data==b)   //  删除开头的结点
			{
				q=h;h=h->next;free(q);
			}
			else    //删除中间及以后的结点
			{
				p=h;
				q=h->next;
				while(q!=NULL && q->data!=b)  //寻找结点的位置
				{
					p=q;
					q=q->next;
				}
				if(!q)
					printf("no result,delete faile!\n");  // 没有寻找到
				else
				{
					p->next=q->next;
					free(q);
				}
			}
		}
		void print(); //声明
		print();  //调用
		scanf("%d",&b);
	}
}

void print()  // 输出链表
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
	creatsort();  // 调用
	print();  //调用
	del();
	print();
	return 0;
}