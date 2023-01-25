/*
BOJ 1152: 단어의 개수

시간 제한: 2초
메모리 제한: 128 MB

문제
영어 대소문자와 공백으로 이루어진 문자열이 주어진다. 이 문자열에는 몇 개의 단어가 있을까? 이를 구하는 프로그램을 작성하시오. 단, 한 단어가 여러 번 등장하면 등장한 횟수만큼 모두 세어야 한다.

입력
첫 줄에 영어 대소문자와 공백으로 이루어진 문자열이 주어진다. 이 문자열의 길이는 1,000,000을 넘지 않는다. 단어는 공백 한 개로 구분되며, 공백이 연속해서 나오는 경우는 없다. 또한 문자열은 공백으로 시작하거나 끝날 수 있다.

출력
첫째 줄에 단어의 개수를 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void trim_front(string &str) {
	if (str[0] == ' ') {
		str = str.substr(1, str.size());
	}
}

vector<string> split(string sentence, char delimiter) {
	vector<string> words;
	stringstream ss(sentence);
	string word;
	
	while (getline(ss, word, delimiter)) {
		words.push_back(word);
	}
	
	return words;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string sentence;
	vector<string> words;
	
	getline(cin, sentence);
	
	trim_front(sentence);
	words = split(sentence, ' ');
	
	cout << words.size();
	
	return 0;
}

/* 

*/ 
