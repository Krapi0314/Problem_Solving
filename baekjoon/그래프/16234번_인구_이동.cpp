/*
baekjoon 16234��: �α� �̵�

�ð� ����: 2��
�޸� ����: 512 MB

����
N��Nũ���� ���� �ְ�, ���� 1��1���� ĭ���� �������� �ִ�. ������ ������ ���� �ϳ��� �����ϸ�, r�� c���� �ִ� ���󿡴� A[r][c]���� ��� �ִ�. ������ ���� ���̿��� ���漱�� �����Ѵ�. ��� ����� 1��1 ũ���̱� ������, ��� ���漱�� ���簢�� �����̴�.
���ú��� �α� �̵��� ���۵Ǵ� ���̴�.
�α� �̵��� ������ ���� ����ǰ�, �� �̻� �Ʒ� ����� ���� �α� �̵��� ���� ������ ���ӵȴ�.

���漱�� �����ϴ� �� ������ �α� ���̰� L�� �̻�, R�� ���϶��, �� ���� �����ϴ� ���漱�� ���� �Ϸ絿�� ����.
���� ���ǿ� ���� ������ϴ� ���漱�� ��� ���ȴٸ�, �α� �̵��� �����Ѵ�.
���漱�� �����־� ������ ĭ���� �̿��� �̵��� �� ������, �� ���� ���� �Ϸ� ������ �����̶�� �Ѵ�.
������ �̷�� �ִ� �� ĭ�� �α����� (������ �α���) / (������ �̷�� �ִ� ĭ�� ����)�� �ȴ�. ���ǻ� �Ҽ����� ������.
������ ��ü�ϰ�, ��� ���漱�� �ݴ´�.
�� ������ �α����� �־����� ��, �α� �̵��� �� �� �߻��ϴ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N, L, R�� �־�����. (1 �� N �� 50, 1 �� L �� R �� 100)
��° �ٺ��� N���� �ٿ� �� ������ �α����� �־�����. r�� c���� �־����� ������ A[r][c]�� ���̴�. (0 �� A[r][c] �� 100)
�α� �̵��� �߻��ϴ� Ƚ���� 2,000�� ���� �۰ų� ���� �Է¸� �־�����.

���
�α� �̵��� �� �� �߻��ϴ��� ù° �ٿ� ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int population[50][50];
bool visited[50][50];
int n,l,r;
int ans;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
bool populationDidMove;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> l >> r;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> population[i][j];
		}
	}
	
	while(true){ // while: �� ���� �α��̵��� �Ͼ���� ����ϴ� ���� ��ȿ����, BFS �ȿ��� �α��̵��� �־����� populatioNDidMove = true�� üũ�ϴ� ������� ����ȭ 
		populationDidMove = false;
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(!visited[i][j]) { // ����, �Լ� �� ���⵵�� ���̱� ���� main �ȿ� bfs ����, �α��̵� ����					
					queue<pair<int,int>> q;
					queue<pair<int,int>> uni;
					int sum = 0;
					int cnt = 0;
					
					q.push(make_pair(i,j));
					uni.push(make_pair(i,j));
					visited[i][j] = true;
					
					while(!q.empty()) {
						pair<int,int> here = q.front(); q.pop();
						
						cnt++;
						sum += population[here.first][here.second];
					
						for(int i=0; i<4; i++) {
							int there_y = here.first + dy[i];
							int there_x = here.second + dx[i];
							int diff = abs(population[here.first][here.second] - population[there_y][there_x]);

							if(there_y >= 0 && there_y < n && there_x >= 0 && there_x < n && diff >= l && diff <= r && !visited[there_y][there_x]) {
								visited[there_y][there_x] = true;
								q.push(make_pair(there_y,there_x));
								uni.push(make_pair(there_y,there_x));
								
								populationDidMove = true;	
							}
						}
					}
					
					int per = sum / cnt;
					while(!uni.empty()) {
						int y = uni.front().first;
						int x = uni.front().second;
						uni.pop();
						
						population[y][x] = per;
					}
				}
			}
		}
		
		if(populationDidMove) {
			memset(visited, false, sizeof(visited));
			ans++;
		}
		else {
			break;
		}
	}

	cout << ans;
}

// bfs
