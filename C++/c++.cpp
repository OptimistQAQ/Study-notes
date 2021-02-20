#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string> 
#include<stack>

using namespace std;

int main()
{
	int n;
	string s;
	map<string,int>mp;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		mp[s]++;
	}
	map<string,int> ::iterator ite=mp.begin();
	map<string,int> ::iterator it=mp.begin();
	int re=ite->second;
	for(;ite!=mp.end();ite++){
		if(ite->second>re){
			re=ite->second;
			it=ite;
		}
	}
	cout<<it->first<<endl;
	return 0;
}
