#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int* milk=new int[n+1];
		for(int i=1;i<=n;i++)
			cin>>milk[i];
		sort(milk+1,milk+n+1);
		cout<<milk[n/2+1]<<endl;
		delete milk;
	}
	return 0;
}