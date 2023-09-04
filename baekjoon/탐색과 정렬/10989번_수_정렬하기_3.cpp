/*
baekjoon 10989��: �� �����ϱ� 3

�ð� ����: 3��
�޸� ����: 8 MB

����
N���� ���� �־����� ��, �̸� ������������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� ���� N(1 �� N �� 10,000,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ���ڰ� �־�����. �� ���� 10,000���� �۰ų� ���� �ڿ����̴�.

���
ù° �ٺ��� N���� �ٿ� ������������ ������ ����� �� �ٿ� �ϳ��� ����Ѵ�.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
using namespace std;

int main(void)
{
	int arr[10001] = { 0, };
	int temp;
	int N;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &temp);
		arr[temp]++; 
	}

	for (int i = 1; i <= 10000; i++)
	{
		for (int j = 0; j < arr[i]; j++)
		{
			printf("%d\n", i);
		}
	}
}
