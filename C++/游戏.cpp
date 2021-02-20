#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
int ballx,bally;
int ballvx,ballvy;
int wide,height;
int count=0;
int countBlock=0;
int blockx,blocky;
void showInit()
{
	wide=50;
	height=30;
	ballx=rand()%wide;
	bally=rand()%height;
	ballvx=ballvy=1;
	blockx=rand()%wide;
	blocky=rand()%height;
}
void gotoxy(int x,int y)
{
	HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(handle,pos);
}
void showBoundry()
{
		int i,j;
		for(i=1;i<height;i++)
		{
			for(j=1;j<wide;j++)
				printf(" ");
			printf("|\n");
		}
		for(i=1;i<=wide;i++)
			printf("-");
}
void showBall()
{
	gotoxy(wide+10,height/2);
	printf("小秋的碰壁次数： %d",count);
	gotoxy(wide+10,height/2+1);
	printf("小秋的碰障碍次数： %d",countBlock);
	while(1)
	{
		gotoxy(blockx,blocky);
		printf("*");
		gotoxy(blockx -8,blocky + 3);
		printf("@");
		gotoxy(blockx ,blocky + 4);
		printf("@");
		gotoxy(ballx,bally);
		printf("o");
		Sleep(100);
		gotoxy(ballx,bally);
		printf(" ");
		if(ballx==blockx && bally==blocky)
		{
			countBlock++;
			blockx=rand()%wide;
			blocky=rand()%height;
			blockx=rand()%wide;
			blocky=rand()%height;
			blockx=rand()%wide;
			blocky=rand()%height;
			gotoxy(wide+10,height/2+1);
			printf("小秋的碰障碍次数： %d",countBlock);
		}
		if(ballx==wide-2 || ballx==0)
		{
			count++;
			ballvx=-ballvx;
			gotoxy(wide+10,height/2);
			printf("小秋的碰壁次数： %d",count);
			gotoxy(wide+10,height/2+1);
			printf("小秋的碰障碍次数： %d",countBlock);
		}
		if(bally==height-2 || bally==0)
		{
			count++;
			ballvy=-ballvy;
			gotoxy(wide+10,height/2);
			printf("小秋的碰壁次数： %d",count);
			gotoxy(wide+10,height/2+1);
			printf("小秋的碰障碍次数： %d",countBlock);
		}
		ballx+=ballvx;
		bally+=ballvy;
	}
}
int main()
{
	system("color 4b");
	//初始化
	showInit();
	//输出边框
	showBoundry();
	//输出小球
	showBall();
	return 0;
}