//��һ�������ĸ�λ�ۼӣ�NowCoder����Ϊ����λ�͡�������������123456����λ����1+2+3+4+5+6=21��
//���ڣ������æ����һ������n��r�����µ���λ�ͣ�������Ӧ�Ľ�����������
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	while (scanf("%d%d", &a, &b) != EOF)
	{
		int count = 0;
		while (a)
		{
			count = count + a%b;
			a = a / b;
		}
		//count�����Ǹ���λ��֮��
		int arr[32] = { 0 };//������Ϊ��ת��b����
		int i = 0;
		while (count)
		{//��ӡcountת��b���ƺ��ÿһλ����������֮��
			arr[i] = count % b;
			i++;
			count = count / b;//ͨ���ٷֺżӳ��ŵķ�ʽ����
		}
		while (--i <= 0)//ÿ��һ��ѭ��֮ǰi��ȥ1
		{
			if (arr[i] < 10)//ʮ��������
			{
				printf("%d", arr[i]);
			}
			else//ʮ������
			{
				printf("%c", arr[i] - 10 + 'A');
			}
		}
	}
	return 0;
}