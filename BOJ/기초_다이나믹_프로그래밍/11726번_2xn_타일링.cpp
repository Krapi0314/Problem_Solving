/*
BOJ 11726번: 2xn 타일링

시간 제한: 1초
메모리 제한: 256 MB

문제
2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.
아래 그림은 2×5 크기의 직사각형을 채운 한 가지 방법의 예이다.

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
	dp[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007; //이미 i 이전 값들은 10007 이하의 값으로 저장되어 있으므로, % 연산은 한번만
	}

	cout << dp[n];
}

/*
Bottom-up DP 반복문
점화식: dp[n] = dp[n-2] + dp[n-1]
+ 모듈러 연산

n 입력

dp[1] = 1
dp[2] = 2

for i 3 to n
	dp[n] = ((dp[n-2] % 10007) + (dp[n-3] % 10007)) % 10007

cout dp[n]
	
*/
