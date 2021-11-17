/*
BOJ 11650번: 좌표 정렬하기

시간 제한: 1초
메모리 제한: 256 MB

문제
2차원 평면 위의 점 N개가 주어진다. 좌표를 x좌표가 증가하는 순으로, x좌표가 같으면 y좌표가 증가하는 순서로 정렬한 다음 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 점의 개수 N (1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N개의 줄에는 i번점의 위치 xi와 yi가 주어진다. (-100,000 ≤ xi, yi ≤ 100,000) 좌표는 항상 정수이고, 위치가 같은 두 점은 없다.

출력
첫째 줄부터 N개의 줄에 점을 정렬한 결과를 출력한다. 
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef struct _coordinate
{
	int x;
	int y;
} coordinate;

int N;
vector<coordinate> v;

bool pred(coordinate& a, coordinate& b)
{
	if (a.x != b.x)
	{
		return a.x < b.x;
	}
	else
	{
		return a.y < b.y;
	}

}

int main(void)
{
	scanf("%d", &N);

	coordinate input;
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &input.x, &input.y);
		v.push_back(input);
	}

	sort(v.begin(), v.end(), pred);

	for (int i = 0; i < N; i++)
	{
		printf("%d %d\n", v[i].x, v[i].y);
	}
}

/*
정렬, sort pred: a_x < b_x / a_x == b_x 이면 a_y < b_y 으로
1. 좌표를 구조체로 설정
2. 입력 받아서 vector에 저장 (int형으로)
3. 조건자를 설정해서 sort
4. 출력
*/
