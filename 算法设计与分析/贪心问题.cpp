#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

/*
输入：
11
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14
*/

typedef struct node {
	int start;
	int end;
	bool flag = false;
}s;

s an_pai[105];

bool cmp(s a, s b) {
	return a.end < b.end;
}

int main()
{
	int n, t;
	while (scanf_s("%d", &n) != EOF && n)
	{
		t = 0;
		for (int i = 0; i < n; i++)
			scanf_s("%d%d", &an_pai[i].start, &an_pai[i].end);
		sort(an_pai, an_pai + n, cmp);
		for (int i = 0; i < n; i++)
			if (t <= an_pai[i].start) {
				an_pai[i].flag = true;
				t = an_pai[i].end;
			}

		cout << "请输出安排的活动的序号：\n";
		for (int i = 0; i < n; i++)
			if (an_pai[i].flag)
				cout << i + 1 << endl;
	}
	system("pause");
	return 0;
}