/*
BOJ 10026번: 적록색약

시간 제한: 1 초
메모리 제한: 128 MB

문제
적록색약은 빨간색과 초록색의 차이를 거의 느끼지 못한다. 따라서, 적록색약인 사람이 보는 그림은 아닌 사람이 보는 그림과는 좀 다를 수 있다.
크기가 N×N인 그리드의 각 칸에 R(빨강), G(초록), B(파랑) 중 하나를 색칠한 그림이 있다. 그림은 몇 개의 구역으로 나뉘어져 있는데, 구역은 같은 색으로 이루어져 있다. 또, 같은 색상이 상하좌우로 인접해 있는 경우에 두 글자는 같은 구역에 속한다. (색상의 차이를 거의 느끼지 못하는 경우도 같은 색상이라 한다)
예를 들어, 그림이 아래와 같은 경우에

RRRBB
GGBBB
BBBRR
BBRRR
RRRRR

적록색약이 아닌 사람이 봤을 때 구역의 수는 총 4개이다. (빨강 2, 파랑 1, 초록 1) 하지만, 적록색약인 사람은 구역을 3개 볼 수 있다. (빨강-초록 2, 파랑 1)
그림이 입력으로 주어졌을 때, 적록색약인 사람이 봤을 때와 아닌 사람이 봤을 때 구역의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (1 ≤ N ≤ 100)
둘째 줄부터 N개 줄에는 그림이 주어진다.

출력
적록색약이 아닌 사람이 봤을 때의 구역의 개수와 적록색약인 사람이 봤을 때의 구역의 수를 공백으로 구분해 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAX 100

int n;
char ch;
char arr[MAX][MAX];
int normal, blind;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
bool visited[MAX][MAX];

void bfs(int i, int j, bool blinded) {
	bool component = false;
	queue<pair<int,int>> q;
	visited[i][j] = true;
	q.push(make_pair(i,j));
	
	while(!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++) {
			bool move = false;
			int new_y = y + dy[i];
			int new_x = x + dx[i];
			
			if(0 <= new_y && new_y < n && 0 <= new_x && new_x < n && !visited[new_y][new_x]) {
				if(!blinded) {
					if(arr[new_y][new_x] == arr[y][x]) {
						move = true;
					}
				}
				else {
					if(((arr[y][x] == 'R' || arr[y][x] == 'G') && (arr[new_y][new_x] == 'R' || arr[new_y][new_x] == 'G')) || (arr[y][x] == 'B' && arr[new_y][new_x] == 'B')) {
						move = true;
					}
				}
				
				if(move) {
					component = true;
					visited[new_y][new_x] = true;
					q.push(make_pair(new_y,new_x));
					move = false;
				}
			}
		}
	}
	
	if(!blinded) {
		normal++;
	}
	else {
		blind++;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> arr[i][j];
		}
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(!visited[i][j]) {
				bfs(i, j, false);
			}
		}
	}
	
	memset(visited, false, sizeof(visited));

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(!visited[i][j]) {
				bfs(i, j, true);
			}
		}
	}
	
	cout << normal << " " << blind;
	return 0;
}

/* 
그래프: BFS 
*/ 
