/*
baekjoon 5618��: �����

�ð� ����: 1��
�޸� ����: 256 MB

����
�ڿ��� n���� �־�����. �� �ڿ����� ������� ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� n�� �־�����. n�� 2 �Ǵ� 3�̴�. ��° �ٿ��� ������� ���ؾ� �ϴ� �ڿ��� n���� �־�����. ��� �ڿ����� 108 �����̴�.

���
�Է����� �־��� n�� ���� ������� �� �ٿ� �ϳ��� �����ϴ� ������� ����Ѵ�. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int n;
int num;
vector<int> v;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;

	if (n == 2)
	{
		for (int i = 0; i < 2; i++)
		{
			cin >> num;
			v.push_back(num);
		}
		sort(v.begin(), v.end());

		for (int i = 1; i <= v[1]; i++)
		{
			if (v[0] % i == 0 && v[1] % i == 0)
				cout << i << "\n";
		}
	}
	else if (n == 3)
	{
		for (int i = 0; i < 3; i++)
		{
			cin >> num;
			v.push_back(num);
		}
		sort(v.begin(), v.end());

		for (int i = 1; i <= v[2]; i++)
		{
			if (v[0] % i == 0 && v[1] % i == 0 && v[2] % i == 0)
				cout << i << "\n";
		}
	}

}

/*
����� ���ϱ�

cin n (n==2,3)

if 2
for 2
	cin num
	vector pushback num

sort num
for vector ������ ����
	if v[0] % i == 0 && v[1] % i == 0
		cout << i

if 3
for 3
	cin num
	vector pushback num

sort num
for vector ������ ����
	if v[0] % i == 0 && v[1] % i == 0 && v[2] % i == 0
		cout << i
*/
