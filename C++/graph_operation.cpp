#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int m = 20;
int visited[m];

typedef struct node
{
    int adjvex;
    struct node *next;
}edgeNode;

typedef struct vnode{
    char vertex;
    edgeNode *firstEdge;
}vertexNode;

typedef struct{
    vertexNode adjlist[m];
    int n,e; //图的顶点总数与边数
}linkedGraph;

void creatwithfile(linkedGraph *g, char *filename, int c)
{
    int i,j,k;
    edgeNode *s;
    FILE *fp;
    fp = fopen(filename, "r");
    if(fp){
        fscanf(fp,"%d%d",&g->n,&g->e);
        for(i=0;i<g->n;i++){
            fscanf(fp,"%ls",&g->adjlist[i].vertex);
            g->adjlist[i].firstEdge = NULL;
        }
        for(k=0;k<g->e;k++){
            fscanf(fp,"%d%d",&i,&j);
            s = (edgeNode *)malloc(sizeof(edgeNode));
            s->adjvex = j;
            s->next = g->adjlist[i].firstEdge;
            g->adjlist[i].firstEdge = s;
            if(c == 0){
                s = (edgeNode *)malloc(sizeof(edgeNode));
                s->adjvex = i;
                s->next = g->adjlist[j].firstEdge;
                g->adjlist[j].firstEdge = s;
            }
        }
        fclose(fp);
    }
    else
    {
        g->n = 0;
    }
    
}

linkedGraph *creat(int c)
{
    //c做一个判断，如果c为0，就表示创建无向图
    linkedGraph *p;
    p = (linkedGraph *)malloc(sizeof(linkedGraph));
    int i,j,k;
    edgeNode *s;
    printf("输入节点数和边数：\n");
    scanf("%d%d",&p->n,&p->e);
    printf("输入节点的值：\n");
    getchar();
    for(i=0;i<p->n;i++)
    {
        scanf("%c",&p->adjlist[i].vertex);  //顶点信息
        getchar();
        p->adjlist[i].firstEdge = NULL;  //置空边表
    }
    if(c == 0)
        printf("输入无序对：\n");
    else
        printf("输入有序对：\n");
    for(k=0;k<p->e;k++)
    {
        scanf("%d%d",&i,&j);  //读入无序对
        s = (edgeNode *)malloc(sizeof(edgeNode));
        s->adjvex = j;
        s->next = p->adjlist[i].firstEdge;
        p->adjlist[i].firstEdge = s;
        if(c == 0)
        {
            s = (edgeNode *)malloc(sizeof(edgeNode));
            s->adjvex = i;
            s->next = p->adjlist[j].firstEdge;
            p->adjlist[j].firstEdge = s;
        }
    }
    return p;
}

void dfs(linkedGraph *g, int i)
{
    edgeNode *p;
    printf("visit vertex: %c \n",g->adjlist[i].vertex);
    visited[i] = 1;
    p = g->adjlist[i].firstEdge;
    while (p)
    {
        if(!visited[p->adjvex])
            dfs(g,p->adjvex);
        p = p->next;
    }
}

void dfsTraverse(linkedGraph *g)
{
    int i;
    for(i=0;i<g->n;i++)
    {
        visited[i] = 0;
    }
    for(i=0;i<g->n;i++)
        if(!visited[i])
            dfs(g,i);
}

void bfs(linkedGraph *g,int i)
{
    int j;
    edgeNode *p;
    int queue[m],front,rear;
    front = rear = 0;
    printf("visit vertex: %c \n",g->adjlist[i].vertex);
    visited[i] = 1;
    queue[rear++] = i;
    while(rear > front)
    {
        j = queue[front++];
        p = g->adjlist[j].firstEdge;
        while(p)
        {
            if(!visited[p->adjvex])
            {
                printf("visit vertex: %c \n",g->adjlist[p->adjvex].vertex);
                queue[rear++] = p->adjvex;
                visited[p->adjvex] = 1;
            }
            p = p->next;
        }
    }
}

int bfsTraverse(linkedGraph *g)
{
    int i,count = 0;
    for(i=0;i<g->n;i++)
        visited[i] = 0;
    for(i=0;i<g->n;i++)
    {
        if(!visited[i])
        {
            printf("\n");
            count++;
            bfs(g,i);
        }
    }
    return count;
}

void dfs_t(linkedGraph *g, int i)
{
    edgeNode *p;
    edgeNode *stack[m];
    int top = -1;
    printf("visit vertex: %c \n",g->adjlist[i].vertex);
    visited[i] = 1;
    p = g->adjlist[i].firstEdge;
    while(top > -1 || p)
    {
        if(p)
            if(visited[p->adjvex])
                p = p->next;
            else
            {
                printf("visit vertex: %c \n",g->adjlist[p->adjvex].vertex);
                visited[p->adjvex] = 1;
                stack[++top] = p;
                p = g->adjlist[p->adjvex].firstEdge;
            }
        else
            if(top > -1)
            {
                p = stack[top--];
                p = p->next;
            }
            
    }
}

void dfsTraverse_t(linkedGraph *g)
{
    int i;
    for(i=0;i<g->n;i++)
        visited[i] = 0;
    for(i=0;i<g->n;i++)
        if(!visited[i])
            dfs_t(g,i);
}

int main()
{
    linkedGraph *h;
    h = creat(0);
    printf("\n深度优先遍历：\n");
    dfsTraverse(h);
    printf("\n广度优先遍历: ");
    int count;
    count = bfsTraverse(h);
    printf("\n此图的连通分量为：\n");
    printf("%d\n",count);

    printf("\n非递归深度优先遍历：\n");
    dfsTraverse_t(h);
    return 0;
}

/*
5 5
0 1 2 3 4
0 1
0 2
1 3
1 4
4 2
*/