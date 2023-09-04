/*
baekjoon 14500��: ��Ʈ�ι̳�

�ð� ����: 2 ��
�޸� ����: 512 MB 

����
�������̳�� ũ�Ⱑ 1��1�� ���簢���� ���� �� �̾ ���� �����̸�, ������ ���� ������ �����ؾ� �Ѵ�.
- ���簢���� ���� ��ġ�� �� �ȴ�.
- ������ ��� ����Ǿ� �־�� �Ѵ�.
- ���簢���� ������ ����Ǿ� �־�� �Ѵ�. ��, �������� �������� �´�� ������ �� �ȴ�.
���簢�� 4���� �̾� ���� �������̳�� ��Ʈ�ι̳��� �ϸ�, ������ ���� 5������ �ִ�.
(���簢�� 4���� �̾� �ٿ��� ������ ��� ����) 

�Ƹ��̴� ũ�Ⱑ N��M�� ���� ���� ��Ʈ�ι̳� �ϳ��� �������� �Ѵ�. ���̴� 1��1 ũ���� ĭ���� �������� ������, ������ ĭ���� ������ �ϳ� ���� �ִ�.
��Ʈ�ι̳� �ϳ��� ������ ���Ƽ� ��Ʈ�ι̳밡 ���� ĭ�� ���� �ִ� ������ ���� �ִ�� �ϴ� ���α׷��� �ۼ��Ͻÿ�.
��Ʈ�ι̳�� �ݵ�� �� ���簢���� ��Ȯ�� �ϳ��� ĭ�� �����ϵ��� ���ƾ� �ϸ�, ȸ���̳� ��Ī�� ���ѵ� �ȴ�.

�Է�
ù° �ٿ� ������ ���� ũ�� N�� ���� ũ�� M�� �־�����. (4 �� N, M �� 500)
��° �ٺ��� N���� �ٿ� ���̿� ���� �ִ� ���� �־�����. i��° ���� j��° ���� ���������� i��° ĭ, ���ʿ������� j��° ĭ�� ���� �ִ� ���̴�. �Է����� �־����� ���� 1,000�� ���� �ʴ� �ڿ����̴�.

���
ù° �ٿ� ��Ʈ�ι̳밡 ���� ĭ�� ���� ������ ���� �ִ��� ����Ѵ�.
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAX 500

int n, m;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int Max;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void dfs(int y, int x, int cnt, int acc) {
	visited[y][x] = true;
	
	if(cnt == 3) {
		Max = max(Max, acc);
		return;
	}
	
	for(int i=0; i<4; i++) {
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		
		if(0 <= new_y && new_y < n && 0 <= new_x && new_x < m && !visited[new_y][new_x]) {
			dfs(new_y, new_x, cnt+1, acc+arr[new_y][new_x]);
			visited[new_y][new_x] = false;
		}
	}
	
	visited[y][x] = false;
}

void middleFinger(int y, int x) {
	// �� 
	if(y >= 1 && x >= 1 && x < m-1) {
		Max = max(Max, arr[y][x] + arr[y][x-1] + arr[y][x+1] + arr[y-1][x]);
	}
	// �� 
	if(y >= 1 && y < n-1 && x < m-1) {
		Max = max(Max, arr[y][x] + arr[y-1][x] + arr[y+1][x] + arr[y][x+1]);
	}
	// �� 
	if(y < n-1 && x >= 1 && x < m-1) {
		Max = max(Max, arr[y][x] + arr[y][x-1] + arr[y][x+1] + arr[y+1][x]);
	}
	// �� 
	if(y >= 1 && y < n-1 && x >= 1) {
		Max = max(Max, arr[y][x] + arr[y-1][x] + arr[y+1][x] + arr[y][x-1]);
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
		}
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			dfs(i,j, 0, arr[i][j]);
			middleFinger(i,j);
		}
	}
	
	cout << Max;
	return 0;
}

/* 
�׷���: DFS + ����Ž�� 
!! DFS�� Ž�� �Ұ����� (��,��,��,��) ��Ʈ�ι̳�� ���� �����Ͽ� ����Ž���ϱ� 
*/ 
