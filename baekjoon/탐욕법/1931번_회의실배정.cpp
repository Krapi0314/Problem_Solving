/*
baekjoon 1931��: ȸ�ǽǹ���

�ð� ����:  2��
�޸� ����: 128 MB

����
�� ���� ȸ�ǽ��� �ִµ� �̸� ����ϰ��� �ϴ� N���� ȸ�ǿ� ���Ͽ� ȸ�ǽ� ���ǥ�� ������� �Ѵ�. �� ȸ�� I�� ���� ���۽ð��� ������ �ð��� �־��� �ְ�, �� ȸ�ǰ� ��ġ�� �ʰ� �ϸ鼭 ȸ�ǽ��� ����� �� �ִ� ȸ���� �ִ� ������ ã�ƺ���. ��, ȸ�Ǵ� �ѹ� �����ϸ� �߰��� �ߴܵ� �� ������ �� ȸ�ǰ� ������ �Ͱ� ���ÿ� ���� ȸ�ǰ� ���۵� �� �ִ�. ȸ���� ���۽ð��� ������ �ð��� ���� ���� �ִ�. �� ��쿡�� �������ڸ��� ������ ������ �����ϸ� �ȴ�.

�Է�
ù° �ٿ� ȸ���� �� N(1 �� N �� 100,000)�� �־�����. ��° �ٺ��� N+1 �ٱ��� �� ȸ���� ������ �־����µ� �̰��� ������ ���̿� �ΰ� ȸ���� ���۽ð��� ������ �ð��� �־�����. ���� �ð��� ������ �ð��� 231-1���� �۰ų� ���� �ڿ��� �Ǵ� 0�̴�.

���
ù° �ٿ� �ִ� ����� �� �ִ� ȸ���� �ִ� ������ ����Ѵ�.
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int a, b;
int n;
deque<pair<int, int>> dq;
int cnt;

bool compare(pair<int,int> &a, pair<int,int> &b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}

	return a.second < b.second;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		dq.push_back(make_pair(a, b));
	}

	sort(dq.begin(), dq.end(), compare);

	while (!dq.empty())
	{
		cnt++;
		int endtime = dq.front().second;
		dq.pop_front();

		while (!dq.empty() && dq.front().first < endtime)
			dq.pop_front();
	}

	cout << cnt;
}

/*
�׸��� �˰���
�κ� ������: �ּ� ������ �ð�

compare a b
	if a.seoncd == b.second
		return a.first < b.first //������ �ð��� ������, ���۽ð��� less�� �����ؾ� �ּ� ���� �ð����� ������ �� �־� ���ܸ� ó���� �� ���� (ex: 2, 2 2, 1 2 �� second���θ� �����ϸ� 2 2, 1 2 ������ ���ĵǾ� 1 2�� ī��Ʈ ���� ���ϴ� ���� �߻���)
	return a.second < b.second
cin n
for n
	cin a b
	deque pushback make pair a b

sort deque pair second compare

while deque not empty
	cnt++
	endtime = deque front second
	deque pop front

	while deque front first < endtime //�� ȸ�ǰ� ������ �Ͱ� ���ÿ� ���� ȸ�ǰ� ���۵� �� �����Ƿ�, ��ȣ ����
		deqeue pop front

cout cnt

*/
