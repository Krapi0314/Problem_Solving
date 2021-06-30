/*
BOJ 2667번: 단지번호붙이기

시간 제한: 1초
메모리 제한: 128 MB

 문제
<그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 철수는 이 지도를 가지고 연결된 집들의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 대각선상에 집이 있는 경우는 연결된 것이 아니다. <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.

입력
첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.

출력
첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[25][25] = { 0, };
bool visited[25][25]= { false, };
int n, cnt;
vector<int> complex;

void dfs(int a,int b)
{
	visited[a][b] = true;
	cnt++;

	//arr를 순회하면서, i,j가 a,b와 인접하고 (위,아래,왼쪽,오른쪽에 있고, 배열를 넘지 않으면) visited하지 않았으며, arr에서 1이면
		//dfs()

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((((i == a - 1) && (j == b)) || ((i == a + 1) && (j == b)) || ((i == a) && (j == b - 1)) || ((i == a) && (j == b + 1))) && !visited[i][j] && arr[i][j])
			{
				dfs(i, j);
			}
		}
	}
}

int main(void)
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%1d", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 1 && !visited[i][j])
			{
				dfs(i, j);
				complex.push_back(cnt);
				cnt = 0;
			}
		}
	}

	sort(complex.begin(), complex.end());
	printf("%d\n",complex.size());
	for (int i = 0; i < complex.size(); i++)
	{
		printf("%d\n", complex[i]);
	}
}

/*
지도를 입력하여 단지수와, 단지에 속하는 집의 수를 오름차순으로 정렬해서 출력
모든 정점 (집)을 돌아야 함 -> dfs

지도의 크기 n 입력
지도 n*n arr에 입력 후 저장

visited 배열 생성
arr를 순회하면서
	1를 만나고, visited하지 않았으면
		dfs()
			cnt++
			visited = 1
	cnt complex 백터에 저장
	
complex 벡터 정렬 (less)
총 단지수 = complex 백터 size 출력
complex 백터 출력
 */
