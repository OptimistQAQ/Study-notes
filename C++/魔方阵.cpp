#include<stdio.h>
#define N 100
int main()
{
	int a[N][N],b,i,j;
	while(scanf("%d",&b)!=EOF)
	{
		for(i=0;i<b;i++)
			for(j=0;j<b;j++)
				a[i][j]=10000;
		a[0][b/2]=1;
		int line,col;
		line=0;col=b/2;
		for(int c=2;c<=b*b;c++)
		{
			i=line;j=col;
			if(line==0)
				line=b-1;
			else
				line--;
			if(col==b-1)
				col=0;
			else
				col++;
			if(a[line][col]<c)
			{
				if(i==b-1)
				{
					line=0;
					col=j;
				}
				else
				{
					line=i+1;
					col=j;
				}
			}
			a[line][col]=c;	
		}
		for(i=0;i<b;i++)
		{
			for(j=0;j<b;j++)
				printf("%5d",a[i][j]);
			printf("\n");
		}
	}
	return 0;
}