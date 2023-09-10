#include "game.h"

void menu()
{
	printf("*****************************\n");
	printf("*****************************\n");
	printf("*********   1.play  *********\n");
	printf("*********   0.exit  *********\n");
	printf("*****************************\n");
	printf("*****************************\n");

}

void game()
{
	//定义数组
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//打印棋盘
	DisplayBoard(show, ROW, COL);
	//DisplayBoard(mine, ROW, COL);

	//布雷
	SetMine(mine, ROW, COL);
	//排雷
	FindMine(mine, show, ROW, COL);

}

int main()
{
	int input = 0;
	
	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("请选择:");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入：\n");
			break;
		}
	} while (input);



	return 0;
}