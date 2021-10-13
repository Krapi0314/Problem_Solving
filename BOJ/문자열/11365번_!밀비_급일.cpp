/*
BOJ 11365번: !밀비 급일 

시간 제한: 1초
메모리 제한: 256 MB

문제
당신은 길을 가다가 이상한 쪽지를 발견했다. 그 쪽지에는 암호가 적혀 있었는데, 똑똑한 당신은 암호가 뒤집으면 해독된다는 것을 발견했다.
이 암호를 해독하는 프로그램을 작성하시오.

입력
한 줄에 하나의 암호가 주어진다. 암호의 길이는 500을 넘지 않는다.
마지막 줄에는 "END"가 주어진다. (END는 해독하지 않는다.)

출력
각 암호가 해독된 것을 한 줄에 하나씩 출력한다. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

//#Include <cstdio>

using namespace std;

string s;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1)
	{
		getline(cin, s);
		if (s == "END")
		{
			break;
		}

		string::reverse_iterator riter = s.rbegin();

		for (; riter != s.rend(); ++riter)
		{
			cout << *riter;
		}
		cout << "\n";
	}
}

/*

 */
