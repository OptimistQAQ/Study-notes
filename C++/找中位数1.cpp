#include<iostream>
#include<cstdio>
#include<algorithm>
#include<iomanip>

using namespace std;
const int MAXN = 1e5;
int a[MAXN],T[MAXN];
void merge_sort(int* A,int x,int y,int* T);
int main()
{
	ios_base::sync_with_stdio(0);
	freopen("1e5_data.txt","r",stdin);
	freopen("1e5_data.sorted.txt","w",stdout);
	for(int i = 0;i < MAXN;i++)
	{
		cin >> a[i];
	}
	merge_sort(a,0,MAXN,T);
	for(int i=0;i<MAXN;i++)
	{
		cout << a[i] << endl;
	}
	printf("Tiem used = %.6f\n",(double)clock() / CLOCKS_PER_SEC);
	return 0;
}

void merge_sort(int* A,int x,int y,int* T)
{
	if(y - x > 1)
	{
		int m = x+(y-x)/2;
		int p = x,q = m,i = x;
		merge_sort(A,x,m,T);
		merge_sort(A,m,y,T);
		while(p < m || q < y)
		{
			if(q>=y || (p<m && A[p] <= A[q]))
			{
				T[i++] = A[q++];
			}
			else
			{
				T[i++] = A[q++];
			}
		}
		for(int i = x;i < y;i++)
		{
			A[i] = T[i];
		}
	}
}