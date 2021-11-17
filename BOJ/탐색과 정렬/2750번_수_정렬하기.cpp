/*
BOJ 2750번: 수 정렬하기
 
시간 제한: 1초
메모리 제한: 128 MB
 
문제
N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000)이 주어진다. 둘째 줄부터 N개의 줄에는 숫자가 주어진다. 이 수는 절댓값이 1,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

출력
첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
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
