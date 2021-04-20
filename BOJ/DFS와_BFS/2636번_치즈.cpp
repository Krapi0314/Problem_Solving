/*
BOJ 2636번: 치즈

시간 제한: 1초
메모리 제한: 128 MB

문제
아래 <그림 1>과 같이 정사각형 칸들로 이루어진 사각형 모양의 판이 있고, 그 위에 얇은 치즈(회색으로 표시된 부분)가 놓여 있다. 판의 가장자리(<그림 1>에서 네모 칸에 X친 부분)에는 치즈가 놓여 있지 않으며 치즈에는 하나 이상의 구멍이 있을 수 있다.
이 치즈를 공기 중에 놓으면 녹게 되는데 공기와 접촉된 칸은 한 시간이 지나면 녹아 없어진다. 치즈의 구멍 속에는 공기가 없지만 구멍을 둘러싼 치즈가 녹아서 구멍이 열리면 구멍 속으로 공기가 들어가게 된다. <그림 1>의 경우, 치즈의 구멍을 둘러싼 치즈는 녹지 않고 ‘c’로 표시된 부분만 한 시간 후에 녹아 없어져서 <그림 2>와 같이 된다.
다시 한 시간 후에는 <그림 2>에서 ‘c’로 표시된 부분이 녹아 없어져서 <그림 3>과 같이 된다.
<그림 3>은 원래 치즈의 두 시간 후 모양을 나타내고 있으며, 남은 조각들은 한 시간이 더 지나면 모두 녹아 없어진다. 그러므로 처음 치즈가 모두 녹아 없어지는 데는 세 시간이 걸린다. <그림 3>과 같이 치즈가 녹는 과정에서 여러 조각으로 나누어 질 수도 있다.
입력으로 사각형 모양의 판의 크기와 한 조각의 치즈가 판 위에 주어졌을 때, 공기 중에서 치즈가 모두 녹아 없어지는 데 걸리는 시간과 모두 녹기 한 시간 전에 남아있는 치즈조각이 놓여 있는 칸의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에는 사각형 모양 판의 세로와 가로의 길이가 양의 정수로 주어진다. 세로와 가로의 길이는 최대 100이다. 판의 각 가로줄의 모양이 윗 줄부터 차례로 둘째 줄부터 마지막 줄까지 주어진다. 치즈가 없는 칸은 0, 치즈가 있는 칸은 1로 주어지며 각 숫자 사이에는 빈칸이 하나씩 있다.

출력
첫째 줄에는 치즈가 모두 녹아서 없어지는 데 걸리는 시간을 출력하고, 둘째 줄에는 모두 녹기 한 시간 전에 남아있는 치즈조각이 놓여 있는 칸의 개수를 출력한다. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int arr[100][100];
bool discovered[100][100];
bool flag;
int cnt, Time;
int n, m;

queue<pair<int, int>> q;

int dx[4] = { 1, 0 ,-1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool bfs()
{
	flag = true;
	memset(discovered, false, sizeof(discovered));
	q.push(make_pair(0, 0));

	while (!q.empty())
	{
		pair<int, int> here = q.front(); q.pop();
		for (int i = 0; i < 4; i++) 
		{
			int newy = here.first + dy[i];
			int newx = here.second + dx[i];

			if (newy >= 0 && newy < n && newx >= 0 && newx < m && arr[newy][newx] == 0 && !discovered[newy][newx])
			{
				discovered[newy][newx] = true;
				q.push(make_pair(newy, newx));
			}
			else if (newy >= 0 && newy < n && newx >= 0 && newx < m && arr[newy][newx] == 1 && !discovered[newy][newx])
			{
				discovered[newy][newx] = true;
				arr[newy][newx] = 2;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 1)
				flag = false;
		}
	}

	if (flag)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 2)
					cnt++;
			}
		}
		return true;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 2)
					arr[i][j] = 0;
			}
		}
		return false;
	}

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	while (!bfs())
	{
		Time++;
	}

	cout << Time + 1 << "\n" << cnt;
}

/*
공기 중에서 치즈가 모두 녹아 없어지는 데 걸리는 시간과 모두 녹기 한 시간 전에 남아있는 치즈조각이 놓여 있는 칸의 개수를 구하기

판의 왼쪽 상단의 X (0,0)에서 BFS, 공기와 맞닿아있는 치즈 표시 후 녹임, 이하 반복

bool BFS()
	init
		flag = true
		memset discovered false
		
		queue push 0,0
		discoverd 0 0 true

	while ! queue empty
		here = queue front pop
		
		for 4
			newy = here + dy
			newx = here + dx

			if newy newx 범위 내 && arr[newy][newx] = 0 && discovered[newy][newx] = false //공기=0 인 부분 BFS
				discovered newy newx true
				queue push newy,newx
			else if newy newx 범위 내 && arr[newy][newx] = 1 discovered[newy][newx] = false //공기와 맞닿아있는 부분은
				discovered newy newx true
				arr[newy][newx] = 2 //다음에 녹는 치즈로 설정
			
	
	//마지막 직전인지 판별
	for n
		for m
			if arr == 1 //아직 녹이지 못한 치즈가 있으면
				flag = false //모두 녹기 한 시간 전 남은 치즈조각이 아님

	if flag true //모두 녹기 한 시간 전 남은 치즈조각이면
		for n
			for m
				if arr == 2
					cnt++
		return true //조사 끝
	else //아니면
		for n
			for m
				if arr == 2
					arr = 0 //녹이기
		return false //다음번 BFS 계속

cin n m 세로 가로

for n
	for m
		cin arr

while(!bfs())
	time++

cout  time+1 cnt
*/
