/*
BOJ 14940번: 쉬운 최단거리

시간 제한: 1초
메모리 제한: 128 MB

문제
지도가 주어지면 모든 지점에 대해서 목표지점까지의 거리를 구하여라.
문제를 쉽게 만들기 위해 오직 가로와 세로로만 움직일 수 있다고 하자.

입력
지도의 크기 n과 m이 주어진다. n은 세로의 크기, m은 가로의 크기다.(2 ≤ n ≤ 1000, 2 ≤ m ≤ 1000)
다음 n개의 줄에 m개의 숫자가 주어진다. 0은 갈 수 없는 땅이고 1은 갈 수 있는 땅, 2는 목표지점이다. 입력에서 2는 단 한개이다.

출력
각 지점에서 목표지점까지의 거리를 출력한다. 원래 갈 수 없는 땅인 위치는 0을 출력하고, 원래 갈 수 있는 땅인 부분 중에서 도달할 수 없는 위치는 -1을 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAX 1000

int n,m;
int arr[MAX][MAX];
int cnt[MAX][MAX]; // == visited
pair<int,int > target;
int dx[4] = { 0, 0, 1 , -1};
int dy[4] = { 1, -1, 0, 0};

void bfs() {
	queue<pair<int,int> > q;
	q.push(target);
	
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++) {
			int newx = x + dx[i];
			int newy = y + dy[i];
			
			if(newx >= 0 && newx < n && newy >= 0 && newy < m && arr[newx][newy] == 1 && cnt[newx][newy] == 0) {
				cnt[newx][newy] = cnt[x][y] + 1;
				q.push(make_pair(newx,newy));
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> arr[i][j];
			
			if(arr[i][j] == 2) {
				target = make_pair(i,j);
			}
		}
	}
	
	bfs();
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(arr[i][j] == 1 && cnt[i][j] == 0) {
				cnt[i][j] = -1;
			}
		}
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cout << cnt[i][j] << " ";
		}
		cout << "\n";
	}
}

/*
bfs
목표지점을 bfs의 시작지점으로 설정하고 bfs 
*/
