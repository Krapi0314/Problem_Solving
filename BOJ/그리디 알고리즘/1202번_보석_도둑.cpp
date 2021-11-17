/*
BOJ 1202번: 보석 도둑

시간 제한: 1초
메모리 제한: 256 MB

문제
세계적인 도둑 상덕이는 보석점을 털기로 결심했다.
상덕이가 털 보석점에는 보석이 총 N개 있다. 각 보석은 무게 Mi와 가격 Vi를 가지고 있다. 상덕이는 가방을 K개 가지고 있고, 각 가방에 담을 수 있는 최대 무게는 Ci이다. 가방에는 최대 한 개의 보석만 넣을 수 있다.
상덕이가 훔칠 수 있는 보석의 최대 가격을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 주어진다. (1 ≤ N, K ≤ 300,000)
다음 N개 줄에는 각 보석의 정보 Mi와 Vi가 주어진다. (0 ≤ Mi, Vi ≤ 1,000,000)
다음 K개 줄에는 가방에 담을 수 있는 최대 무게 Ci가 주어진다. (1 ≤ Ci ≤ 100,000,000)
모든 숫자는 양의 정수이다.

출력
첫째 줄에 상덕이가 훔칠 수 있는 보석 가격의 합의 최댓값을 출력한다. 

*/
//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int n, k;
int m, v;
int c;
vector<pair<int, int>> jewelry;
vector<int> bag;
unsigned long long ans;
int idx;
priority_queue<int> pq;

bool compare(pair<int, int>& a, pair<int, int>& b)
{
	if (a.first == b.first)
	{
		return a.second < b.second;

	}
	return a.first < b.first;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> m >> v;
		jewelry.push_back(make_pair(m, v));
	}
	for (int i = 0; i < k; i++)
	{
		cin >> c;
		bag.push_back(c);
	}

	sort(jewelry.begin(), jewelry.end(), compare);
	sort(bag.begin(), bag.end());

	
	for (int i = 0; i < k; i++)
	{
		while (idx < n && bag[i] >= jewelry[idx].first)
		{
			pq.push(jewelry[idx].second);
			idx++;
		}

		if (!pq.empty()) //가방이 보석을 담을 수 없는 경우가 있을 수 있음, 이 경우 힙이 비어있으므로 비어있는 힙에 접근하면 런타임 에러 발생함. 힙 비어있는지 여부 확인 필요
		{
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans;
}

/*
모든 경우의 수 탐색 불가: 30만Combination1~30만...
최적 부분 구조: 각 단계마다 최대한 비싼 보석을 최대한 가벼운 가방에 담는 형식, 남은 보석들과 가방들도 같은 문제구조를 가짐
탐욕 선택 속성: 항상 최대한 비싼 보석을 최대한 가벼운 가방에 담아도 (탐욕적으로) 전체 최적해를 구할 수 있음

//보석 높은 가격 순으로 sort
//가방 최소 무게 순으로 sort
/가방 기준으로 최대한 비싼 보석 담기
sort vector jewelry greater
sort vector bag

for bag
	for jewerly
		if bag >= jewerly m
			ans += jewerly v
			jwerly m = 100000001
			break
=> O(nk)로 30만*30만 = 90억, 시간초과

!!항상 최대한 비싼 보석을 넣어야 함 -> 가방을 최소 무게 순으로 순차적으로 탐색하고, 가방에 넣을 수 있는 최대한 비싼 보석을 탐색할때, 이전 가방에서 탐색한 보석들을 다시 볼 필요가 없음 (다음 가방에서 충분히 넣을 수 잇으면서, 가장 비싼 보석들이 아니기 때문)
=> 한 번 본 보석은 다시 볼 필요 없음, 시간단축

cin n k
for n
	cin m v
	vector jewel pushback make pair m v
for k
	cin c
	vector bag pushback c

sort bag less (작은 무게 순)
sort jewel less (작은 무게 순)

for bag
	while idx < n && bag >= jewel[idx].first //해당 가방에 들어가는 보석들을 모두 우선순위 큐에 넣기 (idx를 유지하므로써 한 번 본 보석은 다시 보지 않음)
		prioirty_queue push jewel[idx].second
		
	ans += pq top, pop //최대 힙(우선순위 큐)의 루트 = 보석 가격 최댓값 (최대한 비싼 보석을 최대한 가벼운 가방에 담음)

cout ans

