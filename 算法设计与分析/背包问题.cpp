#include<iostream>
#include<string>

using namespace std;

/*
输入：

5
4
2 1 3 2
12 10 20 15

*/

int w[11];   //重量
int v[11];   //价值

int result[11][11];    

int f(int i, int j)
{
	if (i == 0 && w[i] <= j)
		return v[i];
	if (i == 0 && w[i] > j)
		return 0;

	if (i != 0 && j - w[i] >= 0)
		return (result[i - 1][j - w[i]] + v[i]) > result[i - 1][j] ?
		(result[i - 1][j - w[i]] + v[i]) : result[i - 1][j];
	else
		return result[i - 1][j];
}

int getResult(int top, int num)
{
	if (num == 0)
		return 0;
	else
	{
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j <= top; j++)
			{
				result[i][j] = f(i, j);
			}
		}

		cout << "\n结果为：" << endl;
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j <= top; j++)
				cout << result[i][j] << " ";
			cout << endl;
		}

		return result[num - 1][top];
	}
}

int main()
{
	int top;  //背包容量
	int num;   //数量

	cout << "请输入背包容量：" << endl;
	cin >> top;
	cout << "请输入物品数量："  << endl;
	cin >> num;
	cout << "请输入物品重量：" << endl;
	for (int i = 0; i < num; i++)
		cin >> w[i];
	cout << "请输入物品价值：" << endl;
	for (int i = 0; i < num; i++)
		cin >> v[i];

	cout << "\n最大容量为：" << endl << getResult(top, num) << endl;
	system("pause");
	return 0;
}