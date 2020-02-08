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
	//加载图像
	Mat image = imread("D:/秦嘉豪/华五_暖憶/图标/下载.jpg");

	if (image.empty())
	{
		cout << "can not find the image!" << endl;
	}

	//显示图像
	imshow("均值滤波【原图】", image);

	//进行均值滤波操作
	Mat dstImage;

	//使用7x7内核降噪
	blur(image, dstImage, Size(7, 7));

	//显示效果图
	imshow("均值滤波【效果图】", dstImage);

	waitKey(0);

	return 0;
}