/*
BOJ 1931번: 회의실배정

시간 제한:  2초
메모리 제한: 128 MB

문제
한 개의 회의실이 있는데 이를 사용하고자 하는 N개의 회의에 대하여 회의실 사용표를 만들려고 한다. 각 회의 I에 대해 시작시간과 끝나는 시간이 주어져 있고, 각 회의가 겹치지 않게 하면서 회의실을 사용할 수 있는 회의의 최대 개수를 찾아보자. 단, 회의는 한번 시작하면 중간에 중단될 수 없으며 한 회의가 끝나는 것과 동시에 다음 회의가 시작될 수 있다. 회의의 시작시간과 끝나는 시간이 같을 수도 있다. 이 경우에는 시작하자마자 끝나는 것으로 생각하면 된다.

입력
첫째 줄에 회의의 수 N(1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N+1 줄까지 각 회의의 정보가 주어지는데 이것은 공백을 사이에 두고 회의의 시작시간과 끝나는 시간이 주어진다. 시작 시간과 끝나는 시간은 231-1보다 작거나 같은 자연수 또는 0이다.

출력
첫째 줄에 최대 사용할 수 있는 회의의 최대 개수를 출력한다.
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int a, b;
int n;
deque<pair<int, int>> dq;
int cnt;

bool compare(pair<int,int> &a, pair<int,int> &b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}

	return a.second < b.second;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		dq.push_back(make_pair(a, b));
	}

	sort(dq.begin(), dq.end(), compare);

	while (!dq.empty())
	{
		cnt++;
		int endtime = dq.front().second;
		dq.pop_front();

		while (!dq.empty() && dq.front().first < endtime)
			dq.pop_front();
	}

	cout << cnt;
}

/*
그리디 알고리즘
부분 최적해: 최소 끝나는 시간

compare a b
	if a.seoncd == b.second
		return a.first < b.first //끝나는 시간이 같으면, 시작시간을 less로 정렬해야 최소 시작 시간부터 시작할 수 있어 예외를 처리할 수 있음 (ex: 2, 2 2, 1 2 을 second으로만 구분하면 2 2, 1 2 순으로 정렬되어 1 2이 카운트 되지 못하는 예외 발생함)
	return a.second < b.second
cin n
for n
	cin a b
	deque pushback make pair a b

sort deque pair second compare

while deque not empty
	cnt++
	endtime = deque front second
	deque pop front

	while deque front first < endtime //한 회의가 끝나는 것과 동시에 다음 회의가 시작될 수 있으므로, 등호 제외
		deqeue pop front

cout cnt

*/
