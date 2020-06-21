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

/*
10
0 0
-30 -40
-30 -50
-10 -60
50 -60
70 -50
90 -20
90 10
80 20
60 30
*/

Point p[101];   //初始值
Point result[101];  //结果
int visit[101];   //标记数组

int n;

// 用于判断
int Djudge(Point a1, Point a2, Point a3) {
	int ca = a1.x * a2.y + a3.x * a1.y + a2.x * a3.y - a3.x * a2.y - a2.x * a1.y - a1.x * a3.y;
	return ca;
}


int main()
{
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

		int a = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				int one = 0;
				for (int k = 0; k < n; k++) {
					if (k == i || k == j) {
						continue;
					}
					if (Djudge(p[i], p[j], p[k]) > 0)
						one++;
				}
				if (one == n - 2 || one == 0) {
					if (!visit[i]) {
						result[a++] = p[i];
						visit[i] = 1;
					}
					if (!visit[j]) {
						result[a++] = p[j];
						visit[j] = 1;
					}
				}
				one = 0;
				for (int k = 0; k < n; k++) {
					if (k == i || k == j)
						continue;
					if (Djudge(p[i], p[j], p[k]) < 0)
						one++;
				}
				if (one == n - 2 || one == 0) {
					if (!visit[i]) {
						result[a++] = p[i];
						visit[i] = 1;
					}
					if (!visit[j]) {
						result[a++] = p[j];
						visit[j] = 1;
					}
				}
			}
		}

		cout << '(' << result[0].x << ',' << result[0].y << ')';

		Point point0(300 + result[0].x, 300 + result[0].y);
		for (int i = 1; i < a; i++)
		{
			cout << ' ' << '(' << result[i].x << ',' << result[i].y << ')';
			Point point(300 + result[i].x, 300 + result[i].y);
			line(img, point0, point, Scalar(255, 0, 255), 2);
			point0 = point;
		}

		Point point1(300 + result[0].x, 300 + result[0].y);
		Point point2(300 + result[a - 1].x, 300 + result[a - 1].y);
		line(img, point2, point1, Scalar(255, 0, 255), 2);

		imshow("蛮力法解决凸包问题", img);
		waitKey(0);

		cout << endl;
	}
	return 0;
}