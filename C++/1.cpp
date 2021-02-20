#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<string.h>
#include<queue>
#include<stack>
#include<list>
#include<set>
#include<vector> 

using namespace std;

int main(){
	
	
//	int n,k,shu;
//	string s;
//	while(scanf("%d",&n) != EOF){
//		multiset<int>se;
//		scanf("%d",&k);
//		for(int i=0;i<n;i++){
//			cin>>s;
//			if(s == "I"){
//				cin >> shu;
//				se.insert(shu);
//				if(se.size() > k){
//					se.erase(se.begin());
//				}
//			}
//			else
//			cout<< *se.begin() << endl;
//		}
//	}

	long long a=0;
	for(int i=1;i<=100000;i++)
		a += i;
	printf("%lld ",a); 
	
	return 0;
} 

//const int maxn = 10005;
//int n,m;
//int pre[maxn];
//
//void init(){
//	for(int i=1;i<=n;i++){
//		pre[i] = i;
//	}
//}
//
//int find(int x){
//	return x==pre[x]?x:pre[x]=find(pre[x]);
//}
//
//int main(){
//	while(scanf("%d%d",&n,&m)!=EOF && n) {
//		init();
//		int ans = n-1;
//		int a,b;
//		for(int i=0;i<m;i++){
//			scanf("%d%d",&a,&b);
//			int fx = find(a);
//			int fy = find(b);
//			if(fx != fy){
//				ans--;
//				pre[fx]=fy;
//			}
//		}
//		printf("%d\n",ans);
//	}
//}
