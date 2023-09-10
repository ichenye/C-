#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if(j < col-1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}

}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while(1)
	{
		printf("请输入坐标：");
		scanf_s("%d %d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (board[x-1][y-1] == ' ')
			{
				board[x-1][y-1] = '*';
				break;
			}
			else
			{
				printf("坐标位置已被占，请重新输入：\n");
			}
		}
		else
		{
			printf("坐标错误，请重新输入：\n");
		}
	}
}


void ComputerMove(char board[ROW][COL], int row, int col) 
{
	printf("电脑走：\n");

	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
 

int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;		//棋盘没满
			}
		}
	}
	return 1;					//棋盘满了
}

char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//判断行
	for (j = 0; j < col; j++)
	{
		int P_count = 0;
		int C_count = 0;
		for (i = 0; i < row; i++)
		{
			if (board[i][j] == '*')
			{
				P_count++;
			}
			if (board[i][j] == '#')
			{
				C_count++;
			}
			if (P_count == row || C_count == row)
			{
				return board[i][j];
			}
		}
	}
	//判断列
	for (i = 0; i < row; i++)
	{
		int P_count = 0;
		int C_count = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == '*')
			{
				P_count++;
			}
			if (board[i][j] == '#')
			{
				C_count++;
			}
			if (P_count == col || C_count == col)
			{
				return board[i][j];
			}
		}
	}
	//判断对角线
	int P_count = 0;
	int C_count = 0;
	for (i = 0, j = 0; i < row && j < col; i++, j++)
	{
		if (board[i][j] == '*')
		{
			P_count++;
		}
		if (board[i][j] == '#')
		{
			C_count++;
		}
		if (P_count == row || C_count == row)
		{
			return board[i][j];
		}
	}
	P_count = 0;
	C_count = 0;
	for (i = 0, j = col - 1; i < row && j >= 0; i++, j--)
	{
		if (board[i][j] == '*')
		{
			P_count++;
		}
		if (board[i][j] == '#')
		{
			C_count++;
		}
		if (P_count == row || C_count == row)
		{
			return board[i][j];
		}
	}

	//平局
	int ret = IsFull(board, row, col);
	if (ret == 1)
	{
		return 'Q';
	}
	//继续
	return 'C';
}