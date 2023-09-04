/*
baekjoon 1016��: ���� ���� ��

�ð� ����: 2��
�޸� ����: 512 MB

����
� �� X�� 1���� ū �������� ������ �������� ���� ��, ������������� �Ѵ�. �������� ������ �����̴�. min�� max�� �־�����, min�� max�� ������ ���̿� ������������ �� �� �ִ��� ����Ѵ�.

�Է�
ù° �ٿ� �� ���� min�� max�� �־�����.

���
ù° �ٿ� [min,max]������ ������������ �� ������ ����Ѵ�. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

ull Min, Max;
int cnt;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> Min >> Max;

	vector<bool> sieve(Max - Min + 1, true);
	ull i = 2;

	while (i * i <= Max)
	{
		ull fDivNum = Min / (i * i);
		if (Min % (i * i) != 0)
			fDivNum++;

		while (fDivNum * (i * i) <= Max)
		{
			if (sieve[fDivNum * (i * i) - Min])
				sieve[fDivNum * (i * i) - Min] = false;
			fDivNum++;
		}
		i++;
	}

	for (int i = 0; i < sieve.size(); i++)
	{
		if (sieve[i])
			cnt++;
	}

	cout << cnt;
}

/*
�����佺�׳׽��� ü�� ����: �Ҽ��� �Ҽ��� ����� �ɷ����� ���� �ƴ�, �������� ����� �ɷ����� ü

memset sieve true //true: ���� ������

ull i = 2 (i�� ������ ������)
�����佺�׳׽��� ü�� ����:
while  i * i <= max //�������� max �����϶� (�����佺�׳׽��� ü ù���� for��)
	
	//min~max ���� ������ ó������ ���������� ������ ���� �� ã�� -> ���� �����佺�׳׽��� üó�� ó��(1)���� ����ϴ� ���� �ƴ�, ���� ���� �� ���� ����ϱ� ����  
	ull fDivNum = min / (i * i)
	if min % (i * i) != 0 //min���� ���� (���� ���� ��)
		fDivNum++ //��+1 �ؼ� �� ����

	while fDivNum * (i*i) <= max //ó������ ���������� ������ ������ �� ���� ��� ���� false (�����佺�׳׽��� ü �ι��� for��)
		if sieve[fDivNum * (i*i)-min] == true //�������� ���� ���� �ƴϸ� (false�̸� skip)
			sieve[fDivNum * (i*i)-min] = false
		fDivNum++
	
	i++

for sieve
	if sieve true
		cnt++

ans cnt
*/
