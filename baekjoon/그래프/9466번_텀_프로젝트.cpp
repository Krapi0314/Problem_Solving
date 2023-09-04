/*
baekjoon 9466��: �� ������Ʈ

�ð� ����: 3��
�޸� ����: 256 MB

����
�̹� �����б⿡ '���� �ذ�' ���Ǹ� ��û�� �л����� �� ������Ʈ�� �����ؾ� �Ѵ�. ������Ʈ ���� ������ ������ ����. ������ ��� �л����� ������ ���� ������ ���� ���� �� ���� ���� ���� �ִ�. ������Ʈ ���� �����ϱ� ����, ��� �л����� ������Ʈ�� �Բ��ϰ� ���� �л��� �����ؾ� �Ѵ�. (��, �� �� �� ������ �� �ִ�.) ȥ�� �ϰ� �;��ϴ� �л��� �ڱ� �ڽ��� �����ϴ� �͵� �����ϴ�.
�л�����(s1, s2, ..., sr)�̶� �� ��, r=1�̰� s1�� s1�� �����ϴ� ��쳪, s1�� s2�� �����ϰ�, s2�� s3�� �����ϰ�,..., sr-1�� sr�� �����ϰ�, sr�� s1�� �����ϴ� ��쿡�� �� ���� �� �� �ִ�.
���� ���, �� �ݿ� 7���� �л��� �ִٰ� ����. �л����� 1������ 7������ ǥ���� ��, ������ ����� ������ ����.
1	2	3	4	5	6	7
3	1	3	7	3	4	6
���� ����� ���� (3)�� (4, 7, 6)�� ���� �̷� �� �ִ�. 1, 2, 5�� ��� ������ ������ �ʴ´�.
�־��� ������ ����� ���� ��� ������Ʈ ������ ������ �ʴ� �л����� ���� ����ϴ� ���α׷��� �ۼ��϶�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����. �� �׽�Ʈ ���̽��� ù �ٿ��� �л��� ���� ���� n (2 �� n �� 100,000)���� �־�����. �� �׽�Ʈ ���̽��� ��° �ٿ��� ���õ� �л����� ��ȣ�� �־�����. (��� �л����� 1���� n���� ��ȣ�� �ο��ȴ�.)

���
�� �׽�Ʈ ���̽����� �� �ٿ� ����ϰ�, �� �ٿ��� ������Ʈ ���� ������ ���� �л����� ���� ��Ÿ���� �ȴ�. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

#define MAX 100001

bool visited[MAX]; //�� �̻� �ش� ������ �湮�� ���� ����
bool finished[MAX];
int n, cnt;
int match[MAX];
int testcase;

void dfs(int vertex)
{
	visited[vertex] = true;
	int next = match[vertex];

	if (!visited[next]) //���� �湮���� �ʾ�����
	{
		dfs(next); //dfs
	}
	else if (!finished[next]) //�湮������, finished�� ������ �ƴϸ� (���� ����Ŭ ���δ� Ȯ������ ��������) => �湮�� ������ �ٽ� �湮�����Ƿ� ����Ŭ ������
	{
		for (int i = next; i != vertex; i = match[i])
			cnt++;
		cnt++;
	}

	//���� ��� ������ �Ϸ�������,
	finished[vertex] = true; //�湮,����Ŭ���� ��� Ȯ�������Ƿ� �� �̻� �ش� ������ �湮�� ���� �����Ƿ� true üũ
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> testcase;

	for (int t = 0; t < testcase; t++)
	{
		memset(visited, false, sizeof(visited));
		memset(finished, false, sizeof(finished));
		cnt = 0;

		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> match[i];
		}

		for (int i = 1; i <= n; i++)
		{
			if (!visited[i])
				dfs(i);
		}

		cout << n - cnt << "\n";
	}
}

/*
�־��� ������ ����� ���� ��� ������Ʈ ������ ������ �ʴ� �л����� ���� ����ϴ� ���α׷��� �ۼ��϶�.
= ����Ŭ�� �����ϴ� �׷����� �������� ������ ������
DFS

finished �迭: �� �̻� �ش� ��带 �湮�� ���� ���� �� true

void dfs(int vertex)
	visited[vertex] true
	int next = match[vertex]
	
	if not visited[next] //�湮���� �ʾ�����
		dfs(next)
	else if not finished[next] //�湮������ ���� finished���� �ʾ����� = ����Ŭ
		for int i = next; i != vertex; i = match[i] //����Ŭ�� ������ cnt
			cnt++
		cnt++ //�ڱ� �ڽ� ����
	
	finished[vertex] true //�� ������ �ٽ� �湮�� ���� ����

cin testcase
	
for testcase
	init
		memset visited false
		memeset finished false
	cin n
	
	for n
		cin match[i]

	for n
		if not visited[i] //������ (����Ŭ�� �̷�ų�, �̷��� ����) �������� PASS
			dfs(i)
	
	cout n - cnt 
*/	
