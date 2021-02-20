#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include "conio.h"
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
	ballx=bally=1;
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
void gameStart()
{
	int i,j;
	system ("color 4b");
	while(1)
	{
		
		for (i=1;i<=40;i++)
		{
			if(kbhit())
			return;
			for (j=1;j<=i;j++)
			{
				printf(" ");
			}
			printf("         *         \n");
			for (j=1;j<=i;j++)
			{
				printf(" ");
			}
			printf("         *         \n");
			for (j=1;j<=i;j++)
			{
				printf(" ");
			}
			printf("   *************   \n");
			for (j=1;j<=i;j++)
			{
				printf(" ");
			}
			printf("         *         \n");
			for (j=1;j<=i;j++)
			{
				printf(" ");
			}
			printf("     *********     \n\n");
			for (j=1;j<=i;j++)
			{
				printf(" ");
			}
			printf("       *****       \n");
			for (j=1;j<=i;j++)
			{
				printf(" ");
			}
			printf("       *   *       \n");
			for (j=1;j<=i;j++)
			{
				printf(" ");
			}
			printf("       *****       \n");
			Sleep(50);
			system("cls");
		}

			for (i=40;i>=1;i--)
			{
				if(kbhit())
				return;
				for (j=1;j<=i;j++)
				{
					printf(" ");
				}
				printf("         *         \n");
				for (j=1;j<=i;j++)
				{
					printf(" ");
				}
				printf("         *         \n");
				for (j=1;j<=i;j++)
				{
					printf(" ");
				}
				printf("   *************   \n");
				for (j=1;j<=i;j++)
				{
					printf(" ");
				}
				printf("         *         \n");
				for (j=1;j<=i;j++)
				{
					printf(" ");
				}
				printf("     *********     \n\n");
				for (j=1;j<=i;j++)
				{
					printf(" ");
				}
				printf("       *****       \n");
				for (j=1;j<=i;j++)
				{
					printf(" ");
				}
				printf("       *   *       \n");
				for (j=1;j<=i;j++)
				{
					printf(" ");
				}
				printf("       *****       \n");
				Sleep(50);
				system("cls");
			}
	/*char flag;
	printf("Enter Menu? (yorY)");
	fflush (stdin);
	scanf("%c",&flag);
	if(flag=='Y'||flag=='y')
	break;*/
	}
}
int level=1;
void Entermenu()
{
	system("cls");
	printf("**************************\n");
	printf("*     1.    Start        *\n");
	printf("*     2. Select Level    *\n");
	printf("*     3.   Contral       *\n");
	printf("*     4.     Exit        *\n");
	printf("**************************\n");
}
void Enterselect()
{
	system("cls");
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	printf("@      1.Very difficult     @\n");
	printf("@      2.  Difficult        @\n");
	printf("@      3.    Easy           @\n");
	printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	scanf("%d",&level);
}
void Entercontrol()
{
	system("cls");
	printf("*******************\n");
	printf("* left:A  right:D *\n");
	printf("*     Fight:G     *\n");
	printf("*   Jump:H        *\n");
	printf("*******************\n");
	getchar();
	getchar();
}
int main()
{
	gameStart();
	system("color 4b");
	while(1)
	{
		Entermenu();
		int n;
		scanf("%d",&n);
		if(n==1)
		{
			system("cls");
			//初始化
			showInit();
			//输出边框
			showBoundry();
			//输出小球
			showBall();
		}
		else if(n==2)
		{
			Enterselect();
		}
		else if(n==3)
		{
			Entercontrol();
		}
		else if(n==4)
		{
			system("cls");
			printf("\n\n     Game    Over   \n\n");
			exit(0);
		}
		else
		{
			printf("Select ERROR! Please select again!\n");
			Sleep(3000);
		}
	}
	return 0;
}