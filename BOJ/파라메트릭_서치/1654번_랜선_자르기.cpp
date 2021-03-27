/*
BOJ 1654번: 랜선 자르기

시간 제한: 2초
메모리 제한: 128 MB

문제
집에서 시간을 보내던 오영식은 박성원의 부름을 받고 급히 달려왔다. 박성원이 캠프 때 쓸 N개의 랜선을 만들어야 하는데 너무 바빠서 영식이에게 도움을 청했다
이미 오영식은 자체적으로 K개의 랜선을 가지고 있다. 그러나 K개의 랜선은 길이가 제각각이다. 박성원은 랜선을 모두 N개의 같은 길이의 랜선으로 만들고 싶었기 때문에 K개의 랜선을 잘라서 만들어야 한다. 예를 들어 300cm 짜리 랜선에서 140cm 짜리 랜선을 두 개 잘라내면 20cm는 버려야 한다. (이미 자른 랜선은 붙일 수 없다.)
편의를 위해 랜선을 자르거나 만들 때 손실되는 길이는 없다고 가정하며, 기존의 K개의 랜선으로 N개의 랜선을 만들 수 없는 경우는 없다고 가정하자. 그리고 자를 때는 항상 센티미터 단위로 정수길이만큼 자른다고 가정하자. N개보다 많이 만드는 것도 N개를 만드는 것에 포함된다. 이때 만들 수 있는 최대 랜선의 길이를 구하는 프로그램을 작성하시오.

입력
첫째 줄에는 오영식이 이미 가지고 있는 랜선의 개수 K, 그리고 필요한 랜선의 개수 N이 입력된다. K는 1이상 10,000이하의 정수이고, N은 1이상 1,000,000이하의 정수이다. 그리고 항상 K ? N 이다. 그 후 K줄에 걸쳐 이미 가지고 있는 각 랜선의 길이가 센티미터 단위의 정수로 입력된다. 랜선의 길이는 231-1보다 작거나 같은 자연수이다.

출력
첫째 줄에 N개를 만들 수 있는 랜선의 최대 길이를 센티미터 단위의 정수로 출력한다. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int k, n;
long long lo, hi, mid;
int num;
vector<int> v;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k >> n;
	for (int i = 0; i < k; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	lo = 1;
	hi = 2147483647;

	while (lo < hi)
	{
		int cnt = 0;
		mid = (lo + hi + 1) / 2;

		for (int i = 0; i < k; i++)
		{
			if (mid <= v[i])
			{
				cnt += v[i] / mid;
			}
		}

		if (cnt >= n)
			lo = mid;
		else
			hi = mid - 1;
	}

	cout << lo;
}

/*
for 1억, for 1만... 시간초과 -> 탐색범위 (1억), 매우 넓음 => 파라메트릭 서치
결정문제: 모든 랜선에 대해, i만큼 잘라서 랜선을 만들었을때, 총 개수가 n보다 큰가?

cin k n
for k
	cin num
	vector pushback num

lo = 1
hi = 2147483647

while lo < hi //lo == hi (답을 찾으면)가 되면 탈출
	mid = (lo + hi + 1) / 2

	for vector //mid 길이만큼 자를때, 얻을 수 있는 총 개수 계산
		if mid <= v[i]
			cnt += v[i] / mid

	if cnt >= n //총 개수가 n보다 같거나 크면 (mid과 mid보다 작은 범위는 모두 n보다 큰 개수를 만들 수 있음)
		lo = mid //범위를 mid~hi로 변경 (최대값을 구하기 때문에, mid보다 작은 범위는 버리고, mid만 남김)
	else //작으면 (mid를 포함한, mid보다 큰 범위는 모두 n보다 작은 개수밖에 만들지 못함)
		hi = mid - 1 //범위를 lo~mid-1로 변경 (mid까지 총 개수를 만족시키지 못하기 때문에, mid부터 hi까지 버리고, mid-1까지만 새로운 hi 범위에 넣기

cout lo
*/

