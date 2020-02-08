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
	//����ͼ��
	Mat image = imread("D:/�ؼκ�/����_ů��/ͼ��/����.jpg");

	if (image.empty())
	{
		cout << "can not find the image!" << endl;
	}

	imshow("��ʴ������ԭͼ��", image);

	//���и�ʴ����
	Mat eleImage = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat dstImage;
	erode(image, dstImage, eleImage);

	imshow("��ʴ������Ч��ͼ��", dstImage);
	
	waitKey(0);

	return 0;
}