/*
BOJ 2206번: 벽 부수고 이동하기

시간 제한: 2초 
메모리 제한: 192 MB 

문제
N×M의 행렬로 표현되는 맵이 있다. 맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다. 당신은 (1, 1)에서 (N, M)의 위치까지 이동하려 하는데, 이때 최단 경로로 이동하려 한다. 최단경로는 맵에서 가장 적은 개수의 칸을 지나는 경로를 말하는데, 이때 시작하는 칸과 끝나는 칸도 포함해서 센다.
만약에 이동하는 도중에 한 개의 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 벽을 한 개 까지 부수고 이동하여도 된다.
한 칸에서 이동할 수 있는 칸은 상하좌우로 인접한 칸이다.
맵이 주어졌을 때, 최단 경로를 구해 내는 프로그램을 작성하시오.

입력
첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 1,000)이 주어진다. 다음 N개의 줄에 M개의 숫자로 맵이 주어진다. (1, 1)과 (N, M)은 항상 0이라고 가정하자.

출력
첫째 줄에 최단 거리를 출력한다. 불가능할 때는 -1을 출력한다.
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int n, m;

int arr[1001][1001];
int dist[1001][1001][2]; //discoverd 겸 dist
					//0: 벽 뚫은 후, 1:	벽 아직 안 뚫음

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

		if (y == n && x == m) //도착점에 도달했을 때 = 가장 먼저 도착한 최단거리임
		{
			return dist[y][x][block];
		}

		for (int i = 0; i < 4; i++)
		{
			int newy = here.first.first + dy[i];
			int newx = here.first.second + dx[i];

			if (newy > 0 && newy <= n && newx > 0 && newx <= m)
			{
				if (arr[newy][newx] == 1 && block == 1) //벽이 있고, 아직 벽 뚫지 않았을 때
				{
					dist[newy][newx][block-1] = dist[y][x][block] + 1;
					pq.push(make_pair(make_pair(newy, newx), block - 1));
				}
				else if (arr[newy][newx] == 0 && dist[newy][newx][block] == 0) //이미 벽을 뚫었고, 아직 방문하지 않았으면
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
최단거리, BFS
dist[MAX][MAX][2]: discovered 판별 & 거리 계산
			벽 뚫음/뚫지 않음 의 두 가지의 경우에 대해 bfs 기록
			0		1
int dfs()
	queue push ((1,1),1)
	dist[1,1,1] = 1 (시작점 1부터 시작)

	while ! queue empty
		here = queue front
		y = here.first.first x = here.first.second block = here.second

		if y == n && x == m //도착점에 도착하면 = 가장 먼저 도착한, 최단거리임으로
			return dist[x,y,block]

		for 4
			newy = y + dy[]
			newx = x + dx[]

			if newy, newx 범위 안
				if arr[newy][newx] = 벽 && 아직 벽 뚫지 않았으면
					dist[newy][newx][block-1] = dist[newy][newx][block] + 1 //벽 뚫음 경우의 dist[][]에 기록
					queue push (newy,newx,block)
				else if arr[newy][newx] = 0 (이동가능하고) && 아직 방문하지 않았으면
					dist[newy][newx][block] = dist[newy][newx][block] + 1 //(벽 뚫음 경우) dist[][]에 기록 or (벽 안 뚫은 경우) dist[][]에 기록
					queue push (newy,newx,block)

	return -1 //도착점에 도착하지 못함 (벽 뚫어도 도달 불가, -1 반환)

cin n m
for n	
	for m
		cin s
		for s
			arr[i][j] = s[j-1] - '0' //arr 좌표 받기

cout bfs
*/
