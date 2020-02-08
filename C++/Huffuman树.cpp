#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<set>

using namespace std;

const int MAX = 1001;

//Ì°ÐÄÎÊÌâ 
int main()
{
	int i,n,sum = 0;
	int temp;
	int a[MAX];
	cin >> n;
	for(i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	i = 1;
	while(i<n){
		a[i] += a[i-1];
		sum += a[i];
		sort(a+i, a+n);
		i++;
	}
	cout << sum << endl;
	return 0;
} 
