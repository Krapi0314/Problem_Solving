/*
baekjoon 6588��: �������� ����

�ð� ����: 1��
�޸� ����: 256 MB

����
1742��, ������ �Ƹ��߾� ���а� ũ����Ƽ�� ������� �����ϸ�Ʈ ���Ϸ����� ������ ���� ������ �����ϴ� ������ ���´�.
4���� ū ��� ¦���� �� Ȧ�� �Ҽ��� ������ ��Ÿ�� �� �ִ�.
���� ��� 8�� 3 + 5�� ��Ÿ�� �� �ְ�, 3�� 5�� ��� Ȧ���� �Ҽ��̴�. ��, 20 = 3 + 17 = 7 + 13, 42 = 5 + 37 = 11 + 31 = 13 + 29 = 19 + 23 �̴�.
�� ������ ������ �ذ���� ���� �����̴�.
�鸸 ������ ��� ¦���� ���ؼ�, �� ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�Է��� �ϳ� �Ǵ� �� �̻��� �׽�Ʈ ���̽��� �̷���� �ִ�. �׽�Ʈ ���̽��� ������ 100,000���� ���� �ʴ´�.
�� �׽�Ʈ ���̽��� ¦�� ���� n �ϳ��� �̷���� �ִ�. (6 �� n �� 1000000)
�Է��� ������ �ٿ��� 0�� �ϳ� �־�����.

���
�� �׽�Ʈ ���̽��� ���ؼ�, n = a + b ���·� ����Ѵ�. �̶�, a�� b�� Ȧ�� �Ҽ��̴�. ���ڿ� �����ڴ� ���� �ϳ��� ���еǾ��� �ִ�. ����, n�� ���� �� �ִ� ����� ���� �������, b-a�� ���� ū ���� ����Ѵ�. ��, �� Ȧ�� �Ҽ��� ������ n�� ��Ÿ�� �� ���� ��쿡�� "Goldbach's conjecture is wrong."�� ����Ѵ�.
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

#define MAX 1000000

bool arr[MAX + 1];
vector<int> prime;
int n;
bool flag;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(arr, true, sizeof(arr));

	int sqrts = (int)sqrt(MAX);
    arr[1] = false;

    for (int i = 2; i <= sqrts; i++)
	{
		if (!arr[i])
			continue;

		for (int j = 2; i * j <= MAX; j++)
		{
			arr[i * j] = false;
		}
	}

	for (int i = 3; i <= MAX; i++)
	{
		if (arr[i] && i % 2 != 0)
			prime.push_back(i);
	}

	//main
	while (1)
	{
		flag = false;

		cin >> n;
		if (n == 0)
			break;

		for (int i = 0; n - prime[i] > 0 ; i++)
		{
			if (arr[n - prime[i]]) //¦�� - Ȧ�� = Ȧ��
			{
				cout << n << " = " << prime[i] << " + " << n-prime[i] << '\n';
				flag = true;
				break;
			}

		}

		if (!flag)
			cout << "Goldbach's conjecture is wrong.\n";
	}
}

/*
�Ҽ����ϱ�: �����佺�׳׽��� ü
n = a + b ���: 

MAX = 100000
bool arr[MAX]

for 2 to sqrt(MAX)
	if arr[i] false
		continue
	for 2 to i*j <= MAX
		arr[] false

for arr
	if arr true
		vector prime pushback arr

while 1
	flag = false
	cin n

	if n == 0
		break

	���� ����: �� �Ҽ��� p��� �ϰ�, �������� ������ ������, n-p�� �Ҽ����� ��
	for prime
		if arr[n-prime[i]] == true (�� �Ҽ��� p�ϋ�, n-p�� �Ҽ��̸� ������ ���� ����)
			cout << n << " = " << b << " + " << a << '\n';
			flag = true
			break
	if !flag
		cout << "Goldbach's conjecture is wrong." << '\n';
*/
