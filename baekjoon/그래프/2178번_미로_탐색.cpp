/*
baekjoon 2178��: �̷� Ž��

�ð� ����: 1��
�޸� ����: 192 MB

N��Mũ���� �迭�� ǥ���Ǵ� �̷ΰ� �ִ�.

1	0	1	1	1	1
1	0	1	0	1	0
1	0	1	0	1	1
1	1	1	0	1	1

�̷ο��� 1�� �̵��� �� �ִ� ĭ�� ��Ÿ����, 0�� �̵��� �� ���� ĭ�� ��Ÿ����. �̷��� �̷ΰ� �־����� ��, (1, 1)���� ����Ͽ� (N, M)�� ��ġ�� �̵��� �� ������ �ϴ� �ּ��� ĭ ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. �� ĭ���� �ٸ� ĭ���� �̵��� ��, ���� ������ ĭ���θ� �̵��� �� �ִ�.
���� �������� 15ĭ�� ������ (N, M)�� ��ġ�� �̵��� �� �ִ�. ĭ�� �� ������ ���� ��ġ�� ���� ��ġ�� �����Ѵ�.

�Է�
ù° �ٿ� �� ���� N, M(2 �� N, M �� 100)�� �־�����. ���� N���� �ٿ��� M���� ������ �̷ΰ� �־�����. ������ ������ �پ �Է����� �־�����.

���
ù° �ٿ� ������ �ϴ� �ּ��� ĭ ���� ����Ѵ�. �׻� ������ġ�� �̵��� �� �ִ� ��츸 �Է����� �־�����. 
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
�ִ� ��� -> bfs

n,m �Է�
	�� �Է� -> to_string -> arr�� ������ ����
	
	0,0���� n-1,m-1������ �ִܰŸ� ���ϱ�
	=> bfs(0,0)
		distance ���ϱ�
 */
