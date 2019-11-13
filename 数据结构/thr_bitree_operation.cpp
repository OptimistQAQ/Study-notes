#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
	char data;
	int ltag, rtag;
	struct node *lchild, *rchild;
}N;

N *pre = NULL; //初始化前驱节点
N *root;  //根节点

//创建二叉树
N *create()
{
	char ch;
	N *t;
	if ((ch = getchar()) == '#')
		t = NULL;
	else
	{
		t = (N *)malloc(sizeof(N));
		t->data = ch;
		t->lchild = create();
		t->rchild = create();
	}
	return t;
}

//对二叉树进行中序线索化
void in_threading(N *p)
{
	if (p) {
		in_threading(p->lchild);
		p->ltag = (p->lchild) ? 0 : 1;
		p->rtag = (p->rchild) ? 0 : 1;
		if (pre) {
			if (pre->rtag == 1)
				pre->rchild = p;
			if (p->ltag == 1)
				p->lchild = pre;
		}
		pre = p;
		in_threading(p->rchild);
	}
}

//创建中序穿线二叉树
N *createthrtree(N *p) {
	p = create();
	in_threading(p);
	return p;
}

//中序遍历穿线二叉树
N *insuccnode(N *p)
{
	N *q;
	if (p->rtag == 1)
	{
		return p->rchild;
	}
	else
	{
		q = p->rchild;
		while (q->ltag == 0)
		{
			q = q->lchild;
		}
		return q;
	}
}

void inthrtree(N *p) {
	if (p) {
		while (p->ltag == 0)   p = p->lchild;
		do {
			printf("%c  ", p->data);
			p = insuccnode(p);
		} while (p);
	}
	printf("\n");
}

int main()
{
	N *q;
	q = createthrtree(root);
	inthrtree(q);
	return 0;
}