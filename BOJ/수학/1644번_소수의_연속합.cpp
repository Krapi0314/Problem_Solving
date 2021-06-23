/*
BOJ 1644번: 소수의 연속합

시간 제한: 2초
메모리 제한: 128 MB

문제
하나 이상의 연속된 소수의 합으로 나타낼 수 있는 자연수들이 있다. 몇 가지 자연수의 예를 들어 보면 다음과 같다.

3 : 3 (한 가지)
41 : 2+3+5+7+11+13 = 11+13+17 = 41 (세 가지)
53 : 5+7+11+13+17 = 53 (두 가지)

하지만 연속된 소수의 합으로 나타낼 수 없는 자연수들도 있는데, 20이 그 예이다. 7+13을 계산하면 20이 되기는 하나 7과 13이 연속이 아니기에 적합한 표현이 아니다. 또한 한 소수는 반드시 한 번만 덧셈에 사용될 수 있기 때문에, 3+5+5+7과 같은 표현도 적합하지 않다.
자연수가 주어졌을 때, 이 자연수를 연속된 소수의 합으로 나타낼 수 있는 경우의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 N이 주어진다. (1 ≤ N ≤ 4,000,000)

출력
첫째 줄에 자연수 N을 연속된 소수의 합으로 나타낼 수 있는 경우의 수를 출력한다.
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

bool arr[4000001];
vector<int> prime;
int lo, hi;
int cnt;
int sum;
int n;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	memset(arr, true, sizeof(arr));

	for (int i = 2; i <= 2000; i++)
	{
		if (!arr[i])
			continue;

		for (int j = 2; i * j <= n; j++)
		{
			arr[i * j] = false;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (arr[i])
			prime.push_back(i);
	}

	//투 포인터
	while (1)
	{
		if (sum >= n)
		{
			sum -= prime[lo++];
		}
		else if (hi == prime.size())
		{
			break;
		}
		else
		{
			sum += prime[hi++];
		}

		if (sum == n)
			cnt++;
	}

	cout << cnt;
}

/*
에라토스테네스의 체 -> 소수 배열 구하기 -> (이중 for문을 O(n^2) 이용하면 시간초과) 투 포인터 알고리즘 사용 O(n) 시간복잡도 -> 경우의 수 구하기

!!투 포인터 알고리즘: 정렬된 리스트를 두 개의 포인터를 이용해 순차적으로 접근하면서 두 포인터 구간의 값이 타겟값과 같을 때까지 포인터를 조작하는 기법

bool arr[400만] = true

for i 2 to 2000
	for j 2 to i*j <= 2000
		arr[i*j] = false

for arr
	if true
		vector prime pushback i

투 포인터 알고리즘, [lo,hi) 구간합 sum
while 1
	if sum >= n //구간합이 n보다 크거나 같으면
		sum -= prime[lo++] //구간합에서 prime[lo(왼쪽)] 값 빼주고 lo 증가
	else if hi == prime size //hi(오른쪽) 값이 배열을 벗어나면
		 break //탐색 중지 (모든 경우의 수 다 둘러봄)
	else //구간합이 n보다 작으면
		sum += prime[hi++] //구간합에서 primep[hi(오른쪽)] 값 추가하고 hi 증가

	if sum == n
		cnt++

cout cnt

*/
