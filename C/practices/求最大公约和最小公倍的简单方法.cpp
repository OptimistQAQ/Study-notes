#include<stdio.h>
int gcd(int a, int b)
{
	return b==0 ? a:gcd(b,a%b);
}
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		printf("最大公约数：%d\n 最小公倍数：%d\n",gcd(a,b),a/gcd(a,b)*b);
	}
	return 0;
}