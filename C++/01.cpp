#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<string.h>
#include<vector>
#include<math.h>

using namespace std;

int main(){
	int a, b, c;
	for (int i=100; i <1000; i++){
		a = i/100;
		b = i % 100 /10;
		c = i % 10;
		if (a*a*a+b*b*b+c*c*c == i){
			cout << i << endl;
		}
	}
	return 0;
}

//int f[20190324];
//
//int main(){
//	f[0]=f[1]=f[2]=1;
//	for (int i=3; i<20190324; i++){
//		f[i] = (f[i-1] + f[i-2] + f[i-3]) % 10000;
//	}
//	cout << f[20190323] << endl;
//	return 0;
//}


//int main(){
//	string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//	char ans[5];
//	int index = 0;
//	int n = 2019;
//	while(n) {
//		int t = n % 26;
//		n = n / 26;
//		ans[index] = str[t-1];
//		index++;
//	}
//	for (int i=index-1; i >= 0; i--){
//		cout << ans[i];
//	}
//	return 0;
//}



//int check(int n){
//	while(n){
//		int t = n % 10;
//		n = n /10;
//		if(t==2 || t==0 || t==1 || t==9)
//			return 1;
//	}
//	return 0;
//}
//
//int main(){
//	int n;
//	int sum = 0;
//	cin >> n;
//	for (int i=1; i <= n; i++){
//		if(check(i)){
//			sum += i;
//		}
//	}
//	cout << sum << endl;
//	return 0;
//} 



//const int maxn = 1004;
//const double MAX = 1e9;
//
//int n;
//double a[maxn][maxn], d[maxn], ans;
//bool v[maxn];
//
//typedef struct
//{
//    int x;
//    int y;
//    int h;
//} point;
//
//point p[maxn];
//
//void init()
//{
//    for(int i = 0; i <= n; i++)
//    {
//        for(int j = 0; j <= n; j++)
//            a[i][j] = MAX;
//        d[i] = MAX;
//    }
//}
//
//void Prim()
//{
//    memset(v, 0, sizeof(v));
//    d[1] = 0;
//    for(int i = 1; i < n; i++)
//    {
//        int x = 0;
//        for(int j = 1; j <= n; j++)
//            if(!v[j] && (x == 0 || d[j] < d[x])) x = j;
//        v[x] = 1;
//        for(int y = 1; y <= n; y++)
//            if(!v[y]) d[y] = min(d[y], a[x][y]);
//    }
//}
//
//
//int main()
//{
//    cin>>n;
//    init();
//    for(int i = 1; i <= n; i++)
//        scanf("%d %d %d", &p[i].x, &p[i].y, &p[i].h);
//
//    for(int i = 1; i <= n - 1; i++)
//        for(int j = i + 1; j <= n; j++)
//        {
//            double temp = sqrt( (p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y-p[j].y) * (p[i].y-p[j].y)) + (p[i].h-p[j].h) * (p[i].h-p[j].h);
//            a[i][j] = a[j][i] = min(a[i][j], temp);
//        }
//
//    Prim();
//
//    for(int i = 2; i <= n; i++) ans += d[i];
//    printf("%.2f", ans);
//
//    return 0;
// } 

