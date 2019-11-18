//�������ƣ���˭  ��  ����
//���ߣ��ؼκ�(������)
//��Ȩ��������Ϸ�ټ�ª��Ҳ�Ǳ���������Ѫ������Ҳ�ϲ���磡
//

#include<graphics.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

/////////////////////////////////////////////
//����ȫ�ֱ���




IMAGE img_bk,img_f;     //����ͼƬ��ǣ��򿪱���ͼƬ
SIZE g_zsize;           //�Թ���С������
IMAGE g_imgSight(360,280);//��Ϸ����Ұ
RECT g_rtSight;         //��Ϸ��Ұ�ķ�Χ
IMAGE g_imgItem(180,20);//��ͼԪ��
IMAGE g_imgGPS;         //С��ͼ����ʾ��ҵ�λ��
POINT g_ptGPS;          //λ�õ���ʾ
SIZE g_szGPS;           //С��ͼ�ĳߴ�
POINT g_ptPlayer;       //��ҵ�λ��
BYTE** g_aryMap=NULL;   //�����Թ���ͼ

//ö�ٵ�ͼԪ�أ�����Ԫ��λ�õ�x����
enum MAPITEM
{ 
	MAP_WALL=0 , MAP_PLAYER =20,MAP_GROUND = 40,MAP_MARKRED = 60,MAP_MARKGREEN = 80,MAP_MARKYELLOW=100,MAP_ENTRANCE=120,MAP_BOX=180,MAP_EXIT=140,MAP_OUTSIDE=160  
};

//��ҵĿ�������
enum CMD
{ 
	CMD_QUIT = 1,CMD_UP =2,CMD_DOWN = 4,CMD_LEFT = 8,CMD_RIGHT = 16,CMD_MARKRED = 32,CMD_MARKGREEN = 64,CMD_MARKYELLOW = 128,CMD_CLEARMARK = 256,CMD_OPEN = 512
};

////////////////////////////////////////////////
//��������
void Welcome();                        //������Ϸ����
void InitImage();                      //��ʼ����Ϸ����
void InitGame();                       //��ʼ����Ϸ����
void GetMazeSize();                    //��ʾ�û������Թ���С
void MakeMaze(int width,int height);   //�����Թ�����ʼ��
void TravelMaze(int x,int y);          //���������Թ�
MAPITEM GetMazeItem(int x,int y);       //��ȡ��ҵ�λ��
void paint();                          //������Ұ�ڵ��Թ�
int GetCmd();                          //��ȡ��ҵ�ָ��
void DispatchCmd(int cmd);             //������ҵ�ָ��
void OnUp();                           //�����ƶ�
void OnLeft();                         //�����ƶ�
void OnRight();                        //�����ƶ�
void OnDown();                         //�����ƶ�
void OnMark(MAPITEM value);            //�ڵ�ͼ�������
bool check();                          //����Ƿ���������
bool CheckWin();                       //����Ƿ񵽴����
bool Quit();                           //ѯ���û��Ƿ��˳���Ϸ


////////////////////////////////////////////////////
//��������

//��������
#pragma comment(lib,"Winmm.lib")

//������
int main()
{
	mciSendString( L"open 1.mp3 alias bkmusic1",NULL,0,NULL);
	mciSendString(L"play bkmusic1 repeat",NULL,0,NULL);

	//��ʼ���߿�
	initgraph(640,480);                 //������ͼ����
	srand((unsigned)time(NULL));        //�����������

	// ��ʾ������
	Welcome();

	//��ʼ��
	InitImage();
	InitGame();

	//��Ϸ����
	int c;
	while( !(((c = GetCmd()) & CMD_QUIT) && Quit()) )
	{
		DispatchCmd(c);
		paint();
		if(CheckWin())
			break;
		if(check())
			printf("100\n");
		Sleep(100);
	}

	//�����Թ�ռ�õ��ڴ�
	for(int x=0;x<g_zsize.cx+2;x++)
		delete [] g_aryMap[x];
	delete [] g_aryMap;

	//�ر�ͼƬ  
	closegraph();
	return 0;
}

// ������Ϸ����
void Welcome()
{
	// ��ͼƬ
	loadimage(&img_f,_T("d:\\vs�������\\�ؼκ�\\�ؼκ�\\t01f5830dc0df924943.jpg"));    //��ͼƬ�ļ���ֵ��img_f
	putimage(0,0,&img_f);    //�ڣ�0,0��λ�ô�ͼƬ
	

	// ����������ʽ
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);

	// ���Ʊ���
	settextstyle(36,0,_T("����"));
	outtextxy(200,40,_T("��˭  ��  ����"));

	//���Ʋ���˵��
	settextstyle(12,0,_T("����"));
	outtextxy(74,382,_T("����˵����"));
	outtextxy(74,400,_T("������� A/S/D/W���ƶ�"));
	outtextxy(74,418,_T("H��Y��G���ڵ�ͼ�����졢�ơ���ɫM���"));
	outtextxy(74,436,_T("C�������ͼ�ϵı��   p :�򿪱���"));
	outtextxy(74,454,_T("ESC���˳�����"));

	//�û������Թ���С
	GetMazeSize();
}

//��ʼ����Ϸ����
void InitImage()
{
	//����Ϸ����ͼƬ
	SetWorkingImage(&g_imgItem);
	cleardevice();
	loadimage(&img_bk,_T("d:\\vs�������\\�ؼκ�\\�ؼκ�\\t0143a60d518c497937.jpg"));
	
	/*for(int i=0;i<128;i++)
	{
		setlinecolor(RGB(0,0,(127-i<<1)));
		rectangle(149-i,109- (i>>1),490+i,370 + (i>>1));
	}*/
	putimage(0,0,&img_bk);
	
	//����ǽ��
	setorigin(MAP_WALL,0);
	settextcolor(BROWN);
	setfillstyle((BYTE*)"\x20\x20\x20\xff\x04\x04\x04\xff");
	setlinecolor(RED);
	solidrectangle(1,1,18,18);
	rectangle(0,0,19,19);

	//�������ģ��
	setorigin(MAP_PLAYER,0);
	setfillcolor(YELLOW);
	setlinecolor(YELLOW);
	fillellipse(2,2,17,17);
	setlinecolor(BLACK);
	line(7,7,7,8);
	line(12,7,12,8);
	arc(5,6,14,14,3.34,6.08);

	//���ƺ�ɫ���
	setorigin(MAP_MARKRED,0);
	setlinecolor(RED);
	moveto(5,15);
	linerel(0,-10);
	linerel(5,5);
	linerel(5,-5);
	linerel(0,10);

	//������ɫ���
	setorigin(MAP_MARKGREEN,0);
	setlinecolor(GREEN);
	moveto(5,15);
	linerel(0,-10);
	linerel(5,5);
	linerel(5,-5);
	linerel(0,10);

	//������ɫ���
	setorigin(MAP_MARKYELLOW,0);
	setlinecolor(YELLOW);
	moveto(5,15);
	linerel(0,-10);
	linerel(5,5);
	linerel(5,-5);
	linerel(0,10);

	//�������
	setorigin(MAP_ENTRANCE,0);
	setlinecolor(BLUE);
	settextstyle(12,0,_T("����"));
	outtextxy(4,4,_T("��"));

	//��������
	setorigin(MAP_BOX,0);
	outtextxy(4,4,_T("��"));

	//��������
	setorigin(MAP_EXIT,0);
	outtextxy(4,4,_T("��"));

	//����½��
	setorigin(MAP_OUTSIDE,0);
	settextcolor(GREEN);
	setfillstyle((BYTE *)"\x50\x55\x22\x20\x05\x55\x22\x02");
	solidrectangle(0,0,19,19);

	//��������ϵ
	setorigin(0,0);

	//��ʾ����
	SetWorkingImage();
	settextcolor(BLUE);
	TCHAR author[] = _T("created by Mercy Qin !");
	outtextxy(471,4,author);
	settextcolor(LIGHTBLUE);
	outtextxy(470,3,author);
}

//��ʼ����Ϸ����
void InitGame()
{
	//��ʼ��
	if(g_aryMap!=NULL)
	{
		//����ϴε�����
		for(int x=0;x < g_zsize.cx + 2;x++)
			delete [] g_aryMap[x];
		delete [] g_aryMap;
	}

	//�����Թ�
	MakeMaze(g_zsize.cx,g_zsize.cy);

	//��Ϸ�ߵĳ�ʼλ��
	g_ptPlayer.x = 2;
	g_ptPlayer.y = 2;

	//������Ұ��Χ
	g_rtSight.left = 0;
	g_rtSight.top = 0;
	g_rtSight.right = 17;
	g_rtSight.bottom = 13;

	//��ҵ�λ����ʾ
	setfillcolor(BLUE);
	solidrectangle(522,368,637,471);
	if (g_zsize.cx > g_zsize.cy)
	{	
		g_szGPS.cx = 100;
		g_szGPS.cy = (int)(100.0 * g_zsize.cy / g_zsize.cx + 0.5);
	}
	else	
	{	
		g_szGPS.cy = 100; 
		g_szGPS.cx = (int)(100.0 * g_zsize.cx / g_zsize.cy + 0.5);	
	}
	Resize(&g_imgGPS, g_szGPS.cx, g_szGPS.cy);
	g_ptGPS.x = 530 + 50 - g_szGPS.cx / 2;
	g_ptGPS.y = 370 + 50 - g_szGPS.cy / 2;

	// �������ͼ���
	setlinecolor(RED);
	rectangle(g_ptGPS.x - 1, g_ptGPS.y - 1, g_ptGPS.x + g_szGPS.cx, g_ptGPS.y + g_szGPS.cy);

	// �������ͼ��ںͳ���
	setlinecolor(YELLOW);
	moveto(g_ptGPS.x - 8, g_ptGPS.y + g_szGPS.cy / g_zsize.cy);
	linerel(7, 0);	linerel(-3, -3);	moverel(3, 3);	linerel(-3, 3);
	moveto(g_ptGPS.x + g_szGPS.cx, g_ptGPS.y + g_szGPS.cy - g_szGPS.cy / g_zsize.cy);
	linerel(7, 0);	linerel(-3, -3);	moverel(3, 3);	linerel(-3, 3);

	//������Ϸ��
	paint();
}

//��ʾ��������Թ���С
void GetMazeSize()
{
	g_zsize.cx=g_zsize.cy=0;

	//�û�������
	TCHAR s[4];
	while(g_zsize.cx<20 || g_zsize.cy>200)
	{
		InputBox(s,4,_T("�������Թ��Ŀ��\n��Χ20-200"),_T("����"),_T("00"));
		g_zsize.cx=_ttoi(s);
	}
	while(g_zsize.cy<20 || g_zsize.cy>200)
	{
		InputBox(s,4,_T("�������Թ��ĸ߶�\n��Χ20-200"),_T("����"),_T("00"));
		g_zsize.cy=_ttoi(s);
	}

	//ȷ�����������Ϊ����
	if(g_zsize.cx %2 == 0)
		g_zsize.cx++;
	if(g_zsize.cy %2 == 0)
		g_zsize.cy++;
}

//�����Թ�
void MakeMaze(int width,int height)
{
	if(width %2 != 1 || height %2 != 1)
		return ;

	//�����Թ���С�������ڴ�
	int x,y;

	g_aryMap = new BYTE*[width + 2];
	for(x = 0;x<width+2;x++)
	{
		g_aryMap[x] = new BYTE[height + 2];
		memset(g_aryMap[x],MAP_WALL,height + 2);
	}

	//�߽�
	for(x = 0;x <= width+1;x++)
		g_aryMap[x][0] = g_aryMap[x][height + 1] = MAP_GROUND;
	for(y = 1;y <= height;y++)
		g_aryMap[0][y] = g_aryMap[width + 1][y] = MAP_GROUND;
	
	//���ں����
	g_aryMap[1][2] = MAP_ENTRANCE;
	g_aryMap[width][height - 1] = MAP_EXIT;

	//���������Թ�
	TravelMaze(((rand() % (width - 1)) & 0xfffe) + 2, ((rand() % (height - 1)) & 0xfffe) + 2);

	//����Թ�����
	for(x=0;x<=width+1;x++)
		g_aryMap[x][0] = g_aryMap[x][height+1] = MAP_OUTSIDE;
	for(y=1;y<=height ;y++)
		g_aryMap[0][y] = g_aryMap[width+1][y] = MAP_OUTSIDE;

}

//���������Թ�,�Լ�����
void TravelMaze(int x,int y)
{
	//�����������
	int d[4][2] = {0,1,1,0,0,-1,-1,0};

	int n,t,i;

	//�������������
	for(i=0;i<4;i++)
	{
		n = rand()%4;
		t = d[i][0]; d[i][0] = d[n][0]; d[n][0] = t;
		t = d[i][1]; d[i][1] = d[n][1]; d[n][1] = t;
	}

	//����Χ�ĸ�����
	g_aryMap[x][y] = MAP_GROUND;
	for(i=0;i<4;i++)
	{
		if(g_aryMap[x + 2 * d[i][0]][y + 2 * d[i][1]] == MAP_WALL)
		{
			g_aryMap[x + d[i][0]]  [y + d[i][1]] = MAP_GROUND;
			TravelMaze(x+d[i][0]*2,y+d[i][1]*2);  
		}
	}
}

//��ȡ��ҵ�λ������
MAPITEM GetMazeItem(int x,int y)
{
	return (MAPITEM)g_aryMap[x][y];
}

//������Ұ��Χ���Թ�
void paint()
{
	int x1,y1;

	//�����Թ�
	SetWorkingImage(&g_imgSight);
	for(int x=g_rtSight.left;x<=g_rtSight.right;x++)
		for(int y=g_rtSight.top;y<=g_rtSight.bottom;y++)
		{
			x1=(x-g_rtSight.left)*20;
			y1=(y-g_rtSight.top)*20;
			putimage(x1,y1,20,20,&g_imgItem,GetMazeItem(x,y),0);
		}

	//�������
	x1=(g_ptPlayer.x - g_rtSight.left)*20;
	y1=(g_ptPlayer.y - g_rtSight.top)*20;
	putimage(x1,y1,20,20,&g_imgItem,MAP_PLAYER,0);

	//����С��ͼ
	SetWorkingImage(&g_imgGPS);
	cleardevice();
	int tx = (int)((g_ptPlayer.x - 1) * g_szGPS.cx / (double)(g_zsize.cx - 1) + 0.5);
	int ty = (int)((g_ptPlayer.y - 1) * g_szGPS.cy / (double)(g_zsize.cy - 1) + 0.5);
	setlinecolor(YELLOW);
	circle(tx, ty, 1);

	//���»�ͼ����
	SetWorkingImage();
	putimage(150,110,340,260,&g_imgSight,10,10);
	putimage(g_ptGPS.x,g_ptGPS.y,&g_imgGPS);
}

//��ȡ������������
int GetCmd()
{
	int c = 0;
	if (GetAsyncKeyState(VK_LEFT)  & 0x8000) 
		c |=CMD_LEFT;
	if (GetAsyncKeyState(VK_RIGHT)	& 0x8000)
		c |= CMD_RIGHT;
	if (GetAsyncKeyState(VK_UP)		& 0x8000)	
		c |= CMD_UP;
	if (GetAsyncKeyState(VK_DOWN)	& 0x8000)		
		c |= CMD_DOWN;
	if (GetAsyncKeyState('A')		& 0x8000)	
		c |= CMD_LEFT;
	if (GetAsyncKeyState('D')		& 0x8000)		
		c |= CMD_RIGHT;
	if (GetAsyncKeyState('W')		& 0x8000)		
		c |= CMD_UP;
	if (GetAsyncKeyState('S')		& 0x8000)	
		c |= CMD_DOWN;
	if (GetAsyncKeyState(' ')		& 0x8000)	
		c |= CMD_MARKRED;
	if (GetAsyncKeyState('G')		& 0x8000)		
		c |= CMD_MARKGREEN;
	if (GetAsyncKeyState('Y')		& 0x8000)		
		c |= CMD_MARKYELLOW;
	if (GetAsyncKeyState('C')		& 0x8000)	
		c |= CMD_CLEARMARK;
	if  (GetAsyncKeyState('P')      & 0x8000)
		c |= CMD_OPEN;
	if (GetAsyncKeyState(VK_ESCAPE)	& 0x8000)		
		c |= CMD_QUIT;

	return c;
}

//������ҵ�����
void DispatchCmd(int cmd)
{
	if (cmd & CMD_UP){		
		OnUp();}
	if (cmd & CMD_DOWN)	{		
		OnDown();}
	if (cmd & CMD_LEFT)	{		
		OnLeft();}
	if (cmd & CMD_RIGHT){		
		OnRight();}
	if (cmd & CMD_MARKRED){		
		OnMark(MAP_MARKRED);}
	if (cmd & CMD_MARKGREEN){
		OnMark(MAP_MARKGREEN);}
	if (cmd & CMD_MARKYELLOW){
		OnMark(MAP_MARKYELLOW);}
	if (cmd & CMD_CLEARMARK){
		OnMark(MAP_GROUND);}
}

//�����ƶ�
void OnUp()
{
	if(g_ptPlayer.y > 1 && GetMazeItem(g_ptPlayer.x,g_ptPlayer.y-1)!=MAP_WALL)
	{
		g_ptPlayer.y--;
		if(g_ptPlayer.y - g_rtSight.top < 4 && g_rtSight.top > 0)
		{
			g_rtSight.top--;
			g_rtSight.bottom--;
		}
	}
}

//�����ƶ�
void OnLeft()
{
	if (g_ptPlayer.x > 1 && GetMazeItem(g_ptPlayer.x - 1, g_ptPlayer.y) != MAP_WALL && GetMazeItem(g_ptPlayer.x - 1, g_ptPlayer.y) != MAP_ENTRANCE)
	{
		g_ptPlayer.x--;

		if (g_ptPlayer.x - g_rtSight.left < 5 && g_rtSight.left > 0)
		{
			g_rtSight.left--;
			g_rtSight.right--;
		}
	}
}

//�����ƶ�
void OnRight()
{
	if (g_ptPlayer.x < g_zsize.cx && GetMazeItem(g_ptPlayer.x + 1, g_ptPlayer.y) != MAP_WALL)
	{
		g_ptPlayer.x++;

		if (g_rtSight.right - g_ptPlayer.x < 5 && g_rtSight.right <= g_zsize.cx)
		{
			g_rtSight.left++;
			g_rtSight.right++;
		}
	}
}

//�����ƶ�
void OnDown()
{
	if (g_ptPlayer.y < g_zsize.cy && GetMazeItem(g_ptPlayer.x, g_ptPlayer.y + 1) != MAP_WALL)
	{
		g_ptPlayer.y++;

		if (g_rtSight.bottom - g_ptPlayer.y < 4 && g_rtSight.bottom <= g_zsize.cy)
		{
			g_rtSight.top++;
			g_rtSight.bottom++;
		}
	}
}

//�ڵ�ͼ�������
void OnMark(MAPITEM value)
{
	g_aryMap[g_ptPlayer.x][g_ptPlayer.y] = value;
}

//����Ƿ���������
bool check()
{
	if(g_ptPlayer.x==g_zsize.cx/2 && g_ptPlayer.y == g_zsize.cy - 1)
		return 1;
	else
		return 0;
}

//����Ƿ񵽴����
bool CheckWin()
{
	if (g_ptPlayer.x == g_zsize.cx && g_ptPlayer.y == g_zsize.cy - 1)
	{
		HWND hwnd = GetHWnd();
		if (MessageBox(hwnd, _T("��ϲ���߳����ˣ�\n��������һ����"), _T("��ϲ"), MB_YESNO | MB_ICONQUESTION) == IDYES)
		{
			InitGame();
			return false;
		}
		else
			return true;
	}
	return false;
}

//ѯ������Ƿ������Ϸ
bool Quit()
{
	HWND hwnd = GetHWnd();
	return (MessageBox(hwnd, _T("��ȷ��Ҫ�˳���Ϸ��"), _T("ѯ��"), MB_OKCANCEL | MB_ICONQUESTION) == IDOK);
}
