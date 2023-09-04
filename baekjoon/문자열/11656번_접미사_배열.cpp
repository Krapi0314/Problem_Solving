/*
baekjoon 11656��: ���̻� �迭

�ð� ����: 1��
�޸� ����: 256 MB

����
���̻� �迭�� ���ڿ� S�� ��� ���̻縦 ���������� ������ ���� �迭�̴�.
baekjoon�� ���̻�� baekjoon, aekjoon, ekjoon, kjoon, joon, oon, on, n ���� �� 8������ �ְ�, �̸� ���������� �����ϸ�, aekjoon, baekjoon, ekjoon, joon, kjoon, n, on, oon�� �ȴ�.
���ڿ� S�� �־����� ��, ��� ���̻縦 ���������� ������ ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���ڿ� S�� �־�����. S�� ���ĺ� �ҹ��ڷθ� �̷���� �ְ�, ���̴� 1,000���� �۰ų� ����.

���
ù° �ٺ��� S�� ���̻縦 ���������� �� �ٿ� �ϳ��� ����Ѵ�. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

string s;
string sub_s;
vector<string> v;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		sub_s = s.substr(i, s.size() - i);
		v.push_back(sub_s);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "\n";
	}
}

/*
���ڿ� s�� ���̻�� �и��Ͽ� ������ ����

s �Է�
for s
	substring s = sub.str()
	�κ� ���ڿ� ���ڿ� vector�� ����

vector sort
���
 */
