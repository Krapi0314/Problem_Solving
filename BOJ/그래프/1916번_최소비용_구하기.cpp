/*
1916번: 최소비용 구하기

시간 제한: 0.5초
메모리 제한: 128 MB

문제
N개의 도시가 있다. 그리고 한 도시에서 출발하여 다른 도시에 도착하는 M개의 버스가 있다. 우리는 A번째 도시에서 B번째 도시까지 가는데 드는 버스 비용을 최소화 시키려고 한다. A번째 도시에서 B번째 도시까지 가는데 드는 최소비용을 출력하여라. 도시의 번호는 1부터 N까지이다.

입력
첫째 줄에 도시의 개수 N(1 ≤ N ≤ 1,000)이 주어지고 둘째 줄에는 버스의 개수 M(1 ≤ M ≤ 100,000)이 주어진다. 그리고 셋째 줄부터 M+2줄까지 다음과 같은 버스의 정보가 주어진다. 먼저 처음에는 그 버스의 출발 도시의 번호가 주어진다. 그리고 그 다음에는 도착지의 도시 번호가 주어지고 또 그 버스 비용이 주어진다. 버스 비용은 0보다 크거나 같고, 100,000보다 작은 정수이다.
그리고 M+3째 줄에는 우리가 구하고자 하는 구간 출발점의 도시번호와 도착점의 도시번호가 주어진다. 출발점에서 도착점을 갈 수 있는 경우만 입력으로 주어진다.

출력
첫째 줄에 출발 도시에서 도착 도시까지 가는데 드는 최소 비용을 출력한다.

예제 입력 1 
5
8
1 2 2
1 3 3
1 4 1
1 5 10
2 4 2
3 4 1
3 5 1
4 5 3
1 5

예제 출력 1 
4
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define INF 1e9
#define MAX 1000

vector<pair<int,int>> graph[MAX+1]; // graph[vertex] = { adj_vertex, dist }
int n, m;
int s, e, w;
int start_vertex, end_vertex;

vector<int> dijkstra(int start, int end) {
	priority_queue<pair<int,int>> pq; // -dist, adj_vertex
	vector<int> dist(n+1, INF); // start에서 각 정점들까지의 최단거리

	dist[start] = 0;
	pq.push({0, start});

	while(!pq.empty()) {
		int cur_dist = -pq.top().first;
		int cur_vertex = pq.top().second;
		pq.pop();
		
        if(cur_vertex == end) { // 만약 현재 vertex가 end(도착 정점)이면 끝낸다 (현재 vertex가 되기 이전에 end 정점에 대한 최단 거리가 확정되었기 때문)
            break;
        }
		if(cur_dist > dist[cur_vertex]) { // 만약 dist[vertex]가 업데이트 되어 가지고 있던 dist보다 작아지면 스킵한다 (이 경로는 더이상 최단 거리가 아니기 때문)
			continue; 
		}

		for(int i=0; i<graph[cur_vertex].size(); i++) {
			int adj_dist = graph[cur_vertex][i].second;
			int adj_vertex = graph[cur_vertex][i].first;
			
			int new_dist = adj_dist + cur_dist;
			if(new_dist < dist[adj_vertex]) {
				dist[adj_vertex] = new_dist;
				pq.push({-new_dist, adj_vertex});
			}
		}
	}

	return dist;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	while(m--) {
		cin >> s >> e >> w;
		graph[s].push_back({e,w});
	}
	cin >> start_vertex >> end_vertex;

	vector<int> dist = dijkstra(start_vertex, end_vertex);

	cout << dist[end_vertex] << "\n";
	return 0;
}

/*
Graph, Dijkstra
1. 출발 도시를 기준으로, 다익스트라 알고리즘을 사용하여 다른 모든 도시들에 대해 최소 거리 구함
2. 이 때, 도착 도시까지의 최단 거리만 구하면 되므로, 최단 거리가 결정된 우선순위 큐의 원소들 중 도착 도시가 나오면 멈춤 (도착 정점이 나오기 이전에 도착 정점에 대한 최단 거리가 확정되었기 때문)
*/