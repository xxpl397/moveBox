#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

//初始化游戏，静态的游戏面板画出来
void initGame();
//移动人物，实现推箱子
void moveBox();
//判断输赢
void judge();
//用0:空地 1:墙 3:目的地 4:箱子 5:人

int map[9][9]={
	{1,1,1,1,1,0,0,0,0},
	{1,5,0,0,1,0,0,0,0},
	{1,0,4,4,1,0,1,1,1},
	{1,0,4,0,1,0,1,3,1},
	{1,1,1,0,1,1,1,3,1},
	{0,1,1,0,0,0,0,3,1},
	{0,1,0,0,0,1,0,0,1},
	{0,1,0,0,0,1,1,1,1},
	{0,1,1,1,1,1,0,0,0}
};

int main()
{
	while(1)
	{
		initGame();
		moveBox();
		judge();
	}
	return 0;
}

void initGame()
{
	system("cls");//清屏
	//用循环遍历每一个元素
	for(int i=0;i<9;i++)//i当成行
	{
		for(int j=0;j<9;j++)//j当成列
		{
			//条件分支语句
			switch(map[i][j])
			{
				case 0://空地
					printf("  ");//两个空格
					break;
				case 1:
					printf("■");
					break;
				case 3://目的地
					printf("☆");
					break;
				case 4:
					printf("◇");
					break;
				case 5:
				case 8://人站在目的地上的情况
					printf("♀");
					break;
					//箱子加上目的地
				case 7:
					printf("★");
					break;
			}
		}
		printf("\n");
	}

}


//找到人，然后进行相应的判断
void moveBox()
{
	int m,n;//代表人所在地方的数组下标
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(map[i][j]==5||map[i][j]==8)//找到人
			{
				m=i;
				n=j;
			}
		}
	}
	switch(getch())//获取键盘按键
	{
		//向上走
		case 72:
		case 'w':
		case 'W':
			//人前面是空地或者目的地
			if(map[m-1][n]==0||map[m-1][n]==3)
			{
				map[m][n]-=5;//a-=5 相当于 a=a-5
				map[m-1][n]+=5;
			}
			//人前面是箱子
			else if(map[m-1][n]==4||map[m-1][n]==7)
			{
				//箱子前面是空地或者目的地
				if(map[m-2][n]==0||map[m-2][n]==3)
				{
					map[m][n]-=5;
					map[m-1][n]+=1;
					map[m-2][n]+=4;
				}
			}
			break;
		case 80:
		case 's':
		case 'S':
			//人前面是空地或者目的地
			if(map[m+1][n]==0||map[m+1][n]==3)
			{
				map[m][n]-=5;//a-=5 相当于 a=a-5
				map[m+1][n]+=5;
			}
			//人前面是箱子
			else if(map[m+1][n]==4||map[m+1][n]==7)
			{
				//箱子前面是空地或者目的地
				if(map[m+2][n]==0||map[m+2][n]==3)
				{
					map[m][n]-=5;
					map[m+1][n]+=1;
					map[m+2][n]+=4;
				}
			}
			break;
		case 75:
		case 'a':
		case 'A':
			//人前面是空地或者目的地
			if(map[m][n-1]==0||map[m][n-1]==3)
			{
				map[m][n]-=5;//a-=5 相当于 a=a-5
				map[m][n-1]+=5;
			}
			//人前面是箱子
			else if(map[m][n-1]==4||map[m][n-1]==7)
			{
				//箱子前面是空地或者目的地
				if(map[m][n-2]==0||map[m][n-2]==3)
				{
					map[m][n]-=5;
					map[m][n-1]+=1;
					map[m][n-2]+=4;
				}
			}
			break;
		case 77:
		case 'd':
		case 'D':
			//人前面是空地或者目的地
			if(map[m][n+1]==0||map[m][n+1]==3)
			{
				map[m][n]-=5;//a-=5 相当于 a=a-5
				map[m][n+1]+=5;
			}
			//人前面是箱子
			else if(map[m][n+1]==4||map[m][n+1]==7)
			{
				//箱子前面是空地或者目的地
				if(map[m][n+2]==0||map[m][n+2]==3)
				{
					map[m][n]-=5;
					map[m][n+1]+=1;
					map[m][n+2]+=4;
				}
			}
			break;
	}
}

void judge()
{
	int win=0;
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(map[i][j]==7)
			{
				win++;
			}
		}
	}
	if(win==3)
	{
		MessageBox(NULL, L"恭喜你，你赢了",L"推箱子",MB_OK);
		exit(0);
	}
}
