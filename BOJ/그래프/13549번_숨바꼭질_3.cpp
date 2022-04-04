/*
BOJ 13549번: 숨바꼭질 3

시간 제한: 2 초
메모리 제한: 512 MB

문제
수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 수 있다. 만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 0초 후에 2*X의 위치로 이동하게 된다.
수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에 수빈이가 있는 위치 N과 동생이 있는 위치 K가 주어진다. N과 K는 정수이다.

출력
수빈이가 동생을 찾는 가장 빠른 시간을 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAX 100000

int n,k;
int dx[2] = { -1, 1 };
bool visited[MAX+1];

int bfs() {
	queue<pair<int, int>> q;
	q.push({n,0});
	visited[n] = true;
	
	while(!q.empty()) {
		int n = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		if(n == k) {
			return cnt;
		}
		
		// x2
		int new_n = n * 2;
	
		if(new_n <= MAX && !visited[new_n]) {
			visited[new_n] = true;
			q.push({new_n, cnt});
		}
		
		// -1, +1
		new_n = 0;
		for(int i=0; i<2; i++) {
			new_n = n + dx[i];
			
			if(0 <= new_n && new_n <= MAX && !visited[new_n]) {
				visited[new_n] = true;
				q.push({new_n, cnt+1});
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> k;
	
	cout << bfs();
	return 0;
}

/* 
Graph: BFS
순간이동은 0초, +1,-1 이동은 1초가 소요되므로, 3가지 경우를 탐색할 때 순간이동이 더 우선순위가 높음 -> 먼저 큐에 삽입
우선순위 큐가 아니여도 순간이동이 항상 큐에 먼저 들어가기 때문에, 우선순위에 따른 ㅌ남색에 문제가 없음 
*/ 
