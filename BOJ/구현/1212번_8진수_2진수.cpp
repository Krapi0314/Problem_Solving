/*
BOJ 1212번: 8진수 2진수 

시간 제한: 1초
메모리 제한: 128 MB

문제
8진수가 주어졌을 때, 2진수로 변환하는 프로그램을 작성하시오.

입력
첫째 줄에 8진수가 주어진다. 주어지는 수의 길이는 333,334을 넘지 않는다.

출력
첫째 줄에 주어진 수를 2진수로 변환하여 출력한다. 수가 0인 경우를 제외하고는 반드시 1로 시작해야 한다.
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

string s;
string bi;
int digit;
char c;
int num;
bool flag;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> s;

	if (s == "0")
	{
		cout << "0";
		return 0;
	}

	for (int i = 0; i < s.size(); i++)
	{
		bi.clear();

		num = s[i] - '0';

		if (num == 0)
		{
			bi = "000";
		}
		else
		{
			while (num != 0)
			{
				digit = num % 2;
				num /= 2;

				c = digit + '0';
				bi = c + bi;
			}
		}

		if (!flag)
		{
			cout << bi;
			flag = true;
			continue;
		}

		if (bi.size() % 3 == 1)
			bi = "00" + bi;
		else if (bi.size() % 3 == 2)
			bi = "0" + bi;

		cout << bi;
	}
}

/*
8진수 -> 2진수
8진수 1자리 = 2진수 3자리로 표현되므로 8진수 1자리씩 2진수 3자리로 변환

flag = false
cin string s

if s == "0"
	cout 0
	return 0 (exit(1)은 런타임 에러 뜸, exit(0) = main 함수 return == return 0, exit(0)으로 하거나, return 0로 반환하기)

for s.size
	init
		bi = null

	num = s[i]

	if num == 0 //8진수 0 = 2진수 000
		bi = "000"
	else
		while num !=0
			digit = num % 2
			num /= 2
		
			char  c = digit + '0'
			bi = c + bi


	if flag false
		cout bi
		flag = true

	if bi.size % 3 == 1
		bi = "00" + bi
	else if bi.size % 3 == 2
		bi = "0" + bi

	cout bi
*/
