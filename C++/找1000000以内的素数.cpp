#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
int n,cnt;
const int maxn = 1000005;
const int _maxn = 78499+5;     //1000000����ӵ�е�����
int prime[_maxn];
bool vis[maxn];          //�������ɺ�vis�����н�����������ֱ���ж�
int sum[maxn];
void get_prime()        //  ��Ч�������
{
	memset(vis,true,sizeof(vis));
	vis[0]=vis[1]=false;
	for(int i=2;i<=n;i++)
	{
		if(vis[i])
			prime[cnt++]=i;
		for(int j=0;(j<cnt) && (i*prime[j]<=n);j++)
		{
			vis[i*prime[j]] = false;
			if(i%prime[j] == 0)
				break;
		}
	}
}
int main()
{
		while(scanf("%d",&n)!=EOF)
		{
			cnt=0;
			get_prime();
			printf("%d\n",cnt);
		}
	return 0;
}