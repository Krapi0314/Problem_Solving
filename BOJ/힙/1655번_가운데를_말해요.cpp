/*
BOJ 1655번: 가운데를 말해요

시간 제한: 0.1초
메모리 제한: 128 MB

문제
수빈이는 동생에게 "가운데를 말해요" 게임을 가르쳐주고 있다. 수빈이가 정수를 하나씩 외칠때마다 동생은 지금까지 수빈이가 말한 수 중에서 중간값을 말해야 한다. 만약, 그동안 수빈이가 외친 수의 개수가 짝수개라면 중간에 있는 두 수 중에서 작은 수를 말해야 한다.
예를 들어 수빈이가 동생에게 1, 5, 2, 10, -99, 7, 5를 순서대로 외쳤다고 하면, 동생은 1, 1, 2, 2, 2, 2, 5를 차례대로 말해야 한다. 수빈이가 외치는 수가 주어졌을 때, 동생이 말해야 하는 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에는 수빈이가 외치는 정수의 개수 N이 주어진다. N은 1보다 크거나 같고, 100,000보다 작거나 같은 자연수이다. 그 다음 N줄에 걸쳐서 수빈이가 외치는 정수가 차례대로 주어진다. 정수는 -10,000보다 크거나 같고, 10,000보다 작거나 같다.

출력
한 줄에 하나씩 N줄에 걸쳐 수빈이의 동생이 말해야하는 수를 순서대로 출력한다. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <functional>
#include <cmath>

//#include <cstdio>

using namespace std;

int n;
int input;
priority_queue<int, vector<int>, less<int>> max_heap;
priority_queue<int, vector<int>, greater<int>> min_heap;

void cal()
{
	if (max_heap.size() == min_heap.size())
	{
		max_heap.push(input);
	}
	else //max_heap이 하나 더 많을때 뿐
	{
		min_heap.push(input);
	}
	
	if (!max_heap.empty() && !min_heap.empty() && max_heap.top() > min_heap.top())
	{
		int a = max_heap.top(), b = min_heap.top();
		max_heap.pop(); min_heap.pop();
		max_heap.push(b);
		min_heap.push(a);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		cal();
		cout << max_heap.top() << "\n";
	}
}

/*
(정렬한) 수열을 둘로 나누어, 작은 쪽 절반은 max_heap에 less로 저장, 큰 쪽 절반은 min_heap에 greater로 저장하고, 다음의 두 규칙을 만족하면,
	1. max_heap은 min_heap 보다 원소가 하나 많거나 같음
	2. max_heap의 최대원소는 min_heap의 최소 원소보다 작음 (max_heap은 작은쪽 절반이, min_heap은 큰 쪽 절반이 들어갔으므로)

	=> max_heap의 루트 노드는 중간값이 된다

	이를 속성을 유지하기 위해 원소가 하나 들어올떄마다
		1번 규칙 적용 후
		2번 규칙 적용 (원소가 max_heap으로 들어갔는데 min_heap의 원소보다 크면 둘이 교환, 원소가 하나 들어올떄마다 적용하므로 항상 max 원소 크기 < min 원소 크기 유지됨)

1. 정수의 개수 n 입력
2. 수가 입력될떄마다 나누어 담아 중간값을 계산하는 함수 cal 호출
*/
