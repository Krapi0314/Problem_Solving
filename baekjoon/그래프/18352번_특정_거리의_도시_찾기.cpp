/*
baekjoon 18352��: Ư�� �Ÿ��� ���� ã��

�ð� ����: 2��
�޸� ����: 256 MB

����
� ���󿡴� 1������ N�������� ���ÿ� M���� �ܹ��� ���ΰ� �����Ѵ�. ��� ������ �Ÿ��� 1�̴�.
�� �� Ư���� ���� X�κ��� ����Ͽ� ������ �� �ִ� ��� ���� �߿���, �ִ� �Ÿ��� ��Ȯ�� K�� ��� ���õ��� ��ȣ�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. ���� ��� ���� X���� ��� ���� X�� ���� �ִ� �Ÿ��� �׻� 0�̶�� �����Ѵ�.
���� ��� N=4, K=2, X=1�� �� ������ ���� �׷����� �����Ǿ� �ִٰ� ��������.
�� �� 1�� ���ÿ��� ����Ͽ� ������ �� �ִ� ���� �߿���, �ִ� �Ÿ��� 2�� ���ô� 4�� ���� ���̴�.  2���� 3�� ������ ���, �ִ� �Ÿ��� 1�̱� ������ ������� �ʴ´�.

�Է�
ù° �ٿ� ������ ���� N, ������ ���� M, �Ÿ� ���� K, ��� ������ ��ȣ X�� �־�����. (2 �� N �� 300,000, 1 �� M �� 1,000,000, 1 �� K �� 300,000, 1 �� X �� N) ��° �ٺ��� M���� �ٿ� ���ļ� �� ���� �ڿ��� A, B�� ������ �������� ���еǾ� �־�����. �̴� A�� ���ÿ��� B�� ���÷� �̵��ϴ� �ܹ��� ���ΰ� �����Ѵٴ� �ǹ̴�. (1 �� A, B �� N) ��, A�� B�� ���� �ٸ� �ڿ����̴�.

���
X�κ��� ����Ͽ� ������ �� �ִ� ���� �߿���, �ִ� �Ÿ��� K�� ��� ������ ��ȣ�� �� �ٿ� �ϳ��� ������������ ����Ѵ�.
�� �� ������ �� �ִ� ���� �߿���, �ִ� �Ÿ��� K�� ���ð� �ϳ��� �������� ������ -1�� ����Ѵ�. 
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
	
	// ��� ������ �ִܰŸ� ���ϱ� 
	while(!q.empty()) {
		int node = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		// �ִܰŸ��� k�� ������ ����Ʈ�� �߰� 
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
		// �������� ���� �� ��� 
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
	// �� ���͸� ������ �־������ν� 2���� ������ ���� �ʱ�ȭ 
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
��� ���ÿ� ���Ͽ� �ִܰŸ��� ����� ��, �ִܰŸ��� k�� ��ġ�ϴ� ���õ��� ������������ �����Ͽ� ��� 
*/ 
