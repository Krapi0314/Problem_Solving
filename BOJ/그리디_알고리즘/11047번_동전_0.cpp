/*
BOJ 11047번: 동전 0

시간 제한: 1초
메모리 제한: 256 MB

문제
준규가 가지고 있는 동전은 총 N종류이고, 각각의 동전을 매우 많이 가지고 있다.
동전을 적절히 사용해서 그 가치의 합을 K로 만들려고 한다. 이때 필요한 동전 개수의 최솟값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 10, 1 ≤ K ≤ 100,000,000)
둘째 줄부터 N개의 줄에 동전의 가치 Ai가 오름차순으로 주어진다. (1 ≤ Ai ≤ 1,000,000, A1 = 1, i ≥ 2인 경우에 Ai는 Ai-1의 배수)

출력
첫째 줄에 K원을 만드는데 필요한 동전 개수의 최솟값을 출력한다. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>


//#include <cstdio>

using namespace std;

vector<int> coin;
int n, k, value;
int cnt;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		coin.push_back(value);
	}
	
	for(int i=n-1; i >= 0; i--)
	{
		if (k == 0)
			break;
		else if (coin[i] > k)
			continue;
		else
		{
			while (k >= coin[i])
			{
				k -= coin[i];
				cnt++;
			}
		}
	}
	
	cout << cnt;
}

/*
Greedy
K 값
오름차순으로 주어진 동전의 가치를 벡터에 저장
벡터의 마지막 원소부터
	if k == 0 (기저 사례)
		cout << cnt
	else if 마지막 원소 > k
		다음으로 넘어가기 (그 전 원소로)
	else
		while 마지막 원소 > k
			k - 마지막 원소
			cnt++
*/
