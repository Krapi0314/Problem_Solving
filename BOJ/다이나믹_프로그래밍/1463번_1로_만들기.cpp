/*
BOJ 1463번: 1로 만들기

시간 제한: 2초
메모리 제한: 128 MB

문제
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

X가 3으로 나누어 떨어지면, 3으로 나눈다.
X가 2로 나누어 떨어지면, 2로 나눈다.
1을 뺀다.

정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.

입력
첫째 줄에 1보다 크거나 같고, 106보다 작거나 같은 정수 N이 주어진다.

출력
첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int n;
int dp[1000001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	dp[1] = 0;

	for (int i = 2; i <= n; i++) //bottom-up 방식
	{
		//1부터 뺴는 연산을 해서 dp에 최대의 가능성이 있는 값들부터 넣은 후, 2로 나눌때와 3으로 나눌때의 연산횟수를 비교해서 최종적으로 dp에 최솟값 판단해 저장
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)
		{
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
		if (i % 3 == 0)
		{
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
	}

	cout << dp[n];
}

/*
연산을 사용하는 횟수의 최솟값을 출력하시오.
연산은 다음 세 가지임
	1. X가 3으로 나누어 떨어지면, 3으로 나눈다.
	2. X가 2로 나누어 떨어지면, 2로 나눈다.
	3. 1을 뺀다.

n 입력

top-down 재귀함수 x
for문으로 dp

!!top-down(recursive) 방식이 아닌 bottom-up(반복문) 방식을 이용하여 풀자!
*/
