/*
baekjoon 1037��: ���

�ð� ����: 2��
�޸� ����: 512 MB
 
����
��� A�� N�� ��¥ ����� �Ƿ���, N�� A�� ����̰�, A�� 1�� N�� �ƴϾ�� �Ѵ�. � �� N�� ��¥ ����� ��� �־��� ��, N�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� ��¥ ����� ������ �־�����. �� ������ 50���� �۰ų� ���� �ڿ����̴�. ��° �ٿ��� N�� ��¥ ����� �־�����. 1,000,000���� �۰ų� ����, 2���� ũ�ų� ���� �ڿ����̰�, �ߺ����� �ʴ´�.

���
ù° �ٿ� N�� ����Ѵ�. N�� �׻� 32��Ʈ ��ȣ�ִ� ������ ǥ���� �� �ִ�.
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
//#include <cstdio>

using namespace std;

vector<int> divisor;
int n;
int input;
int N;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		divisor.push_back(input);
	}

	sort(divisor.begin(), divisor.end());
	if (n % 2 == 0)
	{
		N = divisor.front() * divisor.back();
	}
	else
	{
		N = divisor[divisor.size() / 2] * divisor[divisor.size() / 2];
	}

	cout << N;
}

/*
��¥ ��� -> 1�� N�� ������ N�� �����
ù°�ٿ� n�� ��¥ ����� ����
�Ѥ��ٿ� ��¥ ��� n��

��¥ ������� ����������,
��� N
	N�� ¦���̸�
		N vector�� �� �� ������ ��
	N�� Ȧ���̸�
		N vector�� �߰����� ����
*/
