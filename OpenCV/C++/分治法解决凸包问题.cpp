#include <opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/opencv.hpp>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include <algorithm>

using namespace std;
using namespace cv;

Point p[101];   //初始值
Point mid[101];   //中间结果
Point result[101];    //顺序排序下的结果

int n;

// 排序用到的函数
bool Cmp(const Point &a, const Point &b)
{
	if (a.x != b.x) {
		return a.x < b.x;
	}
	else
		return a.y < b.y;
}

int visit[101], mark[101];

// 用于判断
int Djudge(Point a1, Point a2, Point a3) {
	int ca = a1.x * a2.y + a3.x*a1.y + a2.x*a3.y - a3.x*a2.y - a2.x*a1.y - a1.x*a3.y;
	return ca;
}

//主要实现分治
void DealLeft(int first, int last) {
	int max = 0, index = -1;
	int i = first;
	if (first < last) {
		for (i = first + 1; i < last; i++) {
			int calcu = Djudge(p[first], p[i], p[last]);
			if (calcu == 0)
				visit[i] = 1;
			if (calcu > max) {
				max = calcu;
				index = i;
			}
		}
	}
	else {
		for (i = i - 1; i > last; i--) {
			int calcu = Djudge(p[first], p[i], p[last]);
			if (calcu == 0)
				visit[i] = 1;
			if (calcu > max) {
				max = calcu;
				index = i;
			}
		}
	}
	if (index != -1) {
		visit[index] = 1;
		DealLeft(first, index);
		DealLeft(index, last);
	}
}

int main()
{
	int top = 0;
	RNG& rng = theRNG();

	Mat img(600, 600, CV_8UC3);
	img.setTo(255);
	line(img, Point(300, 0), Point(300, 600), Scalar(0, 0, 255), 2);
	line(img, Point(0, 300), Point(600, 300), Scalar(0, 0, 255), 2);

	while (cin >> n) {

		for (int i = 0; i < n; i++) {
			cin >> p[i].x >> p[i].y;
			visit[i] = 0;
			Point p0(300 + p[i].x, 300 + p[i].y);
			circle(img, p0, 3, Scalar(rng.uniform(0, 255),
				rng.uniform(0, 255), rng.uniform(0, 255)), FILLED, LINE_AA);
		}

		sort(p, p + n, Cmp);
		visit[0] = 1;
		visit[n - 1] = 1;
		DealLeft(0, n - 1);
		DealLeft(n - 1, 0);

		for (int i = 0; i < n; i++)
			if (visit[i] == 1) {
				mid[top++] = p[i];
			}

		mark[0] = mark[top - 1] = 1;
		for (int i = 1; i < top - 1; i++)
			mark[i] = 0;  //标记数组初始化

		int t = 0;  //循环变量
		result[t++] = mid[0];
		for (int i = 1; i < top - 1; i++) {
			int d = Djudge(mid[0], mid[top - 1], mid[i]);
			if (d <= 0)
			{
				result[t++] = mid[i];
				mark[i] = 1;
			}
		}
		result[t++] = mid[top - 1];
		for (int i = top - 1; i >= 1; i--) {
			if (mark[i] != 1) {
				int d = Djudge(mid[0], mid[top - 1], mid[i]);
				if (d > 0)
					result[t++] = mid[i];
			}
		}

		cout << '(' << result[0].x << ',' << result[0].y << ')';

		Point point0(300 + result[0].x, 300 + result[0].y);
		for (int i = 1; i < top; i++)
		{
			cout << ' ' << '(' << result[i].x << ',' << result[i].y << ')';
			Point point(300 + result[i].x, 300 + result[i].y);
			line(img, point0, point, Scalar(255, 0, 255), 2);
			point0 = point;
		}
		Point point1(300 + result[0].x, 300 + result[0].y);
		Point point2(300 + result[top - 1].x, 300 + result[top - 1].y);
		line(img, point2, point1, Scalar(255, 0, 255), 2);

		imshow("分治法解决凸包问题", img);
		waitKey(0);

		cout << endl;
	}
	return 0;
}