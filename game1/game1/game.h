#pragma once

//ͷ�ļ��İ���
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//���ŵĶ��� 

#define ROW 3  //��
#define COL 3  //��

//����������

//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);

//��ӡ���̺���
void DisplayBoard(char board[ROW][COL], int row, int col);

//�������
void PlayerMove(char board[ROW][COL], int row, int col);

//��������
void ComputerMove(char board[ROW][COL], int row, int col);

//�ж��Ƿ�Ӯ����Ϸ

//��һ�ʤ *
//���Ի�ʤ #
//ƽ��     Q
//����     C

char IsWin(char board[ROW][COL], int row, int col);