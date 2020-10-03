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

int main()
{
	
	return 0;
}

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

