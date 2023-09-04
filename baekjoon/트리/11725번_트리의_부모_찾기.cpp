/*
baekjoon 11725��: Ʈ���� �θ� ã��

�ð� ����: 1��
�޸� ����: 256 MB

����
��Ʈ ���� Ʈ���� �־�����. �̶�, Ʈ���� ��Ʈ�� 1�̶�� ������ ��, �� ����� �θ� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ����� ���� N (2 �� N �� 100,000)�� �־�����. ��° �ٺ��� N-1���� �ٿ� Ʈ�� �󿡼� ����� �� ������ �־�����.

���
ù° �ٺ��� N-1���� �ٿ� �� ����� �θ� ��� ��ȣ�� 2�� ������ ������� ����Ѵ�. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int n;

int parent[100001];
bool visited[100001] = { false, } ;
vector<int> tree[100001];
int a, b;

void dfs(int v)
{
	visited[v] = true;

	for (int i = 0; i < tree[v].size(); i++)
	{
		int nextNode = tree[v][i];
		if (!visited[nextNode])
		{
			parent[nextNode] = v;
			dfs(nextNode);
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;

		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	dfs(1);

	for (int i = 2; i <= n; i++)
	{
		cout << parent[i] << "\n";
	}
}

/*
�Ϲ� Ʈ�� -> �׷��� ��������
!!�־����� ���� �ֵ��� �θ�-�ڽ� ���踦 �𸣹Ƿ�, Ʈ���� ���� ���� ����, ����� �׷����� ����.
!!������ �׷������� ���� ���� 1�� dfs �ϸ� 1�� ��Ʈ�� �ϴ� Ʈ���� �θ�-�ڽ� ���踦 �� �� ����

Ʈ��(����� �׷���)�� ���� ����Ʈ�� ������ ��, dfs�� ��� ������ ������. �̶�, dfs�� ���� �������� �Ѿ�� ���� parent[�������] = ������� �� �������� �θ� ��� �ľ�

parents[]

dfs
	if ����Ǿ� �ְ� �湮���� �ʾ�����
		parent[���� ���] = ���� ���
		dfs(���� ����)
		
cin n (����� ����)

for n-1
	cin >> a >> b
	adj[a][b] = 1
	adj[b][a] = 1

dfs(1)

cout parents
*/
