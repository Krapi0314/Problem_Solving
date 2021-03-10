/*
BOJ 2178번: 미로 탐색

시간 제한: 1초
메모리 제한: 192 MB

N×M크기의 배열로 표현되는 미로가 있다.

1	0	1	1	1	1
1	0	1	0	1	0
1	0	1	0	1	1
1	1	1	0	1	1

미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.
위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.

입력
첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.

출력
첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <utility>

//#Include <cstdio>

using namespace std;

int n, m;
int num;
int arr[100][100] = { 0, };
int dis[100][100];

void bfs()
{
	queue<pair<int,int>> q;
	dis[0][0] = 1;
	
	pair<int, int> loc = make_pair(0, 0);
	q.push(loc);
	while (!q.empty())
	{
		pair<int, int> here = q.front(); q.pop();

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if ((((i == here.first - 1) && (j == here.second)) || ((i == here.first + 1) && (j == here.second)) || ((i == here.first) && (j == here.second - 1)) || ((i == here.first) && (j == here.second + 1))) && arr[i][j])
				{
					pair<int, int> there = make_pair(i, j);
					
					if (dis[there.first][there.second] == -1)
					{
						q.push(there);
						dis[there.first][there.second] = dis[here.first][here.second] + 1;
					}
				}
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	memset(dis, -1, sizeof(dis));
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s;

		for (int j = 0; j < s.size(); j++)
		{
			arr[i][j] = s[j] - '0';
		}
	}

	bfs();

	cout << dis[n - 1][m - 1];
}

/*
최단 경로 -> bfs

n,m 입력
	수 입력 -> to_string -> arr에 나누어 저장
	
	0,0부터 n-1,m-1까지의 최단거리 구하기
	=> bfs(0,0)
		distance 구하기
 */
