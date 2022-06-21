/*
BOJ 18352번: 특정 거리의 도시 찾기

시간 제한: 2초
메모리 제한: 256 MB

문제
어떤 나라에는 1번부터 N번까지의 도시와 M개의 단방향 도로가 존재한다. 모든 도로의 거리는 1이다.
이 때 특정한 도시 X로부터 출발하여 도달할 수 있는 모든 도시 중에서, 최단 거리가 정확히 K인 모든 도시들의 번호를 출력하는 프로그램을 작성하시오. 또한 출발 도시 X에서 출발 도시 X로 가는 최단 거리는 항상 0이라고 가정한다.
예를 들어 N=4, K=2, X=1일 때 다음과 같이 그래프가 구성되어 있다고 가정하자.
이 때 1번 도시에서 출발하여 도달할 수 있는 도시 중에서, 최단 거리가 2인 도시는 4번 도시 뿐이다.  2번과 3번 도시의 경우, 최단 거리가 1이기 때문에 출력하지 않는다.

입력
첫째 줄에 도시의 개수 N, 도로의 개수 M, 거리 정보 K, 출발 도시의 번호 X가 주어진다. (2 ≤ N ≤ 300,000, 1 ≤ M ≤ 1,000,000, 1 ≤ K ≤ 300,000, 1 ≤ X ≤ N) 둘째 줄부터 M개의 줄에 걸쳐서 두 개의 자연수 A, B가 공백을 기준으로 구분되어 주어진다. 이는 A번 도시에서 B번 도시로 이동하는 단방향 도로가 존재한다는 의미다. (1 ≤ A, B ≤ N) 단, A와 B는 서로 다른 자연수이다.

출력
X로부터 출발하여 도달할 수 있는 도시 중에서, 최단 거리가 K인 모든 도시의 번호를 한 줄에 하나씩 오름차순으로 출력한다.
이 때 도달할 수 있는 도시 중에서, 최단 거리가 K인 도시가 하나도 존재하지 않으면 -1을 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAX 300000

int n,m,k,x;
int a,b;
vector<vector<int> > v;
bool visited[MAX+1];

void bfs(int start) {
	queue<pair<int, int> > q;
	vector<int> ans;
	q.push({start, 0});
	visited[start] = true;
	
	// 모든 도시의 최단거리 구하기 
	while(!q.empty()) {
		int node = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		// 최단거리가 k와 같으면 리스트에 추가 
		if(cnt == k) {
			ans.push_back(node);
		}
		
		for(int i=0; i<v[node].size(); i++) {
			int new_node = v[node][i];
			int new_cnt = cnt + 1;
			
			if(!visited[new_node]) {
				visited[new_node] = true;
				q.push({new_node, new_cnt});
			}
		}
	}
	
	if(ans.empty()) {
		cout << "-1";
	}
	else {
		// 오름차순 정렬 후 출력 
		sort(ans.begin(), ans.end());
		for(int i=0; i<ans.size(); i++) {
			cout << ans[i] << "\n";
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k >> x;
	// 빈 벡터를 열마다 넣어줌으로써 2차원 벡터의 열만 초기화 
	for(int i=0; i<n+1; i++) {
		v.push_back(vector<int>());
	}
	
	for(int i=0; i<m; i++) {
		cin >> a >> b;
	
		v[a].push_back(b);
	}
	
	bfs(x);
	
	return 0;
}

/* 
BFS
모든 도시에 대하여 최단거리를 계산한 후, 최단거리가 k와 일치하는 도시들을 오름차순으로 정렬하여 출력 
*/ 
