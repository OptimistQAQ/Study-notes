#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<memory.h> 

using namespace std;

#define MAX 10000
int num[MAX];

void init(){
	memset(num, 0, sizeof(num));
	num[0] = 1;
}

void carry(){
	int i;
	for(i=0; i<MAX-1; i++){
		if(num[i]>9){
			num[i+1]+=num[i]/10;
			num[i]%=10;
		}
	}
}

void mul(int n){
	for(int i=0; i<MAX; i++)
		num[i] *= n;
	carry();
}

void output(){
	int e;
	for(int i=9999; i>=0; i--){
		if(num[i] != 0){
			e = i;
			break;
		}
	}
	
	for(int i=e; i>=0; i--){
		cout << num[i];
	}
	cout << endl;
}

int main()
{
	int n,i;
	init();
	cin >> n;
	for(i=1; i<=n; i++){
		mul(i);
	}
	output();
	return 0;
}
