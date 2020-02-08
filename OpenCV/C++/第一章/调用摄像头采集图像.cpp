#include <opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/opencv.hpp>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>

using namespace std;
using namespace cv;

int main()
{
	// 1. 从摄像头读入视频
	VideoCapture capture(0);
	Mat edges;

	// 2. 循环显示每一帧
	while (1)
	{
		// 1. 读入图像
		Mat frame;  //定义Mat变量，用于储存每一帧的图像
		capture >> frame;  // 读取当前帧

		// 2. 将原图转为灰度图
		cvtColor(frame, edges, COLOR_BGR2GRAY); //转化RGB彩图为灰度图

		// 3. 使用3x3内核降噪(2x3+1=7)
		blur(edges, edges, Size(7, 7));

		// 4. 进行canny边缘检测并显示
		Canny(edges, edges, 0, 30, 3);

		imshow("被canny后的视频", edges);  //显示当前帧
		if (waitKey(30) >= 0)
			break;
	}
	return 0;
}