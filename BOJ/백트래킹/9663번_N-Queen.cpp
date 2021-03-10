/*
BOJ 9663번: N-Queen

시간 제한: 10초
메모리 제한: 128 MB

문제
N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.
N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (1 ≤ N < 15)

출력
첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int n, cnt;
int col[15]; //퀸의 위치(열에 대해), 퀸은 한 열에 하나 밖에 존재하지 못하므로 퀸의 좌표를 다음과 같이 저장 가능

bool promising(int i) //bounding function (한정 함수)
{
	for (int j = 0; j < i; j++) //이전 퀸들의 위치에 대해
	{
		if (col[j] == col[i] || abs(col[i] - col[j]) == (i - j)) //새로운 퀸의 위치가 같은 행이거나 대각선상에 있으면
			return false; //퀸 놓기 불가
	}
	return true; //퀸 놓기 가능
}

void queens(int i)
{
	if (i == n) //그리고 마지막 퀸까지 놓으면 (기저 사례)
	{
		cnt++; //하나의 경우의 수 완성됨
	}
	else //이외에는
	{
		for (int j = 0; j < n; j++) //한 열에 대해
		{
			col[i] = j; //현재 열에 행의 위치 저장 (퀸 일단 놓기)
			if(promising(i)) //유망성 검사
				queens(i + 1); //재귀함수 호출
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	queens(0);

	cout << cnt;
}

/*
백트래킹

퀸을 하나 놓고,

queens()
기저: 퀸을 다 놓았으면
	cnt++;
퀸이 놓일 수 있으면 (promising())
	queens()로 다음 퀸을 놓는다

! 퀸은 한 열에 하나 밖에 놓지 못하므로, 열 단위로 계산
*/
