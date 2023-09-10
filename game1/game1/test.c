
#include "game.h"

void menu()
{
	printf("**********************************\n");
	printf("*********    1.play   ************\n");
	printf("*********    0.exit   ************\n");
	printf("**********************************\n");
	printf("**********************************\n");
}

void game()
{
	//数据储存 - 二维数组
	char board[ROW][COL];
	//初始化棋盘 - 设为空
	InitBoard(board, ROW, COL);
	//打印棋盘 - 本质是打印棋盘数组内容
	DisplayBoard(board, ROW, COL); 

	char ret = 0;
	while (1)
	{
		//玩家
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断是否赢得游戏
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}

		//电脑
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else if (ret == 'Q')
	{
		printf("平局\n");
	}
}



int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择：");
		scanf_s("%d", &input);
		switch(input)
		{
		case 1:
			printf("游戏开始\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("请重新选择\n");
			break;
		}

	} while (input);

	return 0;
}