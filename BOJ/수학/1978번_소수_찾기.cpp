/*
BOJ 1978번: 소수 찾기

시간 제한: 2초
메모리 제한: 128 MB

 문제
주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.

입력
첫 줄에 수의 개수 N이 주어진다. N은 100이하이다. 다음으로 N개의 수가 주어지는데 수는 1,000 이하의 자연수이다.

출력
주어진 수들 중 소수의 개수를 출력한다.
*/

#include <iostream>

using namespace std;

int cnt = 0;

int main(void)
{
	int n;
	int arr[100];
	int num[1001] = { 0, 1 }; //0은 소수, 1은 소수가 아닌 수
	int cnt = 0;

	//체, 1000 sqrt인 31이하의 수의 배수만 제거
	for (int i = 2; i <= 31; i++)
	{
		for (int j = 2; j * i <= 1000; j++)
		{
			num[j * i] = 1;
		}
	}

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (num[arr[i]] == 0)
			cnt++;
	}

	cout << cnt;
}

/*
소수 구하기: 에라토스테네스의 체 활용
	n 이하의 소수를 모두 찾으려 할 때 
		for(int i =2; i<= sqrt(n); i++) 
			for(int j=2; j*i <= n; j++)
				not_prime[j*i] = true
				
		for(int i=0; i<n; i++)
			if(!not_prime[i])
				i는 소수(prime)임 
/*
