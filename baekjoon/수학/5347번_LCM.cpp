/*
baekjoon 5347��: LCM

�ð� ����: 1��
�޸� ����: 128 MB

����
�� �� a�� b�� �־����� ��, a�� b�� �ּ� ������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� n�� �־�����. ���� n�� �ٿ��� a�� b�� �־�����. a�� b���̿��� ������ �ϳ� �̻� �ִ�. �� ���� �鸸���� �۰ų� ���� �ڿ����̴�.

���
�� �׽�Ʈ ���̽��� ���ؼ� �Է����� �־��� �� ���� �ּҰ������ ����Ѵ�. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int t;
int n;
int gcd_n;
int a, b;
int n1, n2;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> a >> b;

		n = max(a, b);
		for (int j = n; j >= 1; j--)
		{
			if (a % j == 0 && b % j == 0)
			{
				gcd_n = j;
				break;
			}
		}

		n1 = a / gcd_n;
		n2 = b / gcd_n;

		cout << gcd_n * n1 * n2 << "\n";
	}
}

/*
a�� b�� �ּ� ������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
�ּҰ������ ����

N1 = gcd(N1,N2) * n1
N2 = gcd(N1,N2) * n2 �϶�,
lcm(N1,N2) = gcd(N1,N2) * n1 * n2

*/
