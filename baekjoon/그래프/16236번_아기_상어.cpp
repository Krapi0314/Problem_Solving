/*
baekjoon 16236��: �Ʊ� ���

�ð� ����: 2 ��
�޸� ����: 512 MB

����
N��N ũ���� ������ ����� M������ �Ʊ� ��� 1������ �ִ�. ������ 1��1 ũ���� ���簢�� ĭ���� �������� �ִ�. �� ĭ���� ����Ⱑ �ִ� 1���� �����Ѵ�.
�Ʊ� ���� ������ ��� ũ�⸦ ������ �ְ�, �� ũ��� �ڿ����̴�. ���� ó���� �Ʊ� ����� ũ��� 2�̰�, �Ʊ� ���� 1�ʿ� �����¿�� ������ �� ĭ�� �̵��Ѵ�.
�Ʊ� ���� �ڽ��� ũ�⺸�� ū ����Ⱑ �ִ� ĭ�� ������ �� ����, ������ ĭ�� ��� ������ �� �ִ�. �Ʊ� ���� �ڽ��� ũ�⺸�� ���� ����⸸ ���� �� �ִ�. ����, ũ�Ⱑ ���� ������ ���� �� ������, �� ����Ⱑ �ִ� ĭ�� ������ �� �ִ�.
�Ʊ� �� ���� �̵����� �����ϴ� ����� �Ʒ��� ����.

�� �̻� ���� �� �ִ� ����Ⱑ ������ ���ٸ� �Ʊ� ���� ���� ���� ������ ��û�Ѵ�.
���� �� �ִ� ����Ⱑ 1�������, �� ����⸦ ������ ����.
���� �� �ִ� ����Ⱑ 1�������� ���ٸ�, �Ÿ��� ���� ����� ����⸦ ������ ����.
	�Ÿ��� �Ʊ� �� �ִ� ĭ���� ����Ⱑ �ִ� ĭ���� �̵��� ��, �������ϴ� ĭ�� ������ �ּڰ��̴�.
	�Ÿ��� ����� ����Ⱑ ���ٸ�, ���� ���� �ִ� �����, �׷��� ����Ⱑ �����������, ���� ���ʿ� �ִ� ����⸦ �Դ´�. 
�Ʊ� ����� �̵��� 1�� �ɸ���, ����⸦ �Դµ� �ɸ��� �ð��� ���ٰ� �����Ѵ�. ��, �Ʊ� �� ���� �� �ִ� ����Ⱑ �ִ� ĭ���� �̵��ߴٸ�, �̵��� ���ÿ� ����⸦ �Դ´�. ����⸦ ������, �� ĭ�� �� ĭ�� �ȴ�.

�Ʊ� ���� �ڽ��� ũ��� ���� ���� ����⸦ ���� �� ���� ũ�Ⱑ 1 �����Ѵ�. ���� ���, ũ�Ⱑ 2�� �Ʊ� ���� ����⸦ 2���� ������ ũ�Ⱑ 3�� �ȴ�.
������ ���°� �־����� ��, �Ʊ� �� �� �� ���� ���� ���� ������ ��û���� �ʰ� ����⸦ ��Ƹ��� �� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ũ�� N(2 �� N �� 20)�� �־�����.
��° �ٺ��� N���� �ٿ� ������ ���°� �־�����. ������ ���´� 0, 1, 2, 3, 4, 5, 6, 9�� �̷���� �ְ�, �Ʒ��� ���� �ǹ̸� ������.

0: �� ĭ
1, 2, 3, 4, 5, 6: ĭ�� �ִ� ������� ũ��
9: �Ʊ� ����� ��ġ
�Ʊ� ���� ������ �� ���� �ִ�.

���
ù° �ٿ� �Ʊ� �� ���� ���� ������ ��û���� �ʰ� ����⸦ ��Ƹ��� �� �ִ� �ð��� ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAX 20

int n;
int arr[20][20];

bool visited[20][20];
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

int shark_x,shark_y, shark_weight, ate;
int ans;

typedef struct _node {
	int x;
	int y;
	int move;
} Node;

struct compare {
	bool operator()(Node a, Node b) {
		if(a.move == b.move) {
			if(a.y == b.y) {
				return a.x > b.x;
			}
			else {
				return a.y > b.y;
			}
		}
		else {
			return a.move > b.move;
		}
	}
};

int bfs(int start_x, int start_y) {
	queue<Node> q;
	priority_queue<Node, vector<Node>, compare> pq;
	visited[start_y][start_x] = true;
	Node node = { start_x, start_y, 0 };
	q.push(node);
	
	while(!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int move = q.front().move;
		q.pop();
		
		for(int i=0; i<4; i++) {
			int new_x = x + dx[i];
			int new_y = y + dy[i];
						
			if(0 <= new_x && new_x < n && 0 <= new_y && new_y < n) {
				// can move
				if(!visited[new_y][new_x] && shark_weight >= arr[new_y][new_x]) {
					Node node = { new_x, new_y, move + 1 };
					visited[new_y][new_x] = true;
					q.push(node);
					
					// if fish and can eat
					if(shark_weight > arr[new_y][new_x] && 1 <= arr[new_y][new_x] && arr[new_y][new_x] <= 6) {
						pq.push(node);
					}
				}
			}
		}
	}
	
	// eat most top left fish
	if(!pq.empty()) {
		ate++;
		if(ate == shark_weight) {
			ate = 0;
			shark_weight++;
		}
						
		shark_x = pq.top().x; shark_y = pq.top().y;
		arr[shark_y][shark_x] = 0;

		return pq.top().move;
	}
	// if no fish no eat
	else {
		return 0;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			int num;
			cin >> num;
			
			if(num == 9) {
				shark_x = j; shark_y = i;
			}
			else {
				arr[i][j] = num;
			}
		}
	}
	
	shark_weight = 2;
	while(true) {
		int cnt = bfs(shark_x, shark_y);
		if(cnt == 0) {
			break;
		}
		else {
			memset(visited, false, sizeof(visited));
			ans += cnt;
		}
	}
	
	cout << ans;
	return 0;
}

/* 
Graph: BFS
!! ���� "�Ÿ��� ����� ����Ⱑ ���ٸ�, ���� ���� �ִ� �����, �׷��� ����Ⱑ �����������, ���� ���ʿ� �ִ� ����⸦ �Դ´�."�� �ǹ�:
	bfs�� �߰��� return ��Ű�� ���� ��ü������ ����, ����⸦ ���������� �ð��� ���� ������, �� �� ���� ��, ���� ������ ������ ó������� ��.
*/ 
