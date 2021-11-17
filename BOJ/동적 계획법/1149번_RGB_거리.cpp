/*
BOJ 1149번: RGB 거리

시간 제한: 0.5초 (추가 시간 없음)
메모리 제한: 128 MB

문제
RGB거리에는 집이 N개 있다. 거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.
집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다. 각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때, 아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값을 구해보자.

1번 집의 색은 2번 집의 색과 같지 않아야 한다.
N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.

입력
첫째 줄에 집의 수 N(2 ≤ N ≤ 1,000)이 주어진다. 둘째 줄부터 N개의 줄에는 각 집을 빨강, 초록, 파랑으로 칠하는 비용이 1번 집부터 한 줄에 하나씩 주어진다. 집을 칠하는 비용은 1,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 모든 집을 칠하는 비용의 최솟값을 출력한다. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int n;
int house[1001][3];
int dp[1001][3];
int Min = 123456789;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> house[i][j];
		}
	}

	dp[1][0] = house[1][0];
	dp[1][1] = house[1][1];
	dp[1][2] = house[1][2];

	for (int i = 2; i <= n; i++)
	{
		dp[i][0] = min(dp[i - 1][1]+house[i][0], dp[i - 1][2]+house[i][0]);
		dp[i][1] = min(dp[i - 1][2]+house[i][1], dp[i - 1][0]+house[i][1]);
		dp[i][2] = min(dp[i - 1][0]+house[i][2], dp[i - 1][1]+house[i][2]);
	}

	Min = min(dp[n][0], dp[n][1]);
	Min = min(Min, dp[n][2]);
	cout << Min;
}

/*
DP

dp[n]: n개의 집 칠하는 최소 비용

dp[n][i] = min(dp[n-1][n-1에 칠하지 않은 색 1]+house[n][i],dp[n-1][n-1에 칠하지 않은 색 2]+house[n][i])
dp[1] (시작점)에 따라 최소 비용도 달라짐

모든 시작점에 대해 계산한 뒤, min 구하기
*/
