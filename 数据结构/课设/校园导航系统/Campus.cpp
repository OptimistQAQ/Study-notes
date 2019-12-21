#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>
#include<math.h>
#include<graphics.h>
#include<conio.h>

/*
*****�����Ժ��ٸ�����ʱ�����������ʵ�ֹ��ܣ���Ҫ�Ľṹ�嶨��ʹ����������� ��������˽�һ�£���ʲô��������Ⱥ������
*****�ȰѾ�����Ϣ���޸��ˣ�Ȼ���ҾͿ��Ա�д�Ӻ������¹����ˣ������������Ū
*/

const int MaxViewNum = 50;   //�궨����󾰵�ĸ���
const int N = 16;  //���嵱ǰ�ľ�������
const int MaxRoad = 10000;   //����·��Ϊ�����

typedef struct //������Ϣ
{
	char name[30];   //��������
	char number[10]; //�������
	char introduction[200];  //�������
}elemInfo;

typedef struct
{
	int num;  //������
	elemInfo data;  //������Ϣ
}viewInfo;

typedef struct
{
	viewInfo view[MaxViewNum];   //���ڴ�Ŷ���
	int length[MaxViewNum][MaxViewNum];   //���ڴ��·������
	int m, n;
}MGraph;

MGraph mGr;   //����MGraph���͵�ȫ�ֱ���
int shortest[MaxViewNum][MaxViewNum];    //����ȫ�ֱ���������С·��

/*
****�����ѧУ��Ϣ�������ž����޸ģ����ǵ�һ���������޸������ǲ������½��С���סҪ����ͼƬ�������ڽṹ�������һ������
*/
void init() //ѧУ��Ϣ���� 
{
	int i, j;
	mGr.view[1].num = 1;
	strcpy(mGr.view[1].data.name, "ѧУ����");
	strcpy(mGr.view[1].data.number, "001");
	strcpy(mGr.view[1].data.introduction, "�����ֵ�ѧԺ·3�ţ�����»���");

	mGr.view[2].num = 2;
	strcpy(mGr.view[2].data.name, "�»�¥");
	strcpy(mGr.view[2].data.number, "002");
	strcpy(mGr.view[2].data.introduction, "15��ѧ¥��");

	mGr.view[3].num = 3;
	strcpy(mGr.view[3].data.name, "�о�����Ԣ");
	strcpy(mGr.view[3].data.number, "003");
	strcpy(mGr.view[3].data.introduction, "�о���ס������");

	mGr.view[4].num = 4;
	strcpy(mGr.view[4].data.name, "���⹫԰");
	strcpy(mGr.view[4].data.number, "004");
	strcpy(mGr.view[4].data.introduction, "��·���⹫԰��");

	mGr.view[5].num = 5;
	strcpy(mGr.view[5].data.name, "�������");
	strcpy(mGr.view[5].data.number, "005");
	strcpy(mGr.view[5].data.introduction, "�б���ѧ��������¥��");
	
	mGr.view[6].num = 6;
	strcpy(mGr.view[6].data.name, "����԰");
	strcpy(mGr.view[6].data.number, "006");
	strcpy(mGr.view[6].data.introduction, "it's very beautiful��");

	mGr.view[7].num = 7;
	strcpy(mGr.view[7].data.name, "��������");
	strcpy(mGr.view[7].data.number, "007");
	strcpy(mGr.view[7].data.introduction, "����ʳ�á����ʳ�á����͸���������ȸ���ʳ�á�");

	mGr.view[8].num = 8;
	strcpy(mGr.view[8].data.name, "���ٳ�");
	strcpy(mGr.view[8].data.number, "008");
	strcpy(mGr.view[8].data.introduction, "����ء����������򳡡����򳡡��������Σ��ḻ�������");

	mGr.view[9].num = 9;
	strcpy(mGr.view[9].data.name, "����ɽ");
	strcpy(mGr.view[9].data.number, "009");
	strcpy(mGr.view[9].data.introduction, "̫ԭ������������");

	mGr.view[10].num = 10;
	strcpy(mGr.view[10].data.name, "����Է");
	strcpy(mGr.view[10].data.number, "010");
	strcpy(mGr.view[10].data.introduction, "��ύ����");

	mGr.view[11].num = 11;
	strcpy(mGr.view[11].data.name, "������");
	strcpy(mGr.view[11].data.number, "011");
	strcpy(mGr.view[11].data.introduction, "��������Լ��췿��������ֿ�ݼķš�");

	mGr.view[12].num = 12;
	strcpy(mGr.view[12].data.name, "��������");
	strcpy(mGr.view[12].data.number, "012");
	strcpy(mGr.view[12].data.introduction, "����ѧԺ���������赸ѧԺ��ͨ�������ĵ��á�");

	mGr.view[13].num = 13;
	strcpy(mGr.view[13].data.name, "ͼ���");
	strcpy(mGr.view[13].data.number, "013");
	strcpy(mGr.view[13].data.introduction, "�������ۣ����û������ţ������ʺ�ѧϰ��");

	mGr.view[14].num = 14;
	strcpy(mGr.view[14].data.name, "�б���¥");
	strcpy(mGr.view[14].data.number, "014");
	strcpy(mGr.view[14].data.introduction, "ѧУ���칫��ʵ��ء�");

	mGr.view[15].num = 15;
	strcpy(mGr.view[15].data.name, "УҽԺ");
	strcpy(mGr.view[15].data.number, "015");
	strcpy(mGr.view[15].data.introduction, "УҽԺ��ͬѧ�ǿ�����ҩ�ĵط����ṩ������");

	mGr.view[16].num = 16;
	strcpy(mGr.view[16].data.name, "�����");
	strcpy(mGr.view[16].data.number, "016");
	strcpy(mGr.view[16].data.introduction, "��¥�ٽ�����ڣ���ͨ�˴");

	for (i = 1; i <= N; i++)  //��·����ʼ��Ϊ�����
	{
		for (j = 1; j <= N; j++)
		{
			mGr.length[i][j] = MaxRoad;
		}
	}

	for (i = 1; i <= N; i++)  //��ʼ����С·��
	{
		shortest[i][j] = 0;
	}

	mGr.length[1][2] = mGr.length[2][1] = 100;
	mGr.length[1][6] = mGr.length[6][1] = 100;
	mGr.length[1][9] = mGr.length[9][1] = 100;
	mGr.length[2][3] = mGr.length[3][2] = 50;
	mGr.length[3][4] = mGr.length[4][3] = 50;
	mGr.length[3][6] = mGr.length[6][3] = 70;
	mGr.length[2][4] = mGr.length[4][2] = 80;
	mGr.length[6][5] = mGr.length[5][6] = 50;
	mGr.length[5][7] = mGr.length[7][5] = 50;
	mGr.length[9][10] =mGr.length[10][9] = 50;
	mGr.length[9][11] = mGr.length[11][9] = 50;
	mGr.length[10][15] = mGr.length[15][10] = 50;
	mGr.length[11][12] = mGr.length[12][11] = 50;
	mGr.length[12][13] = mGr.length[13][12] = 50;
	mGr.length[11][12] = mGr.length[12][11] = 40;
	mGr.length[12][13] = mGr.length[13][12] = 50;
	mGr.length[13][15] = mGr.length[15][13] = 80;
	mGr.length[11][14] = mGr.length[14][11] = 80;
	mGr.length[10][11] = mGr.length[11][10] = 20;
	mGr.length[4][8] = mGr.length[8][4] = 300;
	mGr.length[7][8] = mGr.length[8][7] = 200;
	mGr.length[13][8] = mGr.length[8][13] = 50;
	mGr.length[13][14] = mGr.length[14][13] = 50;
	mGr.length[8][14] = mGr.length[14][8] = 50;
	mGr.length[14][16] = mGr.length[16][14] = 100;
	mGr.length[15][12] = mGr.length[12][15] = 20;
	mGr.length[1][1] = 0;
	mGr.length[2][2] = mGr.length[6][6] = mGr.length[9][9] = 0;
	mGr.length[3][3] = mGr.length[5][5] = mGr.length[11][11] = mGr.length[10][10] = 0;
	mGr.length[4][4] = mGr.length[7][7] = mGr.length[15][15] = mGr.length[12][12] = 0;
	mGr.length[13][13] = 0;
	mGr.length[8][8] = mGr.length[14][14] = 0;
	mGr.length[16][16] = 0;
}

int main()
{
	//��ʼ������
	initgraph(640, 480);
	
	setbkcolor(RED);

	init();

	cleardevice();
	_getch();
	return 0;
}