#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a = 0, b = 0,temp=0;
	printf("����������\n");
	scanf("%d%d", &a, &b);
	if (a < b);
	{
		temp = a;
		a = b;
		b = temp;
	}
	int i = 0;
	for (i = b; i > 0; i--)
	{
		if (a%i == 0 && b%i == 0)
		{
			printf("���Լ��%d",i);
		}
	}
	return 0;
}