/*
baekjoon 2583��: ���� ���ϱ�

����
������ ������ 1�� M��N(M,N��100)ũ���� �����̰� �ִ�. �� ������ ���� ���ݿ� ���߾� K���� ���簢���� �׸� ��, �̵� K���� ���簢���� ���θ� ������ ������ �κ��� �� ���� �и��� �������� ����������.
���� ��� M=5, N=7 �� ������ ���� <�׸� 1>�� ���� ���簢�� 3���� �׷ȴٸ�, �� ������ ������ <�׸� 2>�� ���� 3���� �и��� �������� ���������� �ȴ�.
<�׸� 2>�� ���� �и��� �� ������ ���̴� ���� 1, 7, 13�� �ȴ�.
M, N�� K �׸��� K���� ���簢���� ��ǥ�� �־��� ��, K���� ���簢�� ���θ� ������ ������ �κ��� �� ���� �и��� �������� ������������, �׸��� �и��� �� ������ ���̰� �������� ���Ͽ� �̸� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� M�� N, �׸��� K�� ��ĭ�� ���̿� �ΰ� ���ʷ� �־�����. M, N, K�� ��� 100 ������ �ڿ����̴�. ��° �ٺ��� K���� �ٿ��� �� �ٿ� �ϳ��� ���簢���� ���� �Ʒ� �������� x, y��ǥ���� ������ �� �������� x, y��ǥ���� ��ĭ�� ���̿� �ΰ� ���ʷ� �־�����. �������� ���� �Ʒ� �������� ��ǥ�� (0,0)�̰�, ������ �� �������� ��ǥ��(N,M)�̴�. �ԷµǴ� K���� ���簢������ ������ ��ü�� ä��� ���� ����.

���
ù° �ٿ� �и��Ǿ� ���������� ������ ������ ����Ѵ�. ��° �ٿ��� �� ������ ���̸� ������������ �����Ͽ� ��ĭ�� ���̿� �ΰ� ����Ѵ�. 
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
DFS, ������Ʈ ����

void dfs(int y,int x)
	visited[y][x] = true
	
	for 4
		there_y = y + dy
		there_x = x + dx

		if(there_y there_x ���� �� && not visited && arr �� == 0) 
			area++
			dfs(there_y,there_x)

cin m n k

//arr ����
for k
	cin x1 y1 x2 y2
	
	for y1 to y2
		for x1 to x2
			arr[i][j] = 1 (arr ���� 1�̸� ��, 0�̸� ����)


//arr dfs
for m
	for n
		if not visited && arr �� == 0
			area = 0
			dfs(i,j)
			cnt++;
			vector pushback area

vector sort

cout cnt
for vector
	cout vector
*/
