
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
	//���ݴ��� - ��ά����
	char board[ROW][COL];
	//��ʼ������ - ��Ϊ��
	InitBoard(board, ROW, COL);
	//��ӡ���� - �����Ǵ�ӡ������������
	DisplayBoard(board, ROW, COL); 

	char ret = 0;
	while (1)
	{
		//���
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж��Ƿ�Ӯ����Ϸ
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}

		//����
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
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else if (ret == 'Q')
	{
		printf("ƽ��\n");
	}
}



int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��");
		scanf_s("%d", &input);
		switch(input)
		{
		case 1:
			printf("��Ϸ��ʼ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("������ѡ��\n");
			break;
		}

	} while (input);

	return 0;
}