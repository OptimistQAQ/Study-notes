#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>
#include<math.h>
#include<graphics.h>
#include<conio.h>

const int MaxViewNum = 50;   //�궨����󾰵�ĸ���
const int N = 20;  //���嵱ǰ�ľ�������
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

typedef struct edgedata
{
	int beg, en;    //�������
	int length;    //�ߵ�Ȩֵ
}edge;

MGraph mGr;   //����MGraph���͵�ȫ�ֱ���

int shortest[MaxViewNum][MaxViewNum];    //����ȫ�ֱ���������С·��
int path[MaxViewNum][MaxViewNum];

//�б���ѧѧУ������Ϣ��ͼ�����δ�ͼ�����ڽӾ�����ʽ���д洢
void init()
{
	int i, j;
	mGr.view[1].num = 1;
	strcpy(mGr.view[1].data.name, "ѧУ����");
	strcpy(mGr.view[1].data.number, "001");
	strcpy(mGr.view[1].data.introduction, "�����ֵ�ѧԺ·3�ţ�����»���");

	mGr.view[2].num = 2;
	strcpy(mGr.view[2].data.name, "�»�¥");
	strcpy(mGr.view[2].data.number, "002");
	strcpy(mGr.view[2].data.introduction, "7�Ž�ѧ¥����Ժϵ¥���繤����ʵ�鶼�����¥����У���칫��Ҳ�����¥��");

	mGr.view[3].num = 3;
	strcpy(mGr.view[3].data.name, "����԰");
	strcpy(mGr.view[3].data.number, "003");
	strcpy(mGr.view[3].data.introduction, "С����ˮ�������Ļᣬ��ɢ���ĺõط���");

	mGr.view[4].num = 4;
	strcpy(mGr.view[4].data.name, "����ɽ");
	strcpy(mGr.view[4].data.number, "004");
	strcpy(mGr.view[4].data.introduction, "����ɽ�����еĺ�У԰�����еķ羰����ɽ�Ʋ�̫�ߣ����Ǿ�ɫ������ɽ���ʻ��鲼�������ڶ࣬����ɽ���η羰����̫ԭΪ������ı���ʤ�ء�");

	mGr.view[5].num = 5;
	strcpy(mGr.view[5].data.name, "����Է");
	strcpy(mGr.view[5].data.number, "005");
	strcpy(mGr.view[5].data.introduction, "�����ݳ���ӭ����ᣬѧУ��һЩ��Ļ��鶼��������С�");
	
	mGr.view[6].num = 6;
	strcpy(mGr.view[6].data.name, "�������¥");
	strcpy(mGr.view[6].data.number, "006");
	strcpy(mGr.view[6].data.introduction, "ѧ����ס��������Ӵ�");

	mGr.view[7].num = 7;
	strcpy(mGr.view[7].data.name, "��孲���");
	strcpy(mGr.view[7].data.number, "007");
	strcpy(mGr.view[7].data.introduction, "����ʳ�á����ʳ�á����͸���������ȸ���ʳ�ã��������������������ѧ���Ͳ͡�");

	mGr.view[8].num = 8;
	strcpy(mGr.view[8].data.name, "УҽԺ");
	strcpy(mGr.view[8].data.number, "008");
	strcpy(mGr.view[8].data.introduction, "�б���ѧУҽԺ��һ������ҽԺ���Ǹ���Ϊѧ������������ǵ�ҽԺ��С���Ļ���������ҩһ��Ҳ�ͼ���Ǯ��ȥ��ʱ����һ��ͨ�а���Żݡ�");

	mGr.view[9].num = 9;
	strcpy(mGr.view[9].data.name, "ͼ���");
	strcpy(mGr.view[9].data.number, "009");
	strcpy(mGr.view[9].data.introduction, "�����ң������㶼������ϰ���б���ѧ��ͼ���ѧϰ��Χ�ܲ������д���ͼ�顣");

	mGr.view[10].num = 10;
	strcpy(mGr.view[10].data.name, "���ٳ�");
	strcpy(mGr.view[10].data.number, "010");
	strcpy(mGr.view[10].data.introduction, "�б���ѧ�����ٳ�����ϯ̨���м�Ĳݵ�ȫ��Ϊ��ݲ�Ƥ������ֻ�����˶��ᣬ��ѵ���ݺ�һЩ���������");

	mGr.view[11].num = 11;
	strcpy(mGr.view[11].data.name, "�б���ѧ��¥");
	strcpy(mGr.view[11].data.number, "011");
	strcpy(mGr.view[11].data.introduction, "��¥��ѧУ������λ�ã�ͬѧ�ǵĿγ̴󶼰����������ϣ��ż�Ҳ�Ὺ�Ź�ѧ������ϰ��");

	mGr.view[12].num = 12;
	strcpy(mGr.view[12].data.name, "��֪�㳡");
	strcpy(mGr.view[12].data.number, "012");
	strcpy(mGr.view[12].data.introduction, "��ѧӭ�¶���������Ӵ���������ѵ�����գ��˶���ľٰ춼��������С�");

	mGr.view[13].num = 13;
	strcpy(mGr.view[13].data.name, "��·���⹫԰");
	strcpy(mGr.view[13].data.number, "013");
	strcpy(mGr.view[13].data.introduction, "�б���ѧ���ҹ�Ψһһ��У԰���л𳵵Ĵ�ѧ���������й���ʦ������ȵȡ�");

	mGr.view[14].num = 14;
	strcpy(mGr.view[14].data.name, "����ѵ������");
	strcpy(mGr.view[14].data.number, "014");
	strcpy(mGr.view[14].data.introduction, "ѧУ���칫��ʵ��أ������и��ֻ�е�豸��ͬѧ���������ʵϰ��");

	mGr.view[15].num = 15;
	strcpy(mGr.view[15].data.name, "�о���Ժ");
	strcpy(mGr.view[15].data.number, "015");
	strcpy(mGr.view[15].data.introduction, "�о�����ס������");

	mGr.view[16].num = 16;
	strcpy(mGr.view[16].data.name, "�ƾó���");
	strcpy(mGr.view[16].data.number, "016");
	strcpy(mGr.view[16].data.introduction, "���������ĳ��У���Ʒ��ȫ��������װ�ģ���С�Եģ�Ӧ�о��С�");

	mGr.view[16].num = 17;
	strcpy(mGr.view[17].data.name, "������");
	strcpy(mGr.view[17].data.number, "017");
	strcpy(mGr.view[17].data.introduction, "������ݣ������ʼ��ĵط���");

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

	mGr.length[1][2] = mGr.length[2][1] = 128;
	//mGr.length[1][13] = mGr.length[13][1] = 13;
	mGr.length[2][3] = mGr.length[3][2] = 767;
	mGr.length[2][6] = mGr.length[6][2] = 623;
	mGr.length[2][4] = mGr.length[4][2] = 540;
	mGr.length[2][13] = mGr.length[13][2] = 494;
	mGr.length[3][6] = mGr.length[6][3] = 210;
	mGr.length[3][4] = mGr.length[4][3] = 226;
	mGr.length[4][6] = mGr.length[6][4] = 242;
	mGr.length[4][14] = mGr.length[14][4] = 569;
	mGr.length[4][5] = mGr.length[5][4] = 192;
	mGr.length[6][7] = mGr.length[7][6] = 56;
	mGr.length[6][16] = mGr.length[16][6] = 274;
	mGr.length[6][13] = mGr.length[13][6] = 270;
	mGr.length[5][14] = mGr.length[14][5] = 435;
	mGr.length[5][17] = mGr.length[17][5] = 9;
	mGr.length[5][16] = mGr.length[16][5] = 88;
	mGr.length[7][16] = mGr.length[16][7] = 185;
	mGr.length[7][10] = mGr.length[10][7] = 328;
	mGr.length[7][13] = mGr.length[13][7] = 243;
	mGr.length[8][17] = mGr.length[17][8] = 439;
	mGr.length[8][9] = mGr.length[9][8] = 422;
	mGr.length[8][16] = mGr.length[16][8] = 326;
	mGr.length[9][10] =mGr.length[10][9] = 186;
	mGr.length[9][11] = mGr.length[11][9] = 53;
	mGr.length[9][16] = mGr.length[16][9] = 290;
	mGr.length[10][13] = mGr.length[13][10] = 141;
	mGr.length[10][12] = mGr.length[12][10] = 104;
	mGr.length[10][11] = mGr.length[11][10] = 99;
	mGr.length[15][11] = mGr.length[11][15] = 538;
	mGr.length[15][12] = mGr.length[12][15] = 489;
	mGr.length[12][13] = mGr.length[13][12] = 464;
	mGr.length[17][14] = mGr.length[14][17] = 460;
	mGr.length[1][1] = 0;
	mGr.length[2][2] = mGr.length[6][6] = mGr.length[9][9] = 0;
	mGr.length[3][3] = mGr.length[5][5] = mGr.length[11][11] = mGr.length[10][10] = 0;
	mGr.length[4][4] = mGr.length[7][7] = mGr.length[15][15] = mGr.length[12][12] = 0;
	mGr.length[13][13] = 0;
	mGr.length[8][8] = mGr.length[14][14] = 0;
	mGr.length[16][16] = mGr.length[17][17]=0;
}


/*****************������Ϣ����***********************/
void introduce()
{
	int m;
	printf("*****************************************************\n");
	printf("*1��ѧУ����       2���»�¥          3������԰     *\n");
	printf("*4������ɽ         5������Է          6���������¥ *\n");
	printf("*7����孲���       8��УҽԺ          9��ͼ���     *\n");
	printf("*10�����ٳ�        11���б���ѧ��¥   12����֪�㳡  *\n");
	printf("*13����·���⹫԰  14������ѵ������   15���о���Ժ  *\n");
	printf("*16���ƾó���      17��������                       *\n");
	printf("*****************************************************\n\n\n");
	printf("�������ѯ������:\n");
	scanf("%d", &m); fflush(stdin);
	IMAGE bmg;
	LOGFONT f;
	switch (m)
	{
	case 1:
		system("cls");
		initgraph(640, 640);
		loadimage(&bmg, _T("D:\\Program Files (x86)\\VS2017projects\\Navigation_consultation\\Navigation_consultation\\ѧУ����.jpg"), 640, 640);
		putimage(0, 0, &bmg);
		gettextstyle(&f);                     // ��ȡ��ǰ��������
		f.lfHeight = 25;                      // ��������߶�
		_tcscpy(f.lfFaceName, _T("����"));    // ��������
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		settextstyle(&f);                     // ����������ʽ
		outtextxy(16, 350, _T("�����ţ�"));
		outtextxy(150, 350, _T(mGr.view[1].data.number));
		outtextxy(16, 380, _T("�������ƣ�"));
		outtextxy(150, 380, _T(mGr.view[1].data.name));
		outtextxy(16, 410, _T("�����飺"));
		outtextxy(150, 410, _T(mGr.view[1].data.introduction));
		system("pause");
		closegraph();
		break;

	case 2:
		system("cls");
		initgraph(640, 640);
		loadimage(&bmg, _T("D:\\Program Files (x86)\\VS2017projects\\Navigation_consultation\\Navigation_consultation\\�»�¥.jpg"), 640, 640);
		putimage(0, 0, &bmg);
		gettextstyle(&f);                     // ��ȡ��ǰ��������
		f.lfHeight = 25;                      // ��������߶�
		_tcscpy(f.lfFaceName, _T("����"));    // ��������
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		settextstyle(&f);                     // ����������ʽ
		outtextxy(16, 350, _T("�����ţ�"));
		outtextxy(150, 350, _T(mGr.view[1].data.number));
		outtextxy(16, 380, _T("�������ƣ�"));
		outtextxy(150, 380, _T(mGr.view[1].data.name));
		outtextxy(16, 410, _T("�����飺"));
		outtextxy(150, 410, _T(mGr.view[1].data.introduction));
		system("pause");
		closegraph();
		break;

	case 3:
		system("cls");
		initgraph(640, 640);
		loadimage(&bmg, _T("D:\\Program Files (x86)\\VS2017projects\\Navigation_consultation\\Navigation_consultation\\����԰.jpg"), 640, 640);
		putimage(0, 0, &bmg);
		gettextstyle(&f);                     // ��ȡ��ǰ��������
		f.lfHeight = 25;                      // ��������߶�
		_tcscpy(f.lfFaceName, _T("����"));    // ��������
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		settextstyle(&f);                     // ����������ʽ
		outtextxy(16, 350, _T("�����ţ�"));
		outtextxy(150, 350, _T(mGr.view[1].data.number));
		outtextxy(16, 380, _T("�������ƣ�"));
		outtextxy(150, 380, _T(mGr.view[1].data.name));
		outtextxy(16, 410, _T("�����飺"));
		outtextxy(150, 410, _T(mGr.view[1].data.introduction));
		system("pause");
		closegraph();
		break;

	case 4:
		system("cls");
		initgraph(640, 640);
		loadimage(&bmg, _T("D:\\Program Files (x86)\\VS2017projects\\Navigation_consultation\\Navigation_consultation\\����ɽ.jpg"), 640, 640);
		putimage(0, 0, &bmg);
		gettextstyle(&f);                     // ��ȡ��ǰ��������
		f.lfHeight = 25;                      // ��������߶�
		_tcscpy(f.lfFaceName, _T("����"));    // ��������
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		settextstyle(&f);                     // ����������ʽ
		outtextxy(16, 350, _T("�����ţ�"));
		outtextxy(150, 350, _T(mGr.view[1].data.number));
		outtextxy(16, 380, _T("�������ƣ�"));
		outtextxy(150, 380, _T(mGr.view[1].data.name));
		outtextxy(16, 410, _T("�����飺"));
		outtextxy(150, 410, _T(mGr.view[1].data.introduction));
		system("pause");
		closegraph();
		break;

	case 5:
		system("cls");
		initgraph(640, 640);
		loadimage(&bmg, _T("D:\\Program Files (x86)\\VS2017projects\\Navigation_consultation\\Navigation_consultation\\����Է.jpg"), 640, 640);
		putimage(0, 0, &bmg);
		gettextstyle(&f);                     // ��ȡ��ǰ��������
		f.lfHeight = 25;                      // ��������߶�
		_tcscpy(f.lfFaceName, _T("����"));    // ��������
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		settextstyle(&f);                     // ����������ʽ
		outtextxy(16, 350, _T("�����ţ�"));
		outtextxy(150, 350, _T(mGr.view[1].data.number));
		outtextxy(16, 380, _T("�������ƣ�"));
		outtextxy(150, 380, _T(mGr.view[1].data.name));
		outtextxy(16, 410, _T("�����飺"));
		outtextxy(150, 410, _T(mGr.view[1].data.introduction));
		system("pause");
		closegraph();
		break;

	case 6:
		system("cls");
		initgraph(640, 640);
		loadimage(&bmg, _T("D:\\Program Files (x86)\\VS2017projects\\Navigation_consultation\\Navigation_consultation\\�������¥.jpg"), 640, 640);
		putimage(0, 0, &bmg);
		gettextstyle(&f);                     // ��ȡ��ǰ��������
		f.lfHeight = 25;                      // ��������߶�
		_tcscpy(f.lfFaceName, _T("����"));    // ��������
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		settextstyle(&f);                     // ����������ʽ
		outtextxy(16, 350, _T("�����ţ�"));
		outtextxy(150, 350, _T(mGr.view[1].data.number));
		outtextxy(16, 380, _T("�������ƣ�"));
		outtextxy(150, 380, _T(mGr.view[1].data.name));
		outtextxy(16, 410, _T("�����飺"));
		outtextxy(150, 410, _T(mGr.view[1].data.introduction));
		system("pause");
		closegraph();
		break;

	case 7:
		system("cls");
		initgraph(640, 640);
		loadimage(&bmg, _T("D:\\Program Files (x86)\\VS2017projects\\Navigation_consultation\\Navigation_consultation\\��孲���.jpg"), 640, 640);
		putimage(0, 0, &bmg);
		gettextstyle(&f);                     // ��ȡ��ǰ��������
		f.lfHeight = 25;                      // ��������߶�
		_tcscpy(f.lfFaceName, _T("����"));    // ��������
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		settextstyle(&f);                     // ����������ʽ
		outtextxy(16, 350, _T("�����ţ�"));
		outtextxy(150, 350, _T(mGr.view[1].data.number));
		outtextxy(16, 380, _T("�������ƣ�"));
		outtextxy(150, 380, _T(mGr.view[1].data.name));
		outtextxy(16, 410, _T("�����飺"));
		outtextxy(150, 410, _T(mGr.view[1].data.introduction));
		system("pause");
		closegraph();
		break;

	case 8:
		system("cls");
		initgraph(640, 640);
		loadimage(&bmg, _T("D:\\Program Files (x86)\\VS2017projects\\Navigation_consultation\\Navigation_consultation\\УҽԺ.jpg"), 640, 640);
		putimage(0, 0, &bmg);
		gettextstyle(&f);                     // ��ȡ��ǰ��������
		f.lfHeight = 25;                      // ��������߶�
		_tcscpy(f.lfFaceName, _T("����"));    // ��������
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		settextstyle(&f);                     // ����������ʽ
		outtextxy(16, 350, _T("�����ţ�"));
		outtextxy(150, 350, _T(mGr.view[1].data.number));
		outtextxy(16, 380, _T("�������ƣ�"));
		outtextxy(150, 380, _T(mGr.view[1].data.name));
		outtextxy(16, 410, _T("�����飺"));
		outtextxy(150, 410, _T(mGr.view[1].data.introduction));
		system("pause");
		closegraph();
		break;

	case 9:
		system("cls");
		initgraph(640, 640);
		loadimage(&bmg, _T("D:\\Program Files (x86)\\VS2017projects\\Navigation_consultation\\Navigation_consultation\\ͼ���.jpg"), 640, 640);
		putimage(0, 0, &bmg);
		gettextstyle(&f);                     // ��ȡ��ǰ��������
		f.lfHeight = 25;                      // ��������߶�
		_tcscpy(f.lfFaceName, _T("����"));    // ��������
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		settextstyle(&f);                     // ����������ʽ
		outtextxy(16, 350, _T("�����ţ�"));
		outtextxy(150, 350, _T(mGr.view[1].data.number));
		outtextxy(16, 380, _T("�������ƣ�"));
		outtextxy(150, 380, _T(mGr.view[1].data.name));
		outtextxy(16, 410, _T("�����飺"));
		outtextxy(150, 410, _T(mGr.view[1].data.introduction));
		system("pause");
		closegraph();
		break;

	case 10:
		system("cls");
		initgraph(640, 640);
		loadimage(&bmg, _T("D:\\Program Files (x86)\\VS2017projects\\Navigation_consultation\\Navigation_consultation\\���ٳ�.jpg"), 640, 640);
		putimage(0, 0, &bmg);
		gettextstyle(&f);                     // ��ȡ��ǰ��������
		f.lfHeight = 25;                      // ��������߶�
		_tcscpy(f.lfFaceName, _T("����"));    // ��������
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		settextstyle(&f);                     // ����������ʽ
		outtextxy(16, 350, _T("�����ţ�"));
		outtextxy(150, 350, _T(mGr.view[1].data.number));
		outtextxy(16, 380, _T("�������ƣ�"));
		outtextxy(150, 380, _T(mGr.view[1].data.name));
		outtextxy(16, 410, _T("�����飺"));
		outtextxy(150, 410, _T(mGr.view[1].data.introduction));
		system("pause");
		closegraph();
		break;

	case 11:
		system("cls");
		initgraph(640, 640);
		loadimage(&bmg, _T("D:\\Program Files (x86)\\VS2017projects\\Navigation_consultation\\Navigation_consultation\\�б���ѧ��¥.jpg"), 640, 640);
		putimage(0, 0, &bmg);
		gettextstyle(&f);                     // ��ȡ��ǰ��������
		f.lfHeight = 25;                      // ��������߶�
		_tcscpy(f.lfFaceName, _T("����"));    // ��������
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		settextstyle(&f);                     // ����������ʽ
		outtextxy(16, 350, _T("�����ţ�"));
		outtextxy(150, 350, _T(mGr.view[1].data.number));
		outtextxy(16, 380, _T("�������ƣ�"));
		outtextxy(150, 380, _T(mGr.view[1].data.name));
		outtextxy(16, 410, _T("�����飺"));
		outtextxy(150, 410, _T(mGr.view[1].data.introduction));
		system("pause");
		closegraph();
		break;

	case 12:
		system("cls");
		initgraph(640, 640);
		loadimage(&bmg, _T("D:\\Program Files (x86)\\VS2017projects\\Navigation_consultation\\Navigation_consultation\\��֪�㳡.jpg"), 640, 640);
		putimage(0, 0, &bmg);
		gettextstyle(&f);                     // ��ȡ��ǰ��������
		f.lfHeight = 25;                      // ��������߶�
		_tcscpy(f.lfFaceName, _T("����"));    // ��������
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		settextstyle(&f);                     // ����������ʽ
		outtextxy(16, 350, _T("�����ţ�"));
		outtextxy(150, 350, _T(mGr.view[1].data.number));
		outtextxy(16, 380, _T("�������ƣ�"));
		outtextxy(150, 380, _T(mGr.view[1].data.name));
		outtextxy(16, 410, _T("�����飺"));
		outtextxy(150, 410, _T(mGr.view[1].data.introduction));
		system("pause");
		closegraph();
		break;

	case 13:
		system("cls");
		initgraph(640, 640);
		loadimage(&bmg, _T("D:\\Program Files (x86)\\VS2017projects\\Navigation_consultation\\Navigation_consultation\\��·���⹫԰.jpg"), 640, 640);
		putimage(0, 0, &bmg);
		gettextstyle(&f);                     // ��ȡ��ǰ��������
		f.lfHeight = 25;                      // ��������߶�
		_tcscpy(f.lfFaceName, _T("����"));    // ��������
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		settextstyle(&f);                     // ����������ʽ
		outtextxy(16, 350, _T("�����ţ�"));
		outtextxy(150, 350, _T(mGr.view[1].data.number));
		outtextxy(16, 380, _T("�������ƣ�"));
		outtextxy(150, 380, _T(mGr.view[1].data.name));
		outtextxy(16, 410, _T("�����飺"));
		outtextxy(150, 410, _T(mGr.view[1].data.introduction));
		system("pause");
		closegraph();
		break;

	case 14:
		system("cls");
		initgraph(640, 640);
		loadimage(&bmg, _T("D:\\Program Files (x86)\\VS2017projects\\Navigation_consultation\\Navigation_consultation\\����ѵ������.jpg"), 640, 640);
		putimage(0, 0, &bmg);
		gettextstyle(&f);                     // ��ȡ��ǰ��������
		f.lfHeight = 25;                      // ��������߶�
		_tcscpy(f.lfFaceName, _T("����"));    // ��������
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		settextstyle(&f);                     // ����������ʽ
		outtextxy(16, 350, _T("�����ţ�"));
		outtextxy(150, 350, _T(mGr.view[1].data.number));
		outtextxy(16, 380, _T("�������ƣ�"));
		outtextxy(150, 380, _T(mGr.view[1].data.name));
		outtextxy(16, 410, _T("�����飺"));
		outtextxy(150, 410, _T(mGr.view[1].data.introduction));
		system("pause");
		closegraph();
		break;

	case 15:
		system("cls");
		initgraph(640, 640);
		loadimage(&bmg, _T("D:\\Program Files (x86)\\VS2017projects\\Navigation_consultation\\Navigation_consultation\\�о���Ժ.jpg"), 640, 640);
		putimage(0, 0, &bmg);
		gettextstyle(&f);                     // ��ȡ��ǰ��������
		f.lfHeight = 25;                      // ��������߶�
		_tcscpy(f.lfFaceName, _T("����"));    // ��������
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		settextstyle(&f);                     // ����������ʽ
		outtextxy(16, 350, _T("�����ţ�"));
		outtextxy(150, 350, _T(mGr.view[1].data.number));
		outtextxy(16, 380, _T("�������ƣ�"));
		outtextxy(150, 380, _T(mGr.view[1].data.name));
		outtextxy(16, 410, _T("�����飺"));
		outtextxy(150, 410, _T(mGr.view[1].data.introduction));
		system("pause");
		closegraph();
		break;

	case 16:
		system("cls");
		initgraph(640, 640);
		loadimage(&bmg, _T("D:\\Program Files (x86)\\VS2017projects\\Navigation_consultation\\Navigation_consultation\\�ƾó���.jpg"), 640, 640);
		putimage(0, 0, &bmg);
		gettextstyle(&f);                     // ��ȡ��ǰ��������
		f.lfHeight = 25;                      // ��������߶�
		_tcscpy(f.lfFaceName, _T("����"));    // ��������
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		settextstyle(&f);                     // ����������ʽ
		outtextxy(16, 350, _T("�����ţ�"));
		outtextxy(150, 350, _T(mGr.view[1].data.number));
		outtextxy(16, 380, _T("�������ƣ�"));
		outtextxy(150, 380, _T(mGr.view[1].data.name));
		outtextxy(16, 410, _T("�����飺"));
		outtextxy(150, 410, _T(mGr.view[1].data.introduction));
		system("pause");
		closegraph();
		break;

	case 17:
		system("cls");
		initgraph(640, 640);
		loadimage(&bmg, _T("D:\\Program Files (x86)\\VS2017projects\\Navigation_consultation\\Navigation_consultation\\������.jpg"), 640, 640);
		putimage(0, 0, &bmg);
		gettextstyle(&f);                     // ��ȡ��ǰ��������
		f.lfHeight = 25;                      // ��������߶�
		_tcscpy(f.lfFaceName, _T("����"));    // ��������
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		settextstyle(&f);                     // ����������ʽ
		outtextxy(16, 350, _T("�����ţ�"));
		outtextxy(150, 350, _T(mGr.view[1].data.number));
		outtextxy(16, 380, _T("�������ƣ�"));
		outtextxy(150, 380, _T(mGr.view[1].data.name));
		outtextxy(16, 410, _T("�����飺"));
		outtextxy(150, 410, _T(mGr.view[1].data.introduction));
		system("pause");
		closegraph();
		break;

	default:
		printf("������Ŵ���\n");
		break;
	}

	printf("\n");
}


/**********�������� ���·��********/
void floyd()
{
	int i, j, k;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			shortest[i][j] = mGr.length[i][j];
			path[i][j] = 0;
		}
	}
	for (k = 1; k <= N; k++)
	{
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{
				if (shortest[i][j] > (shortest[i][k] + shortest[k][j]))
				{
					shortest[i][j] = shortest[i][k] + shortest[k][j];
					path[i][j] = k;
					path[j][i] = k;
				}
			}
		}
	}
}
void display(int i, int j)
{
	int a, b;
	a = i;
	b = j;
	printf("��Ҫ��ѯ������������·���ǣ� \n\n");
	fflush(stdin);
	if (i < j)
	{
		printf("%d", b);
		while (path[i][j] != 0)
		{
			printf("<--%d", path[i][j]);
			if (i < j)
				j = path[i][j];
			else
				i = path[j][i];
		}
		printf("<-%d\n\n", a);
		printf("%d->%d�����·���ǣ� %d �ס�\n\n", a, b, shortest[a][b]);
	}
	else
	{
		printf("%d", a);
		while (path[i][j] != 0)
		{
			printf("-->%d", path[i][j]);
			if (i < j)
				j = path[i][j];
			else
				i = path[j][i];
		}
		printf("->%d\n\n", b);
		printf("%d->%d�����·���ǣ� %d �ס�\n\n", a, b, shortest[a][b]);
	}
}
int shortdistance()
{
	int i, j;
	printf("*****************************************************\n");
	printf("*1��ѧУ����       2���»�¥          3������԰     *\n");
	printf("*4������ɽ         5������Է          6���������¥ *\n");
	printf("*7����孲���       8��УҽԺ          9��ͼ���     *\n");
	printf("*10�����ٳ�        11���б���ѧ��¥   12����֪�㳡  *\n");
	printf("*13����·���⹫԰  14������ѵ������   15���о���Ժ  *\n");
	printf("*16���ƾó���      17��������                       *\n");
	printf("*****************************************************\n\n\n");
	printf("������Ҫ��ѯ��������������ֱ��(1->17)�м��ÿո�������\n");
	scanf("%d %d", &i, &j);
	if (i > N || i<0 || j>N || j < 0)
	{
		printf("������Ϣ����\n");
		printf("������Ҫ��ѯ��������������ֱ�ţ�1->16���м��ÿո�������\n");
		scanf("%d %d", &i, &j);
	}
	else
	{
		floyd();
		display(i, j);
	}
	return 1;
	fflush(stdin);
}


//������������֮�������·��//
typedef struct
{
	int path[N];
	int top;
}node;

node slt;
int visited[N + 1];
int count;                              //��¼·��

void sousuo(MGraph g, int i, int j)
{
	int b, k;
	int len = 0;                          //·������
	slt.path[slt.top] = i;
	slt.top++;
	visited[i] = 1;
	for (k = 1; k <= N; k++)
	{
		if (g.length[i][k] > 0 && g.length[i][k] < MaxRoad && !visited[k])
		{
			if (k == j)
			{
				printf("��%d��·����", count++);
				for (b = 0; b < slt.top; b++)
				{
					printf("%s%s->", g.view[slt.path[b]].data.number, g.view[slt.path[b]].data.name);
					if (b < slt.top - 1)
						len = len + g.length[slt.path[b]][slt.path[b + 1]];
				}
				len = len + g.length[slt.path[slt.top - 1]][j];
				printf("%s %s\n", g.view[j].data.number, g.view[j].data.name);
				printf("·���ܳ��ȣ�%d\n", len);
			}
			else
					{
						sousuo(mGr, k, j);
						slt.top--;
						visited[k] = 0;
					}
		}
		

	}
}

void allRoad(MGraph g)
{
	slt.top = 0;
	count = 1;
	int i, j, k;
	for (k = 1; k <= N; k++)
		visited[k] = 0;
	printf("��������㣺\n");
	scanf("%d", &i);
	printf("�������յ�:\n");
	scanf("%d", &j);
	if (i == j)
	{
		printf("������յ���ͬ����·��\n"); return;
	}
	sousuo(g, i, j);
}


/******��ȱ����ؽڵ�********/
int visitable[20];
void dfs_Coila(int visi[], int a)
{
	for (int i = 1; i <= mGr.m; i++)
	{
		if (!visi[i] && mGr.length[a][i] != 0 && mGr.length[a][i] != MaxRoad)
		{
			visi[i] = 1;
			dfs_Coila(visi, i);
		}
	}
}

/*��У԰ͼ�еĹؽڵ�*/
void coila_Search(MGraph *g)
{
	int node[18];
	int num = 0;
	for (int i = 1; i <= mGr.m; i++)
	{
		for (int j = 1; j <= mGr.m; j++)
		{
			visitable[j] = 0;
		}
		visitable[i] = 1;
		if (i == 1)
		{
			for (int j = 1; j <= mGr.m; j++)
			{
				if (!visitable[j] && mGr.length[2][j] != 0 && mGr.length[2][j] != MaxRoad)
				{
					visitable[j] = 1;
					dfs_Coila(visitable, j);
				}
			}
		}
		else
		{
			for (int j = 1; j <= mGr.m; j++)
			{
				if (!visitable[j] && mGr.length[1][j] != 0 && mGr.length[1][j] != MaxRoad)
				{
					visitable[j] = 1;
					dfs_Coila(visitable, j);
				}
			}
		}
		for (int j = 1; j <= mGr.m; j++)
		{
			if (visitable[j] == 0)
			{
				node[++num] = i;
				break;
			}
		}
	}
	if (num == 0)
	{
		printf("��ͼû�йؽڵ㣡����\n");
	}
	else
	{
		printf("��ͼ�Ĺؽڵ���%d�����ֱ�Ϊ:\n", num);
		for (int j = 1; j <= num; j++)
		{
			printf("%d\t", mGr.view[node[j]].num);
			printf("%s\n", mGr.view[node[j]].data.name);
		}
	}
}


/*Kruskal�㷨����С������*/

/*�Աߵ�Ȩֵ��������*/
void quickSort(edge edges[], int left, int right)
{
	edge x;
	int i, j, flag = 1;
	if (left < right)
	{
		i = left;
		j = right;
		x = edges[i];
		while (i < j)
		{
			while (i < j && x.length < edges[j].length)
				j--;
			if (i < j)
				edges[i++] = edges[j];
			while (i<j && x.length>edges[i].length)
				i++;
			if (i < j)
				edges[j--] = edges[i];
		}
		edges[i] = x;
		quickSort(edges, left, i - 1);
		quickSort(edges, i + 1, right);
	}
}

//���鼯
int find(int parent[], int x)
{
	while (parent[x] > 0)
	{
		x = parent[x];
	}
	return x;
}

/*��Ҫ�㷨*/
void kruskal(MGraph g)
{
	edge edges[40];
	int nodes[20];
	
	for (int i = 1; i <= 17; i++)
	{
		nodes[i] = 0;
	}
	int sum = 0;  //������,��Ҫȥ�ľ�������
	printf("\n\n");
	printf("*****************************************************\n");
	printf("*1��ѧУ����       2���»�¥          3������԰     *\n");
	printf("*4������ɽ         5������Է          6���������¥ *\n");
	printf("*7����孲���       8��УҽԺ          9��ͼ���     *\n");
	printf("*10�����ٳ�        11���б���ѧ��¥   12����֪�㳡  *\n");
	printf("*13����·���⹫԰  14������ѵ������   15���о���Ժ  *\n");
	printf("*16���ƾó���      17��������                       *\n");
	printf("*****************************************************\n\n\n");
	printf("����������Ҫȥ�ľ�����(����0��ʾ����)��\n");
	int x;
	scanf("%d", &x);
	nodes[x] = 1;
	sum++;
	while (x != 0)
	{
		scanf("%d", &x);
		if (x == 0)
			break;
		nodes[x] = 1;    //��ʾ�ýڵ���ѡ
		sum++;
	}
	int i, j, k = 1;
	for (i = 1; i <= g.m; i++)
		for (j = 1; j <= i; j++)
			if (g.length[i][j] != 0 && g.length[i][j] != MaxRoad && nodes[i] && nodes[j])
			{
				edges[k].beg = i;
				edges[k].en = j;
				edges[k++].length = g.length[i][j];
			}
	quickSort(edges, 1, k-1);
	
	int m = 0;  //���ս��Ϊ��С�������ı���
	int parent[40];
	edge min_edges[20];
	for (int i = 1; i <= k; i++)
	{
		parent[i] = 0;
	}

	for (int i = 1; i < k; i++)
	{
		int m1 = find(parent, edges[i].beg);
		int m2 = find(parent, edges[i].en);
		if (m1 != m2)
		{
			parent[m1] = m2;
			min_edges[++m] = edges[i];
		}
	}

	int distance = 0;
	for (int i = 1; i <= m; i++)
	{
		printf("%s--->%s\n", g.view[min_edges[i].en].data.name, g.view[min_edges[i].beg].data.name);
		distance += min_edges[i].length;
	}
	printf("\n���߹���·���ܳ�Ϊ%d�ף�\n", distance);
}

int main()
{
	mGr.m = 17;
	mGr.n = 32;

	MGraph g;
	g = mGr;
	init();

	printf("**********************************************************************\n");
	printf("*                                                                    *\n");
	printf("*                                                                    *\n");
	printf("*                                                                    *\n");
	printf("*                ��ӭʹ���б���ѧУ԰������Ѷϵͳ !                  *\n");
	printf("*                                                                    *\n");
	printf("*                                                                    *\n");
	printf("*                                                                    *\n");
	printf("*                                                                    *\n");
	printf("*                                                                    *\n");
	printf("*                                            ���ߣ�  18070041��      *\n");
	printf("*                                                  �ؼκ�   ����־   *\n");
	printf("*                                                  ��Ч��   �ž���   *\n");
	printf("**********************************************************************\n");

	Sleep(1500);
	system("cls");

	char k;
	while (1)
	{
		system("cls");
		printf("***************************************************************\n");
		printf("*                                                             *\n");
		printf("*         1.������Ϣ��ѯ�밴��1����;                          *\n");
		printf("*         2.�������·����ѯ�����������㷨���밴��2����;      *\n");
		printf("*         3.��������·����ѯ�밴��3����;                      *\n");
		printf("*         4.У�ڹؽڵ��ѯ�밴��4����;                        *\n");
		printf("*         5.���·����ѯ�밴��5����;                          *\n");
		printf("*         6.�˳�ϵͳ�밴��6����;                              *\n");
		printf("*         7.�б���ѧ����ͼԤ����7����;                        *\n");
		printf("*                                                             *\n");
		printf("*                                                             *\n");
		printf("***************************************************************\n\n");
		printf("��ѡ��: \n");
		scanf("%c", &k);
		getchar();

		switch (k)

		{
		case '1':
			system("cls");
			printf("������ܲ�ѯ��������1-17����\n");
			introduce();
			getchar();
			break;

		case '2':
			system("cls");
			printf("�������·����ѯ�����������㷨����\n");
			shortdistance();
			system("pause");
			getchar();
			break;

		case '3':
			system("cls");
			printf("��������·����ѯ��\n");
			allRoad(mGr);
			system("pause");
			getchar();
			break;

		case '4':
			system("cls");
			printf("У԰ͼ�ؽڵ��ѯ��\n");
			coila_Search(&mGr);
			system("pause");
			break;

		case '5':
			system("cls");
			printf("���·����\n");
			kruskal(mGr);
			system("pause");
			getchar();
			break;

		case '6':
			system("cls");
			printf("ллʹ��!\n"); 
			system("pause");
			exit(0);

		case '7':
			system("cls");
			initgraph(1000, 640);
			IMAGE img_bk;
			loadimage(&img_bk, _T("D:\\Program Files (x86)\\VS2017projects\\Navigation_consultation\\Navigation_consultation\\2.png"), 1000, 640);
			putimage(0, 0, &img_bk);
			system("pause");
			closegraph();
			break;
		}
	}
	return 0;
}