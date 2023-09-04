/*
baekjoon 10026��: ���ϻ���

�ð� ����: 1 ��
�޸� ����: 128 MB

����
���ϻ����� �������� �ʷϻ��� ���̸� ���� ������ ���Ѵ�. ����, ���ϻ����� ����� ���� �׸��� �ƴ� ����� ���� �׸����� �� �ٸ� �� �ִ�.
ũ�Ⱑ N��N�� �׸����� �� ĭ�� R(����), G(�ʷ�), B(�Ķ�) �� �ϳ��� ��ĥ�� �׸��� �ִ�. �׸��� �� ���� �������� �������� �ִµ�, ������ ���� ������ �̷���� �ִ�. ��, ���� ������ �����¿�� ������ �ִ� ��쿡 �� ���ڴ� ���� ������ ���Ѵ�. (������ ���̸� ���� ������ ���ϴ� ��쵵 ���� �����̶� �Ѵ�)
���� ���, �׸��� �Ʒ��� ���� ��쿡

RRRBB
GGBBB
BBBRR
BBRRR
RRRRR

���ϻ����� �ƴ� ����� ���� �� ������ ���� �� 4���̴�. (���� 2, �Ķ� 1, �ʷ� 1) ������, ���ϻ����� ����� ������ 3�� �� �� �ִ�. (����-�ʷ� 2, �Ķ� 1)
�׸��� �Է����� �־����� ��, ���ϻ����� ����� ���� ���� �ƴ� ����� ���� �� ������ ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� �־�����. (1 �� N �� 100)
��° �ٺ��� N�� �ٿ��� �׸��� �־�����.

���
���ϻ����� �ƴ� ����� ���� ���� ������ ������ ���ϻ����� ����� ���� ���� ������ ���� �������� ������ ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAX 100

int n;
char ch;
char arr[MAX][MAX];
int normal, blind;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
bool visited[MAX][MAX];

void bfs(int i, int j, bool blinded) {
	bool component = false;
	queue<pair<int,int>> q;
	visited[i][j] = true;
	q.push(make_pair(i,j));
	
	while(!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++) {
			bool move = false;
			int new_y = y + dy[i];
			int new_x = x + dx[i];
			
			if(0 <= new_y && new_y < n && 0 <= new_x && new_x < n && !visited[new_y][new_x]) {
				if(!blinded) {
					if(arr[new_y][new_x] == arr[y][x]) {
						move = true;
					}
				}
				else {
					if(((arr[y][x] == 'R' || arr[y][x] == 'G') && (arr[new_y][new_x] == 'R' || arr[new_y][new_x] == 'G')) || (arr[y][x] == 'B' && arr[new_y][new_x] == 'B')) {
						move = true;
					}
				}
				
				if(move) {
					component = true;
					visited[new_y][new_x] = true;
					q.push(make_pair(new_y,new_x));
					move = false;
				}
			}
		}
	}
	
	if(!blinded) {
		normal++;
	}
	else {
		blind++;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> arr[i][j];
		}
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(!visited[i][j]) {
				bfs(i, j, false);
			}
		}
	}
	
	memset(visited, false, sizeof(visited));

	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(!visited[i][j]) {
				bfs(i, j, true);
			}
		}
	}
	
	cout << normal << " " << blind;
	return 0;
}

/* 
�׷���: BFS 
*/ 
