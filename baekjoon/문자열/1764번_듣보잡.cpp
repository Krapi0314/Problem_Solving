/*
baekjoon 1764��: �躸��

�ð� ����: 2��
�޸� ����: 256 MB

����
�������� �赵 ���� ����� ��ܰ�, ���� ���� ����� ����� �־��� ��, �赵 ���� ���� ����� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �赵 ���� ����� �� N, ���� ���� ����� �� M�� �־�����. �̾ ��° �ٺ��� N���� �ٿ� ���� �赵 ���� ����� �̸���, N+2° �ٺ��� ���� ���� ����� �̸��� ������� �־�����. �̸��� ���� ���� ���ĺ� �ҹ��ڷθ� �̷������, �� ���̴� 20 �����̴�. N, M�� 500,000 ������ �ڿ����̴�.
�赵 ���� ����� ��ܿ��� �ߺ��Ǵ� �̸��� ������, ���� ���� ����� ��ܵ� ���������̴�.

���
�躸���� ���� �� ����� ���������� ����Ѵ�. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

set<string> s1, s2;
string s;
int n, m;
vector<string> v;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		s1.insert(s);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		s2.insert(s);
	}

	set<string>::iterator iter;
	set<string>::iterator f_iter;

	for (iter = s1.begin(); iter != s1.end(); iter++)
	{
		f_iter = s2.find(*iter);
		if (f_iter != s2.end())
			v.push_back(*f_iter);
	}

	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "\n";
	}
}

/*
�� ������ ������ ã�� -> Ž��
n,m ����: 500,000 => �Ϲ����� 2�� for���� �̿��� Ž�� �ð����⵵: 2õ��ȸ �̻� => �̺� Ž������ �ð� �����ؾ� ��

=> set �����̳ʷ� �� ������ ����(�ڵ� ����)�ϰ�, ��(���� Ʈ���� Ž�� = �̺� Ž��, �� set�� ���ҵ��� ��, �ð����⵵: O(nlogn)-> 3�鸸ȸ)�ؼ� �ð� ����

cin n m
for n
	cin s (string)
	s1.insert(s)
for m
	cin s (string)
	s2.insert(s)

for s1 iter
	f_iter = s2.find(*iter)
	if(f_iter != s2.end())
		v.pushback(f_iter)

cout v.size
for v
	cout v[i]

*/
