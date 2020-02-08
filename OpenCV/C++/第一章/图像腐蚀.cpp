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

	imshow("腐蚀操作【原图】", image);

	//进行腐蚀操作
	Mat eleImage = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat dstImage;
	erode(image, dstImage, eleImage);

	imshow("腐蚀操作【效果图】", dstImage);
	
	waitKey(0);

	return 0;
}