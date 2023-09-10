#include"game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("*****************************************\n");
	for (i = 0; i <= row; i++)
	{
		printf(" %d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++) 
	{
		printf(" %d ", i);
		for (j = 1; j <= col; j++)
		{
			printf(" %c ", board[i][j]);
		}
		printf("\n");
	}
	printf("*****************************************\n");
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = MINE;
	while (count)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

static get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] +
		mine[x - 1][y] - 8 * '0';
}

void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col)
{
	int win = 0;
	while (win < row * col - MINE)
	{
		printf("ÇëÊäÈë×ø±ê£º");
		int x = 0;
		int y = 0;
		scanf_s("%d %d", &x, &y);
		if (x > 0 && x <= row && y>0 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("Äã±»Õ¨ÁË\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else
			{
				int count = get_mine_count(mine, x, y);
				show[x][y] = count+'0';
				DisplayBoard(show, ROW, COL);
				win++;
			}
		}
		else
			printf("×ø±ê´íÎó\n");
	}
	if (win == row * col - MINE)
	{
		printf("ÄãÓ®ÁË");
		DisplayBoard(mine, ROW, COL);
	}
}



