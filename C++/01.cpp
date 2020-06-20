//#include<stdio.h>
//#include<iostream>
//#include<algorithm>
//#include<set>
//#include<map>
//#include<string>
//#include<string.h>
//#include<vector>
//#include<math.h>
//
//using namespace std;
//
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

#include <iostream>
#include <cmath>
using namespace std;
int main(){
	double q, t, r, u, x, x1, x2,n1,e1,e0=1.602;
	double p1 = 981,g = 9.80,l = 2.00e-3,b = 8.23e-3,p = 0.101e6,d = 5.00e-3,n = 1.83e-5;
	cout<<"先输入时间,再输入电压:"<<endl;
	cin>>t>>u;
	r = sqrt(9 * n*l / (2 * p1*g*t));
	x1 = ((n*l) / (t*(1 + b / (p*r))));
	x2 = x1*x1*x1;
	x = sqrt(x2);
	q = 18 * 3.14*x*d / (sqrt(2 * p1*g)*u);
	n1=q/(1.6e-19);
	if(n1-int(n1)>=0.5) n1=int(n1)+1;
	else if(n1-int(n1)<0.5||n1-int(n1)>=0) n1=int(n1);
	else cout<<"error";
	e1=q/n1;
	cout<<"半径为r="<<r<<endl; 
	cout<<"油滴所带电量q="<<q<<endl;
	cout<<"实验数据所得电荷量e="<<e1<<endl;
	cout<<"基本电荷相对误差结果u="<<abs(100*(e1*1e19-e0)/e0)<<"%"<<endl;
	system("pause");
	return 0;
}

