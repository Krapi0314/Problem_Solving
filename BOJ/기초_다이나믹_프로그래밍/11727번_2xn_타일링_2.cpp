/*
BOJ 11727번: 2xn 타일링 2 

시간 제한: 1초
메모리 제한: 256 MB 

문제
2×n 직사각형을 1×2, 2×1과 2×2 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.
아래 그림은 2×17 직사각형을 채운 한가지 예이다.

입력
첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)

출력
첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int n;
int dp[1001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
	}

	cout << dp[n];
}

/*
방법의 수, 동적계획법
bottom-up

dp[n]: 2xn 직사각형에 타일로 채우는 방법의 수

점화식
	i번쨰 타일의 방법의 수 = i-1번쨰 타일에서 1*2 타일 하나 붙이기 + i-2번째 타일에서 2*1 타일 하나 OR 2*2 타일 2개 붙이는 경우
	dp[i] = dp[i-1] + dp[i-2] * 2
*/
