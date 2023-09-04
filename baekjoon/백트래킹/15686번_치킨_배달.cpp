/*
baekjoon 15686��: ġŲ ���

�ð� ����: 1��
�޸� ����: 512 MB

����
ũ�Ⱑ N��N�� ���ð� �ִ�. ���ô� 1��1ũ���� ĭ���� �������� �ִ�. ������ �� ĭ�� �� ĭ, ġŲ��, �� �� �ϳ��̴�. ������ ĭ�� (r, c)�� ���� ���·� ��Ÿ����, r�� c�� �Ǵ� ���������� r��° ĭ, ���ʿ������� c��° ĭ�� �ǹ��Ѵ�. r�� c�� 1���� �����Ѵ�.
�� ���ÿ� ��� ������� ġŲ�� �ſ� �����Ѵ�. ����, ������� "ġŲ �Ÿ�"��� ���� �ַ� ����Ѵ�. ġŲ �Ÿ��� ���� ���� ����� ġŲ�� ������ �Ÿ��̴�. ��, ġŲ �Ÿ��� ���� �������� ��������, ������ ���� ġŲ �Ÿ��� ������ �ִ�. ������ ġŲ �Ÿ��� ��� ���� ġŲ �Ÿ��� ���̴�.
������ �� ĭ (r1, c1)�� (r2, c2) ������ �Ÿ��� |r1-r2| + |c1-c2|�� ���Ѵ�.
���� ���, �Ʒ��� ���� ������ ���� ���ø� ���캸��.

0 2 0 1 0
1 0 1 0 0
0 0 0 0 0
0 0 0 1 1
0 0 0 1 2

0�� �� ĭ, 1�� ��, 2�� ġŲ���̴�.
(2, 1)�� �ִ� ���� (1, 2)�� �ִ� ġŲ������ �Ÿ��� |2-1| + |1-2| = 2, (5, 5)�� �ִ� ġŲ������ �Ÿ��� |2-5| + |1-5| = 7�̴�. ����, (2, 1)�� �ִ� ���� ġŲ �Ÿ��� 2�̴�.
(5, 4)�� �ִ� ���� (1, 2)�� �ִ� ġŲ������ �Ÿ��� |5-1| + |4-2| = 6, (5, 5)�� �ִ� ġŲ������ �Ÿ��� |5-5| + |4-5| = 1�̴�. ����, (5, 4)�� �ִ� ���� ġŲ �Ÿ��� 1�̴�.
�� ���ÿ� �ִ� ġŲ���� ��� ���� �����������̴�. ���������� ���翡���� ������ ������Ű�� ���� �Ϻ� ġŲ���� �����Ű���� �Ѵ�. ���� ���� ���� �� ���ÿ��� ���� ������ ���� �� �� �ִ�  ġŲ���� ������ �ִ� M����� ����� �˾Ƴ�����.
���ÿ� �ִ� ġŲ�� �߿��� �ִ� M���� ����, ������ ġŲ���� ��� ������Ѿ� �Ѵ�. ��� ����, ������ ġŲ �Ÿ��� ���� �۰� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N(2 �� N �� 50)�� M(1 �� M �� 13)�� �־�����.
��° �ٺ��� N���� �ٿ��� ������ ������ �־�����.
������ ������ 0, 1, 2�� �̷���� �ְ�, 0�� �� ĭ, 1�� ��, 2�� ġŲ���� �ǹ��Ѵ�. ���� ������ 2N���� ���� ������, ��� 1���� �����Ѵ�. ġŲ���� ������ M���� ũ�ų� ����, 13���� �۰ų� ����.

���
ù° �ٿ� �����Ű�� ���� ġŲ���� �ִ� M���� ����� ��, ������ ġŲ �Ÿ��� �ּڰ��� ����Ѵ�. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

#define INF 87654321

vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
int visited[13];
int n, m;
int num;
int ans;

int dist, chicken_dist, city_chicken_dist;

void dfs(int idx, int n)
{
	if (n == m)
	{
		city_chicken_dist = 0;
		for (int i = 0; i < house.size(); i++)
		{
			chicken_dist = INF;
			for (int j = 0; j < chicken.size(); j++)
			{
				if (visited[j])
				{
					dist = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);

					chicken_dist = min(chicken_dist, dist);
				}
			}
			city_chicken_dist += chicken_dist;
		}
		ans = min(ans, city_chicken_dist);
	}

	for (int i = 0; i < chicken.size(); i++)
	{
		if (n == 0 || i > idx)
		{
			visited[i] = true;
			dfs(i, ++n);
			visited[i] = false;
			n--;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ans = INF;

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> num;
			if (num == 1)
				house.push_back(make_pair(i, j));
			else if (num == 2)
				chicken.push_back(make_pair(i, j));
		}
	}

	dfs(0, 0);

	cout << ans;
}

/*
������ ġŲ�Ÿ��� �ּڰ�
����Ž��, dfs

chicken[]: ġŲ���� ��ġ pair
house[]: ���� ��ġ pair
visited[]: dfs �湮

dfs(int idx,int n) //ġŲ�� m�� �����ϴ� ��� ��� ����Ž��(dfs), idx: ġŲ�� idx, n: �� ġŲ�� ����

	if n == m //ġŲ�� m�� �� �������
		for house[] //�� ������ ���� �ּ� ġŲ�Ÿ� ���
			
			chicken_dist = INF 
			for chicken[]
				if visited
					dist = abs(house-chicken)
					chicken_dist = min(chicken_dist,dist)

			city_chicken_dist += chicken_dist //���� �ּ� ġŲ�Ÿ� �������� ������ ġŲ�Ÿ��� �߰�
		ans = min(ans,city_chicken_dist) //������ ġŲ�Ÿ� �ּڰ� (����) ����

	//���� ġŲ�� ���� (��ȯ), dfs(���)
	for chicken
		if i > idx
			visited[i] = true
			dfs(i,++n)
			n--
			visited[i] = false
	
cin n m
for n
	for n
		cin num
		if num == 1
			house(i,j)
		else if num == 2
			chikcen(i,j)

dfs(0,0)

cout << ans
*/
