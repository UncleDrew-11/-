#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void InitBoard(char MineBoard[ROWS][COLS], int row, int col, char set)//��ʼ������
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			MineBoard[i][j] = set;
		}
	}
}
void Display(char board[ROWS][COLS], int row, int col)//��ӡ����
{
	{
		int i = 0;
		int j = 0;
		printf("   ");
		for (j = 0; j < col ; j++)//�����
		{
			printf("%d   ",j+1);

		}
		printf("\n");
		for (i = 1; i <= row; i++)
		{
			printf("%d", i);//�����
			printf(" ");
			for (j = 1; j <= col; j++)
			{
				printf(" %c ", board[i][j]);
				if (j <= col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
			printf("  ");
			for (j = 1; j <= col; j++)
			{
				if (i <= row - 1)
				{
					printf("---");
					if (j <= col - 1)
					{
						printf("|");
					}
				}
			}
			printf("\n");

		}
	}
}
void PutMine(char board[ROWS][COLS], int row, int col)//������
{
	int x = 0;
	int y = 0;
	int count = MINE;
	while (count)
	{
		x = rand() % MINE + 1;
		y = rand() % MINE + 1;
		if (x>0 && x <= row && y>0 && y <= col && board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}
int NearMine(char mine[COLS][ROWS], int x, int y)
{
	return mine[x-1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}
void NoMine(char mine[ROWS][COLS], char show[ROWS][COLS],int x,int y)
{
	int ret = NearMine(mine, x, y);
	if (ret == 0)
	{
		show[x][y] = ' ';
		if ((x - 1)>0 && (y - 1)>0 && (show[x - 1][y - 1] == '*'))
			NoMine(mine, show, x - 1, y - 1);

		if ((x - 1)>0 && (y)>0 && (show[x - 1][y] == '*'))
			NoMine(mine, show, x - 1, y);

		if ((x - 1)>0 && (y + 1)>0 && (show[x - 1][y + 1] == '*'))
			NoMine(mine, show, x - 1, y + 1);

		if ((x)>0 && (y - 1)>0 && (show[x][y - 1] == '*'))
			NoMine(mine, show, x, y - 1);

		if ((x)>0 && (y + 1)>0 && (show[x][y + 1] == '*'))
			NoMine(mine, show, x, y + 1);

		if ((x + 1)>0 && (y - 1)>0 && (show[x + 1][y - 1] == '*'))
			NoMine(mine, show, x + 1, y - 1);

		if ((x + 1)>0 && (y)>0 && (show[x + 1][y] == '*'))
			NoMine(mine, show, x + 1, y);

		if ((x + 1)>0 && (y + 1)>0 && (show[x + 1][y + 1] == '*'))
			NoMine(mine, show, x - 1, y - 1);
	}
	else
	{
		show[x][y] = ret + '0';
	}
}
int CountBlank(char show[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int count = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (show[i][j] == '*')
				count++;
		}
	}
	return count;
}
void Saolei(char mine[ROWS][COLS],char show[ROWS][COLS],int row, int col)
{
	int x = 0;
	int y = 0;
	int flag = 1;
	int ret = 0;
	int count = 0;
	do
	{
		printf("������ɨ������:>");
		scanf("%d%d", &x, &y);
		count++;
		{
			if (x >= 1 && x <= row && y >= 1 && y <= col)
			{
				if (mine[x][y] == '0' && show[x][y] == '*')
				{
					NoMine(mine, show, x, y);
					/*Display(mine, ROW, COL);*/
					Display(show, ROW, COL);
					ret = CountBlank(show, ROW, COL);
					if (ret == MINE)
					{
						printf("��Ӯ��\n");
						break;
					}
				}
				if (mine[x][y] == '1' && show[x][y] == '*'&& count == 1)
				{
					printf("���������ˣ���һ�����Ӳ���ը��\n");
				}
				if (mine[x][y] == '1' && show[x][y] == '*'&& count != 1)
				{
					show[x][y] = 'S';
					Display(show, ROW, COL);
					printf("�㱻ը����,��ͼ����\n");
					Display(mine, ROW, COL);
					flag = 0;
				}
			}
			else
			{
				printf("����Ƿ�����������\n");
			}
		}
	} while (flag);
}