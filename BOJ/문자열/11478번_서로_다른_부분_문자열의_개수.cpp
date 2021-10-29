/*
BOJ 11478번: 서로 다른 부분 문자열의 개수

시간 제한: 1초
메모리 제한: 512 MB

문제
문자열 S가 주어졌을 때, S의 서로 다른 부분 문자열의 개수를 구하는 프로그램을 작성하시오.
부분 문자열은 S에서 연속된 일부분을 말하며, 길이가 1보다 크거나 같아야 한다.
예를 들어, ababc의 부분 문자열은 a, b, a, b, c, ab, ba, ab, bc, aba, bab, abc, abab, babc, ababc가 있고, 서로 다른것의 개수는 12개이다.

입력
첫째 줄에 문자열 S가 주어진다. S는 알파벳 소문자로만 이루어져 있고, 길이는 1,000 이하이다.

출력
첫째 줄에 S의 서로 다른 부분 문자열의 개수를 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

string str;
set<string> s;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str;
	
	for(int i=1; i<=(int)str.size(); i++) {
		for(int j=0; j<=(int)str.size()-i; j++) {
			s.insert(str.substr(j,i));
		}
	}
	
	cout << s.size();
}

/*
string, data structure
추가: vector를 이용한 erase,unique 작업보다, 중복을 허용하지 않는 자료구조인 set을 이용해서 삽입만 수행하면 더 쉽고, 빠르게 가능 
*/
