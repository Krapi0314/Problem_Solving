/*
BOJ 1826번: 연료 채우기

시간 제한: 2초
메모리 제한: 128 MB

문제
성경이는 트럭을 정글 속에서 운전하다가 트럭의 연료탱크에 갑자기 구멍이 나서 1km를 가는데 1L의 연료가 새 나가게 되었다. 이것을 고치기 위해서는 가장 가까운 마을에 가야 한다. 그런데 그냥 가다가는 중간에 연료가 다 빠질 수가 있다. 다행스럽게도 정글 곳곳에 연료를 채울 수 있는 주유소가 N개 있다. 그런데 정글 속에서 중간에 차를 멈추는 행위는 매우 위험한 행위이므로 주유소에서 멈추는 횟수를 최소화 하려 한다.
그리고 다행이도 성경이의 트럭은 매우 좋아서 연료 탱크에는 연료의 제한이 없이 많이 충분히 많이 넣을 수 있다고 한다. 각각의 주유소의 위치와, 각 주유소에서 얻을 수 있는 연료의 양이 주어져 있을 때, 주유소에서 멈추는 횟수를 구하는 프로그램을 작성하시오.
정글은 일직선이고, 성경이의 트럭과 주유소도 모두 일직선 위에 있다. 주유소는 모두 성경이의 트럭을 기준으로 오른쪽에 있다.

입력
첫째 줄에 주유소의 개수 N(1 ≤ N ≤ 10,000)가 주어지고 두 번째 줄부터 N+1번째 줄 까지 주유소의 정보가 주어진다. 주유소의 정보는 두개의 정수 a,b로 이루어 져 있는데 a(1 ≤ a ≤ 1,000,000)는 성경이의 시작 위치에서 주유소 까지의 거리, 그리고 b(1 ≤ b ≤ 100)는 그 주유소에서 채울 수 있는 연료의 양을 의미한다. 그리고 N+2번째 줄에는 두 정수 L과 P가 주어지는데 L(1 ≤ L ≤ 1,000,000)은 성경이의 위치에서 마을까지의 거리, (1 ≤ P ≤ 1,000,000)는 트럭에 원래 있던 연료의 양을 의미한다.

출력
첫째 줄에 주유소에서 멈추는 횟수를 출력한다. 만약 마을에 도착하지 못할경우 -1을 출력한다. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int n;
int a, b, l, p;
int ans;

priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
priority_queue<int> pq2;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		pq.push(make_pair(a, b));
	}

	cin >> l >> p;

	while (p < l)
	{
		while (!pq.empty() && p >= pq.top().first)
		{
			pq2.push(pq.top().second);
			pq.pop();
		}

		if (!pq2.empty())
		{
			ans++;
			p += pq2.top(); pq2.pop();
		}
		else
		{
			cout << "-1";
			return 0;
		}
	}

	cout << ans;
}

/*
최적 부분 문제, 탐욕 선택 속성 -> greedy

매 선택마다 갈 수 있는 주유소 중 가장 연료를 많이 채워주는 주유소로 가기 + 연료가 마을/주유소까지 가기 부족하면 지나온 주유소 중 그 다음 연료를 많이 채워주는 주유소 방문... (greedy) 

!! 2중 for문: O(n^2), n = 10000이므로 시간초과 => 힙 이용: O(logn) (힙 이용 시 연료가 부족할 경우 갈 수 있는 그 다음으로 연료를 많이 채워주는 주유소를 방문하는 연산을 쉽게 할 수 있음)

cin n
for n
	cin a b
	prioirty queue push pair a,b //거리 오름차순으로

cin l p

while p < l //마을에 도착하기 전까지 실행
	while !pq.empty && p >= pq.top.a //남은 연료로 갈 수 있는 주유소이면
		pq2.push pq.top.b //주유소에서 얻을 수 있는 연료량 최대 힙으로 push
		pq.pop

	if !pq2.empty //갈 수 있는 주유소가 남아있으면
		ans++
		p += pq2.top, pop //연료 추가
	else //갈 수 있는 주유소가 없으면
		cout -1
		return 0 //-1 출력 후 종료

cout ans
		
*/
