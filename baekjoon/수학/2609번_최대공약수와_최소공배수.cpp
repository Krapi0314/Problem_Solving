/*
baekjoon 2609��: �ִ������� �ּҰ����

�ð� ����: 1��
�޸� ����: 128 MB

����
�� ���� �ڿ����� �Է¹޾� �ִ� ������� �ּ� ������� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ��� �� ���� �ڿ����� �־�����. �� ���� 10,000������ �ڿ����̸� ���̿� �� ĭ�� ������ �־�����.

���
ù° �ٿ��� �Է����� �־��� �� ���� �ִ�������, ��° �ٿ��� �Է����� �־��� �� ���� �ּ� ������� ����Ѵ�.
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int a, b; int Min,Max;
int Gcd, Lcm = 1;
int n1, n2;

int gcd(int a,int b) //��Ŭ���� ȣ����: a�� b�� ���� ������
{
	if (b == 0) //�������� 0�� ������ 
		return a;

	return gcd(b, a % b);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> b;

	Min = min(a, b); Max = max(a, b);
	Gcd = gcd(Max,Min);

	n1 = a / Gcd;
	n2 = b / Gcd;

	Lcm = Gcd * n1 * n2;

	cout << Gcd << "\n" << Lcm;
}

/*
��Ŭ���� ȣ����, �ִ� ������� ����

cin a b

Gcd = gcd(a,b)

n1 = a % gcd
n2 = b % gcd

Lcm = Gcd * n1 * n2

cout << Gcd << Lcm
*/
