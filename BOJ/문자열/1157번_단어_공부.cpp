/*
BOJ 1157번: 단어 공부

시간 제한: 2초
메모리 제한: 128 MB

문제
알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오. 단, 대문자와 소문자를 구분하지 않는다.

입력
첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다. 주어지는 단어의 길이는 1,000,000을 넘지 않는다.

출력
첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다. 단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int alphabet[26];
string word;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> word;
	
	int len = word.size();
	for (int i=0; i<len; i++) {
		if ( 'a' <= word[i] && word[i] <= 'z') {
			word[i] = word[i] - 'a' + 'A';
		}
	}
	
	for (int i=0; i<len; i++) {
		alphabet[word[i]-'A']++;
	}
	
	pair<char, int> ans; // alphabet, count
	for (int i=0; i<26; i++) {
		if (alphabet[i] > ans.second) {
			ans.first = 'A' + i;
			ans.second = alphabet[i];
		}
	}
	
	int dup = 0;
	for (int i=0; i<26; i++) {
		if (alphabet[i] == ans.second) {
			dup++;
		}
	}
	
	if (dup >= 2) {
		cout << "?\n";
	}
	else {
		cout << ans.first << "\n";
	}
	
	return 0;
}

/* 

*/ 
