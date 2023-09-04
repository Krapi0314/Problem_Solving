/*
baekjoon 9576��: å �����ֱ�

�ð� ����: 2��
�޸� ����: 256 MB

����
�����̴� �� û�Ҹ� �ϸ鼭 �ʿ� ���� ���� ������ ����鿡�� �����ַ��� �Ѵ�. ������ å�� ��ƺ��� �� N���̾���. å�� �ʹ� ���� ������ �����̴� å�� �����ϱ� ���� ���� 1���� N������ ���� ��ȣ�� �ߺ����� �ʰ� �Ű� �ξ���.
���縦 �� ���� å�� ���ϴ� �������б� �кλ��� �� M���̾���. �����̴� �� M���� ��û���� �� ���� a, b (1 �� a �� b �� N)�� ���� ����� �ߴ�. �׷��� �����̴� å ��ȣ�� a �̻� b ������ å �� �����ִ� å �� ���� ��� �� �л����� �ش�. ���� a������ b�������� ��� å�� �̹� �ٸ� �л����� �ְ� ���ٸ� �� �л����Դ� å�� ���� �ʴ´�.
�����̰� å�� �� �� �ִ� �ִ� �л� ���� ���Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� �־�����.
�� ���̽��� ù �ٿ� ���� N(1 �� N �� 1,000)�� M(1 �� M �� 1,000)�� �־�����. ���� �ٺ��� M���� �ٿ��� ���� ���� ai, bi�� �־�����. (1 �� ai �� bi �� N)

���
�� �׽�Ʈ ���̽����� �����̰� å�� �� �� �ִ� �ִ� �л� ���� �� �ٿ� �ϳ��� ����Ѵ�. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

bool book[1001];
vector<pair<int, int>> v;
int n, m;
int a, b;
bool possible;
int ans;

bool compare(pair<int, int>& a, pair<int, int>& b)
{
	return a.second < b.second;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int k = 0; k < T; k++)
	{
		memset(book, false, sizeof(book));
		v.clear();

		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b;
			v.push_back(make_pair(a, b));
		}

		sort(v.begin(), v.end(), compare);

		ans = m;
		for (int i = 0; i < m; i++)
		{
			possible = false;

			for (int j = v[i].first; j <= v[i].second; j++)
			{
				if (!book[j])
				{
					book[j] = true;
					possible = true;
					break;
				}
			}

			if (!possible)
				ans--;
		}

		cout << ans << "\n";
	}
}

/*
���� �κ� ����, Ž�� ���� �Ӽ� ���� => greedy

b�� �������� �������� ���� (a�� �������� ������ ���, �ݷ� �߻�: i��° ���� 2,3�̰�, i+1��° ���� 2,2�̸�, i��°�� 3, i+1������ 2�� �������� �ִ�� ������ �� �������� �ұ��ϰ� i������ 2�� �������� i+1��°�� �ƹ��͵� �������� ���ϴ� ��Ȳ �߻� => b�� �������� �����ϸ� �ش� �ݷ� ������)

bool book[] false

input
sort vector pair, a less, b less

for vector
	bool possible
	for second to first
		if book[i] false
			book[i] true
			possible true
			break
	if !possible
		ans--

cout ans
*/
