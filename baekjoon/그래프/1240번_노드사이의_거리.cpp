/*
baekjoon 1240��: �������� �Ÿ�

�ð� ����: 2��
�޸� ����: 128 MB

����
N(2��N��1,000)���� ���� �̷���� Ʈ���� �־����� M(M��1,000)���� �� ��� ���� �Է¹��� �� �� ��� ������ �Ÿ��� ����϶�.

�Է�
ù° �ٿ� ����� ���� N�� �Էµǰ� ���� N-1���� �ٿ� Ʈ�� �� ����� �� ���� �Ÿ�(10,000 ������ ����)�� �Է¹޴´�. �� ���� �ٿ��� �Ÿ��� �˰� ���� M���� ��� ���� �� �ٿ� �� �־� �Էµȴ�.

���
M���� �ٿ� ���ʴ�� �Է¹��� �� ��� ������ �Ÿ��� ����Ѵ�. 
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

// �����ϰ� dfs�� ��ȯ���� ���� �ϰ�, �ִܰŸ���  dfs ���ο��� ���  
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
Ʈ���� �׷����� �����̰�, ������ �� ��� ���� ��ΰ� ���� 1���̱� ������ DFS�� ����Ͽ� �ִ� �Ÿ� ��� ���� 
*/ 
