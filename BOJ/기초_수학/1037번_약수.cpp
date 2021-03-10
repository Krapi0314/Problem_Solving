/*
BOJ 1037번: 약수

시간 제한: 2초
메모리 제한: 512 MB
 
문제
양수 A가 N의 진짜 약수가 되려면, N이 A의 배수이고, A가 1과 N이 아니어야 한다. 어떤 수 N의 진짜 약수가 모두 주어질 때, N을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N의 진짜 약수의 개수가 주어진다. 이 개수는 50보다 작거나 같은 자연수이다. 둘째 줄에는 N의 진짜 약수가 주어진다. 1,000,000보다 작거나 같고, 2보다 크거나 같은 자연수이고, 중복되지 않는다.

출력
첫째 줄에 N을 출력한다. N은 항상 32비트 부호있는 정수로 표현할 수 있다.
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
진짜 약수 -> 1과 N을 제외한 N의 약수들
첫째줄에 n의 진짜 약수의 개수
둘쨰줄에 진짜 약수 n개

진짜 약수들을 정렬했을떄,
약수 N
	N이 짝수이면
		N vector의 양 끝 원소의 곱
	N이 홀수이면
		N vector의 중간값의 제곱
*/
