/*
BOJ 7569번: 토마토

시간 제한: 1초
메모리 제한: 256 MB

문제
철수의 토마토 농장에서는 토마토를 보관하는 큰 창고를 가지고 있다. 토마토는 아래의 그림과 같이 격자모양 상자의 칸에 하나씩 넣은 다음, 상자들을 수직으로 쌓아 올려서 창고에 보관한다.
창고에 보관되는 토마토들 중에는 잘 익은 것도 있지만, 아직 익지 않은 토마토들도 있을 수 있다. 보관 후 하루가 지나면, 익은 토마토들의 인접한 곳에 있는 익지 않은 토마토들은 익은 토마토의 영향을 받아 익게 된다. 하나의 토마토에 인접한 곳은 위, 아래, 왼쪽, 오른쪽, 앞, 뒤 여섯 방향에 있는 토마토를 의미한다. 대각선 방향에 있는 토마토들에게는 영향을 주지 못하며, 토마토가 혼자 저절로 익는 경우는 없다고 가정한다. 철수는 창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지 그 최소 일수를 알고 싶어 한다.
토마토를 창고에 보관하는 격자모양의 상자들의 크기와 익은 토마토들과 익지 않은 토마토들의 정보가 주어졌을 때, 며칠이 지나면 토마토들이 모두 익는지, 그 최소 일수를 구하는 프로그램을 작성하라. 단, 상자의 일부 칸에는 토마토가 들어있지 않을 수도 있다.

입력
첫 줄에는 상자의 크기를 나타내는 두 정수 M,N과 쌓아올려지는 상자의 수를 나타내는 H가 주어진다. M은 상자의 가로 칸의 수, N은 상자의 세로 칸의 수를 나타낸다. 단, 2 ≤ M ≤ 100, 2 ≤ N ≤ 100, 1 ≤ H ≤ 100 이다. 둘째 줄부터는 가장 밑의 상자부터 가장 위의 상자까지에 저장된 토마토들의 정보가 주어진다. 즉, 둘째 줄부터 N개의 줄에는 하나의 상자에 담긴 토마토의 정보가 주어진다. 각 줄에는 상자 가로줄에 들어있는 토마토들의 상태가 M개의 정수로 주어진다. 정수 1은 익은 토마토, 정수 0 은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다. 이러한 N개의 줄이 H번 반복하여 주어진다.
토마토가 하나 이상 있는 경우만 입력으로 주어진다.

출력
여러분은 토마토가 모두 익을 때까지 최소 며칠이 걸리는지를 계산해서 출력해야 한다. 만약, 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 토마토가 모두 익지는 못하는 상황이면 -1을 출력해야 한다. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int m, n,h;
int arr[100][100][100];
bool discovered[100][100][100] = { false, };

int traverse_cnt;
int next_cnt;
int cnt;

int ans;
int num;

//6방향의 정점들에 대한 offset 값들
int dx[6] = { 1, 0, -1, 0, 0, 0 };
int dy[6] = { 0, 1, 0, -1, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

typedef struct 
{
	int x;
	int y;
	int z;
} coordinate;
coordinate cord;

queue<coordinate> q;

void bfs()
{
	while (!q.empty())
	{
		coordinate here = q.front(); q.pop();

		//인접한, 6방향의 정점들에 대해서만 체크!!! (다중 for문으로 모든 정점 확인할 필요 없음!)
		for (int k = 0; k < 6; k++)
		{
			//좌표평면 형태의 dfs,bfs 문제에서 인접 정점들 확인할때 사용하는 테크닉!
			int newy = here.y + dy[k];
			int newx = here.x + dx[k];
			int newz = here.z + dz[k];
			if (newx >= 0 && newx < m && newy >= 0 && newy < n && newz >= 0 && newz < h && !discovered[newz][newy][newx] && arr[newz][newy][newx] != -1)
			{
				discovered[newz][newy][newx] = true;
				arr[newz][newy][newx] = 1;
				cord.x = newx; cord.y = newy; cord.z = newz;
				q.push(cord);
				next_cnt++;
			}
		}

		cnt++;
		if (cnt == traverse_cnt)
		{
			ans++;
			traverse_cnt = next_cnt;
			cnt = 0;
			next_cnt = 0;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m >> n >> h;
	for (int k = 0; k < h; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> num;

				if (num == 1)
				{
					traverse_cnt++;
					cord.z = k; cord.y = i; cord.x = j;
					q.push(cord); //큐에 토마토들의 위치를 미리 푸쉬해서 bfs시 동시에 bfs가 이루어지도록 한다
					discovered[k][i][j] = true;
				}

				arr[k][i][j] = num;
			}
		}
	}

	bfs(); //bfs시 큐에 미리 토마토(1)들의 위치가 들어가 있으므로, 한꺼번에 bfs 수행이 가능


	//결과값에서 0이 남아있으면 -> 다 익히기 불가
	int flag = 0;
	for (int k = 0; k < h; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[k][i][j] == 0)
				{
					flag = 1;
				}
			}
		}
	}

	if (flag == 1)
	{
		cout << "-1";
	}
	else
	{
		cout << ans - 1;
	}
}

/*
2차원 -> 3차원 확장
	검사해야 하는 방향은 4방향 -> 6방향으로 변하고
	arr, discovered 3차원으로 확장
	구조체로 x,y,z 저장 (pair 사용 불가)

!!! 토마토 (1)이 여러 군데 있을 수 있고, 이들이 한꺼번에 주변 토마토를 익게 만드므로, bfs 실행 시 큐에 미리 첫 상태의 토마토(1)들의 위치가 들어가야 각각의 토마토(1)에서 bfs가 수행됨!!!


bfs, 토마토가 모두 익을 떄까지 최소 날짜 구하기

가로 m, 세로 n 입력
토마토 정보 입력 후 배열에 저장
	if 1 입력
		traverse_cnt++ (한 턴에 큐에서 빼서 시행하는 정점들의 수)

for 배열 순회하면서
	if 값 == 1
		bfs

bfs(좌표)
	discovered[좌표] true
	큐에 푸쉬

	while(!큐)
		start = 큐 pop
		for 배열
			if 6방향에 존재하고, 아직 발견하지 못했으면
				큐에 푸쉬
				travsere_cnt++

	if traverse 0이 아니면
		ans++
 */
