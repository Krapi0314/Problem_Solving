/*
BOJ 1932번: 정수 삼각형

시간 제한: 2초
메모리 제한: 128 MB

문제
        7
      3   8
    8   1   0
  2   7   4   4
4   5   2   6   5
위 그림은 크기가 5인 정수 삼각형의 한 모습이다.
맨 위층 7부터 시작해서 아래에 있는 수 중 하나를 선택하여 아래층으로 내려올 때, 이제까지 선택된 수의 합이 최대가 되는 경로를 구하는 프로그램을 작성하라. 아래층에 있는 수는 현재 층에서 선택된 수의 대각선 왼쪽 또는 대각선 오른쪽에 있는 것 중에서만 선택할 수 있다.
삼각형의 크기는 1 이상 500 이하이다. 삼각형을 이루고 있는 각 수는 모두 정수이며, 범위는 0 이상 9999 이하이다.

입력
첫째 줄에 삼각형의 크기 n(1 ≤ n ≤ 500)이 주어지고, 둘째 줄부터 n+1번째 줄까지 정수 삼각형이 주어진다.

출력
첫째 줄에 합이 최대가 되는 경로에 있는 수의 합을 출력한다. 
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int tri[500][500]; //저장방식은 예제처럼
int cache[500][500];

int path(int y, int x)
{
	//기저: 제일 밑일떄
	if (y == n-1)
	{
		return tri[y][x];
	}

	int& ret = cache[x][y];
	if (ret != -1)
		return ret;
	
	return ret = max(path(y + 1,x), path(y + 1, x + 1)) + tri[y][x];
}

int main(void)
{
	memset(cache, -1, sizeof(cache));
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i+1; j++)
		{
			scanf("%d", &tri[i][j]);
		}
	}

	printf("%d\n", path(0, 0));
}

/*
* 1. 완전 탐색 알고리즘으로 최적해 찾기
*	(x,y) 부터 가장 밑까지의 경로의 최대 = Max(x,y 왼쪽 대각선까지의 경로의 최대,x,y 오른쪽 대각선까지의 경로의 최대) + (x,y)의 값
* 2. 메모이제이션
*/
