/*
BOJ 2609번: 최대공약수와 최소공배수

시간 제한: 1초
메모리 제한: 128 MB

문제
두 개의 자연수를 입력받아 최대 공약수와 최소 공배수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에는 두 개의 자연수가 주어진다. 이 둘은 10,000이하의 자연수이며 사이에 한 칸의 공백이 주어진다.

출력
첫째 줄에는 입력으로 주어진 두 수의 최대공약수를, 둘째 줄에는 입력으로 주어진 두 수의 최소 공배수를 출력한다.
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int a, b; int Min,Max;
int Gcd, Lcm = 1;
int n1, n2;

int gcd(int a,int b) //유클리드 호제법: a를 b로 나눈 나머지
{
	if (b == 0) //나머지가 0이 나오면 
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
유클리드 호제법, 최대 공약수의 성질

cin a b

Gcd = gcd(a,b)

n1 = a % gcd
n2 = b % gcd

Lcm = Gcd * n1 * n2

cout << Gcd << Lcm
*/
