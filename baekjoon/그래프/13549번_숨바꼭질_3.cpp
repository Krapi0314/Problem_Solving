/*
baekjoon 13549��: ���ٲ��� 3

�ð� ����: 2 ��
�޸� ����: 512 MB

����
�����̴� ������ ���ٲ����� �ϰ� �ִ�. �����̴� ���� �� N(0 �� N �� 100,000)�� �ְ�, ������ �� K(0 �� K �� 100,000)�� �ִ�. �����̴� �Ȱų� �����̵��� �� �� �ִ�. ����, �������� ��ġ�� X�� �� �ȴ´ٸ� 1�� �Ŀ� X-1 �Ǵ� X+1�� �̵��ϰ� �ȴ�. �����̵��� �ϴ� ��쿡�� 0�� �Ŀ� 2*X�� ��ġ�� �̵��ϰ� �ȴ�.
�����̿� ������ ��ġ�� �־����� ��, �����̰� ������ ã�� �� �ִ� ���� ���� �ð��� �� �� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù ��° �ٿ� �����̰� �ִ� ��ġ N�� ������ �ִ� ��ġ K�� �־�����. N�� K�� �����̴�.

���
�����̰� ������ ã�� ���� ���� �ð��� ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAX 100000

int n,k;
int dx[2] = { -1, 1 };
bool visited[MAX+1];

int bfs() {
	queue<pair<int, int>> q;
	q.push({n,0});
	visited[n] = true;
	
	while(!q.empty()) {
		int n = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		if(n == k) {
			return cnt;
		}
		
		// x2
		int new_n = n * 2;
	
		if(new_n <= MAX && !visited[new_n]) {
			visited[new_n] = true;
			q.push({new_n, cnt});
		}
		
		// -1, +1
		new_n = 0;
		for(int i=0; i<2; i++) {
			new_n = n + dx[i];
			
			if(0 <= new_n && new_n <= MAX && !visited[new_n]) {
				visited[new_n] = true;
				q.push({new_n, cnt+1});
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> k;
	
	cout << bfs();
	return 0;
}

/* 
Graph: BFS
�����̵��� 0��, +1,-1 �̵��� 1�ʰ� �ҿ�ǹǷ�, 3���� ��츦 Ž���� �� �����̵��� �� �켱������ ���� -> ���� ť�� ����
�켱���� ť�� �ƴϿ��� �����̵��� �׻� ť�� ���� ���� ������, �켱������ ���� �������� ������ ���� 
*/ 
