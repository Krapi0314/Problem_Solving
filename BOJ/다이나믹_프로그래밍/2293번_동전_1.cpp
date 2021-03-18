/*
BOJ 2293번: 동전 1

시간 제한: 0.5초
메모리 제한: 4 MB

문제
n가지 종류의 동전이 있다. 각각의 동전이 나타내는 가치는 다르다. 이 동전을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다. 그 경우의 수를 구하시오. 각각의 동전은 몇 개라도 사용할 수 있다.
사용한 동전의 구성이 같은데, 순서만 다른 것은 같은 경우이다.

입력
첫째 줄에 n, k가 주어진다. (1 ≤ n ≤ 100, 1 ≤ k ≤ 10,000) 다음 n개의 줄에는 각각의 동전의 가치가 주어진다. 동전의 가치는 100,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 경우의 수를 출력한다. 경우의 수는 231보다 작다.
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int n, k;
int dp[10001];
int coin[101];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> coin[i];
	}

	dp[0] = 1; //동전으로 가치 0을 만드는 경우의 수: 아무 동전도 쓰지 못하는 경우 1가지


	for (int i = 1; i <= n; i++) //동전
	{
		for (int j = coin[i]; j <= k; j++) //가치의 합, coin[i] 미만의 동전에서는 추가될 경우의 수가 없으므로, j=coin[i]부터 시작 
		{
			dp[j] += dp[j - coin[i]]; //2차원 점화식의 절약형
		}
	}

	cout << dp[k];
}

/*
동적계획법, Bottom-Up, 메모리 제한 4 MB
dp[i][k]: i번째까지의 동전을 이용해 가치의 합이 k원인 경우의 수

점화식
if i번째 동전 > k, 동전 사용 불가능할때)
	dp[i][k] = dp[i-1][k]
else (i번쨰 동전 <= k, 동전 사용 가능할때)
	dp[i][k] = dp[i-1][k] (동전 사용 안한 경우) + dp[i][k-a[i]] (동전 사용한 경우)


...메모리 초과...
cin n k
for n
	cin coin[i]

for n
	dp[i][0] = 1 //i번까지의 동전으로 가치 0을 만드는 경우의 수: 아무 동전도 쓰지 못하는 경우 1가지

for n
	for k
		if coin[i] <= j //i번쨰 동전 <= k, 동전 사용 가능할때
			dp[i][j] = dp[i-1][j] + dp[i][j - coin[i]]
		else //i번째 동전 > k, 동전 사용 불가능할때
			dp[i][j] = dp[i - 1][j]

cout dp[n][k]

메모리 절약 -> 2차원 배열을 1차원으로

점화식
dp[j]: 동전으로 만들 수 있는 가치 j인 경우의 수

dp[i][j] = dp[i-1][j] (동전 사용 안한 경우) + dp[i][j-a[i]] (동전 사용한 경우)를
dp[i][] = A, dp[i-1][] = B라고 하면,
A[j] = B[j] + A[j-a[i]] 이고, B[j] 배열을 완성한 후 A[j] 배열에 복사하는 형태로 진행되므로,
dp[j] += dp[j-coin[i]]

cin n k
for n
	cin coin[i]

for n
	dp[0] = 1 //동전으로 가치 0을 만드는 경우의 수: 아무 동전도 쓰지 못하는 경우 1가지

for i 1 to n
	for j coin[i] to k //coin[i] 미만의 동전에서는 추가될 경우의 수가 없으므로, j=coin[i]부터 시작
		dp[j] += dp[j-coin[i]]

cout dp[k]
*/
