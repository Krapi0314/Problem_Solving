/*
BOJ 2580번: 스도쿠

시간 제한: 1초
메모리 제한: 256 MB

스도쿠는 18세기 스위스 수학자가 만든 '라틴 사각형'이랑 퍼즐에서 유래한 것으로 현재 많은 인기를 누리고 있다. 이 게임은 아래 그림과 같이 가로, 세로 각각 9개씩 총 81개의 작은 칸으로 이루어진 정사각형 판 위에서 이뤄지는데, 게임 시작 전 일부 칸에는 1부터 9까지의 숫자 중 하나가 쓰여 있다.
나머지 빈 칸을 채우는 방식은 다음과 같다.

각각의 가로줄과 세로줄에는 1부터 9까지의 숫자가 한 번씩만 나타나야 한다.
굵은 선으로 구분되어 있는 3x3 정사각형 안에도 1부터 9까지의 숫자가 한 번씩만 나타나야 한다.
위의 예의 경우, 첫째 줄에는 1을 제외한 나머지 2부터 9까지의 숫자들이 이미 나타나 있으므로 첫째 줄 빈칸에는 1이 들어가야 한다.
또한 위쪽 가운데 위치한 3x3 정사각형의 경우에는 3을 제외한 나머지 숫자들이 이미 쓰여있으므로 가운데 빈 칸에는 3이 들어가야 한다.
이와 같이 빈 칸을 차례로 채워 가면 다음과 같은 최종 결과를 얻을 수 있다.
게임 시작 전 스도쿠 판에 쓰여 있는 숫자들의 정보가 주어질 때 모든 빈 칸이 채워진 최종 모습을 출력하는 프로그램을 작성하시오.

입력
아홉 줄에 걸쳐 한 줄에 9개씩 게임 시작 전 스도쿠판 각 줄에 쓰여 있는 숫자가 한 칸씩 띄워서 차례로 주어진다. 스도쿠 판의 빈 칸의 경우에는 0이 주어진다. 스도쿠 판을 규칙대로 채울 수 없는 경우의 입력은 주어지지 않는다.

출력
모든 빈 칸이 채워진 스도쿠 판의 최종 모습을 아홉 줄에 걸쳐 한 줄에 9개씩 한 칸씩 띄워서 출력한다.
스도쿠 판을 채우는 방법이 여럿인 경우는 그 중 하나만을 출력한다. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

#define MAX 9

int arr[MAX + 1][MAX + 1];

bool promising(int n, int y, int x)
{
	for (int i = 1; i <= MAX; i++)
	{
		if (arr[i][x] == n)
			return false;
	}
	
	for (int j = 1; j <= MAX; j++)
	{
		if (arr[y][j] == n)
			return false;
	}

	int rect_f_y = 3 * ((y-1) / 3) + 1;
	int rect_f_x = 3 * ((x-1) / 3) + 1;
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (arr[rect_f_y + i][rect_f_x + j] == n)
				return false;
		}
	}
	
	return true;
}

void dfs(int y,int x)
{
	for (int i = y; i <= MAX; i++)
	{
		for (int j = 1; j <= MAX; j++)
		{
			if (arr[i][j] == 0)
			{
				for (int k = 1; k <= MAX; k++)
				{
					if (promising(k, i, j))
					{
						arr[i][j] = k;
						dfs(i,j);
						arr[i][j] = 0;
					}
				}
				return;
			}

			if (i == MAX && j == MAX)
			{
				for (int a = 1; a <= MAX; a++)
				{
					for (int b = 1; b <= MAX; b++)
					{
						if (arr[a][b] == 0)
							return;
					}
				}

				for (int a = 1; a <= MAX; a++)
				{
					for (int b = 1; b <= MAX; b++)
					{
						cout << arr[a][b] << " ";
					}
					cout << "\n";
				}
				exit(0);
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= MAX; i++)
	{
		for (int j = 1; j <= MAX; j++)
		{
			cin >> arr[i][j];
		}
	}

	dfs(1,1);
}

/*
완전탐색, 백트래킹

vector number_filled: 왼쪽 위에서부터 채운 숫자 저장

bool promising(int n,int x,int y) //arr[y][x] 위치에 n을 넣어도 스도쿠가 성립하는지
	//세로 확인
	for 1 to 9
		if arr[i][x] == n
			return false
	//가로 확인
	for 1 to 9
		if arr[y][i] == n
			return false
	//3x3 정사각형 확인
		//해당 위치의 정사각형의 첫 인덱스 구하기
	int rect_first_idx_y = 3 * ((y-1)/3) + 1
	int rect_first_idx_x = 3 * ((x-1)/3) + 1

		//정사각형 검사
	for 3
		for 3
			if arr[rect_first_y_idx + i][..] == n
				return false

	//다 통과하면
	return true

void dfs(int x,int y) //스도쿠 채우기, x/y: 지금까지 조사한 곳

	for i = y to 9
		for j = 1 to 9
			if arr[i][j] == 0
				for i = 1 to 9
					if(promising(k,i,j))
						arr[i][j] = k
						dfs(i,j)
						arr[i][j] = 0

				return //해당되는 수가 없음 -> 그 전이 잘못됨 -> return
			if i,y == MAX
					for 1 to 9
						for 1 to 9
							if arr[i][j] == 0
								return

					//다 채웠으면
					for 1 to 9
						for 1 to 9
							cout arr[i][j]

					exit(0) //프로그램 종료

for 1 to 9
	for 1 to 9
		cin n
		if n == 0
			cnt++
		arr[i][j] = n

dfs(1,1)
*/
