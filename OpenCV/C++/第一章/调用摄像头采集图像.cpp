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
	// 1. ������ͷ������Ƶ
	VideoCapture capture(0);
	Mat edges;

	// 2. ѭ����ʾÿһ֡
	while (1)
	{
		// 1. ����ͼ��
		Mat frame;  //����Mat���������ڴ���ÿһ֡��ͼ��
		capture >> frame;  // ��ȡ��ǰ֡

		// 2. ��ԭͼתΪ�Ҷ�ͼ
		cvtColor(frame, edges, COLOR_BGR2GRAY); //ת��RGB��ͼΪ�Ҷ�ͼ

		// 3. ʹ��3x3�ں˽���(2x3+1=7)
		blur(edges, edges, Size(7, 7));

		// 4. ����canny��Ե��Ⲣ��ʾ
		Canny(edges, edges, 0, 30, 3);

		imshow("��canny�����Ƶ", edges);  //��ʾ��ǰ֡
		if (waitKey(30) >= 0)
			break;
	}
	return 0;
}