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

int cal(int n, int p) {
        if(n < p) return 0;
        else return n / p + cal(n / p, p);
}

int main() {
	int n, k;
	while(cin>>n>>k) {
        if(2*k>n)  k=n-k;
        for(int i=1,m=1;prime[i]<=n,i<t;i++)
                m*=(cal(n,prime[i])-cal(k,prime[i])-cal(nk, prime[i])+1);  
        printf("%d/n",m);
	}
	return 0;
}

//const int N=1010;
//int n, k, ans, a[N];
//
//void swap(int x, int y) {
//	int z=a[x];
//	a[x] = a[y];
//	a[y] = z;
//	return;
//}
//
////判断a[x]是不是转折点 
//bool pd(int x) {
//	if(a[x] > a[x-1] && a[x] > a[x+1] || a[x] < a[x-1] && a[x] < a[x+1]) {
//		return 1;
//	}
//	return 0;
//}
//
////m为递归层数，sum为已经有的转折点数量 
//void dfs(int m, int sum) {
//	if(m>2 && pd(m-2)) //判断a[m-2]是不是转折点 
//		sum++;
//	if(sum>k-1 || sum+n-m<k-1)
//		return;
//	if(m==n-1)//全排列到递归出口
//	{
//		if(m>1 && pd(m-1))
//			sum++;
//		if(sum==k-1)
//			ans++;
//		return;
//	}
//	//全排列
//	for (int i=m; i<n; i++) {
//		swap(m, i);
//		dfs(m+1, sum);
//		swap(m, i);
//	}
//	for (int i=m; i<n; i++) {
//		cout << i << " ";
//	}
//	cout << endl;
//	return;
//}
//
//int main() {
//	cin >> n >> k;
//	for (int i=0; i<n; i++)
//		a[i] = i+1;
//	dfs(0,0);
//	cout << ans << endl;
//	return 0;
//}


//int main() {
//	
//	int t = 2019*2019;
//	for (int x=2020;;x++) {
//		int x2=x*x;
//		int y2=2 * x2 - t;
//		int y = sqrt(y2);
//		if (y*y==y2) {
//			cout << x+y << endl;
//			break;
//		}
//	}
//	
//	return 0;
//}

//const int N=1010;
//int dp[N][N];
//string s, t;
//
//int main() {
//	cin >> s >> t;
//	int ls = s.size();
//	int lt = t.size();
//	if(s[0] != t[0])
//		dp[0][0] = 1;
//	
//	for (int i=1; i<lt; i++){
//		if(s[i]==t[i])
//			dp[i][i] = dp[i-1][i-1];
//		else
//			dp[i][i] = dp[i-1][i-1] + 1; 
//	}
//	
//	for(int i=1; i<ls; i++) {
//		if(s[i] == t[0])
//			dp[i][0]=0;
//		else
//			dp[i][0] = dp[i-1][0];
//	}
//	
//	for (int j=1; j<lt; j++) {
//		for (int i=j+1; i<ls; i++) {
//			if(s[i] == t[j])
//				dp[i][j] = dp[i-1][j-1];
//			else
//				dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]+1);
//		}
//	}
//	
//	printf("%d\n", dp[ls-1][lt-1]);
//	
//	return 0;
//}



//int main() {
//	for (int i=100; ; i++) {
//		int sum = 0;
//		for (int j=1; j<=i; j++) {
//			if (i%j == 0)
//				sum++;
//		}
//		if (sum == 100) {
//			cout << i << endl;
//			break;
//		}
//	}
//	return 0;
//}





//typedef long long ll;
//const int N=25;
//int ans;
//bool vis[N][N];
//int b[4][2] = {{0,1},{0, -1}, {1, 0}, {-1, 0}};
//
//void dfs(int x, int y, int k) {
//	if (k > 12)
//		return;
//	for (int i=0; i<4; i++) {
//		int tx = x + b[i][0];
//		int ty = y + b[i][1];
//		if (!tx && !ty && k+1>2 && k+1<=12)
//			ans++;
//		if (tx<0 || tx >7 || ty < 0 || ty > 7)
//			continue;
//		if (vis[tx][ty])
//			continue;
//		vis[tx][ty] = 1;
//		dfs(tx, ty, k+1);
//		vis[tx][ty] = 0;
//	}
//	return ;
//}
//
//int main() {
//	vis[0][0] = 1;
//	dfs(0, 0, 0);
//	vis[0][0] = 0;
//	cout << ans << endl;
//	return 0;
//}



//int main() {
//	int t = 2019 * 2019;
//	for(int x=2020;;x++) {
//		int x2 = x*x;
//		int y2 = 2 * x2 - t;
//		int y = sqrt(y2);
//		if (y * y == y2) {
//			cout << x+y << endl;
//			break;
//		}
//	}
//	return 0;
//}



//int main(){
//	int a, b, c;
//	for (int i=100; i <1000; i++){
//		a = i/100;
//		b = i % 100 /10;
//		c = i % 10;
//		if (a*a*a+b*b*b+c*c*c == i){
//			cout << i << endl;
//		}
//	}
//	return 0;
//}

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

