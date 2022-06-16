/*
BOJ 1240번: 노드사이의 거리

시간 제한: 2초
메모리 제한: 128 MB

문제
N(2≤N≤1,000)개의 노드로 이루어진 트리가 주어지고 M(M≤1,000)개의 두 노드 쌍을 입력받을 때 두 노드 사이의 거리를 출력하라.

입력
첫째 줄에 노드의 개수 N이 입력되고 다음 N-1개의 줄에 트리 상에 연결된 두 점과 거리(10,000 이하의 정수)를 입력받는다. 그 다음 줄에는 거리를 알고 싶은 M개의 노드 쌍이 한 줄에 한 쌍씩 입력된다.

출력
M개의 줄에 차례대로 입력받은 두 노드 사이의 거리를 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAX 1000

int n, m;
int a, b, w;
int arr[MAX+1][MAX+1];
bool visited[MAX+1];

// 간단하게 dfs는 반환값을 없게 하고, 최단거리를  dfs 내부에서 출력  
void dfs(int node, int dist) {
	if(node == b) {
		cout << dist << "\n";
		return;
	}
	
	visited[node] = true;
	
	for(int i=1; i<=MAX; i++) {
		if(arr[node][i] && !visited[i]) {
			dfs(i, dist + arr[node][i]);
		}
	}
	
	return;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for(int i=0; i<n-1; i++) {
		cin >> a >> b >> w;
		arr[a][b] = w;
		arr[b][a] = w;
	}

	for(int i=0; i<m; i++) {
		cin >> a >> b;
		
		memset(visited, false, sizeof(visited));
		dfs(a, 0);
	}
	
	return 0;
}

/* 
DFS
트리는 그래프의 일종이고, 임의의 두 노드 간의 경로가 오직 1개이기 때문에 DFS를 사용하여 최단 거리 계산 가능 
*/ 
