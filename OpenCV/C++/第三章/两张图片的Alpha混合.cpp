#include <opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/opencv.hpp>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>

#define WINDOWS_NAME "�����Ի��ʾ����"

using namespace std;
using namespace cv;

//ȫ�ֱ�������
const int g_nMaxAlphaValue = 100; //Alpha�����ֵ
int g_nAlphaValueSlider;  //��������Ӧ�ı���
double g_dAlphaValue;
double g_dBetaValue;

//��������ͼ��ı���
Mat g_srcImageA;
Mat g_srcImageB;
Mat g_dstImage;

void on_Trackbar(int, void *)
{
	//�����ǰ��Alphaֵ��ռ�ı���
	g_dAlphaValue = (double)g_nAlphaValueSlider / g_nMaxAlphaValue;

	//beteֵΪ1��ȥAlpha��ֵ
	g_dBetaValue = (1.0 - g_dAlphaValue);

	//���ݵ�ǰ��Alpha��ֵ��betaֵ�������Ի��
	addWeighted(g_srcImageA, g_dAlphaValue, g_srcImageB, g_dBetaValue, 0.0, g_dstImage);

	//��ʾЧ��ͼ
	imshow(WINDOWS_NAME, g_dstImage);
}

int main()
{
	//����ͼ������ͼƬ�Ĵ�С�ߴ������ȣ�
	g_srcImageA = imread("D://�ؼκ�//Pictures//1_170621165119_1.jpg");
	g_srcImageB = imread("D://�ؼκ�//Pictures//1_170621165119_11.jpg");
	if (!g_srcImageA.data) {
		cout << "can not find the imageA!" << endl;
		return -1;
	}
	if (!g_srcImageB.data) {
		cout << "can not find the imageB!" << endl;
		return -1;
	}

	//���û�����ʼֵ
	g_nAlphaValueSlider = 70;

	//��������
	namedWindow(WINDOWS_NAME, 1);

	//�ڴ����д���һ��������
	char TrackbarName[50];
	sprintf_s(TrackbarName, "͸��ֵ %d", g_nMaxAlphaValue);

	createTrackbar(TrackbarName, WINDOWS_NAME, &g_nAlphaValueSlider,
		g_nMaxAlphaValue, on_Trackbar);

	//����ڻص���������ʾ
	on_Trackbar(g_nAlphaValueSlider, 0);

	//�����������
	waitKey(0);

	return 0;
}