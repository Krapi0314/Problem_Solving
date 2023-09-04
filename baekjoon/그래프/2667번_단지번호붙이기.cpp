/*
baekjoon 2667��: ������ȣ���̱�

�ð� ����: 1��
�޸� ����: 128 MB

 ����
<�׸� 1>�� ���� ���簢�� ����� ������ �ִ�. 1�� ���� �ִ� ����, 0�� ���� ���� ���� ��Ÿ����. ö���� �� ������ ������ ����� ������ ������ ������ �����ϰ�, ������ ��ȣ�� ���̷� �Ѵ�. ���⼭ ����Ǿ��ٴ� ���� � ���� �¿�, Ȥ�� �Ʒ����� �ٸ� ���� �ִ� ��츦 ���Ѵ�. �밢���� ���� �ִ� ���� ����� ���� �ƴϴ�. <�׸� 2>�� <�׸� 1>�� �������� ��ȣ�� ���� ���̴�. ������ �Է��Ͽ� �������� ����ϰ�, �� ������ ���ϴ� ���� ���� ������������ �����Ͽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù ��° �ٿ��� ������ ũ�� N(���簢���̹Ƿ� ���ο� ������ ũ��� ������ 5��N��25)�� �Էµǰ�, �� ���� N�ٿ��� ���� N���� �ڷ�(0Ȥ�� 1)�� �Էµȴ�.

���
ù ��° �ٿ��� �� �������� ����Ͻÿ�. �׸��� �� ������ ���� ���� ������������ �����Ͽ� �� �ٿ� �ϳ��� ����Ͻÿ�.
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

	//arr�� ��ȸ�ϸ鼭, i,j�� a,b�� �����ϰ� (��,�Ʒ�,����,�����ʿ� �ְ�, �迭�� ���� ������) visited���� �ʾ�����, arr���� 1�̸�
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
������ �Է��Ͽ� ��������, ������ ���ϴ� ���� ���� ������������ �����ؼ� ���
��� ���� (��)�� ���ƾ� �� -> dfs

������ ũ�� n �Է�
���� n*n arr�� �Է� �� ����

visited �迭 ����
arr�� ��ȸ�ϸ鼭
	1�� ������, visited���� �ʾ�����
		dfs()
			cnt++
			visited = 1
	cnt complex ���Ϳ� ����
	
complex ���� ���� (less)
�� ������ = complex ���� size ���
complex ���� ���
 */
