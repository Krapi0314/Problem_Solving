/*
BOJ 16928번: 뱀과 사다리 게임 

시간 제한: 1 초
메모리 제한: 512 MB

문제
뱀과 사다리 게임을 즐겨 하는 큐브러버는 어느 날 궁금한 점이 생겼다.
주사위를 조작해 내가 원하는 수가 나오게 만들 수 있다면, 최소 몇 번만에 도착점에 도착할 수 있을까?
게임은 정육면체 주사위를 사용하며, 주사위의 각 면에는 1부터 6까지 수가 하나씩 적혀있다. 게임은 크기가 10×10이고, 총 100개의 칸으로 나누어져 있는 보드판에서 진행된다. 보드판에는 1부터 100까지 수가 하나씩 순서대로 적혀져 있다.
플레이어는 주사위를 굴려 나온 수만큼 이동해야 한다. 예를 들어, 플레이어가 i번 칸에 있고, 주사위를 굴려 나온 수가 4라면, i+4번 칸으로 이동해야 한다. 만약 주사위를 굴린 결과가 100번 칸을 넘어간다면 이동할 수 없다. 도착한 칸이 사다리면, 사다리를 타고 위로 올라간다. 뱀이 있는 칸에 도착하면, 뱀을 따라서 내려가게 된다. 즉, 사다리를 이용해 이동한 칸의 번호는 원래 있던 칸의 번호보다 크고, 뱀을 이용해 이동한 칸의 번호는 원래 있던 칸의 번호보다 작아진다.
게임의 목표는 1번 칸에서 시작해서 100번 칸에 도착하는 것이다.
게임판의 상태가 주어졌을 때, 100번 칸에 도착하기 위해 주사위를 굴려야 하는 횟수의 최솟값을 구해보자.

입력
첫째 줄에 게임판에 있는 사다리의 수 N(1 ≤ N ≤ 15)과 뱀의 수 M(1 ≤ M ≤ 15)이 주어진다.
둘째 줄부터 N개의 줄에는 사다리의 정보를 의미하는 x, y (x < y)가 주어진다. x번 칸에 도착하면, y번 칸으로 이동한다는 의미이다.
다음 M개의 줄에는 뱀의 정보를 의미하는 u, v (u > v)가 주어진다. u번 칸에 도착하면, v번 칸으로 이동한다는 의미이다.
1번 칸과 100번 칸은 뱀과 사다리의 시작 또는 끝이 아니다. 모든 칸은 최대 하나의 사다리 또는 뱀을 가지고 있으며, 동시에 두 가지를 모두 가지고 있는 경우는 없다. 항상 100번 칸에 도착할 수 있는 입력만 주어진다.

출력
100번 칸에 도착하기 위해 주사위를 최소 몇 번 굴려야 하는지 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, m;
int x, y;
int arr[101];
bool visited[101];

int bfs(int start) {
	queue<pair<int,int> > q; // idx, cnt
	visited[start] = true;
	q.push(make_pair(start, 0));
	
	while(!q.empty()) {
		int idx = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		if(idx == 100) {
			return cnt;
		}
		
		for(int i=1; i<=6; i++) {
			if(idx+i > 100 || visited[idx+i] || arr[idx+i] > 100 || visited[arr[idx+i]]) {
				continue;
			}
			else {
				if(arr[idx+i] != 0) {
					visited[arr[idx+i]] = true;
					q.push(make_pair(arr[idx+i], cnt+1));
				}
				else {
					visited[idx+i] = true;
					q.push(make_pair(idx+i, cnt+1));
				}
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=0; i<n+m; i++) {
		cin >> x >> y;
		arr[x] = y;
	}

	cout << bfs(1);
	return 0;
}

/* 
BFS: 최단거리의 응용
!! 최소 이동(주사위 횟수) -> 최단거리 -> BFS  
*/ 
