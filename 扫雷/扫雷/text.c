#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void menu()
{
	printf("**********************\n");
	printf("******1.  play********\n");
	printf("******0.  exit********\n");
	printf("**********************\n");
}
void game()
{
	char MineBoard[ROWS][COLS] = { 0 };
	char ShowBoard[ROWS][COLS] = { 0 };
	InitBoard(MineBoard, ROWS,COLS, '0');
	Display(MineBoard, ROWS, COLS);
	InitBoard(ShowBoard, ROWS, COLS, '*');
	Display(ShowBoard, ROW, COL);

	//PlayerMove(MineBoard[ROWS][COLS], ROW, COL);
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
		{case 1:
			game();
			break;
		case 0:
			printf("�����˳�\n");
			break;
		default:
			printf("�������������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}