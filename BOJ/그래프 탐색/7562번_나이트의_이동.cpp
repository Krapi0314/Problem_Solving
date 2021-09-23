/*
BOJ 7562번: 나이트의 이동

시간 제한: 1초
메모리 제한: 256 MB

문제
체스판 위에 한 나이트가 놓여져 있다. 나이트가 한 번에 이동할 수 있는 칸은 아래 그림에 나와있다. 나이트가 이동하려고 하는 칸이 주어진다. 나이트는 몇 번 움직이면 이 칸으로 이동할 수 있을까?

입력
입력의 첫째 줄에는 테스트 케이스의 개수가 주어진다.
각 테스트 케이스는 세 줄로 이루어져 있다. 첫째 줄에는 체스판의 한 변의 길이 l(4 ≤ l ≤ 300)이 주어진다. 체스판의 크기는 l × l이다. 체스판의 각 칸은 두 수의 쌍 {0, ..., l-1} × {0, ..., l-1}로 나타낼 수 있다. 둘째 줄과 셋째 줄에는 나이트가 현재 있는 칸, 나이트가 이동하려고 하는 칸이 주어진다.

출력
각 테스트 케이스마다 나이트가 최소 몇 번만에 이동할 수 있는지 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int t;
int l;

bool visited[300][300];

int dx[8] = { 2, 2, 1, 1, -1, -1, -2, -2 };
int dy[8] = { -1, 1, 2, -2, 2, -2, 1, -1 };

int start_x, start_y;
int end_x, end_y;

void bfs() {
	queue<pair<int,pair<int,int> > > q;
	q.push(make_pair(0, make_pair(start_x,start_y)));
	visited[start_x][start_y] = true;
	
	while(!q.empty()) {
		pair<int,pair<int,int> > coordinate = q.front(); q.pop();
		int x = coordinate.second.first;
		int y = coordinate.second.second;
		
		if(x == end_x && y == end_y) {
			cout << coordinate.first << "\n";
			return;
		}
		
		for(int i=0; i<8; i++) {
			int new_x = x + dx[i];
			int new_y = y + dy[i];
			
			if(new_x >= 0 && new_x < l && new_y >= 0 && new_y < l && !visited[new_x][new_y]) {
				visited[new_x][new_y] = true;
				q.push(make_pair(coordinate.first+1 ,make_pair(new_x,new_y)));
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> t;
	while(t--) {	
		cin >> l;
		cin >> start_x >> start_y;
		cin >> end_x >> end_y;
		
		memset(visited, false, sizeof(visited));
		bfs();
	}
}

/* 
최소 움직임 (거리) 계산: bfs
queue에 pair<cnt, x, y>를 저장하여 몇번째 움직임인지, x, y 좌표가 몇인지 저장 
*/
