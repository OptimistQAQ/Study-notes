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

	imshow("【原图】显示图像", image);
	Mat greyImage, edge; //参数定义

	//[one] 将原图转化为灰度图像
	cvtColor(image, greyImage, COLOR_BGR2GRAY);
	
	//[two] 先使用3 X 3内核降噪
	blur(greyImage, edge, Size(3, 3));

	//[three] 运行Canny算子
	Canny(edge, edge, 3, 9, 3);

	//[four] 显示效果图
	imshow("均值滤波【效果图】", edge);
	
	//按任意键结束
	waitKey(0);
	return 0;
}