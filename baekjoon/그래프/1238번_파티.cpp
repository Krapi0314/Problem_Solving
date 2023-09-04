/*
BOJ 1238��: ��Ƽ

�ð� ����: 1��
�޸� ����: 128 MB

����
N���� ���ڷ� ���е� ������ ������ �� ���� �л��� ��� �ִ�.
��� �� �� N���� �л��� X (1 �� X �� N)�� ������ �𿩼� ��Ƽ�� ���̱�� �ߴ�. �� ���� ���̿��� �� M���� �ܹ��� ���ε��� �ְ� i��° ���� �����µ� Ti(1 �� Ti �� 100)�� �ð��� �Һ��Ѵ�.
������ �л����� ��Ƽ�� �����ϱ� ���� �ɾ�� �ٽ� �׵��� ������ ���ƿ;� �Ѵ�. ������ �� �л����� ���� �������� �ִ� �ð��� ���� ���⸦ ���Ѵ�.
�� ���ε��� �ܹ����̱� ������ �Ƹ� �׵��� ���� ���� ���� �ٸ����� �𸥴�. N���� �л��� �� ���� ���µ� ���� ���� �ð��� �Һ��ϴ� �л��� �������� ���Ͽ���.

�Է�
ù° �ٿ� N(1 �� N �� 1,000), M(1 �� M �� 10,000), X�� �������� ���еǾ� �Էµȴ�. �� ��° �ٺ��� M+1��° �ٱ��� i��° ������ ������, ����, �׸��� �� ���θ� �����µ� �ʿ��� �ҿ�ð� Ti�� ���´�. �������� ������ ���� ���δ� ������, �������� �� ���� A���� �ٸ� ���� B�� ���� ������ ������ �ִ� 1���̴�.
��� �л����� ������ X�� ���� �ְ�, X���� ������ ���ƿ� �� �ִ� �����͸� �Է����� �־�����.

���
ù ��° �ٿ� N���� �л��� �� ���� ���µ� ���� ���� �ɸ��� �л��� �ҿ�ð��� ����Ѵ�.

���� �Է� 1 
4 8 2
1 2 4
1 3 2
1 4 7
2 1 1
2 3 5
3 1 2
3 4 4
4 2 3

���� ��� 1 
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
vector<pair<int,int> > arr[2][MAX+1]; // ������, ������ ��� �Է¹ޱ� 
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
	
	// 0. �Է�
	cin >> n >> m >> x;
	for(int i=0; i<m; i++) {
		cin >> s >> e >> t;
		
		arr[0][s].push_back({ e, t }); // ������
		arr[1][e].push_back({ s, t }); // ������

	}
	
	// 1. x�� ���� ������ ���ͽ�Ʈ��, �ִܰŸ� ��� dist_sum�� ���
	dijkstra(0, x);
	
	// 2. x�� ���� ������ ���ͽ�Ʈ��, �ִܰŸ� ��� dist_sum�� ���
	dijkstra(1, x);
	
	// 3. dist_sum �������� ���� �� dist_sum[0] ��� 
	sort(dist_sum+1, dist_sum+(n+1), greater<int>());
	cout << dist_sum[1];
	
	return 0;
}

/* 
Graph: Dijkstra

a -> x + x -> a �ִܰŸ��� �ִ� ���ϱ�
1. x�� ���� ������ ���ͽ�Ʈ�� ����ϸ� x���� ��� �������� ���� �ִܰŸ��� ����� �� ����. ��, x -> a 
2. x�� ���� ������ ���ͽ�Ʈ��(�ܹ��� ������ ������ �׷����� ���)�� ����ϸ� ��� �������� x�� ���� �ִܰŸ��� ����� �� ����. ��, a -> x 
*/ 
