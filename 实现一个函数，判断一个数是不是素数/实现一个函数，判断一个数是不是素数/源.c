#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int judge(int num)
{
	int i = 0;
	for (i = 2; i < num; i++)
	{
		if (num % i == 0)
		{
			return 0;
		}
		else
		{
			continue;
		}
		return 1;
	}
}
int main()
{
	int num = 0;
	scanf("%d", &num);
	if (judge(num))
	{
		printf("������\n");
	}
	else
	{
		printf("��������\n");
	}
	return 0;
}