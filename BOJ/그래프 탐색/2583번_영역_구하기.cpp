/*
BOJ 2583번: 영역 구하기

문제
눈금의 간격이 1인 M×N(M,N≤100)크기의 모눈종이가 있다. 이 모눈종이 위에 눈금에 맞추어 K개의 직사각형을 그릴 때, 이들 K개의 직사각형의 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어진다.
예를 들어 M=5, N=7 인 모눈종이 위에 <그림 1>과 같이 직사각형 3개를 그렸다면, 그 나머지 영역은 <그림 2>와 같이 3개의 분리된 영역으로 나누어지게 된다.
<그림 2>와 같이 분리된 세 영역의 넓이는 각각 1, 7, 13이 된다.
M, N과 K 그리고 K개의 직사각형의 좌표가 주어질 때, K개의 직사각형 내부를 제외한 나머지 부분이 몇 개의 분리된 영역으로 나누어지는지, 그리고 분리된 각 영역의 넓이가 얼마인지를 구하여 이를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 M과 N, 그리고 K가 빈칸을 사이에 두고 차례로 주어진다. M, N, K는 모두 100 이하의 자연수이다. 둘째 줄부터 K개의 줄에는 한 줄에 하나씩 직사각형의 왼쪽 아래 꼭짓점의 x, y좌표값과 오른쪽 위 꼭짓점의 x, y좌표값이 빈칸을 사이에 두고 차례로 주어진다. 모눈종이의 왼쪽 아래 꼭짓점의 좌표는 (0,0)이고, 오른쪽 위 꼭짓점의 좌표는(N,M)이다. 입력되는 K개의 직사각형들이 모눈종이 전체를 채우는 경우는 없다.

출력
첫째 줄에 분리되어 나누어지는 영역의 개수를 출력한다. 둘째 줄에는 각 영역의 넓이를 오름차순으로 정렬하여 빈칸을 사이에 두고 출력한다. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int arr[100][100];
int m, n, k;
int x_1, y_1, x_2, y_2;

bool visited[100][100];
int area;
int cnt;

vector<int> v;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

void dfs(int y, int x)
{
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int there_y = y + dy[i];
		int there_x = x + dx[i];

		if (there_y >= 0 && there_y < m && there_x >= 0 && there_x < n && !visited[there_y][there_x] && arr[there_y][there_x] == 0)
		{
			area++;
			dfs(there_y, there_x);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> m >> n >> k;

	for (int t = 0; t < k; t++)
	{
		cin >> x_1 >> y_1 >> x_2 >> y_2;

		for (int i = y_1; i < y_2; i++)
		{
			for (int j = x_1; j < x_2; j++)
			{
				arr[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j] && arr[i][j] == 0)
			{
				area = 0;
				dfs(i, j);
				cnt++;
				v.push_back(area+1);
			}
		}
	}

	sort(v.begin(), v.end());

	cout << cnt << "\n";
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}

/*
DFS, 컴포넌트 세기

void dfs(int y,int x)
	visited[y][x] = true
	
	for 4
		there_y = y + dy
		there_x = x + dx

		if(there_y there_x 범위 안 && not visited && arr 값 == 0) 
			area++
			dfs(there_y,there_x)

cin m n k

//arr 생성
for k
	cin x1 y1 x2 y2
	
	for y1 to y2
		for x1 to x2
			arr[i][j] = 1 (arr 값이 1이면 벽, 0이면 공백)


//arr dfs
for m
	for n
		if not visited && arr 값 == 0
			area = 0
			dfs(i,j)
			cnt++;
			vector pushback area

vector sort

cout cnt
for vector
	cout vector
*/
