/*
BOJ 1016번: 제곱 ㄴㄴ 수

시간 제한: 2초
메모리 제한: 512 MB

문제
어떤 수 X가 1보다 큰 제곱수로 나누어 떨어지지 않을 때, 제곱ㄴㄴ수라고 한다. 제곱수는 정수의 제곱이다. min과 max가 주어지면, min과 max를 포함한 사이에 제곱ㄴㄴ수가 몇 개 있는지 출력한다.

입력
첫째 줄에 두 정수 min과 max가 주어진다.

출력
첫째 줄에 [min,max]구간에 제곱ㄴㄴ수가 몇 개인지 출력한다. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull Min, Max;
int cnt;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> Min >> Max;

	vector<bool> sieve(Max - Min + 1, true);
	ull i = 2;

	while (i * i <= Max)
	{
		ull fDivNum = Min / (i * i);
		if (Min % (i * i) != 0)
			fDivNum++;

		while (fDivNum * (i * i) <= Max)
		{
			if (sieve[fDivNum * (i * i) - Min])
				sieve[fDivNum * (i * i) - Min] = false;
			fDivNum++;
		}
		i++;
	}

	for (int i = 0; i < sieve.size(); i++)
	{
		if (sieve[i])
			cnt++;
	}

	cout << cnt;
}

/*
에라토스테네스의 체의 응용: 소수와 소수의 배수를 걸러내는 것이 아닌, 제곱수의 배수를 걸러내는 체

memset sieve true //true: 제곱 ㄴㄴ수

ull i = 2 (i는 제곱수 시작점)
에라토스테네스의 체의 응용:
while  i * i <= max //제곱수가 max 이하일때 (에라토스테네스의 체 첫번쨰 for문)
	
	//min~max 범위 내에서 처음으로 제곱수에게 나뉘는 값의 몫 찾기 -> 기존 에라토스테네스의 체처럼 처음(1)부터 고려하는 것이 아닌, 범위 안의 값 만을 고려하기 위함  
	ull fDivNum = min / (i * i)
	if min % (i * i) != 0 //min보다 작을 (범위 밖일 때)
		fDivNum++ //몫+1 해서 몫 결정

	while fDivNum * (i*i) <= max //처음으로 제곱수에게 나뉘는 값부터 이 값의 배수 전부 false (에라토스테네스의 체 두번쨰 for문)
		if sieve[fDivNum * (i*i)-min] == true //제곱수로 나뉜 수가 아니면 (false이면 skip)
			sieve[fDivNum * (i*i)-min] = false
		fDivNum++
	
	i++

for sieve
	if sieve true
		cnt++

ans cnt
*/
