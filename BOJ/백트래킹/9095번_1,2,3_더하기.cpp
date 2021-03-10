/*
BOJ 9095번: 1,2,3 더하기

시간 제한: 1초
메모리 제한 128 MB

문제
정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다.

1+1+1+1
1+1+2
1+2+1
2+1+1
2+2
1+3
3+1

정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. n은 양수이며 11보다 작다.

출력
각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 출력한다.
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int dp[11];
int n;
int t;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(dp, -1, sizeof(dp));

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;

		if (dp[n] != -1) //계산됨
		{
			cout << dp[n] << "\n";
		}
		else
		{
			for (int j = 4; j <= n; j++)
			{
				dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
			}

			cout << dp[n] << "\n";
		}
	}
}

/*
정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

top-down 재귀 방식

int cnt

void sum(int n): n을 1,2,3의 합으로 나타낼 수 있는 방법의 수
	기저 n == 0
		cnt++; //합 만들어짐
		return
	
	if(sum >= 3)
		sum(n-3)
	if sum >= 2
		sum(n-2)
	if sum >= 1
		sum(n-1)
테스트 케이스 t
for t
	초기화
	n 입력 (11보다 작은 정수,양수)
	
	sum(n)

	cout << cnt


!!bottom-up dp 반복문 방식:
	dp[n] = dp[n-1]+dp[n-2]+dp[n-3] (dp[n-1]의 조합들을 +1 하면 dp[n]의 조합이 되고 + ... 해서 나온 점화식)
*/
