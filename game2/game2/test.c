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
	//��������
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	//��ʼ������
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//��ӡ����
	DisplayBoard(show, ROW, COL);
	//DisplayBoard(mine, ROW, COL);

	//����
	SetMine(mine, ROW, COL);
	//����
	FindMine(mine, show, ROW, COL);

}

int main()
{
	int input = 0;
	
	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("��ѡ��:");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			printf("��ʼ��Ϸ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("����������������룺\n");
			break;
		}
	} while (input);



	return 0;
}