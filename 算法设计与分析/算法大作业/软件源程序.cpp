/*
1.	���������ڽӾ����������ͼ��Ӧ��Warshall�㷨�����Ĵ��ݱհ���
*/

#include<graphics.h>
#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

/*
����
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

		outtextxy(x, y, "��");
		TCHAR s[2];
		_stprintf(s, _T("%d"), k);
		outtextxy(x + 20, y, s);
		outtextxy(x + 40, y, "��ת����");
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

	gettextstyle(&f);                     // ��ȡ��ǰ��������
	_tcscpy(f.lfFaceName, _T("����"));    // ��������
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(&f);                     // ����������ʽ

	TCHAR s[3];
	InputBox(s, 3, _T("������ͼ�нڵ���Ŀ��"), _T("�ڵ�����"), _T("00"), 0, 0, false);
	num = _ttoi(s);

	outtextxy(x, y, "�������Ϊ��");
	outtextxy(x + 100, y, s);
	outtextxy(x, y + 20, "�ڽӾ���");

	int **r = (int **)malloc(sizeof(int *) *(num + 1));
	
	for (i = 0; i < num + 1; i++)
		r[i] = (int *)malloc(sizeof(int) *(num + 1));
	
	outtextxy(x, y + 20, "�ڽӾ���");

	y = 40;
	for (i = 1; i < num + 1; i++) {
		for (j = 1; j < num + 1; j++)
		{
			InputBox(s, 3, _T("�������ڽӾ���"), _T("����"), _T("00"), 0, 0, false);
			r[i][j] = _ttoi(s);
			outtextxy(x, y, s);
			x += 20;
		}
		y += 20;
		x = 0;
	}
		
	Warshall(num, r);

	y = 530;
	outtextxy(x, y, "���ձհ���");
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