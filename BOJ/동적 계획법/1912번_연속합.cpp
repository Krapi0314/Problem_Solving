/*
BOJ 1912번: 연속합

시간 제한: 1초
메모리 제한: 128 MB

문제
n개의 정수로 이루어진 임의의 수열이 주어진다. 우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다. 단, 수는 한 개 이상 선택해야 한다.
예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자. 여기서 정답은 12+21인 33이 정답이 된다.

입력
첫째 줄에 정수 n(1 ≤ n ≤ 100,000)이 주어지고 둘째 줄에는 n개의 정수로 이루어진 수열이 주어진다. 수는 -1,000보다 크거나 같고, 1,000보다 작거나 같은 정수이다.

출력
첫째 줄에 답을 출력한다. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int dp[100001];

vector<int> v(1);
int n;
int num;
int Max;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	dp[1] = v[1];
	Max = dp[1];

	for (int i = 2; i <= n; i++)
	{
		dp[i] = max(dp[i - 1] + v[i], v[i]); //부분 연속 최댓값이 i번째 값보다 작으면 -> 이전 수들은 버림
		Max = max(Max, dp[i]); //해당 연속 부분합이 지금까지의 부분합 중 최댓값인지 확인
	}

	cout << Max;
}

/*
완전탐색, 최댓값, 동적계획법
bottom-up

dp[n]: n번째 정수까지의 최대 연속 부분합
v[n]: n개의 정수로 이루어진 수열의 값
Max: 연속 부분합 중 최대값

조건: 연속되어야 함
점화식:

경우의 수
1. n-1번째까지의 부분합 + n번쨰 값 > n번째 값 => 부분합 이어가기, dp[n] = dp[n-1] = v[n]
2. n-1번째까지의 부분합 + n번쨰 값 < n번째 값 =< 부분합 끊김, n번쨰부터 새로 시작, dp[n] = v[n]
    
이렇게 구하는 부분합들 중 최댓값을 Max에 갱신 

*/
