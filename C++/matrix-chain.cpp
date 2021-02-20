/**
 * 动态规划解决矩阵连乘问题
 */
 
 #include<iostream>
 #include<string>

 using namespace std;


void calculate_Min(int i, int j, int p[], int **m, int **s){
     //若i与j不相等，m[i][j]的初值的断开位置位i的最优值
     m[i][j] = m[i][i] + m[i+1][j] + p[i-1] * p[i] * p[j];

     s[i][j] = i;

     for (int k = i; k < j; k++){
         int cu = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
         if (cu < m[i][j]){
             m[i][j] = cu;
             s[i][j] = k;
         }
     }
 }

 void matrix_Chain(int n, int p[], int **m, int **s)
 {
     for(int i = n; i >= 1; i--){
         for (int j = i; j <= n; j++)
         {
            if(i == j){
                m[i][j] = 0;
            }
            else{
                calculate_Min(i, j, p, m, s);
            }
         }
     }
 }

  void print(int i, int j, int **s){
     if(i == j){
         cout << "A" << i;
     }
     else{
         cout << "(";
         print(i, s[i][j], s);
         print(s[i][j]+1, j, s);
         cout << ")";
     }
 }


 int main()
 {
     int n;
     cin >> n;
     int *temp = new int[2 * n];
     int *p = new int[n+1];
     int **m = new int *[n + 1];
     int **s = new int *[n+1];

     for (int i=1; i <= n; i++){
         m[i] = new int[n+1];
         s[i] = new int[n+1];
     }

     for (int i=0; i < 2 * n; i++){
         cin >> temp[i];
     }

     for(int i = 0; i <= n; i++){
         p[i] = i == 0? temp[0] : temp[i*2-1];
     }

     matrix_Chain(n, p, m, s);
    //  cout << m[1][n] << endl;
     print(1, n, s);
    
     return 0;
 }