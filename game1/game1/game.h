#pragma once

//头文件的包含
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//符号的定义 

#define ROW 3  //行
#define COL 3  //列

//函数的声明

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);

//打印棋盘函数
void DisplayBoard(char board[ROW][COL], int row, int col);

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);

//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);

//判断是否赢得游戏

//玩家获胜 *
//电脑获胜 #
//平局     Q
//继续     C

char IsWin(char board[ROW][COL], int row, int col);