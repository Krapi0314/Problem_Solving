/*
BOJ 9576번: 책 나눠주기

시간 제한: 2초
메모리 제한: 256 MB

문제
백준이는 방 청소를 하면서 필요 없는 전공 서적을 사람들에게 나눠주려고 한다. 나눠줄 책을 모아보니 총 N권이었다. 책이 너무 많기 때문에 백준이는 책을 구분하기 위해 각각 1부터 N까지의 정수 번호를 중복되지 않게 매겨 두었다.
조사를 해 보니 책을 원하는 서강대학교 학부생이 총 M명이었다. 백준이는 이 M명에게 신청서에 두 정수 a, b (1 ≤ a ≤ b ≤ N)를 적어 내라고 했다. 그러면 백준이는 책 번호가 a 이상 b 이하인 책 중 남아있는 책 한 권을 골라 그 학생에게 준다. 만약 a번부터 b번까지의 모든 책을 이미 다른 학생에게 주고 없다면 그 학생에게는 책을 주지 않는다.
백준이가 책을 줄 수 있는 최대 학생 수를 구하시오.

입력
첫째 줄에 테스트 케이스의 수가 주어진다.
각 케이스의 첫 줄에 정수 N(1 ≤ N ≤ 1,000)과 M(1 ≤ M ≤ 1,000)이 주어진다. 다음 줄부터 M개의 줄에는 각각 정수 ai, bi가 주어진다. (1 ≤ ai ≤ bi ≤ N)

출력
각 테스트 케이스마다 백준이가 책을 줄 수 있는 최대 학생 수를 한 줄에 하나씩 출력한다. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

bool book[1001];
vector<pair<int, int>> v;
int n, m;
int a, b;
bool possible;
int ans;

bool compare(pair<int, int>& a, pair<int, int>& b)
{
	return a.second < b.second;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int k = 0; k < T; k++)
	{
		memset(book, false, sizeof(book));
		v.clear();

		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b;
			v.push_back(make_pair(a, b));
		}

		sort(v.begin(), v.end(), compare);

		ans = m;
		for (int i = 0; i < m; i++)
		{
			possible = false;

			for (int j = v[i].first; j <= v[i].second; j++)
			{
				if (!book[j])
				{
					book[j] = true;
					possible = true;
					break;
				}
			}

			if (!possible)
				ans--;
		}

		cout << ans << "\n";
	}
}

/*
최적 부분 구조, 탐욕 선택 속성 존재 => greedy

b를 기준으로 오름차순 정렬 (a를 기준으로 정렬할 경우, 반례 발생: i번째 수가 2,3이고, i+1번째 수가 2,2이면, i번째가 3, i+1번쨰가 2를 가져가면 최대로 가져갈 수 있음에도 불구하고 i번쨰가 2를 가져가서 i+1번째가 아무것도 가져가지 못하는 상황 발생 => b를 기준으로 정렬하면 해당 반례 없어짐)

bool book[] false

input
sort vector pair, a less, b less

for vector
	bool possible
	for second to first
		if book[i] false
			book[i] true
			possible true
			break
	if !possible
		ans--

cout ans
*/
