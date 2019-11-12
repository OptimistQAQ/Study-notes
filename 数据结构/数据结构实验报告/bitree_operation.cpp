#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char data;
    struct node *lchild, *rchild;
}N;

N *root;

//创建二叉树
N *create()
{
    N *t;
    char a;
    if((a = getchar()) == '#')
        t = NULL;
    else
    {
        t = (N *)malloc(sizeof(N));
        t->data = a;
        t->lchild = create();
        t->rchild = create();
    }
    return t;
}

//定义栈
typedef struct stack{
    N *data[100];
    int tag[100];
    int top;
}seqstack;

//进栈
void push(seqstack *s, N *t)
{
    s->data[s->top] = t;
    s->top++;
}

//出栈
N *pop(seqstack *s){
    if(s->top != 0){
        s->top--;
        return s->data[s->top];
    }
    else
    {
        return NULL;
    }
}

//前序遍历二叉树，非递归
void preorder(N *t){
    seqstack s;
    s.top = 0;
    printf("前序遍历结果：");
    while((t) || (s.top != 0)){
        if(t){
            printf("%c  ",t->data);
            push(&s,t);
            t = t->lchild;
        }
        else
        {
            t = pop(&s);
            t = t->rchild;
        }
    }
    printf("\n");
}

//前序遍历二叉树，递归
void preorder1(N *t)
{
    if(t){
        printf("%c  ",t->data);
        preorder1(t->lchild);
        preorder1(t->rchild);
    }
}

//中序遍历二叉树，非递归
void inorder(N *t) {
    seqstack s;
    s.top = 0;
    printf("中序遍历结果：");
    while((t != NULL) || (s.top != 0)){
        if(t){
            push(&s,t);
            t = t->lchild;
        }
        else{
            t = pop(&s);
            printf("%c  ",t->data);
            t = t->rchild;
        }
    }
    printf("\n");
}

//中序遍历二叉树，递归
void inorder1(N *t)
{
    if(t)
    {
        inorder1(t->lchild);
        printf("%c  ",t->data);
        inorder1(t->rchild);
    }
}

//中序遍历返回最后一个节点
N *lastnode(N *t)
{
    if(t->rchild)
    {
        while(t->rchild)
        {
            t = t->rchild;
        }
    }
    return t;
}

//后序遍历二叉树，非递归
void postorder(N *t) {
    seqstack s;
    s.top = 0;
    printf("后序遍历结果：");
    while ((t) || (s.top != 0))
    {
        if(t){
            s.data[s.top] = t;
            s.tag[s.top] = 0;
            s.top++;
            t = t->lchild;
        }
        else if (s.tag[s.top - 1] == 1)
        {
            s.top--;
            t = s.data[s.top];
            printf("%c  ",t->data);
            t = NULL;
        }
        else
        {
            t = s.data[s.top - 1];
            s.tag[s.top - 1] = 1;
            t = t->rchild;
        }
    }
    printf("\n");
}

//后序遍历二叉树，递归
void posorder1(N *t) {
    if(t)
    {
        posorder1(t->lchild);
        posorder1(t->rchild);
        printf("%c  ",t->data);
    }
}

//统计节点个数
int num_of_node(N *t)
{
    if(t == NULL)
        return 0;
    else
    {
        return (num_of_node(t->lchild) + num_of_node(t->rchild) + 1);
    }
}

//统计二叉树叶子节点的个数，递归
int num_of_Leafnode(N *t)
{
    if(t == NULL)
        return 0;
    if(t->lchild == NULL && t->rchild == NULL)
        return 1;
    else
    {
        return num_of_Leafnode(t->lchild) + num_of_Leafnode(t->rchild);
    }
}

//统计二叉树叶子节点的个数，非递归
int num_of_Leafnode1(N *t)
{
    if(t == NULL)
        return 0;
    int num = 0;
    stack s;
    s.top = 0;
    while ((t != NULL) || s.top!=0)
    {
        if(t)
        {
            push(&s, t);
            t = t->lchild;
        }
        else
        {
            t = pop(&s);
            if(t->lchild == NULL && t->rchild == NULL)
            {
                num++;
            }
            t = t->rchild;
        }
    }
    return num;
}

//求二叉树的深度
int depth(N *t){
    int h,lh,rh;
    if(t == NULL)
        return 0;
    else
    {
        lh = depth(t->lchild);
        rh = depth(t->rchild);
        if(lh > rh) h = lh + 1;
        else
        {
            h = rh + 1;
        }
    }
    return h;   
}

//返回值为x的节点
N *findNode(N *t, char x)
{
	N *p;
	p = t;
	if (t == NULL)
		return NULL;
	else if (t->data == x)
		return t;
	else
	{
		N *temp;
		temp = findNode(p->lchild, x);
		if (!temp)
		{
			return findNode(p->rchild, x);
		}
		return temp;
	}
	return NULL;
}

int treeFind(N *t,N *node)
{
    if(t == NULL)
        return 0;
    if(t == node)
        return 1;
    if(treeFind(t->lchild,node) == 1)
        return 1;
    else if(treeFind(t->rchild,node) == 1)
        return 1;
    else
    {
        return 0;
    }
    
}

//求p和q的最近共同祖先
N *lowestCommonAncestor(N *t, N *p, N *q)
{
    if(t == NULL)
        return NULL;
    if(t == p || t == q)
        return t;
    //最近祖先在左孩子
    int pLeft = treeFind(t->lchild,p);
    int qLeft = treeFind(t->lchild,q);
    if(pLeft == 1 && qLeft == 1)
        return lowestCommonAncestor(t->lchild,p,q);
    //最近祖先在右孩子
    else if(pLeft == 0 && qLeft == 0)
        return lowestCommonAncestor(t->rchild,p,q);
    //p、q一个在左一个在右
    else
    {
        return t;
    }
    
}

int main()
{
    int total;
    root = create();

    preorder(root);  //前序遍历，非递归

    inorder(root);   //中序遍历，非递归

    postorder(root); //后序遍历，非递归

    preorder1(root);   //前序递归
    printf("\n");

    inorder1(root);   //中序递归
    printf("\n");

    posorder1(root);    //后序递归
    printf("\n");

    //节点总数
    total = num_of_node(root);
    printf("\n节点总数为：\n%d\n",total);

    //叶子节点总数,时间复杂度O(n)
    int leafCount;
    leafCount = num_of_Leafnode1(root);
    printf("叶子节点的总数为：\n%d\n",leafCount);

    //中序遍历下最后一个节点
    N *lastNode;
    lastNode = lastnode(root);
    printf("中序遍历下最后一个节点为：\n%c\n",lastNode->data);

    //二叉树高度
    int hight;
    hight = depth(root);
    printf("树的高度为：\n%d\n",hight);

    //求p、q的最近共同祖先
    getchar();
    char m,n;
    m = getchar();
    getchar();
    n = getchar();
    N *p,*q,*lowest;
    p = findNode(root, m);
    q = findNode(root, n);
    lowest = lowestCommonAncestor(root,p,q);
    printf("%c\n",lowest->data);

    return 0;
}