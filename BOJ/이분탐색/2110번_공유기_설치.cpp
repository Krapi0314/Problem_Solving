/*
BOJ 2110번: 공유기 설치

시간 제한: 2초
메모리 제한: 128 MB

문제
도현이의 집 N개가 수직선 위에 있다. 각각의 집의 좌표는 x1, ..., xN이고, 집 여러개가 같은 좌표를 가지는 일은 없다.
도현이는 언제 어디서나 와이파이를 즐기기 위해서 집에 공유기 C개를 설치하려고 한다. 최대한 많은 곳에서 와이파이를 사용하려고 하기 때문에, 한 집에는 공유기를 하나만 설치할 수 있고, 가장 인접한 두 공유기 사이의 거리를 가능한 크게 하여 설치하려고 한다.
C개의 공유기를 N개의 집에 적당히 설치해서, 가장 인접한 두 공유기 사이의 거리를 최대로 하는 프로그램을 작성하시오.

입력
첫째 줄에 집의 개수 N (2 ≤ N ≤ 200,000)과 공유기의 개수 C (2 ≤ C ≤ N)이 하나 이상의 빈 칸을 사이에 두고 주어진다. 둘째 줄부터 N개의 줄에는 집의 좌표를 나타내는 xi (0 ≤ xi ≤ 1,000,000,000)가 한 줄에 하나씩 주어진다.

출력
첫째 줄에 가장 인접한 두 공유기 사이의 최대 거리를 출력한다. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int n, c;
long long num;
vector<long long> v;
long long hi, mid, lo;

bool possible(int current_idx, int remain)
{
	if (remain == 1) 
		return true;

	for (int i = current_idx+1; i < n; i++)
	{
		if (v[i] - v[current_idx] >= mid)
		{
			return possible(i, remain - 1);
		}
	}

	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	lo = 0;
	hi = 1000000000;

	while (lo < hi)
	{
		mid = (hi + lo + 1) / 2;

		if (possible(0, c))
		{
			lo = mid;
		}
		else
		{
			hi = mid - 1;
		}
	}

	cout << lo;
}

/*
이분탐색, 파라메트릭 서치
결정 문제: 공유기 사이의 최대 거리를 d라고 하면, 이 최대 거리로 공유기를 놓을 수 있는가?

bool possible(int current_idx,int remain)
	if remain == 1 //공유기를 맨 왼쪽에 놓은 상태에서 시작했으므로, remain이 하나 남았을때가 모든 공유기를 집에 놓았을때
		return true

	for vector
		if v[i] - v[current_idx] >= mid //공유기를 설치한 이전 집과의 거리가 최대 거리와 같거나 크면 (성립)
			return possible(i,remain-1) //다음 공유기 놓으러 가기
	
	return false

cin n c
for n
	cin num
	v vector pushback num

sort vector

lo = 0
hi = 10억

while lo < hi
	mid = (lo+hi+1) /2

	if(possible(0,c)) //최대 거리 mid로 집들에 공유기를 놓을 수 있는지 검사, 가장 왼쪽 = 0에 공유기를 먼저 하나 놓는 것이 최선임 greedy
		lo = mid
	else
		hi = mid-1

cout lo
*/
