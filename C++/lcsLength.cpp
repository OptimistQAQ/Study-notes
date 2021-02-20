#include<iostream>
#include <string.h>

using namespace std;

char a[10], b[10];
char num[11][11];  //记录中间结果
char flag[11][11];  //标记数组

void lcs()
{
    int i, j;
    for(i=1; i<=strlen(a); i++)
        for(j=1; j<=strlen(b); j++){
            if (a[i-1] == b[j-1]){
                num[i][j] = num[i-1][j-1] + 1;  //斜向下
                flag[i][j] = 1;
            }
            else if(num[i][j-1] > num[i-1][j]){
                num[i][j] = num[i][j-1];   //向右
                flag[i][j] = 2;
            }
            else{  //向下
                num[i][j] = num[i-1][j];
                flag[i][j] = 3;
            }
        }
}

void getLCS()
{
    char res[11];
    int i = strlen(a);
    int j = strlen(b);
    int k = 0;  //保存结果的数组标志位

    while(i>0 && j>0){
        if(flag[i][j] == 1){
            res[k] = a[i-1];
            
            k++;
            i--;
            j--;
        }
        else if(flag[i][j] == 2)
            j--;
        else if(flag[i][j] == 3)
            i--;
    }
    for(i=k-1; i>=0; i--)
        printf("%c", res[i]);
}

int main()
{
    scanf("%s", a);
    scanf("%s", b);
    int i = strlen(a);
    int j = strlen(b);
    memset(num, 0, sizeof(num));
    memset(flag, 0, sizeof(flag));
    lcs();
    printf("%d\n", num[i][j]);
    cout << "最长公共子序列为：" << endl;
    getLCS();
    return 0;
}