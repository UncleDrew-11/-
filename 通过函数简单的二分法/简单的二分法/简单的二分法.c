#include <stdio.h>
int erfen(int arr[], int k,int sz)  //Ҫ��int sz
{
	int right = sz - 1;
	int left = 0;
	int mid = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2;   //int mid�Ķ��� Ҫ��ѭ�����ڽ���
		if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
			break;
		}
    }
	if (left > right)
	{
		return -1;
	}
}
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sz = (sizeof arr / sizeof arr[0]);   // �����ڵı���Ҫ���������ڶ���
	int k = 7;
	int ret = 0;
	ret = erfen(arr, k,10);   //szҪ�Ž�����
	if (ret == -1)
	{
		printf("�Ҳ���\n");
	}
	else
	{
		printf("�ҵ��ˣ��±���%d\n", ret);
	}

	return 0;
}