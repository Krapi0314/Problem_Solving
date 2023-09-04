/*
baekjoon 10867��: �ߺ� ���� �����ϱ�

�ð� ����: 1��
�޸� ����: 256 MB

����
N���� ������ �־�����. �̶�, N���� ������ ������������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�. ���� ������ �� ���� ����Ѵ�.

�Է�
ù° �ٿ� ���� ���� N (1 �� N �� 100,000)�� �־�����. ��°���� ���ڰ� �־�����. �� ���� ������ 1,000���� �۰ų� ���� �����̴�.

���
ù° �ٿ� ���� ������������ ������ ����� ����Ѵ�. �̶�, ���� ���� �� ���� ����Ѵ�.
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int n;
int num;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
}

/*
�ߺ� ����, ����
*/
