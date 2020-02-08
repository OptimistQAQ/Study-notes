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

	imshow("��ԭͼ����ʾͼ��", image);
	Mat greyImage, edge; //��������

	//[one] ��ԭͼת��Ϊ�Ҷ�ͼ��
	cvtColor(image, greyImage, COLOR_BGR2GRAY);
	
	//[two] ��ʹ��3 X 3�ں˽���
	blur(greyImage, edge, Size(3, 3));

	//[three] ����Canny����
	Canny(edge, edge, 3, 9, 3);

	//[four] ��ʾЧ��ͼ
	imshow("��ֵ�˲���Ч��ͼ��", edge);
	
	//�����������
	waitKey(0);
	return 0;
}