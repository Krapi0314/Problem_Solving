/*
BOJ 5618번: 공약수

시간 제한: 1초
메모리 제한: 256 MB

문제
자연수 n개가 주어진다. 이 자연수의 공약수를 모두 구하는 프로그램을 작성하시오.

입력
첫째 줄에 n이 주어진다. n은 2 또는 3이다. 둘째 줄에는 공약수를 구해야 하는 자연수 n개가 주어진다. 모든 자연수는 108 이하이다.

출력
입력으로 주어진 n개 수의 공약수를 한 줄에 하나씩 증가하는 순서대로 출력한다. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int n;
int num;
vector<int> v;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;

	if (n == 2)
	{
		for (int i = 0; i < 2; i++)
		{
			cin >> num;
			v.push_back(num);
		}
		sort(v.begin(), v.end());

		for (int i = 1; i <= v[1]; i++)
		{
			if (v[0] % i == 0 && v[1] % i == 0)
				cout << i << "\n";
		}
	}
	else if (n == 3)
	{
		for (int i = 0; i < 3; i++)
		{
			cin >> num;
			v.push_back(num);
		}
		sort(v.begin(), v.end());

		for (int i = 1; i <= v[2]; i++)
		{
			if (v[0] % i == 0 && v[1] % i == 0 && v[2] % i == 0)
				cout << i << "\n";
		}
	}

}

/*
공약수 구하기

cin n (n==2,3)

if 2
for 2
	cin num
	vector pushback num

sort num
for vector 마지막 원소
	if v[0] % i == 0 && v[1] % i == 0
		cout << i

if 3
for 3
	cin num
	vector pushback num

sort num
for vector 마지막 원소
	if v[0] % i == 0 && v[1] % i == 0 && v[2] % i == 0
		cout << i
*/
