#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>
#include<math.h>
#include<graphics.h>
#include<conio.h>

const int MaxViewNum = 50;   //宏定义最大景点的个数
const int N = 20;  //定义当前的景点总数
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

typedef struct edgedata
{
	int beg, en;    //顶点序号
	int length;    //边的权值
}edge;

MGraph mGr;   //定义MGraph类型的全局变量

int shortest[MaxViewNum][MaxViewNum];    //定义全局变量贮存最小路径
int path[MaxViewNum][MaxViewNum];

//中北大学学校景点信息存图，本次存图采用邻接矩阵形式进行存储
void init()
{
	int i, j;
	mGr.view[1].num = 1;
	strcpy(mGr.view[1].data.name, "学校大门");
	strcpy(mGr.view[1].data.number, "001");
	strcpy(mGr.view[1].data.introduction, "上兰街道学院路3号，有彭德怀像。");

	mGr.view[2].num = 2;
	strcpy(mGr.view[2].data.name, "德怀楼");
	strcpy(mGr.view[2].data.number, "002");
	strcpy(mGr.view[2].data.introduction, "7号教学楼，二院系楼，电工电子实验都在这个楼做，校长办公室也在这个楼。");

	mGr.view[3].num = 3;
	strcpy(mGr.view[3].data.name, "柏林园");
	strcpy(mGr.view[3].data.number, "003");
	strcpy(mGr.view[3].data.introduction, "小桥流水，密林幽会，是散步的好地方。");

	mGr.view[4].num = 4;
	strcpy(mGr.view[4].data.name, "二龙山");
	strcpy(mGr.view[4].data.number, "004");
	strcpy(mGr.view[4].data.introduction, "二龙山是少有的和校园相依托的风景区。山势不太高，但是景色秀丽，山上鲜花遍布，景点众多，二龙山旅游风景区是太原为数不多的避暑胜地。");

	mGr.view[5].num = 5;
	strcpy(mGr.view[5].data.name, "科艺苑");
	strcpy(mGr.view[5].data.number, "005");
	strcpy(mGr.view[5].data.introduction, "文艺演出，迎新晚会，学校的一些大的会议都在这里举行。");
	
	mGr.view[6].num = 6;
	strcpy(mGr.view[6].data.name, "文瀛宿舍楼");
	strcpy(mGr.view[6].data.number, "006");
	strcpy(mGr.view[6].data.introduction, "学生居住区，面积庞大。");

	mGr.view[7].num = 7;
	strcpy(mGr.view[7].data.name, "文瀛餐厅");
	strcpy(mGr.view[7].data.number, "007");
	strcpy(mGr.view[7].data.introduction, "第四食堂、文瀛食堂、雅贤阁、名族餐厅等各种食堂，紧挨文瀛宿舍区，方便学生就餐。");

	mGr.view[8].num = 8;
	strcpy(mGr.view[8].data.name, "校医院");
	strcpy(mGr.view[8].data.number, "008");
	strcpy(mGr.view[8].data.introduction, "中北大学校医院是一个二甲医院，是个很为学生经济情况考虑的医院，小病的话看病加买药一共也就几块钱，去的时候用一卡通有半价优惠。");

	mGr.view[9].num = 9;
	strcpy(mGr.view[9].data.name, "图书馆");
	strcpy(mGr.view[9].data.number, "009");
	strcpy(mGr.view[9].data.introduction, "地下室，顶两层都可以自习，中北大学的图书馆学习氛围很不错，存有大量图书。");

	mGr.view[10].num = 10;
	strcpy(mGr.view[10].data.name, "主操场");
	strcpy(mGr.view[10].data.number, "010");
	strcpy(mGr.view[10].data.introduction, "中北大学的主操场有主席台，中间的草地全部为真草草皮，不过只用于运动会，军训汇演和一些足球比赛。");

	mGr.view[11].num = 11;
	strcpy(mGr.view[11].data.name, "中北大学主楼");
	strcpy(mGr.view[11].data.number, "011");
	strcpy(mGr.view[11].data.introduction, "主楼在学校的中心位置，同学们的课程大都安排在这里上，放假也会开放供学生们自习。");

	mGr.view[12].num = 12;
	strcpy(mGr.view[12].data.name, "行知广场");
	strcpy(mGr.view[12].data.number, "012");
	strcpy(mGr.view[12].data.introduction, "开学迎新都会在这里接待新生，军训的验收，运动会的举办都在这里举行。");

	mGr.view[13].num = 13;
	strcpy(mGr.view[13].data.name, "铁路主题公园");
	strcpy(mGr.view[13].data.number, "013");
	strcpy(mGr.view[13].data.introduction, "中北大学是我国唯一一所校园内有火车的大学，里面铸有工程师的塑像等等。");

	mGr.view[14].num = 14;
	strcpy(mGr.view[14].data.name, "工程训练中心");
	strcpy(mGr.view[14].data.number, "014");
	strcpy(mGr.view[14].data.introduction, "学校最大办公、实验地，里面有各种机械设备，同学们来这里金工实习。");

	mGr.view[15].num = 15;
	strcpy(mGr.view[15].data.name, "研究生院");
	strcpy(mGr.view[15].data.number, "015");
	strcpy(mGr.view[15].data.introduction, "研究生居住的区域。");

	mGr.view[16].num = 16;
	strcpy(mGr.view[16].data.name, "唐久超市");
	strcpy(mGr.view[16].data.number, "016");
	strcpy(mGr.view[16].data.introduction, "是西区最大的超市，商品齐全，有卖服装的，卖小吃的，应有尽有。");

	mGr.view[16].num = 17;
	strcpy(mGr.view[17].data.name, "邮政办");
	strcpy(mGr.view[17].data.number, "017");
	strcpy(mGr.view[17].data.introduction, "邮政快递，发送邮件的地方。");

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


/*****************景点信息介绍***********************/
void introduce()
{
	int m;
	printf("*****************************************************\n");
	printf("*1：学校大门       2：德怀楼          3：柏林园     *\n");
	printf("*4：二龙山         5：科艺苑          6：文瀛宿舍楼 *\n");
	printf("*7：文瀛餐厅       8：校医院          9：图书馆     *\n");
	printf("*10：主操场        11：中北大学主楼   12：行知广场  *\n");
	printf("*13：铁路主题公园  14：工程训练中心   15：研究生院  *\n");
	printf("*16：唐久超市      17：邮政办                       *\n");
	printf("*****************************************************\n\n\n");
	printf("请输入查询景点编号:\n");
	scanf("%d", &m); fflush(stdin);
	IMAGE bmg;
	LOGFONT f;
	switch (m)
	{
	case 1:
		system("cls");
		initgraph(640, 640);
		loadimage(&bmg, _T("D:\\Program Files (x86)\\VS2017projects\\Navigation_consultation\\Navigation_consultation\\学校大门.jpg"), 640, 640);
		putimage(0, 0, &bmg);
		gettextstyle(&f);                     // 获取当前字体设置
		f.lfHeight = 25;                      // 设置字体高度
		_tcscpy(f.lfFaceName, _T("楷体"));    // 设置字体
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		settextstyle(&f);                     // 设置字体样式
		outtextxy(16, 350, _T("景点编号："));
		outtextxy(150, 350, _T(mGr.view[1].data.number));
		outtextxy(16, 380, _T("景点名称："));
		outtextxy(150, 380, _T(mGr.view[1].data.name));
		outtextxy(16, 410, _T("景点简介："));
		outtextxy(150, 410, _T(mGr.view[1].data.introduction));
		system("pause");
		closegraph();
		break;

	case 2:
		system("cls");
		initgraph(640, 640);
		loadimage(&bmg, _T("D:\\Program Files (x86)\\VS2017projects\\Navigation_consultation\\Navigation_consultation\\德怀楼.jpg"), 640, 640);
		putimage(0, 0, &bmg);
		gettextstyle(&f);                     // 获取当前字体设置
		f.lfHeight = 25;                      // 设置字体高度
		_tcscpy(f.lfFaceName, _T("楷体"));    // 设置字体
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		settextstyle(&f);                     // 设置字体样式
		outtextxy(16, 350, _T("景点编号："));
		outtextxy(150, 350, _T(mGr.view[1].data.number));
		outtextxy(16, 380, _T("景点名称："));
		outtextxy(150, 380, _T(mGr.view[1].data.name));
		outtextxy(16, 410, _T("景点简介："));
		outtextxy(150, 410, _T(mGr.view[1].data.introduction));
		system("pause");
		closegraph();
		break;

	case 3:
		system("cls");
		initgraph(640, 640);
		loadimage(&bmg, _T("D:\\Program Files (x86)\\VS2017projects\\Navigation_consultation\\Navigation_consultation\\柏林园.jpg"), 640, 640);
		putimage(0, 0, &bmg);
		gettextstyle(&f);                     // 获取当前字体设置
		f.lfHeight = 25;                      // 设置字体高度
		_tcscpy(f.lfFaceName, _T("楷体"));    // 设置字体
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		settextstyle(&f);                     // 设置字体样式
		outtextxy(16, 350, _T("景点编号："));
		outtextxy(150, 350, _T(mGr.view[1].data.number));
		outtextxy(16, 380, _T("景点名称："));
		outtextxy(150, 380, _T(mGr.view[1].data.name));
		outtextxy(16, 410, _T("景点简介："));
		outtextxy(150, 410, _T(mGr.view[1].data.introduction));
		system("pause");
		closegraph();
		break;

	case 4:
		system("cls");
		initgraph(640, 640);
		loadimage(&bmg, _T("D:\\Program Files (x86)\\VS2017projects\\Navigation_consultation\\Navigation_consultation\\二龙山.jpg"), 640, 640);
		putimage(0, 0, &bmg);
		gettextstyle(&f);                     // 获取当前字体设置
		f.lfHeight = 25;                      // 设置字体高度
		_tcscpy(f.lfFaceName, _T("楷体"));    // 设置字体
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		settextstyle(&f);                     // 设置字体样式
		outtextxy(16, 350, _T("景点编号："));
		outtextxy(150, 350, _T(mGr.view[1].data.number));
		outtextxy(16, 380, _T("景点名称："));
		outtextxy(150, 380, _T(mGr.view[1].data.name));
		outtextxy(16, 410, _T("景点简介："));
		outtextxy(150, 410, _T(mGr.view[1].data.introduction));
		system("pause");
		closegraph();
		break;

	case 5:
		system("cls");
		initgraph(640, 640);
		loadimage(&bmg, _T("D:\\Program Files (x86)\\VS2017projects\\Navigation_consultation\\Navigation_consultation\\科艺苑.jpg"), 640, 640);
		putimage(0, 0, &bmg);
		gettextstyle(&f);                     // 获取当前字体设置
		f.lfHeight = 25;                      // 设置字体高度
		_tcscpy(f.lfFaceName, _T("楷体"));    // 设置字体
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		settextstyle(&f);                     // 设置字体样式
		outtextxy(16, 350, _T("景点编号："));
		outtextxy(150, 350, _T(mGr.view[1].data.number));
		outtextxy(16, 380, _T("景点名称："));
		outtextxy(150, 380, _T(mGr.view[1].data.name));
		outtextxy(16, 410, _T("景点简介："));
		outtextxy(150, 410, _T(mGr.view[1].data.introduction));
		system("pause");
		closegraph();
		break;

	case 6:
		system("cls");
		initgraph(640, 640);
		loadimage(&bmg, _T("D:\\Program Files (x86)\\VS2017projects\\Navigation_consultation\\Navigation_consultation\\文瀛宿舍楼.jpg"), 640, 640);
		putimage(0, 0, &bmg);
		gettextstyle(&f);                     // 获取当前字体设置
		f.lfHeight = 25;                      // 设置字体高度
		_tcscpy(f.lfFaceName, _T("楷体"));    // 设置字体
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		settextstyle(&f);                     // 设置字体样式
		outtextxy(16, 350, _T("景点编号："));
		outtextxy(150, 350, _T(mGr.view[1].data.number));
		outtextxy(16, 380, _T("景点名称："));
		outtextxy(150, 380, _T(mGr.view[1].data.name));
		outtextxy(16, 410, _T("景点简介："));
		outtextxy(150, 410, _T(mGr.view[1].data.introduction));
		system("pause");
		closegraph();
		break;

	case 7:
		system("cls");
		initgraph(640, 640);
		loadimage(&bmg, _T("D:\\Program Files (x86)\\VS2017projects\\Navigation_consultation\\Navigation_consultation\\文瀛餐厅.jpg"), 640, 640);
		putimage(0, 0, &bmg);
		gettextstyle(&f);                     // 获取当前字体设置
		f.lfHeight = 25;                      // 设置字体高度
		_tcscpy(f.lfFaceName, _T("楷体"));    // 设置字体
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		settextstyle(&f);                     // 设置字体样式
		outtextxy(16, 350, _T("景点编号："));
		outtextxy(150, 350, _T(mGr.view[1].data.number));
		outtextxy(16, 380, _T("景点名称："));
		outtextxy(150, 380, _T(mGr.view[1].data.name));
		outtextxy(16, 410, _T("景点简介："));
		outtextxy(150, 410, _T(mGr.view[1].data.introduction));
		system("pause");
		closegraph();
		break;

	case 8:
		system("cls");
		initgraph(640, 640);
		loadimage(&bmg, _T("D:\\Program Files (x86)\\VS2017projects\\Navigation_consultation\\Navigation_consultation\\校医院.jpg"), 640, 640);
		putimage(0, 0, &bmg);
		gettextstyle(&f);                     // 获取当前字体设置
		f.lfHeight = 25;                      // 设置字体高度
		_tcscpy(f.lfFaceName, _T("楷体"));    // 设置字体
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		settextstyle(&f);                     // 设置字体样式
		outtextxy(16, 350, _T("景点编号："));
		outtextxy(150, 350, _T(mGr.view[1].data.number));
		outtextxy(16, 380, _T("景点名称："));
		outtextxy(150, 380, _T(mGr.view[1].data.name));
		outtextxy(16, 410, _T("景点简介："));
		outtextxy(150, 410, _T(mGr.view[1].data.introduction));
		system("pause");
		closegraph();
		break;

	case 9:
		system("cls");
		initgraph(640, 640);
		loadimage(&bmg, _T("D:\\Program Files (x86)\\VS2017projects\\Navigation_consultation\\Navigation_consultation\\图书馆.jpg"), 640, 640);
		putimage(0, 0, &bmg);
		gettextstyle(&f);                     // 获取当前字体设置
		f.lfHeight = 25;                      // 设置字体高度
		_tcscpy(f.lfFaceName, _T("楷体"));    // 设置字体
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		settextstyle(&f);                     // 设置字体样式
		outtextxy(16, 350, _T("景点编号："));
		outtextxy(150, 350, _T(mGr.view[1].data.number));
		outtextxy(16, 380, _T("景点名称："));
		outtextxy(150, 380, _T(mGr.view[1].data.name));
		outtextxy(16, 410, _T("景点简介："));
		outtextxy(150, 410, _T(mGr.view[1].data.introduction));
		system("pause");
		closegraph();
		break;

	case 10:
		system("cls");
		initgraph(640, 640);
		loadimage(&bmg, _T("D:\\Program Files (x86)\\VS2017projects\\Navigation_consultation\\Navigation_consultation\\主操场.jpg"), 640, 640);
		putimage(0, 0, &bmg);
		gettextstyle(&f);                     // 获取当前字体设置
		f.lfHeight = 25;                      // 设置字体高度
		_tcscpy(f.lfFaceName, _T("楷体"));    // 设置字体
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		settextstyle(&f);                     // 设置字体样式
		outtextxy(16, 350, _T("景点编号："));
		outtextxy(150, 350, _T(mGr.view[1].data.number));
		outtextxy(16, 380, _T("景点名称："));
		outtextxy(150, 380, _T(mGr.view[1].data.name));
		outtextxy(16, 410, _T("景点简介："));
		outtextxy(150, 410, _T(mGr.view[1].data.introduction));
		system("pause");
		closegraph();
		break;

	case 11:
		system("cls");
		initgraph(640, 640);
		loadimage(&bmg, _T("D:\\Program Files (x86)\\VS2017projects\\Navigation_consultation\\Navigation_consultation\\中北大学主楼.jpg"), 640, 640);
		putimage(0, 0, &bmg);
		gettextstyle(&f);                     // 获取当前字体设置
		f.lfHeight = 25;                      // 设置字体高度
		_tcscpy(f.lfFaceName, _T("楷体"));    // 设置字体
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		settextstyle(&f);                     // 设置字体样式
		outtextxy(16, 350, _T("景点编号："));
		outtextxy(150, 350, _T(mGr.view[1].data.number));
		outtextxy(16, 380, _T("景点名称："));
		outtextxy(150, 380, _T(mGr.view[1].data.name));
		outtextxy(16, 410, _T("景点简介："));
		outtextxy(150, 410, _T(mGr.view[1].data.introduction));
		system("pause");
		closegraph();
		break;

	case 12:
		system("cls");
		initgraph(640, 640);
		loadimage(&bmg, _T("D:\\Program Files (x86)\\VS2017projects\\Navigation_consultation\\Navigation_consultation\\行知广场.jpg"), 640, 640);
		putimage(0, 0, &bmg);
		gettextstyle(&f);                     // 获取当前字体设置
		f.lfHeight = 25;                      // 设置字体高度
		_tcscpy(f.lfFaceName, _T("楷体"));    // 设置字体
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		settextstyle(&f);                     // 设置字体样式
		outtextxy(16, 350, _T("景点编号："));
		outtextxy(150, 350, _T(mGr.view[1].data.number));
		outtextxy(16, 380, _T("景点名称："));
		outtextxy(150, 380, _T(mGr.view[1].data.name));
		outtextxy(16, 410, _T("景点简介："));
		outtextxy(150, 410, _T(mGr.view[1].data.introduction));
		system("pause");
		closegraph();
		break;

	case 13:
		system("cls");
		initgraph(640, 640);
		loadimage(&bmg, _T("D:\\Program Files (x86)\\VS2017projects\\Navigation_consultation\\Navigation_consultation\\铁路主题公园.jpg"), 640, 640);
		putimage(0, 0, &bmg);
		gettextstyle(&f);                     // 获取当前字体设置
		f.lfHeight = 25;                      // 设置字体高度
		_tcscpy(f.lfFaceName, _T("楷体"));    // 设置字体
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		settextstyle(&f);                     // 设置字体样式
		outtextxy(16, 350, _T("景点编号："));
		outtextxy(150, 350, _T(mGr.view[1].data.number));
		outtextxy(16, 380, _T("景点名称："));
		outtextxy(150, 380, _T(mGr.view[1].data.name));
		outtextxy(16, 410, _T("景点简介："));
		outtextxy(150, 410, _T(mGr.view[1].data.introduction));
		system("pause");
		closegraph();
		break;

	case 14:
		system("cls");
		initgraph(640, 640);
		loadimage(&bmg, _T("D:\\Program Files (x86)\\VS2017projects\\Navigation_consultation\\Navigation_consultation\\工程训练中心.jpg"), 640, 640);
		putimage(0, 0, &bmg);
		gettextstyle(&f);                     // 获取当前字体设置
		f.lfHeight = 25;                      // 设置字体高度
		_tcscpy(f.lfFaceName, _T("楷体"));    // 设置字体
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		settextstyle(&f);                     // 设置字体样式
		outtextxy(16, 350, _T("景点编号："));
		outtextxy(150, 350, _T(mGr.view[1].data.number));
		outtextxy(16, 380, _T("景点名称："));
		outtextxy(150, 380, _T(mGr.view[1].data.name));
		outtextxy(16, 410, _T("景点简介："));
		outtextxy(150, 410, _T(mGr.view[1].data.introduction));
		system("pause");
		closegraph();
		break;

	case 15:
		system("cls");
		initgraph(640, 640);
		loadimage(&bmg, _T("D:\\Program Files (x86)\\VS2017projects\\Navigation_consultation\\Navigation_consultation\\研究生院.jpg"), 640, 640);
		putimage(0, 0, &bmg);
		gettextstyle(&f);                     // 获取当前字体设置
		f.lfHeight = 25;                      // 设置字体高度
		_tcscpy(f.lfFaceName, _T("楷体"));    // 设置字体
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		settextstyle(&f);                     // 设置字体样式
		outtextxy(16, 350, _T("景点编号："));
		outtextxy(150, 350, _T(mGr.view[1].data.number));
		outtextxy(16, 380, _T("景点名称："));
		outtextxy(150, 380, _T(mGr.view[1].data.name));
		outtextxy(16, 410, _T("景点简介："));
		outtextxy(150, 410, _T(mGr.view[1].data.introduction));
		system("pause");
		closegraph();
		break;

	case 16:
		system("cls");
		initgraph(640, 640);
		loadimage(&bmg, _T("D:\\Program Files (x86)\\VS2017projects\\Navigation_consultation\\Navigation_consultation\\唐久超市.jpg"), 640, 640);
		putimage(0, 0, &bmg);
		gettextstyle(&f);                     // 获取当前字体设置
		f.lfHeight = 25;                      // 设置字体高度
		_tcscpy(f.lfFaceName, _T("楷体"));    // 设置字体
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		settextstyle(&f);                     // 设置字体样式
		outtextxy(16, 350, _T("景点编号："));
		outtextxy(150, 350, _T(mGr.view[1].data.number));
		outtextxy(16, 380, _T("景点名称："));
		outtextxy(150, 380, _T(mGr.view[1].data.name));
		outtextxy(16, 410, _T("景点简介："));
		outtextxy(150, 410, _T(mGr.view[1].data.introduction));
		system("pause");
		closegraph();
		break;

	case 17:
		system("cls");
		initgraph(640, 640);
		loadimage(&bmg, _T("D:\\Program Files (x86)\\VS2017projects\\Navigation_consultation\\Navigation_consultation\\邮政办.jpg"), 640, 640);
		putimage(0, 0, &bmg);
		gettextstyle(&f);                     // 获取当前字体设置
		f.lfHeight = 25;                      // 设置字体高度
		_tcscpy(f.lfFaceName, _T("楷体"));    // 设置字体
		setbkmode(TRANSPARENT);
		settextcolor(RED);
		settextstyle(&f);                     // 设置字体样式
		outtextxy(16, 350, _T("景点编号："));
		outtextxy(150, 350, _T(mGr.view[1].data.number));
		outtextxy(16, 380, _T("景点名称："));
		outtextxy(150, 380, _T(mGr.view[1].data.name));
		outtextxy(16, 410, _T("景点简介："));
		outtextxy(150, 410, _T(mGr.view[1].data.introduction));
		system("pause");
		closegraph();
		break;

	default:
		printf("输入序号错误。\n");
		break;
	}

	printf("\n");
}


/**********弗洛伊德 最短路径********/
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
	printf("您要查询的两景点间最短路径是： \n\n");
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
		printf("%d->%d的最短路径是： %d 米。\n\n", a, b, shortest[a][b]);
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
		printf("%d->%d的最短路径是： %d 米。\n\n", a, b, shortest[a][b]);
	}
}
int shortdistance()
{
	int i, j;
	printf("*****************************************************\n");
	printf("*1：学校大门       2：德怀楼          3：柏林园     *\n");
	printf("*4：二龙山         5：科艺苑          6：文瀛宿舍楼 *\n");
	printf("*7：文瀛餐厅       8：校医院          9：图书馆     *\n");
	printf("*10：主操场        11：中北大学主楼   12：行知广场  *\n");
	printf("*13：铁路主题公园  14：工程训练中心   15：研究生院  *\n");
	printf("*16：唐久超市      17：邮政办                       *\n");
	printf("*****************************************************\n\n\n");
	printf("请输入要查询的两个景点的数字编号(1->17)中间用空格间隔开。\n");
	scanf("%d %d", &i, &j);
	if (i > N || i<0 || j>N || j < 0)
	{
		printf("输入信息错误！\n");
		printf("请输入要查询的两个景点的数字编号（1->16）中间用空格间隔开。\n");
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


//任意两个景点之间的所有路径//
typedef struct
{
	int path[N];
	int top;
}node;

node slt;
int visited[N + 1];
int count;                              //纪录路径

void sousuo(MGraph g, int i, int j)
{
	int b, k;
	int len = 0;                          //路径长度
	slt.path[slt.top] = i;
	slt.top++;
	visited[i] = 1;
	for (k = 1; k <= N; k++)
	{
		if (g.length[i][k] > 0 && g.length[i][k] < MaxRoad && !visited[k])
		{
			if (k == j)
			{
				printf("第%d条路径：", count++);
				for (b = 0; b < slt.top; b++)
				{
					printf("%s%s->", g.view[slt.path[b]].data.number, g.view[slt.path[b]].data.name);
					if (b < slt.top - 1)
						len = len + g.length[slt.path[b]][slt.path[b + 1]];
				}
				len = len + g.length[slt.path[slt.top - 1]][j];
				printf("%s %s\n", g.view[j].data.number, g.view[j].data.name);
				printf("路径总长度：%d\n", len);
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
	printf("请输入起点：\n");
	scanf("%d", &i);
	printf("请输入终点:\n");
	scanf("%d", &j);
	if (i == j)
	{
		printf("起点与终点相同，无路径\n"); return;
	}
	sousuo(g, i, j);
}


/******深度遍历关节点********/
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

/*求校园图中的关节点*/
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
		printf("该图没有关节点！！！\n");
	}
	else
	{
		printf("此图的关节点有%d个，分别为:\n", num);
		for (int j = 1; j <= num; j++)
		{
			printf("%d\t", mGr.view[node[j]].num);
			printf("%s\n", mGr.view[node[j]].data.name);
		}
	}
}


/*Kruskal算法求最小生成树*/

/*对边的权值进行排序*/
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

//并查集
int find(int parent[], int x)
{
	while (parent[x] > 0)
	{
		x = parent[x];
	}
	return x;
}

/*主要算法*/
void kruskal(MGraph g)
{
	edge edges[40];
	int nodes[20];
	
	for (int i = 1; i <= 17; i++)
	{
		nodes[i] = 0;
	}
	int sum = 0;  //计数器,想要去的景点总数
	printf("\n\n");
	printf("*****************************************************\n");
	printf("*1：学校大门       2：德怀楼          3：柏林园     *\n");
	printf("*4：二龙山         5：科艺苑          6：文瀛宿舍楼 *\n");
	printf("*7：文瀛餐厅       8：校医院          9：图书馆     *\n");
	printf("*10：主操场        11：中北大学主楼   12：行知广场  *\n");
	printf("*13：铁路主题公园  14：工程训练中心   15：研究生院  *\n");
	printf("*16：唐久超市      17：邮政办                       *\n");
	printf("*****************************************************\n\n\n");
	printf("请输入你想要去的景点编号(输入0表示结束)：\n");
	int x;
	scanf("%d", &x);
	nodes[x] = 1;
	sum++;
	while (x != 0)
	{
		scanf("%d", &x);
		if (x == 0)
			break;
		nodes[x] = 1;    //表示该节点入选
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
	
	int m = 0;  //最终结果为最小生成树的边数
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
	printf("\n所走过的路径总长为%d米！\n", distance);
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
	printf("*                欢迎使用中北大学校园导航资讯系统 !                  *\n");
	printf("*                                                                    *\n");
	printf("*                                                                    *\n");
	printf("*                                                                    *\n");
	printf("*                                                                    *\n");
	printf("*                                                                    *\n");
	printf("*                                            作者：  18070041班      *\n");
	printf("*                                                  秦嘉豪   韩林志   *\n");
	printf("*                                                  秦效国   张竞文   *\n");
	printf("**********************************************************************\n");

	Sleep(1500);
	system("cls");

	char k;
	while (1)
	{
		system("cls");
		printf("***************************************************************\n");
		printf("*                                                             *\n");
		printf("*         1.景点信息查询请按“1”键;                          *\n");
		printf("*         2.景点最短路径查询（佛洛依德算法）请按“2”键;      *\n");
		printf("*         3.景点所有路径查询请按“3”键;                      *\n");
		printf("*         4.校内关节点查询请按“4”键;                        *\n");
		printf("*         5.最佳路径查询请按“5”键;                          *\n");
		printf("*         6.退出系统请按“6”键;                              *\n");
		printf("*         7.中北大学景点图预览“7”键;                        *\n");
		printf("*                                                             *\n");
		printf("*                                                             *\n");
		printf("***************************************************************\n\n");
		printf("请选择: \n");
		scanf("%c", &k);
		getchar();

		switch (k)

		{
		case '1':
			system("cls");
			printf("景点介绍查询（请输入1-17）。\n");
			introduce();
			getchar();
			break;

		case '2':
			system("cls");
			printf("景点最短路径查询（佛洛依德算法）。\n");
			shortdistance();
			system("pause");
			getchar();
			break;

		case '3':
			system("cls");
			printf("景点所有路径查询。\n");
			allRoad(mGr);
			system("pause");
			getchar();
			break;

		case '4':
			system("cls");
			printf("校园图关节点查询：\n");
			coila_Search(&mGr);
			system("pause");
			break;

		case '5':
			system("cls");
			printf("最佳路径。\n");
			kruskal(mGr);
			system("pause");
			getchar();
			break;

		case '6':
			system("cls");
			printf("谢谢使用!\n"); 
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