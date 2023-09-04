/*
baekjoon 2110��: ������ ��ġ

�ð� ����: 2��
�޸� ����: 128 MB

����
�������� �� N���� ������ ���� �ִ�. ������ ���� ��ǥ�� x1, ..., xN�̰�, �� �������� ���� ��ǥ�� ������ ���� ����.
�����̴� ���� ��𼭳� �������̸� ���� ���ؼ� ���� ������ C���� ��ġ�Ϸ��� �Ѵ�. �ִ��� ���� ������ �������̸� ����Ϸ��� �ϱ� ������, �� ������ �����⸦ �ϳ��� ��ġ�� �� �ְ�, ���� ������ �� ������ ������ �Ÿ��� ������ ũ�� �Ͽ� ��ġ�Ϸ��� �Ѵ�.
C���� �����⸦ N���� ���� ������ ��ġ�ؼ�, ���� ������ �� ������ ������ �Ÿ��� �ִ�� �ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� ���� N (2 �� N �� 200,000)�� �������� ���� C (2 �� C �� N)�� �ϳ� �̻��� �� ĭ�� ���̿� �ΰ� �־�����. ��° �ٺ��� N���� �ٿ��� ���� ��ǥ�� ��Ÿ���� xi (0 �� xi �� 1,000,000,000)�� �� �ٿ� �ϳ��� �־�����.

���
ù° �ٿ� ���� ������ �� ������ ������ �ִ� �Ÿ��� ����Ѵ�. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int n, c;
long long num;
vector<long long> v;
long long hi, mid, lo;

bool possible(int current_idx, int remain)
{
	if (remain == 1) 
		return true;

	for (int i = current_idx+1; i < n; i++)
	{
		if (v[i] - v[current_idx] >= mid)
		{
			return possible(i, remain - 1);
		}
	}

	return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	lo = 0;
	hi = 1000000000;

	while (lo < hi)
	{
		mid = (hi + lo + 1) / 2;

		if (possible(0, c))
		{
			lo = mid;
		}
		else
		{
			hi = mid - 1;
		}
	}

	cout << lo;
}

/*
�̺�Ž��, �Ķ��Ʈ�� ��ġ
���� ����: ������ ������ �ִ� �Ÿ��� d��� �ϸ�, �� �ִ� �Ÿ��� �����⸦ ���� �� �ִ°�?

bool possible(int current_idx,int remain)
	if remain == 1 //�����⸦ �� ���ʿ� ���� ���¿��� ���������Ƿ�, remain�� �ϳ� ���������� ��� �����⸦ ���� ��������
		return true

	for vector
		if v[i] - v[current_idx] >= mid //�����⸦ ��ġ�� ���� ������ �Ÿ��� �ִ� �Ÿ��� ���ų� ũ�� (����)
			return possible(i,remain-1) //���� ������ ������ ����
	
	return false

cin n c
for n
	cin num
	v vector pushback num

sort vector

lo = 0
hi = 10��

while lo < hi
	mid = (lo+hi+1) /2

	if(possible(0,c)) //�ִ� �Ÿ� mid�� ���鿡 �����⸦ ���� �� �ִ��� �˻�, ���� ���� = 0�� �����⸦ ���� �ϳ� ���� ���� �ּ��� greedy
		lo = mid
	else
		hi = mid-1

cout lo
*/
