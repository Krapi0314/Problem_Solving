/*
baekjoon 1967��: Ʈ���� ����

�ð� ����: 2 ��
�޸� ����: 128 MB

����
Ʈ��(tree)�� ����Ŭ�� ���� ������ �׷����̴�. Ʈ�������� � �� ��带 �����ص� �� ���̿� ��ΰ� �׻� �ϳ��� �����ϰ� �ȴ�. Ʈ������ � �� ��带 �����ؼ� �������� �� ��� ��, ���� ��� �þ�� ��찡 ���� ���̴�. �̷� �� Ʈ���� ��� ������ �� �� ��带 ������ �� ������ �ϴ� �� �ȿ� ���� �ȴ�.
�̷� �� ��� ������ ����� ���̸� Ʈ���� �����̶�� �Ѵ�. ��Ȯ�� �������ڸ� Ʈ���� �����ϴ� ��� ��ε� �߿��� ���� �� ���� ���̸� ���Ѵ�.
�Է����� ��Ʈ�� �ִ� Ʈ���� ����ġ�� �ִ� ������� �� ��, Ʈ���� ������ ���ؼ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. �Ʒ��� ���� Ʈ���� �־����ٸ� Ʈ���� ������ 45�� �ȴ�.
Ʈ���� ���� 1���� n���� ��ȣ�� �Ű��� �ִ�.

�Է�
������ ù ��° ���� ����� ���� n(1 �� n �� 10,000)�̴�. ��° �ٺ��� n-1���� �ٿ� �� ������ ���� ������ ���´�. ������ ���� ������ �� ���� ������ �̷���� �ִ�. ù ��° ������ ������ �����ϴ� �� ��� �� �θ� ����� ��ȣ�� ��Ÿ����, �� ��° ������ �ڽ� ��带, �� ��° ������ ������ ����ġ�� ��Ÿ����. ������ ���� ������ �θ� ����� ��ȣ�� ���� ���� ���� �Էµǰ�, �θ� ����� ��ȣ�� ������ �ڽ� ����� ��ȣ�� ���� ���� ���� �Էµȴ�. ��Ʈ ����� ��ȣ�� �׻� 1�̶�� �����ϸ�, ������ ����ġ�� 100���� ũ�� ���� ���� �����̴�.

���
ù° �ٿ� Ʈ���� ������ ����Ѵ�. 
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
!! Ʈ���� ����: �ϳ��� �������� ���� �ָ� �ִ� ������ ���� ������ �ش��ϴ� �� ���� �߿� �ϳ���
			=> �� �������� dfs�� �����Ͽ� ���� �ָ� �ִ� ������ ã�� �� (���� ���� 1), �ش� �������� ���� �ָ� �ִ� ������ �� ã���� (���� ���� 2) �� ������ �Ÿ��� Ʈ���� ���� 

�ٸ� Ǯ��: Leaf�� �ش��ϴ� �����鿡�� �����ϴ� dfs ���� -> �ִ밪 ã��
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
