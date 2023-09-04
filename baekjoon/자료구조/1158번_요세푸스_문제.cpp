/*
baekjoon 1158��: �似Ǫ�� ����

�ð� ����: 2��
�޸� ����: 256 MB

����
�似Ǫ�� ������ ������ ����.
1������ N������ N���� ����� ���� �̷�鼭 �ɾ��ְ�, ���� ���� K(�� N)�� �־�����. ���� ������� K��° ����� �����Ѵ�. �� ����� ���ŵǸ� ���� ������ �̷���� ���� ���� �� ������ ����� ������. �� ������ N���� ����� ��� ���ŵ� ������ ��ӵȴ�. ������ ������� ���ŵǴ� ������ (N, K)-�似Ǫ�� �����̶�� �Ѵ�. ���� ��� (7, 3)-�似Ǫ�� ������ <3, 6, 2, 7, 5, 1, 4>�̴�.
N�� K�� �־����� (N, K)-�似Ǫ�� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� K�� �� ĭ�� ���̿� �ΰ� ������� �־�����. (1 �� K �� N �� 5,000)

���
������ ���� �似Ǫ�� ������ ����Ѵ�. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

list<int> lt;
vector<int> v;
int n, k;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		lt.push_back(i);
	}

	list<int>::iterator iter = lt.begin();

	int cnt = 0;
	while (!lt.empty())
	{
		if (iter == lt.end())
			iter = lt.begin();

		if (cnt == k-1)
		{
			cnt = 0;
			v.push_back(*iter);
			iter = lt.erase(iter);
		}
		else
		{
			cnt++;
			iter++;
		}
	}

	if (n == 1)
	{
		cout << "<1>";
	}
	else
	{
		cout << "<" << v[0] << ", ";
		for (int i = 1; i < n - 1; i++)
		{
			cout << v[i] << ", ";
		}
		cout << v[n - 1] << ">";
	}
}

/*
���� ����Ʈ

list

input n,k

for i to n
	list ä���

iter = list liter
while(list.empty)
	iter ++
	
	if cnt == 3
		iter�� ����Ű�� ���� ���Ϳ� ���� �� ����

	if iter�� end���� �̵��ϸ�
		iter = begin
���� ���
*/
