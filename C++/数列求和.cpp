#include<stdio.h>
#include<math.h>
int main()
{
	int n,i,sign;
	double term,j,sum;
	while(scanf("%d",&n)!=EOF)
	{
		sum=0;
		sign=1;
		term=1;
		j=1;
		for(i=1;i<=n;i++)
		{
			sum=sum+term;
			j++;
			sign=-sign;
			term=sign/j;
		}
		printf("%.2lf\n",sum);
	}
	return 0;
}
