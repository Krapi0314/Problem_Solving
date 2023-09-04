/*
baekjoon 2750��: �� �����ϱ�
 
�ð� ����: 1��
�޸� ����: 128 MB
 
����
N���� ���� �־����� ��, �̸� ������������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� ���� N(1 �� N �� 1,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ���ڰ� �־�����. �� ���� ������ 1,000���� �۰ų� ���� �����̴�. ���� �ߺ����� �ʴ´�.

���
ù° �ٺ��� N���� �ٿ� ������������ ������ ����� �� �ٿ� �ϳ��� ����Ѵ�.
*/

#include <iostream>

using namespace std;

//bubble sort
void bubble_sort(int arr[], int n)
{
	int temp;
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main(void)
{
	int N;
	int arr[1000];

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	bubble_sort(arr, N);
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << endl;
	}
	return 0;
}
