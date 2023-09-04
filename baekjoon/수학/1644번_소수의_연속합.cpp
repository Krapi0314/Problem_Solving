/*
baekjoon 1644��: �Ҽ��� ������

�ð� ����: 2��
�޸� ����: 128 MB

����
�ϳ� �̻��� ���ӵ� �Ҽ��� ������ ��Ÿ�� �� �ִ� �ڿ������� �ִ�. �� ���� �ڿ����� ���� ��� ���� ������ ����.

3 : 3 (�� ����)
41 : 2+3+5+7+11+13 = 11+13+17 = 41 (�� ����)
53 : 5+7+11+13+17 = 53 (�� ����)

������ ���ӵ� �Ҽ��� ������ ��Ÿ�� �� ���� �ڿ����鵵 �ִµ�, 20�� �� ���̴�. 7+13�� ����ϸ� 20�� �Ǳ�� �ϳ� 7�� 13�� ������ �ƴϱ⿡ ������ ǥ���� �ƴϴ�. ���� �� �Ҽ��� �ݵ�� �� ���� ������ ���� �� �ֱ� ������, 3+5+5+7�� ���� ǥ���� �������� �ʴ�.
�ڿ����� �־����� ��, �� �ڿ����� ���ӵ� �Ҽ��� ������ ��Ÿ�� �� �ִ� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �ڿ��� N�� �־�����. (1 �� N �� 4,000,000)

���
ù° �ٿ� �ڿ��� N�� ���ӵ� �Ҽ��� ������ ��Ÿ�� �� �ִ� ����� ���� ����Ѵ�.
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

bool arr[4000001];
vector<int> prime;
int lo, hi;
int cnt;
int sum;
int n;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	memset(arr, true, sizeof(arr));

	for (int i = 2; i <= 2000; i++)
	{
		if (!arr[i])
			continue;

		for (int j = 2; i * j <= n; j++)
		{
			arr[i * j] = false;
		}
	}

	for (int i = 2; i <= n; i++)
	{
		if (arr[i])
			prime.push_back(i);
	}

	//�� ������
	while (1)
	{
		if (sum >= n)
		{
			sum -= prime[lo++];
		}
		else if (hi == prime.size())
		{
			break;
		}
		else
		{
			sum += prime[hi++];
		}

		if (sum == n)
			cnt++;
	}

	cout << cnt;
}

/*
�����佺�׳׽��� ü -> �Ҽ� �迭 ���ϱ� -> (���� for���� O(n^2) �̿��ϸ� �ð��ʰ�) �� ������ �˰��� ��� O(n) �ð����⵵ -> ����� �� ���ϱ�

!!�� ������ �˰���: ���ĵ� ����Ʈ�� �� ���� �����͸� �̿��� ���������� �����ϸ鼭 �� ������ ������ ���� Ÿ�ٰ��� ���� ������ �����͸� �����ϴ� ���

bool arr[400��] = true

for i 2 to 2000
	for j 2 to i*j <= 2000
		arr[i*j] = false

for arr
	if true
		vector prime pushback i

�� ������ �˰���, [lo,hi) ������ sum
while 1
	if sum >= n //�������� n���� ũ�ų� ������
		sum -= prime[lo++] //�����տ��� prime[lo(����)] �� ���ְ� lo ����
	else if hi == prime size //hi(������) ���� �迭�� �����
		 break //Ž�� ���� (��� ����� �� �� �ѷ���)
	else //�������� n���� ������
		sum += prime[hi++] //�����տ��� primep[hi(������)] �� �߰��ϰ� hi ����

	if sum == n
		cnt++

cout cnt

*/
