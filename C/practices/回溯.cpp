#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 10000001;
const int _maxn=10000001;
int a[maxn];
int vis[maxn];//回溯的标记位数组
void print(int n)//将数组中1~n号元素全部输出
{
	int i;
	for(i=0;i<n;i++)
	{
		if(i)printf(" ");
		printf("%d",a[i]);
	}
	printf("\n");
}

void dfs(int val,int index, int n)
{
	int x;
	if(index == n-1)
	{
		a[index]=val;
		print(n);
		return ;
	}
	a[index] = val;
	for(x=1;x<=n;x++)
	{
		if(vis[x]==0)
		{
			vis[x]=1;
			dfs(x,index+1,n);
			vis[x]=0;//回溯
		}
	}
}
int main()
{
	int n,x;
	scanf("%d",&n);
	memset(vis,0,sizeof(vis));//标记位初始化为0
	for(x=1;x<=n;x++)
	{
		if(vis[x]==0)
		{
			vis[x]=1;
			dfs(x,0,n);
			vis[x]=0;
		}
	}
	print(n);
	return 0;
}