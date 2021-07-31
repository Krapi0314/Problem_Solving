/*
BOJ 5347번: LCM

시간 제한: 1초
메모리 제한: 128 MB

문제
두 수 a와 b가 주어졌을 때, a와 b의 최소 공배수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 n이 주어진다. 다음 n개 줄에는 a와 b가 주어진다. a와 b사이에는 공백이 하나 이상 있다. 두 수는 백만보다 작거나 같은 자연수이다.

출력
각 테스트 케이스에 대해서 입력으로 주어진 두 수의 최소공배수를 출력한다. 
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
a와 b의 최소 공배수를 구하는 프로그램을 작성하시오.
최소공배수의 성질

N1 = gcd(N1,N2) * n1
N2 = gcd(N1,N2) * n2 일때,
lcm(N1,N2) = gcd(N1,N2) * n1 * n2

*/
