/*
BOJ 1967번: 트리의 지름

시간 제한: 2 초
메모리 제한: 128 MB

문제
트리(tree)는 사이클이 없는 무방향 그래프이다. 트리에서는 어떤 두 노드를 선택해도 둘 사이에 경로가 항상 하나만 존재하게 된다. 트리에서 어떤 두 노드를 선택해서 양쪽으로 쫙 당길 때, 가장 길게 늘어나는 경우가 있을 것이다. 이럴 때 트리의 모든 노드들은 이 두 노드를 지름의 끝 점으로 하는 원 안에 들어가게 된다.
이런 두 노드 사이의 경로의 길이를 트리의 지름이라고 한다. 정확히 정의하자면 트리에 존재하는 모든 경로들 중에서 가장 긴 것의 길이를 말한다.
입력으로 루트가 있는 트리를 가중치가 있는 간선들로 줄 때, 트리의 지름을 구해서 출력하는 프로그램을 작성하시오. 아래와 같은 트리가 주어진다면 트리의 지름은 45가 된다.
트리의 노드는 1부터 n까지 번호가 매겨져 있다.

입력
파일의 첫 번째 줄은 노드의 개수 n(1 ≤ n ≤ 10,000)이다. 둘째 줄부터 n-1개의 줄에 각 간선에 대한 정보가 들어온다. 간선에 대한 정보는 세 개의 정수로 이루어져 있다. 첫 번째 정수는 간선이 연결하는 두 노드 중 부모 노드의 번호를 나타내고, 두 번째 정수는 자식 노드를, 세 번째 정수는 간선의 가중치를 나타낸다. 간선에 대한 정보는 부모 노드의 번호가 작은 것이 먼저 입력되고, 부모 노드의 번호가 같으면 자식 노드의 번호가 작은 것이 먼저 입력된다. 루트 노드의 번호는 항상 1이라고 가정하며, 간선의 가중치는 100보다 크지 않은 양의 정수이다.

출력
첫째 줄에 트리의 지름을 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAX 10000

int n;
int x,y,w;
vector<pair<int,int>> adj[MAX+1];
bool visited[MAX+1];
int diameter_node;
int ans;

void dfs(int node, int len) {	
	visited[node] = true;
	
	if(len > ans) {
		diameter_node = node;
		ans = len;
	} 
	
	int adj_len = (int)adj[node].size();
	for(int i=0; i<adj_len; i++) {
		int adj_node = adj[node][i].first;
		int new_len = adj[node][i].second + len;
		
		if(!visited[adj_node]) {
			dfs(adj_node, new_len);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i=1; i<n; i++) {
		cin >> x >> y >> w;
		adj[x].push_back(make_pair(y, w));
		adj[y].push_back(make_pair(x, w));
	}
		
	dfs(1,0);
	memset(visited, false, sizeof(visited));
	dfs(diameter_node, 0);
	
	cout << ans;
	return 0;
}

/* 
Graph: DFS + Tree
!! 트리의 지름: 하나의 정점에서 가장 멀리 있는 정점은 원의 지름에 해당하는 두 정점 중에 하나임
			=> 한 정점에서 dfs를 수행하여 가장 멀리 있는 지점을 찾은 후 (지름 정점 1), 해당 지점에서 가장 멀리 있는 지점을 또 찾으면 (지름 정점 2) 두 지점의 거리가 트리의 지름 

다른 풀이: Leaf에 해당하는 정점들에서 시작하는 dfs 수행 -> 최대값 찾기
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAX 10000

int n;
int x,y,w;
vector<pair<int,int>> adj[MAX+1];
int degree[MAX+1];
bool visited[MAX+1];
int ans;

void dfs(int node, int len) {	
	visited[node] = true;
	
	int adj_len = (int)adj[node].size();
	for(int i=0; i<adj_len; i++) {
		int adj_node = adj[node][i].first;
		int new_len = adj[node][i].second + len;
		
		if(!visited[adj_node]) {
			ans = max(ans, new_len);
			dfs(adj_node, new_len);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i=1; i<n; i++) {
		cin >> x >> y >> w;
		degree[x]++;
		adj[x].push_back(make_pair(y, w));
		adj[y].push_back(make_pair(x, w));
	}
		
	for(int i=1; i<=n; i++) {
		if(degree[i] == 0) {
			memset(visited, false, sizeof(visited));
			dfs(i, 0);
		}
	}
	
	cout << ans;
	return 0;
}
*/
