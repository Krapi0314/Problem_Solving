/*
BOJ 2512번: 예산

시간 제한: 1초
메모리 제한: 128 MB

문제
국가의 역할 중 하나는 여러 지방의 예산요청을 심사하여 국가의 예산을 분배하는 것이다. 국가예산의 총액은 미리 정해져 있어서 모든 예산요청을 배정해 주기는 어려울 수도 있다. 그래서 정해진 총액 이하에서 가능한 한 최대의 총 예산을 다음과 같은 방법으로 배정한다.

모든 요청이 배정될 수 있는 경우에는 요청한 금액을 그대로 배정한다.
모든 요청이 배정될 수 없는 경우에는 특정한 정수 상한액을 계산하여 그 이상인 예산요청에는 모두 상한액을 배정한다. 상한액 이하의 예산요청에 대해서는 요청한 금액을 그대로 배정한다. 
예를 들어, 전체 국가예산이 485이고 4개 지방의 예산요청이 각각 120, 110, 140, 150이라고 하자. 이 경우, 상한액을 127로 잡으면, 위의 요청들에 대해서 각각 120, 110, 127, 127을 배정하고 그 합이 484로 가능한 최대가 된다. 

여러 지방의 예산요청과 국가예산의 총액이 주어졌을 때, 위의 조건을 모두 만족하도록 예산을 배정하는 프로그램을 작성하시오.

입력
첫째 줄에는 지방의 수를 의미하는 정수 N이 주어진다. N은 3 이상 10,000 이하이다. 다음 줄에는 각 지방의 예산요청을 표현하는 N개의 정수가 빈칸을 사이에 두고 주어진다. 이 값들은 모두 1 이상 100,000 이하이다. 그 다음 줄에는 총 예산을 나타내는 정수 M이 주어진다. M은 N 이상 1,000,000,000 이하이다. 

출력
첫째 줄에는 배정된 예산들 중 최댓값인 정수를 출력한다.  
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
vector<int> v;
int n,m;
int num;
int lo, hi,mid;

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

	cin >> m;

	sort(v.begin(), v.end());
	lo = 1; //모든 지방이 요청한 예산이 국가예산보다 오버인 경우가 있을 수 있으므로, 상한액의 lo는 최솟값인 1부터 시작해야 함
	hi = v[n - 1];

	while (lo < hi)
	{
		mid = (lo + hi + 1) / 2;

		ull sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (v[i] > mid)
				sum += mid;
			else
				sum += v[i];
		}

		if (sum > m)
			hi = mid - 1;
		else
			lo = mid;
	}

	cout << lo;
}

/*
상한액: 최대 1억, 지방의 수: 최대 1만 => 2중 for문: 1조
이분 탐색, 파라메트릭 서치
결정 문제: 상한액을 i라 할때, 지방에 예산을 분배한 총액이 국가예산 이하인가?

cin n

for n
	cin num
	v vector pushback num
cin m

sort v
lo = 1 //모든 지방이 요청한 예산이 국가예산보다 오버인 경우가 있을 수 있으므로, 상한액의 lo는 최솟값인 1부터 시작해야 함
hi = v[n-1]

while lo < hi
	mid = (lo+hi+1) / 2 (최대)

	int sum = 0
	for v
		if v[i] > mid
			sum += mid
		else
			sum += v[i]

	if sum > m //예산 초과
		hi = mid-1 //mid 이상의 값들은 예산 초과이므로, mid 이상의 값들은 버리고, hi를 mid-1로 설정해 가능한 범위 조정
	else //예산 이하
		lo = mid //mid 이하의 값들은 모두 가능하므로, 이 값들 중 최대인 mid를 새로운 lo로 설정

cout lo
*/
