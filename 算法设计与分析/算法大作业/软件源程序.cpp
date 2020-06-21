/*
1.	对由下面邻接矩阵定义的有向图，应用Warshall算法求它的传递闭包。
*/

#include<graphics.h>
#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

/*
输入
4
0 1 0 0
0 0 0 1
0 0 0 0
1 0 1 0
*/

int x = 0, y = 0;
IMAGE img;
LOGFONT f;

void Warshall(int num, int **r)
{
	int i, j, k;
	int **temp = (int **)malloc(sizeof(int *) * (num + 1));
	for (i = 0; i < num + 1; i++)
		temp[i] = (int *)malloc(sizeof(int) * (num + 1));
	y = 130;
	for (k = 1; k <= num; k++) {
		for (i = 1; i <= num; i++)
			for (j = 1; j <= num; j++)
				temp[i][j] = (r[i][j]) || (r[i][k] & r[k][j]);

		for (i = 1; i <= num; i++)
			for (j = 1; j <= num; j++)
				r[i][j] = temp[i][j];

		outtextxy(x, y, "第");
		TCHAR s[2];
		_stprintf(s, _T("%d"), k);
		outtextxy(x + 20, y, s);
		outtextxy(x + 40, y, "次转换：");
		for (i = 1; i <= num; i++) {
			y += 15;
			for (j = 1; j <= num; j++)
			{
				_stprintf(s, _T("%d"), r[i][j]);
				outtextxy(x, y, s);
				x += 20;
			}
			x = 0;
		}
		y += 40;
	}
}

int main()
{
	int i, j, num;

	initgraph(800, 650);

	loadimage(&img, _T("D:\\Program Files (x86)\\VS2017projects\\Navigation_consultation\\Navigation_consultation\\001.jpg"), 800, 650);
	putimage(0, 0, &img);

	gettextstyle(&f);                     // 获取当前字体设置
	_tcscpy(f.lfFaceName, _T("黑体"));    // 设置字体
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(&f);                     // 设置字体样式

	TCHAR s[3];
	InputBox(s, 3, _T("请输入图中节点数目："), _T("节点输入"), _T("00"), 0, 0, false);
	num = _ttoi(s);

	outtextxy(x, y, "顶点个数为：");
	outtextxy(x + 100, y, s);
	outtextxy(x, y + 20, "邻接矩阵：");

	int **r = (int **)malloc(sizeof(int *) *(num + 1));
	
	for (i = 0; i < num + 1; i++)
		r[i] = (int *)malloc(sizeof(int) *(num + 1));
	
	outtextxy(x, y + 20, "邻接矩阵：");

	y = 40;
	for (i = 1; i < num + 1; i++) {
		for (j = 1; j < num + 1; j++)
		{
			InputBox(s, 3, _T("请输入邻接矩阵："), _T("输入"), _T("00"), 0, 0, false);
			r[i][j] = _ttoi(s);
			outtextxy(x, y, s);
			x += 20;
		}
		y += 20;
		x = 0;
	}
		
	Warshall(num, r);

	y = 530;
	outtextxy(x, y, "最终闭包：");
	for (i = 1; i < num + 1; i++)
	{
		y += 15;
		x = 0;
		for (j = 1; j < num + 1; j++)
		{
			_stprintf(s, _T("%d"), r[i][j]);
			outtextxy(x, y, s);
			x += 20;
		}
	}

	system("pause");
	closegraph();
	return 0;
}