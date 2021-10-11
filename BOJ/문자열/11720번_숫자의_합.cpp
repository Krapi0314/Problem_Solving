/*
BOJ 11720번: 숫자의 합

시간 제한: 1초
메모리 제한: 256 MB

문제
N개의 숫자가 공백 없이 쓰여있다. 이 숫자를 모두 합해서 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 숫자의 개수 N (1 ≤ N ≤ 100)이 주어진다. 둘째 줄에 숫자 N개가 공백없이 주어진다.

출력
입력으로 주어진 숫자 N개의 합을 출력한다. 
*/

#include <iostream>

using namespace std;

int main(void)
{
	int N;
	char arr[101];
	int result = 0;
	cin >> N;
	cin >> arr;
	
	for (int i = 0; i < N; i++)
	{
		result += arr[i] - '0';
	}
	cout << result << endl;
	return 0;
}
