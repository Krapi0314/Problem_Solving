/*
baekjoon 1325��: ȿ������ ��ŷ

�ð� ����: 5��
�޸� ����: 256 MB

����
��Ŀ �������� �� �˷��� ��� ȸ�縦 ��ŷ�Ϸ��� �Ѵ�. �� ȸ��� N���� ��ǻ�ͷ� �̷���� �ִ�. �������� ������ ������, �� ���� ��ŷ���� ���� ���� ��ǻ�͸� ��ŷ �� �� �ִ� ��ǻ�͸� ��ŷ�Ϸ��� �Ѵ�.
�� ȸ���� ��ǻ�ʹ� �ŷ��ϴ� �����, �ŷ����� �ʴ� ����� �̷���� �ִµ�, A�� B�� �ŷ��ϴ� ��쿡�� B�� ��ŷ�ϸ�, A�� ��ŷ�� �� �ִٴ� �Ҹ���.
�� ȸ���� ��ǻ���� �ŷ��ϴ� ���谡 �־����� ��, �� ���� ���� ���� ��ǻ�͸� ��ŷ�� �� �ִ� ��ǻ���� ��ȣ�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ�, N�� M�� ���´�. N�� 10,000���� �۰ų� ���� �ڿ���, M�� 100,000���� �۰ų� ���� �ڿ����̴�. ��° �ٺ��� M���� �ٿ� �ŷ��ϴ� ���谡 A B�� ���� �������� ������, "A�� B�� �ŷ��Ѵ�"�� �ǹ��Ѵ�. ��ǻ�ʹ� 1������ N������ ��ȣ�� �ϳ��� �Ű��� �ִ�.

���
ù° �ٿ�, �������� �� ���� ���� ���� ��ǻ�͸� ��ŷ�� �� �ִ� ��ǻ���� ��ȣ�� ������������ ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAX 10001

vector<int> adj[MAX];
bool discovered[MAX];
vector<int> v;
queue<int> q;
int n,m,a,b;
int Max,cnt;

void bfs(int vertex) {
	discovered[vertex] = true;
	q.push(vertex);
	
	while(!q.empty()) {
		int here = q.front(); q.pop();
		for(int i=0; i<adj[here].size(); i++) {
			int there = adj[here][i];
			if(!discovered[there]) {
				q.push(there);
				cnt++;
				discovered[there] = true;
			}
		}
	}

}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for(int i=0; i<m; i++) {
		cin >> a >> b;
		adj[b].push_back(a);
	}
	
	for(int i=1; i<=n; i++) {
		memset(discovered,false,sizeof(discovered));
		cnt = 0;
		bfs(i);
		if(cnt > Max) {
			v.clear();
			v.push_back(i);
			Max = cnt;
		}
		else if(cnt == Max) {
			v.push_back(i);
		}
	}
	
	for(int i=0; i<v.size(); i++) {
		cout << v[i] << " ";
	}
}

/*
bfs

vector<int> adj[MAX] : vector<int>���� MAX�� ������, �ϳ��ϳ��� vector<int>�� array�� 

bfs(vertex)
	discovered vertex
	cnt++
	queue push vertex
	
	while ! queue empty
		int here = queue front pop
		for n
			int there = adj[here][i]
			if !discovered[there]
				queue push there
				discovered[there]

cin n m
for m
	cin a b
	adj[b].push_back(b)

for n
	memset discovered false
	bfs()
	if cnt > max
		vector clear
		vector pushback i
	else if cnt == max
		vector pushback i
	
for vector
	cout v[i]					
*/
