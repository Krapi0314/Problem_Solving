/*
BOJ 1238번: 파티

시간 제한: 1초
메모리 제한: 128 MB

문제
N개의 숫자로 구분된 각각의 마을에 한 명의 학생이 살고 있다.
어느 날 이 N명의 학생이 X (1 ≤ X ≤ N)번 마을에 모여서 파티를 벌이기로 했다. 이 마을 사이에는 총 M개의 단방향 도로들이 있고 i번째 길을 지나는데 Ti(1 ≤ Ti ≤ 100)의 시간을 소비한다.
각각의 학생들은 파티에 참석하기 위해 걸어가서 다시 그들의 마을로 돌아와야 한다. 하지만 이 학생들은 워낙 게을러서 최단 시간에 오고 가기를 원한다.
이 도로들은 단방향이기 때문에 아마 그들이 오고 가는 길이 다를지도 모른다. N명의 학생들 중 오고 가는데 가장 많은 시간을 소비하는 학생은 누구일지 구하여라.

입력
첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 10,000), X가 공백으로 구분되어 입력된다. 두 번째 줄부터 M+1번째 줄까지 i번째 도로의 시작점, 끝점, 그리고 이 도로를 지나는데 필요한 소요시간 Ti가 들어온다. 시작점과 끝점이 같은 도로는 없으며, 시작점과 한 도시 A에서 다른 도시 B로 가는 도로의 개수는 최대 1개이다.
모든 학생들은 집에서 X에 갈수 있고, X에서 집으로 돌아올 수 있는 데이터만 입력으로 주어진다.

출력
첫 번째 줄에 N명의 학생들 중 오고 가는데 가장 오래 걸리는 학생의 소요시간을 출력한다.

예제 입력 1 
4 8 2
1 2 4
1 3 2
1 4 7
2 1 1
2 3 5
3 1 2
3 4 4
4 2 3

예제 출력 1 
10
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAX 1000
#define INF 2e9

int n, m, x;
int s, e, t;
vector<pair<int,int> > arr[2][MAX+1]; // 정방향, 역방향 모두 입력받기 
int dist_sum[MAX+1];

void dijkstra(int direction, int start_vertex) {
	vector<int> shortest(n+1, INF);
	shortest[start_vertex] = 0;
	
	priority_queue<pair<int,int> > pq;
	pq.push({ 0, start_vertex });
	
	while(!pq.empty()) {
		int vertex = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();
		
		if(dist > shortest[vertex]) {
			continue;
		}
		
		int next_vertex_num = arr[direction][vertex].size();
		for(int i=0; i<next_vertex_num; i++) {
			int next_vertex = arr[direction][vertex][i].first;
			int next_dist = arr[direction][vertex][i].second;
			
			int new_dist = dist + next_dist;
			if(new_dist < shortest[next_vertex]) {
				shortest[next_vertex] = new_dist;
				pq.push({ -new_dist, next_vertex });
			}
		}
	}

	for(int i=1; i<=n; i++) {
		dist_sum[i] += shortest[i];
	}
	
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 0. 입력
	cin >> n >> m >> x;
	for(int i=0; i<m; i++) {
		cin >> s >> e >> t;
		
		arr[0][s].push_back({ e, t }); // 정방향
		arr[1][e].push_back({ s, t }); // 역방향

	}
	
	// 1. x에 대해 정방향 다익스트라, 최단거리 모두 dist_sum에 기록
	dijkstra(0, x);
	
	// 2. x에 대해 역방향 다익스트라, 최단거리 모두 dist_sum에 기록
	dijkstra(1, x);
	
	// 3. dist_sum 내림차순 정렬 후 dist_sum[0] 출력 
	sort(dist_sum+1, dist_sum+(n+1), greater<int>());
	cout << dist_sum[1];
	
	return 0;
}

/* 
Graph: Dijkstra

a -> x + x -> a 최단거리의 최댓값 구하기
1. x에 대해 정방향 다익스트라를 사용하면 x에서 모든 정점으로 가는 최단거리를 계산할 수 있음. 즉, x -> a 
2. x에 대해 역방향 다익스트라(단방향 간선을 뒤집은 그래프를 사용)를 사용하면 모든 정점에서 x로 가는 최단거리를 계산할 수 있음. 즉, a -> x 
*/ 
