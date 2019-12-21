#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>
#include<math.h>
#include<graphics.h>
#include<conio.h>

/*
*****界面稍后再改先暂时这样，大家先实现功能，主要的结构体定义就大体是这样了 ，大家先了解一下，有什么不懂的在群里问我
*****先把景点信息都修改了，然后大家就可以编写子函数是新功能了，界面这边我来弄
*/

const int MaxViewNum = 50;   //宏定义最大景点的个数
const int N = 16;  //定义当前的景点总数
const int MaxRoad = 10000;   //定义路径为无穷大

typedef struct //景点信息
{
	char name[30];   //景点名称
	char number[10]; //景点代号
	char introduction[200];  //景点介绍
}elemInfo;

typedef struct
{
	int num;  //景点编号
	elemInfo data;  //景点信息
}viewInfo;

typedef struct
{
	viewInfo view[MaxViewNum];   //用于存放顶点
	int length[MaxViewNum][MaxViewNum];   //用于存放路径长度
	int m, n;
}MGraph;

MGraph mGr;   //定义MGraph类型的全局变量
int shortest[MaxViewNum][MaxViewNum];    //定义全局变量贮存最小路径

/*
****这里的学校信息整理由张竞文修改，这是第一步，这里修改了我们才能往下进行。记住要加上图片，可以在结构体中添加一个变量
*/
void init() //学校信息整理 
{
	int i, j;
	mGr.view[1].num = 1;
	strcpy(mGr.view[1].data.name, "学校正门");
	strcpy(mGr.view[1].data.number, "001");
	strcpy(mGr.view[1].data.introduction, "上兰街道学院路3号，有彭德怀像。");

	mGr.view[2].num = 2;
	strcpy(mGr.view[2].data.name, "德怀楼");
	strcpy(mGr.view[2].data.number, "002");
	strcpy(mGr.view[2].data.introduction, "15教学楼。");

	mGr.view[3].num = 3;
	strcpy(mGr.view[3].data.name, "研究生公寓");
	strcpy(mGr.view[3].data.number, "003");
	strcpy(mGr.view[3].data.introduction, "研究生住宿区。");

	mGr.view[4].num = 4;
	strcpy(mGr.view[4].data.name, "主题公园");
	strcpy(mGr.view[4].data.number, "004");
	strcpy(mGr.view[4].data.introduction, "铁路主题公园。");

	mGr.view[5].num = 5;
	strcpy(mGr.view[5].data.name, "文瀛宿舍");
	strcpy(mGr.view[5].data.number, "005");
	strcpy(mGr.view[5].data.introduction, "中北大学西区宿舍楼。");
	
	mGr.view[6].num = 6;
	strcpy(mGr.view[6].data.name, "柏林园");
	strcpy(mGr.view[6].data.number, "006");
	strcpy(mGr.view[6].data.introduction, "it's very beautiful。");

	mGr.view[7].num = 7;
	strcpy(mGr.view[7].data.name, "西区餐厅");
	strcpy(mGr.view[7].data.number, "007");
	strcpy(mGr.view[7].data.introduction, "第四食堂、文瀛食堂、雅贤阁、名族餐厅等各种食堂。");

	mGr.view[8].num = 8;
	strcpy(mGr.view[8].data.name, "主操场");
	strcpy(mGr.view[8].data.number, "008");
	strcpy(mGr.view[8].data.introduction, "绿茵地、健身房、篮球场、足球场、网球场依次，丰富课余生活。");

	mGr.view[9].num = 9;
	strcpy(mGr.view[9].data.name, "二龙山");
	strcpy(mGr.view[9].data.number, "009");
	strcpy(mGr.view[9].data.introduction, "太原市著名景区。");

	mGr.view[10].num = 10;
	strcpy(mGr.view[10].data.name, "科艺苑");
	strcpy(mGr.view[10].data.number, "010");
	strcpy(mGr.view[10].data.introduction, "晚会交流。");

	mGr.view[11].num = 11;
	strcpy(mGr.view[11].data.name, "邮政办");
	strcpy(mGr.view[11].data.number, "011");
	strcpy(mGr.view[11].data.introduction, "邮政快递以及红房子里面各种快递寄放。");

	mGr.view[12].num = 12;
	strcpy(mGr.view[12].data.name, "艺术教室");
	strcpy(mGr.view[12].data.number, "012");
	strcpy(mGr.view[12].data.introduction, "美术学院和音乐与舞蹈学院，通往艺术的殿堂。");

	mGr.view[13].num = 13;
	strcpy(mGr.view[13].data.name, "图书馆");
	strcpy(mGr.view[13].data.number, "013");
	strcpy(mGr.view[13].data.introduction, "造型美观，内置环境优雅，及其适合学习。");

	mGr.view[14].num = 14;
	strcpy(mGr.view[14].data.name, "中北主楼");
	strcpy(mGr.view[14].data.number, "014");
	strcpy(mGr.view[14].data.introduction, "学校最大办公、实验地。");

	mGr.view[15].num = 15;
	strcpy(mGr.view[15].data.name, "校医院");
	strcpy(mGr.view[15].data.number, "015");
	strcpy(mGr.view[15].data.introduction, "校医院，同学们看病拿药的地方，提供便利。");

	mGr.view[16].num = 16;
	strcpy(mGr.view[16].data.name, "五道门");
	strcpy(mGr.view[16].data.number, "016");
	strcpy(mGr.view[16].data.introduction, "主楼临近出入口，四通八达。");

	for (i = 1; i <= N; i++)  //将路径初始化为无穷大
	{
		for (j = 1; j <= N; j++)
		{
			mGr.length[i][j] = MaxRoad;
		}
	}

	for (i = 1; i <= N; i++)  //初始化最小路径
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
	//初始化窗口
	initgraph(640, 480);
	
	setbkcolor(RED);

	init();

	cleardevice();
	_getch();
	return 0;
}