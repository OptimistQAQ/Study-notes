#include <opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/opencv.hpp>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>

using namespace std;
using namespace cv;

#define	WINDOW_NAME "�����򴰿ڡ�"

// ȫ�ֺ���������
void on_MouseHandle(int enent, int x, int y, int flags, void* param);
void DrawRectangle(cv::Mat& img, cv::Rect box);

//ȫ�ֱ���������
Rect g_rectangle;  //���Ʒ���
bool g_bDrawingBox = false;  //�Ƿ���л���
RNG g_rng(12345);

//���ص�����
void on_MouseHandle(int event, int x, int y, int flags, void* param)
{
	Mat image = *(cv::Mat*) param;
	switch (event)
	{
		// ����ƶ���Ϣ
	case EVENT_MOUSEMOVE:
	{
		// ������л��Ƶı�ʶ��Ϊ�棬���¼�³��Ϳ�RECT��������
		if (g_bDrawingBox)
		{
			g_rectangle.width = x - g_rectangle.x;
			g_rectangle.height = y - g_rectangle.y;
		}
	}
	break;

	case EVENT_LBUTTONDOWN:
	{
		g_bDrawingBox = true;
		g_rectangle = Rect(x, y, 0, 0);
	}
	break;

	case EVENT_LBUTTONUP:
	{
		// ��ʶ������Ϊfalse
		g_bDrawingBox = false;

		// ���ڿ�͸�С��0�Ĵ���
		if (g_rectangle.width < 0)
		{
			g_rectangle.x += g_rectangle.width;
			g_rectangle.width *= -1;
		}

		if (g_rectangle.height < 0)
		{
			g_rectangle.y += g_rectangle.height;
			g_rectangle.height *= -1;
		}

		// ���ú������л���
		DrawRectangle(image, g_rectangle);
	}
	break;
	default:
		break;
	}
}

void DrawRectangle(cv::Mat& img, cv::Rect box)
{
	rectangle(img, box.tl(), box.br(), Scalar(g_rng.uniform(0, 255),
		g_rng.uniform(0, 255), g_rng.uniform(0, 255)));  //�����ɫ
}

int main()
{
	// 1. ׼������
	g_rectangle = Rect(-1, -1, 0, 0);
	Mat srcImage(600, 800, CV_8UC3), tempImage;
	srcImage.copyTo(tempImage);
	g_rectangle = Rect(-1, -1, 0, 0);
	srcImage = Scalar::all(0);

	// 2. �����������ص�����
	namedWindow(WINDOW_NAME);
	setMouseCallback(WINDOW_NAME, on_MouseHandle, (void *)&srcImage);

	// 3. ������ѭ��
	// �����л��Ƶ�ͼ��Ϊ��ʱ�����л���
	while (1)
	{
		// ����ԭͼ����ʱ����
		srcImage.copyTo(tempImage);
		if (g_bDrawingBox)
			DrawRectangle(tempImage, g_rectangle);
		imshow(WINDOW_NAME, tempImage);
		// ��ESC�˳�
		if (waitKey(10) == 27)
			break;
	}
	return 0;
}