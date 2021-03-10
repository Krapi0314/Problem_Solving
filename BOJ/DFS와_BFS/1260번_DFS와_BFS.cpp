/*
BOJ 1260번: DFS와 BFS

시간 제한: 2초
메모리 제한: 128 MB
 
문제
그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 정점 번호는 1번부터 N번까지이다.

입력
첫째 줄에 정점의 개수 N(1 ≤ N ≤ 1,000), 간선의 개수 M(1 ≤ M ≤ 10,000), 탐색을 시작할 정점의 번호 V가 주어진다. 다음 M개의 줄에는 간선이 연결하는 두 정점의 번호가 주어진다. 어떤 두 정점 사이에 여러 개의 간선이 있을 수 있다. 입력으로 주어지는 간선은 양방향이다.

출력
첫째 줄에 DFS를 수행한 결과를, 그 다음 줄에는 BFS를 수행한 결과를 출력한다. V부터 방문된 점을 순서대로 출력하면 된다.
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
//#include <cstdio>

using namespace std;

int adj[1001][1001] = { 0, };
bool visited[1001] = { false, };
bool discovered[1001] = { false, };
int n, m, v;
int a, b;

void dfs(int v) //재귀함수로 구현
{
	//정점 방문했다고 출력
	cout << v << " ";
	//정점 방문 처리
	visited[v] = true;
	//모든 인접 정점을 1부터 순회하면서 (정점 번호 작은 순)
		//갈 수 있는 정점이고 && 아직 방문하지 않았으면
			//dfs()

	for (int i = 1; i <= n; i++)
	{
		if (adj[v][i] == 1 && !visited[i])
		{
			dfs(i);
		}
	}
	//모든 정점의 방문이 끝났으면 종료하고 이전 정점으로 돌아간다
}

void bfs(int v) //큐로 구현
{
	int vertex;
	queue<int> q;
	//정점을 큐에 등록
	q.push(v);
	//정점을 찾았다고 기록
	discovered[v] = true;
	//큐가 빌때까지
		//큐에 저장된 첫 정점 출력
		//꺼내진 첫 정점을 기준으로
			//모든 인접 정점을 1부터 순회하면서 (정점 번호 작은 순)
				//갈 수 있는 정점이고 && 정점을 찾지 못했다면
					//큐에 등록
					//정점을 찾았다고 기록

	while (!q.empty())
	{
		vertex = q.front();
		q.pop();
		cout << vertex << " ";

		for (int i = 1; i <= n; i++)
		{
			if (adj[vertex][i] == 1 && !discovered[i])
			{
				q.push(i);
				discovered[i] = true;
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> v;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;

		adj[a][b] = 1; adj[b][a] = 1;
	}

	dfs(v);
	cout << "\n";
	bfs(v);
}

/*
정점의 개수 n, 간선의 개수 m, 탐색을 시작할 정점의 번호 v
정점과 간선의 정보 입력 받아 그래프 생성 (인접 리스트로)
v를 시작으로 dfs(v) (모두 방문)
v를 시작으로 bfs(v) (모두 방문)

시간 복잡도: 10000 + 1000 * 1000 + 1000 * 1000 = 2010000회 정도
 */
