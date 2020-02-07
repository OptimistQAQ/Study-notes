#include<stdio.h>
#include<iostream>
#include<stack>
#include<vector>
#include<map>
#include<string.h>
#include<set>
#include<algorithm>
#include<list>
#include<queue>
#include<string>

using namespace std;

int a[100010], n, m;

bool check(int k)
{
	int cnt = a[0],num=1;
	for (int i = 1; i < n; i++)
	{
		if (a[i] - cnt > k)
		{
			cnt = a[i];
			num++;
		}
		if (num == m)
			return true;
	}
	return false;
}

int main()
{
	int mid,i, l, r;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		for (i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		sort(a,a+n);
		l = a[0]; r = 1000000000;
		while (r-l>1)
		{
			mid = (l + r) / 2;
			if (check(mid))
				l = mid;
			else
				r = mid;
		}
		printf("%d\n", l+1);
	}
	return 0;
}