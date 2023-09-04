/*
baekjoon 1697��: ���ٲ���

�ð� ����: 2��
�޸� ����: 128 MB

����
�����̴� ������ ���ٲ����� �ϰ� �ִ�. �����̴� ���� �� N(0 �� N �� 100,000)�� �ְ�, ������ �� K(0 �� K �� 100,000)�� �ִ�. �����̴� �Ȱų� �����̵��� �� �� �ִ�. ����, �������� ��ġ�� X�� �� �ȴ´ٸ� 1�� �Ŀ� X-1 �Ǵ� X+1�� �̵��ϰ� �ȴ�. �����̵��� �ϴ� ��쿡�� 1�� �Ŀ� 2*X�� ��ġ�� �̵��ϰ� �ȴ�.
�����̿� ������ ��ġ�� �־����� ��, �����̰� ������ ã�� �� �ִ� ���� ���� �ð��� �� �� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù ��° �ٿ� �����̰� �ִ� ��ġ N�� ������ �ִ� ��ġ K�� �־�����. N�� K�� �����̴�.

���
�����̰� ������ ã�� ���� ���� �ð��� ����Ѵ�.
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

#define Max 100001

int k, n;
int ans;
queue<pair<int,int>> q;
bool visited[100001] = { false, };

void bfs(int n)
{
	q.push(make_pair(n,0));
	visited[n] = true;

	while (!q.empty())
	{
		int v = q.front().first; 
		int d = q.front().second;
		q.pop();

		visited[v] = true;

		if (v == k)
		{
			ans = d;
			break;
		}
		else
		{
			if(v + 1 <= Max && !visited[v+1])
				q.push(make_pair(v + 1,d+1));
			if (v - 1 >= 0 && !visited[v - 1])
				q.push(make_pair(v - 1, d+1));
			if (v * 2 <= Max && !visited[v * 2])
				q.push(make_pair(v * 2, d+1));
		}
	}
}


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	if (k == n)
		cout << "0";
	else if (k < n)
		cout << n - k;
	else
	{
		bfs(n);
		cout << ans;
	}
}

/*
����Ž��(��Ʈ��ŷ,dfs)���δ� �ð��ʰ� (����Ŭ�� �����ǰų�, �ʹ� ���� ������, ����Ž��(bfs)�� n�� k�� �ɋ����� �а� ��� ����� �� Ž��
if k == n
	0��
else if k < n
	n-k��
else (k > n)
	bfs(n)

bfs
	���� n���� �����ؼ� ��� ����� ��(+,-,*)�� bfs, k�� ������ ���� ���� (depth) = ans
	ť�� pair<int,int>�� ����, first�� v, second�� depth
	�湮�� ������ �ٽ� �湮���� ����, �ٽ� �湮�ҽ� ��ġ�� ������ ������ �ð��ʰ�

	q push n
	
	while 1
		v = q pop
		
		if v == k
			ans = depth
			break
		else
			if �湮 x and �迭 ���� ��
				q push v+,v-,v*
*/
