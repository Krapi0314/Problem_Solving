/*
BOJ 14500번: 테트로미노

시간 제한: 2 초
메모리 제한: 512 MB 

문제
폴리오미노란 크기가 1×1인 정사각형을 여러 개 이어서 붙인 도형이며, 다음과 같은 조건을 만족해야 한다.
- 정사각형은 서로 겹치면 안 된다.
- 도형은 모두 연결되어 있어야 한다.
- 정사각형의 변끼리 연결되어 있어야 한다. 즉, 꼭짓점과 꼭짓점만 맞닿아 있으면 안 된다.
정사각형 4개를 이어 붙인 폴리오미노는 테트로미노라고 하며, 다음과 같은 5가지가 있다.
(정사각형 4개를 이어 붙여서 나오는 모든 형태) 

아름이는 크기가 N×M인 종이 위에 테트로미노 하나를 놓으려고 한다. 종이는 1×1 크기의 칸으로 나누어져 있으며, 각각의 칸에는 정수가 하나 쓰여 있다.
테트로미노 하나를 적절히 놓아서 테트로미노가 놓인 칸에 쓰여 있는 수들의 합을 최대로 하는 프로그램을 작성하시오.
테트로미노는 반드시 한 정사각형이 정확히 하나의 칸을 포함하도록 놓아야 하며, 회전이나 대칭을 시켜도 된다.

입력
첫째 줄에 종이의 세로 크기 N과 가로 크기 M이 주어진다. (4 ≤ N, M ≤ 500)
둘째 줄부터 N개의 줄에 종이에 쓰여 있는 수가 주어진다. i번째 줄의 j번째 수는 위에서부터 i번째 칸, 왼쪽에서부터 j번째 칸에 쓰여 있는 수이다. 입력으로 주어지는 수는 1,000을 넘지 않는 자연수이다.

출력
첫째 줄에 테트로미노가 놓인 칸에 쓰인 수들의 합의 최댓값을 출력한다.
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAX 500

int n, m;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int Max;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void dfs(int y, int x, int cnt, int acc) {
	visited[y][x] = true;
	
	if(cnt == 3) {
		Max = max(Max, acc);
		return;
	}
	
	for(int i=0; i<4; i++) {
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		
		if(0 <= new_y && new_y < n && 0 <= new_x && new_x < m && !visited[new_y][new_x]) {
			dfs(new_y, new_x, cnt+1, acc+arr[new_y][new_x]);
			visited[new_y][new_x] = false;
		}
	}
	
	visited[y][x] = false;
}

void middleFinger(int y, int x) {
	// ㅗ 
	if(y >= 1 && x >= 1 && x < m-1) {
		Max = max(Max, arr[y][x] + arr[y][x-1] + arr[y][x+1] + arr[y-1][x]);
	}
	// ㅏ 
	if(y >= 1 && y < n-1 && x < m-1) {
		Max = max(Max, arr[y][x] + arr[y-1][x] + arr[y+1][x] + arr[y][x+1]);
	}
	// ㅜ 
	if(y < n-1 && x >= 1 && x < m-1) {
		Max = max(Max, arr[y][x] + arr[y][x-1] + arr[y][x+1] + arr[y+1][x]);
	}
	// ㅓ 
	if(y >= 1 && y < n-1 && x >= 1) {
		Max = max(Max, arr[y][x] + arr[y-1][x] + arr[y+1][x] + arr[y][x-1]);
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
		}
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			dfs(i,j, 0, arr[i][j]);
			middleFinger(i,j);
		}
	}
	
	cout << Max;
	return 0;
}

/* 
그래프: DFS + 완전탐색 
!! DFS로 탐색 불가능한 (ㅗ,ㅜ,ㅓ,ㅏ) 테트로미노는 직접 구현하여 완전탐색하기 
*/ 
