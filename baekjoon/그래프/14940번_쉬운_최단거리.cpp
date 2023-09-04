/*
baekjoon 14940��: ���� �ִܰŸ�

�ð� ����: 1��
�޸� ����: 128 MB

����
������ �־����� ��� ������ ���ؼ� ��ǥ���������� �Ÿ��� ���Ͽ���.
������ ���� ����� ���� ���� ���ο� ���ηθ� ������ �� �ִٰ� ����.

�Է�
������ ũ�� n�� m�� �־�����. n�� ������ ũ��, m�� ������ ũ���.(2 �� n �� 1000, 2 �� m �� 1000)
���� n���� �ٿ� m���� ���ڰ� �־�����. 0�� �� �� ���� ���̰� 1�� �� �� �ִ� ��, 2�� ��ǥ�����̴�. �Է¿��� 2�� �� �Ѱ��̴�.

���
�� �������� ��ǥ���������� �Ÿ��� ����Ѵ�. ���� �� �� ���� ���� ��ġ�� 0�� ����ϰ�, ���� �� �� �ִ� ���� �κ� �߿��� ������ �� ���� ��ġ�� -1�� ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAX 1000

int n,m;
int arr[MAX][MAX];
int cnt[MAX][MAX]; // == visited
pair<int,int > target;
int dx[4] = { 0, 0, 1 , -1};
int dy[4] = { 1, -1, 0, 0};

void bfs() {
	queue<pair<int,int> > q;
	q.push(target);
	
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++) {
			int newx = x + dx[i];
			int newy = y + dy[i];
			
			if(newx >= 0 && newx < n && newy >= 0 && newy < m && arr[newx][newy] == 1 && cnt[newx][newy] == 0) {
				cnt[newx][newy] = cnt[x][y] + 1;
				q.push(make_pair(newx,newy));
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> arr[i][j];
			
			if(arr[i][j] == 2) {
				target = make_pair(i,j);
			}
		}
	}
	
	bfs();
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(arr[i][j] == 1 && cnt[i][j] == 0) {
				cnt[i][j] = -1;
			}
		}
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cout << cnt[i][j] << " ";
		}
		cout << "\n";
	}
}

/*
bfs
��ǥ������ bfs�� ������������ �����ϰ� bfs 
*/
