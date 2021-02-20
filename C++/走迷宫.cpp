#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 20;
char M[maxn][maxn];
int vis[maxn][maxn];
int n,flag;
int a[]={0,0,1,-1};
int b[]={1,-1,0,0};
void dfs(int x,int y)
{
	int i;
	int xx,yy;
	vis[x][y]=1;
	if(x == n-1 && y == n-1)
	{
		flag = 1;
		return ;
	}

	for (i=0;i < 4;i++)
	{
		xx = x+ a[i];
		yy = y+ b[i];

		if(xx >= 0 && xx < n && yy >= 0 && yy < n && M[xx][yy] !='#' && vis[xx][yy] == 0)
		{
			dfs(xx,yy);
		}
	}
}

int main()
{
	int m;
	int i,j;
	cin >> m;
	while(m--)
	{
		cin >> n;

		for(i = 0;i < n;i++)
		{
			for(j = 0;j < n;j++)
			{
				cin >> M[i][j];
			}
		}
		memset(vis,0,sizeof(vis));
			flag = 0;

			dfs(0,0);

			if(flag == 0)
				printf("NO\n");
			else
				printf("YES\n");
	}

	return 0;
}