/*
baekjoon 3184��: ��

�ð� ����: 1��
�޸� ����: 128 MB

����
��Ű�� �޸��翡�� Ư�� ���� ���� �ִ�. �װ� ǫ ��� ���̿� ����� ����� ���翡 ���� ���� �����ߴ�.
������ ��� ���� �̷���� ���簢�� ����̴�. ���� '.' (��)�� �� �ʵ带 �ǹ��ϸ�, ���� '#'�� ��Ÿ����, 'o'�� ��, 'v'�� ���븦 �ǹ��Ѵ�.
�� ĭ���� ����, ���������� �̵��ϸ� ��Ÿ���� ������ �ʰ� �ٸ� ĭ���� �̵��� �� �ִٸ�, �� ĭ�� ���� ���� �ȿ� ���� �ִٰ� �Ѵ�. ���翡�� "Ż��"�� �� �ִ� ĭ�� � �������� ������ �ʴ´ٰ� �����Ѵ�.
������ �츮�� ���� ���뿡�� �ο��� �� �� �ְ� ���� ���� ���� ���� ������ ������ ���ٸ� �̱��, ���븦 �츮���� �ѾƳ���. �׷��� �ʴٸ� ���밡 �� ���� ���� ��� ���� �Դ´�.
�� ó�� ��� ��� ����� ���� �� ������ �����Ѵ�.
��ħ�� �������� �� ��Ƴ��� ��� ������ ���� ����ϴ� ���α׷��� �ۼ��϶�.

�Է�
ù �ٿ��� �� ���� R�� C�� �־�����(3 �� R, C �� 250), �� ���� ������ ��� ���� ���� �ǹ��Ѵ�.
���� R���� ���� C���� ���ڸ� ������. �̵��� ������ ����(��Ÿ��, ��, ������ ��ġ)�� �ǹ��Ѵ�.

���
�ϳ��� �ٿ� ��ħ���� ����ִ� ��� ������ ���� �ǹ��ϴ� �� ������ ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int r,c;

char arr[250][250];
bool visited[250][250];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int oCnt, vCnt;
int oAns, vAns;

void bfs(int y, int x) {
	visited[y][x] = true;
		
	queue<pair<int,int> > q;
	q.push(make_pair(y,x));
	
	while(!q.empty()) {
		int curX = q.front().second;
		int curY = q.front().first;
		q.pop();
		
		if(arr[curY][curX] == 'o') {
			oCnt++;
		}
		else if(arr[curY][curX] == 'v') {
			vCnt++;
		}
		
		for(int i=0; i<4; i++) {
			int newX = curX + dx[i];
			int newY = curY + dy[i];
			
			if(newX >= 0 && newX < c && newY >= 0 && newY < r) {
				if(!visited[newY][newX] && arr[newY][newX] != '#') {
					visited[newY][newX] = true;
					q.push(make_pair(newY,newX));
				}
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> r >> c;
	
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			cin >> arr[i][j];
		}
	}
	
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			if(!visited[i][j] && arr[i][j] != '#') {
				oCnt = 0; vCnt = 0;
				
				bfs(i,j);
								
				if(oCnt > vCnt) {
					oAns += oCnt;
				}
				else {
					vAns += vCnt;
				}
			}
		}
	}
	
	cout << oAns << " " << vAns;
}

/*
bfs
!! visited ó���� �׻� ���ο� newY,newX�� ť�� �ֱ� ���� �ϱ�: ���� ��ǥ�� �� ť�� ���� ���� ���� 
*/
