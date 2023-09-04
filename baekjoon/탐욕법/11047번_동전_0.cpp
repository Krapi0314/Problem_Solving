/*
baekjoon 11047��: ���� 0

�ð� ����: 1��
�޸� ����: 256 MB

����
�ر԰� ������ �ִ� ������ �� N�����̰�, ������ ������ �ſ� ���� ������ �ִ�.
������ ������ ����ؼ� �� ��ġ�� ���� K�� ������� �Ѵ�. �̶� �ʿ��� ���� ������ �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� K�� �־�����. (1 �� N �� 10, 1 �� K �� 100,000,000)
��° �ٺ��� N���� �ٿ� ������ ��ġ Ai�� ������������ �־�����. (1 �� Ai �� 1,000,000, A1 = 1, i �� 2�� ��쿡 Ai�� Ai-1�� ���)

���
ù° �ٿ� K���� ����µ� �ʿ��� ���� ������ �ּڰ��� ����Ѵ�. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>


//#include <cstdio>

using namespace std;

vector<int> coin;
int n, k, value;
int cnt;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> value;
		coin.push_back(value);
	}
	
	for(int i=n-1; i >= 0; i--)
	{
		if (k == 0)
			break;
		else if (coin[i] > k)
			continue;
		else
		{
			while (k >= coin[i])
			{
				k -= coin[i];
				cnt++;
			}
		}
	}
	
	cout << cnt;
}

/*
Greedy
K ��
������������ �־��� ������ ��ġ�� ���Ϳ� ����
������ ������ ���Һ���
	if k == 0 (���� ���)
		cout << cnt
	else if ������ ���� > k
		�������� �Ѿ�� (�� �� ���ҷ�)
	else
		while ������ ���� > k
			k - ������ ����
			cnt++
*/
