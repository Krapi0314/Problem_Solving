/*
baekjoon 1389��: �ɺ� �������� 6�ܰ� ��Ģ

�ð� ����: 2 ��
�޸� ����: 128 MB

����
�ɺ� �������� 6�ܰ� ��Ģ�� ���ϸ� ������ �ִ� ��� ������� �ִ� 6�ܰ� �̳����� ���� �ƴ� ������� ����� �� �ִ�. �ɺ� ������ ������ ������ �� ����� �ּ� �� �ܰ� ���� �̾��� �� �ִ��� ����ϴ� �����̴�.
���� ���, ���� ������� �� ���� ���ϴ��б��� �̰�ȣ�� �������б��� �μ���� �� �ܰ踸�� �̾��� �� ������?
õ��ȣ�� �̰�ȣ�� ���� �б��� �ٴϴ� �����̴�. õ��ȣ�� �ֹ����� baekjoon Online Judge�� ���� �˰� �Ǿ���. �ֹ��ذ� �輱���� ���� Startlink�� â���ߴ�. �輱���� �赵���� ���� �б� ���Ƹ� �Ҽ��̴�. �赵���� �μ���� ���� �б��� �ٴϴ� ���̷� ���� �˰� �ִ�. ��, �̰�ȣ-õ��ȣ-�ֹ���-�輱��-�赵��-�μ��� �� ���� 5�ܰ踸 ��ġ�� �ȴ�.
�ɺ� �������� �̱� �渮��� ��ȭ���� ���� �ɺ� ������ ������ ������ ������ �ܰ��� �� ���� ���� ���� ����̶�� �Ѵ�.
������ baekjoon Online Judge�� ���� �߿��� �ɺ� �������� ���� ���� ���� ����� ã������ �Ѵ�. �ɺ� ������ ���� ��� ����� �ɺ� ������ ������ ���� ��, ������ �ܰ��� ���̴�.

���� ���, baekjoon�� ������ 5���̰�, 1�� 3, 1�� 4, 2�� 3, 3�� 4, 4�� 5�� ģ���� ��츦 �����غ���.
1�� 2���� 3�� ���� 2�ܰ� ����, 3���� 1�ܰ�, 4���� 1�ܰ�, 5���� 4�� ���ؼ� 2�ܰ� ���� �� �� �ִ�. ����, �ɺ� �������� ���� 2+1+1+2 = 6�̴�.
2�� 1���� 3�� ���ؼ� 2�ܰ� ����, 3���� 1�ܰ� ����, 4���� 3�� ���ؼ� 2�ܰ� ����, 5���� 3�� 4�� ���ؼ� 3�ܰ� ���� �� �� �ִ�. ����, �ɺ� �������� ���� 2+1+2+3 = 8�̴�.
3�� 1���� 1�ܰ�, 2���� 1�ܰ�, 4���� 1�ܰ�, 5���� 4�� ���� 2�ܰ� ���� �� �� �ִ�. ����, �ɺ� �������� ���� 1+1+1+2 = 5�̴�.
4�� 1���� 1�ܰ�, 2���� 3�� ���� 2�ܰ�, 3���� 1�ܰ�, 5���� 1�ܰ� ���� �� �� �ִ�. 4�� �ɺ� �������� ���� 1+2+1+1 = 5�� �ȴ�.
���������� 5�� 1���� 4�� ���� 2�ܰ�, 2���� 4�� 3�� ���� 3�ܰ�, 3���� 4�� ���� 2�ܰ�, 4���� 1�ܰ� ���� �� �� �ִ�. 5�� �ɺ� �������� ���� 2+3+2+1 = 8�̴�.
5���� ���� �߿��� �ɺ� �������� ���� ���� ���� ����� 3�� 4�̴�.

baekjoon ������ ���� ģ�� ���谡 �Է����� �־����� ��, �ɺ� �������� ���� ���� ���� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ �� N (2 �� N �� 100)�� ģ�� ������ �� M (1 �� M �� 5,000)�� �־�����. ��° �ٺ��� M���� �ٿ��� ģ�� ���谡 �־�����. ģ�� ����� A�� B�� �̷���� ������, A�� B�� ģ����� ���̴�. A�� B�� ģ���̸�, B�� A�� ģ���̸�, A�� B�� ���� ���� ����. ģ�� ����� �ߺ��Ǿ� ���� ���� ������, ģ���� �� �� ���� ����� ����. ��, ��� ����� ģ�� ����� ����Ǿ��� �ִ�. ����� ��ȣ�� 1���� N�����̸�, �� ����� ���� ��ȣ�� ���� ���� ����.

���
ù° �ٿ� baekjoon�� ���� �߿��� �ɺ� �������� ���� ���� ���� ����� ����Ѵ�. �׷� ����� ���� ���� ��쿡�� ��ȣ�� ���� ���� ����� ����Ѵ�.
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAX 100
#define INF 2e8

int n, m;
int a, b;
int graph[MAX+1][MAX+1];
int cnt, Min, ans;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	for(int i=1; i<=MAX; i++) {
		for(int j=1; j<=MAX; j++) {
			if(i == j) graph[i][j] = 0;
			else graph[i][j] = INF;
		}
	}

	cin >> n >> m;
	for(int i=0; i<m; i++) {
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}
	
	// floyd-warshall algorithm
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
			}
		}
	}
	
	Min = INF;
	for(int i=1; i<=n; i++) {
		cnt = 0;
		for(int j=1; j<=n; j++) {
			cnt += graph[i][j];
		}
		if(cnt < Min) {
			Min = cnt;
			ans = i;
		}
	}
	
	cout << ans;
	return 0;
}

/* 
�׷��� - �÷��̵�-�ͼ� �˰��� (��� ���� �ֿ� ���� �ִܰ�� �˰���) 

BFS�� �̿��� ���� Ǯ��
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAX 100

int n, m;
int a, b;
bool arr[MAX+1][MAX+1];
int cnt, Min, ans;

int bfs(int start) {
	int bacon = 0;
	bool visited[MAX+1] = { false, }; // �湮 ���� 
	queue<pair<int, int> > q; // node, count
	
	visited[start] = true;
	q.push(make_pair(start, 0));
	
	while(!q.empty()) {
		int node = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		for(int i=1; i<=n; i++) {
			if(node != i && arr[node][i] && !visited[i]) {
				visited[i] = true;
				q.push(make_pair(i, cnt+1));
				bacon += cnt+1;
			}
		}
	}

	return bacon;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for(int i=0; i<m; i++) {
		cin >> a >> b;
		arr[a][b] = true;
		arr[b][a] = true;
	}
	
	Min = 2e9;
	for(int i=1; i<=n; i++) {
		cnt = bfs(i);
		if(cnt < Min) {
			Min = cnt;
			ans = i;
		}
	}
	
	cout << ans;
	return 0;
} 
*/ 
