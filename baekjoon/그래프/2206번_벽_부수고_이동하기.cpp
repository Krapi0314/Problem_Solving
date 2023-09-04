/*
baekjoon 2206��: �� �μ��� �̵��ϱ�

�ð� ����: 2�� 
�޸� ����: 192 MB 

����
N��M�� ��ķ� ǥ���Ǵ� ���� �ִ�. �ʿ��� 0�� �̵��� �� �ִ� ���� ��Ÿ����, 1�� �̵��� �� ���� ���� �ִ� ���� ��Ÿ����. ����� (1, 1)���� (N, M)�� ��ġ���� �̵��Ϸ� �ϴµ�, �̶� �ִ� ��η� �̵��Ϸ� �Ѵ�. �ִܰ�δ� �ʿ��� ���� ���� ������ ĭ�� ������ ��θ� ���ϴµ�, �̶� �����ϴ� ĭ�� ������ ĭ�� �����ؼ� ����.
���࿡ �̵��ϴ� ���߿� �� ���� ���� �μ��� �̵��ϴ� ���� �� �� ��ΰ� ª�����ٸ�, ���� �� �� ���� �μ��� �̵��Ͽ��� �ȴ�.
�� ĭ���� �̵��� �� �ִ� ĭ�� �����¿�� ������ ĭ�̴�.
���� �־����� ��, �ִ� ��θ� ���� ���� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N(1 �� N �� 1,000), M(1 �� M �� 1,000)�� �־�����. ���� N���� �ٿ� M���� ���ڷ� ���� �־�����. (1, 1)�� (N, M)�� �׻� 0�̶�� ��������.

���
ù° �ٿ� �ִ� �Ÿ��� ����Ѵ�. �Ұ����� ���� -1�� ����Ѵ�.
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int n, m;

int arr[1001][1001];
int dist[1001][1001][2]; //discoverd �� dist
					//0: �� ���� ��, 1:	�� ���� �� ����

string s;
queue<pair<pair<int,int>,int>> pq;

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

int ans;

int bfs()
{
	pq.push(make_pair(make_pair(1, 1),1));
	dist[1][1][1] = 1;

	while (!pq.empty())
	{
		pair<pair<int, int>,int> here = pq.front(); pq.pop();
		
		int y = here.first.first;
		int x = here.first.second;
		int block = here.second;

		if (y == n && x == m) //�������� �������� �� = ���� ���� ������ �ִܰŸ���
		{
			return dist[y][x][block];
		}

		for (int i = 0; i < 4; i++)
		{
			int newy = here.first.first + dy[i];
			int newx = here.first.second + dx[i];

			if (newy > 0 && newy <= n && newx > 0 && newx <= m)
			{
				if (arr[newy][newx] == 1 && block == 1) //���� �ְ�, ���� �� ���� �ʾ��� ��
				{
					dist[newy][newx][block-1] = dist[y][x][block] + 1;
					pq.push(make_pair(make_pair(newy, newx), block - 1));
				}
				else if (arr[newy][newx] == 0 && dist[newy][newx][block] == 0) //�̹� ���� �վ���, ���� �湮���� �ʾ�����
				{
					dist[newy][newx][block] = dist[y][x][block] + 1;
					pq.push(make_pair(make_pair(newy, newx), block));
				}
			}
		}
	}

	return -1;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;

		for (int j = 1; j <= m; j++)
		{
			arr[i][j] = s[j-1]-'0';
		}
	}

	cout << bfs();
}

/*
�ִܰŸ�, BFS
dist[MAX][MAX][2]: discovered �Ǻ� & �Ÿ� ���
			�� ����/���� ���� �� �� ������ ��쿡 ���� bfs ���
			0		1
int bfs()
	queue push ((1,1),1)
	dist[1,1,1] = 1 (������ 1���� ����)

	while ! queue empty
		here = queue front
		y = here.first.first x = here.first.second block = here.second

		if y == n && x == m //�������� �����ϸ� = ���� ���� ������, �ִܰŸ�������
			return dist[x,y,block]

		for 4
			newy = y + dy[]
			newx = x + dx[]

			if newy, newx ���� ��
				if arr[newy][newx] = �� && ���� �� ���� �ʾ�����
					dist[newy][newx][block-1] = dist[newy][newx][block] + 1 //�� ���� ����� dist[][]�� ���
					queue push (newy,newx,block)
				else if arr[newy][newx] = 0 (�̵������ϰ�) && ���� �湮���� �ʾ�����
					dist[newy][newx][block] = dist[newy][newx][block] + 1 //(�� ���� ���) dist[][]�� ��� or (�� �� ���� ���) dist[][]�� ���
					queue push (newy,newx,block)

	return -1 //�������� �������� ���� (�� �վ ���� �Ұ�, -1 ��ȯ)

cin n m
for n	
	for m
		cin s
		for s
			arr[i][j] = s[j-1] - '0' //arr ��ǥ �ޱ�

cout bfs
*/
