#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void menu()
{
	printf("**************\n");
	printf("****1.play****\n");
	printf("****0.exit****\n"); 
	printf("**************\n");
}
void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	while (1)
	{

		PlayerMove(board, ROW, COL);
		CheckWin2(board, ROW, COL);
		ret = CheckWin2(board, ROW, COL);
        /*DisplayBoard(board, ROW, COL);*/
		if (ret != ' ')
		{
			break;
		}
		srand((unsigned int)time(NULL));
        ComputerMove(board, ROW, COL);
		CheckWin2(board, ROW, COL);
		int ret = CheckWin2(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		if (ret != ' ')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
		DisplayBoard(board, ROW, COL);
	}
	if (ret == '#')
	{
		printf("����Ӯ\n");
		DisplayBoard(board, ROW, COL);
	}
	if (ret == 'q')
	{
		printf("��ƽ��\n");
		DisplayBoard(board, ROW, COL);
	}
}
int main()
{
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			printf("\n");
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("���������������\n");
			break;
		}
	} while (input);
	return 0;
}