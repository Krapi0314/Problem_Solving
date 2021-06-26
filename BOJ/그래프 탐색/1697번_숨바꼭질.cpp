/*
BOJ 1697번: 숨바꼭질

시간 제한: 2초
메모리 제한: 128 MB

문제
수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.
수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

출력
수빈이가 동생을 찾는 가장 빠른 시간을 출력한다.
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

#define Max 100001

int k, n;
int ans;
queue<pair<int,int>> q;
bool visited[100001] = { false, };

void bfs(int n)
{
	q.push(make_pair(n,0));
	visited[n] = true;

	while (!q.empty())
	{
		int v = q.front().first; 
		int d = q.front().second;
		q.pop();

		visited[v] = true;

		if (v == k)
		{
			ans = d;
			break;
		}
		else
		{
			if(v + 1 <= Max && !visited[v+1])
				q.push(make_pair(v + 1,d+1));
			if (v - 1 >= 0 && !visited[v - 1])
				q.push(make_pair(v - 1, d+1));
			if (v * 2 <= Max && !visited[v * 2])
				q.push(make_pair(v * 2, d+1));
		}
	}
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	if (k == n)
		cout << "0";
	else if (k < n)
		cout << n - k;
	else
	{
		bfs(n);
		cout << ans;
	}
}

/*
완전탐색(백트래킹,dfs)으로는 시간초과 (사이클이 형성되거나, 너무 깊이 들어가버림, 완전탐색(bfs)로 n이 k가 될떄까지 넓게 모든 경우의 수 탐색
if k == n
	0초
else if k < n
	n-k초
else (k > n)
	bfs(n)

bfs
	정점 n부터 시작해서 모든 경우의 수(+,-,*)를 bfs, k를 만나면 들어온 깊이 (depth) = ans
	큐는 pair<int,int>로 저장, first는 v, second는 depth
	방문한 지점은 다시 방문하지 않음, 다시 방문할시 겹치는 연산이 많아져 시간초과

	q push n
	
	while 1
		v = q pop
		
		if v == k
			ans = depth
			break
		else
			if 방문 x and 배열 범위 안
				q push v+,v-,v*
*/
