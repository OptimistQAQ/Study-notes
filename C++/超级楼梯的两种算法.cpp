#include<stdio.h>
int main()
{
	int i,j,m,n,a[41];
	scanf("%d",&n);
	a[0] = 1;
	a[1] = 1;
	for(j=1;j<=n;j++)
	{
		scanf("%d",&m);
		for(i=2;i<=m;i++)
		{
			a[i] = a[i-1] + a[i-2];	
		}
		printf("%d\n",a[i-2]);
	}
	return 0;
}


#include<stdio.h>
int fun(int x)
{
    if(x==2||x==1)
        return 1;
    else
    return fun(x-1)+fun(x-2);
}
int main()
{
    int n,a;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&a);
        printf("%d\n",fun(a));
    } 
    return 0;    
}
