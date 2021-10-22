/*
BOJ 11725번: 트리의 부모 찾기

시간 제한: 1초
메모리 제한: 256 MB

문제
루트 없는 트리가 주어진다. 이때, 트리의 루트를 1이라고 정했을 때, 각 노드의 부모를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 노드의 개수 N (2 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N-1개의 줄에 트리 상에서 연결된 두 정점이 주어진다.

출력
첫째 줄부터 N-1개의 줄에 각 노드의 부모 노드 번호를 2번 노드부터 순서대로 출력한다. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int n;

int parent[100001];
bool visited[100001] = { false, } ;
vector<int> tree[100001];
int a, b;

void dfs(int v)
{
	visited[v] = true;

	for (int i = 0; i < tree[v].size(); i++)
	{
		int nextNode = tree[v][i];
		if (!visited[nextNode])
		{
			parent[nextNode] = v;
			dfs(nextNode);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i <= n; i++)
	{
		cout << parent[i] << "\n";
	}
}

/*
일반 트리 -> 그래프 형식으로
!!주어지는 정점 쌍들의 부모-자식 관계를 모르므로, 트리를 만들 수는 없고, 양방향 그래프로 생성.
!!생성한 그래프에서 시작 정점 1로 dfs 하면 1을 루트로 하는 트리의 부모-자식 관계를 알 수 있음

트리(양방향 그래프)를 인접 리스트로 구현한 뒤, dfs로 모든 정점에 접근함. 이때, dfs의 다음 정점으로 넘어가기 전에 parent[다음노드] = 현재노드로 각 정점들의 부모 노드 파악

parents[]

dfs
	if 연결되어 있고 방문하지 않았으면
		parent[다음 노드] = 현재 노드
		dfs(다음 노드로)
		
cin n (노드의 개수)

for n-1
	cin >> a >> b
	adj[a][b] = 1
	adj[b][a] = 1

dfs(1)

cout parents
*/
