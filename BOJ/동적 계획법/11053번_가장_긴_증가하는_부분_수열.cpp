/*
BOJ 11053번: 가장 긴 증가하는 부분 수열

시간 제한: 1초
메모리 제한: 256 MB

문제
수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 가장 긴 증가하는 부분 수열은 {10, 20, 30, 50} 이고, 길이는 4이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.
둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int n;
int dp[1001];
vector<int> v(1001);
int Max;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}

	Max = 0;
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		for (int j = 1; j <= i-1; j++)
		{
			if (v[j] < v[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		Max = max(Max, dp[i]);
	}

	cout << Max;
}

/*
가장 긴 증가하는 부분 수열 LIS의 길이를 출력한다

완전탐색, 최적화, 동적 계획법
bottom-up

dp[n]: n개의 원소를 가진 수열에서 증가하는 부분 수열의 길이
v[n]: 수열 n번쨰 원소
Max: dp값 중 가장 큰 값 = LIS의 최댓값

점화식

dp[n]은:1 ~ n-1에서 v[n]보다 작은 원소들 중, LIS가 가장 큰 원소 + 1
(v[n]을 기준으로, v[n]보다 작은 1~n-1 인덱스의 원소들 중 가장 큰 LIS를 가진 수열에 v[n]를 붙이면, 이 수열이 가장 큰 LIS로 갱신되기 때문)

!!핵심: dp[n]에서, 인덱스 n인 v[n]보다 작은 인덱스 1~n-1인 v[i]들을 탐색하는 과정
(이 문제 같은 경우는 현재의 자신 값을 기준으로 과거의 값들을 돌아봐서 그 중 최대의 값으로 자신의 최대 길이를 정하는 문제이다)
*/
