/*
baekjoon 7562��: ����Ʈ�� �̵�

�ð� ����: 1��
�޸� ����: 256 MB

����
ü���� ���� �� ����Ʈ�� ������ �ִ�. ����Ʈ�� �� ���� �̵��� �� �ִ� ĭ�� �Ʒ� �׸��� �����ִ�. ����Ʈ�� �̵��Ϸ��� �ϴ� ĭ�� �־�����. ����Ʈ�� �� �� �����̸� �� ĭ���� �̵��� �� ������?

�Է�
�Է��� ù° �ٿ��� �׽�Ʈ ���̽��� ������ �־�����.
�� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ִ�. ù° �ٿ��� ü������ �� ���� ���� l(4 �� l �� 300)�� �־�����. ü������ ũ��� l �� l�̴�. ü������ �� ĭ�� �� ���� �� {0, ..., l-1} �� {0, ..., l-1}�� ��Ÿ�� �� �ִ�. ��° �ٰ� ��° �ٿ��� ����Ʈ�� ���� �ִ� ĭ, ����Ʈ�� �̵��Ϸ��� �ϴ� ĭ�� �־�����.

���
�� �׽�Ʈ ���̽����� ����Ʈ�� �ּ� �� ������ �̵��� �� �ִ��� ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int t;
int l;

bool visited[300][300];

int dx[8] = { 2, 2, 1, 1, -1, -1, -2, -2 };
int dy[8] = { -1, 1, 2, -2, 2, -2, 1, -1 };

int start_x, start_y;
int end_x, end_y;

void bfs() {
	queue<pair<int,pair<int,int> > > q;
	q.push(make_pair(0, make_pair(start_x,start_y)));
	visited[start_x][start_y] = true;
	
	while(!q.empty()) {
		pair<int,pair<int,int> > coordinate = q.front(); q.pop();
		int x = coordinate.second.first;
		int y = coordinate.second.second;
		
		if(x == end_x && y == end_y) {
			cout << coordinate.first << "\n";
			return;
		}
		
		for(int i=0; i<8; i++) {
			int new_x = x + dx[i];
			int new_y = y + dy[i];
			
			if(new_x >= 0 && new_x < l && new_y >= 0 && new_y < l && !visited[new_x][new_y]) {
				visited[new_x][new_y] = true;
				q.push(make_pair(coordinate.first+1 ,make_pair(new_x,new_y)));
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> t;
	while(t--) {	
		cin >> l;
		cin >> start_x >> start_y;
		cin >> end_x >> end_y;
		
		memset(visited, false, sizeof(visited));
		bfs();
	}
}

/* 
�ּ� ������ (�Ÿ�) ���: bfs
queue�� pair<cnt, x, y>�� �����Ͽ� ���° ����������, x, y ��ǥ�� ������ ���� 
*/
