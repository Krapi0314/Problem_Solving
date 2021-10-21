/*
BOJ 1213번: 팰린드롬 만들기

시간 제한: 2초
메모리 제한: 128 MB

문제
임한수와 임문빈은 서로 사랑하는 사이이다.
임한수는 세상에서 팰린드롬인 문자열을 너무 좋아하기 때문에, 둘의 백일을 기념해서 임문빈은 팰린드롬을 선물해주려고 한다.
임문빈은 임한수의 영어 이름으로 팰린드롬을 만들려고 하는데, 임한수의 영어 이름의 알파벳 순서를 적절히 바꿔서 팰린드롬을 만들려고 한다.
임문빈을 도와 임한수의 영어 이름을 팰린드롬으로 바꾸는 프로그램을 작성하시오.

입력
첫째 줄에 임한수의 영어 이름이 있다. 알파벳 대문자로만 된 최대 50글자이다.

출력
첫째 줄에 문제의 정답을 출력한다. 만약 불가능할 때는 "I'm Sorry Hansoo"를 출력한다. 정답이 여러 개일 경우에는 사전순으로 앞서는 것을 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

string s;
int alphabet[26];
int cnt;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> s;
	
	sort(s.begin(), s.end());
	
	// 홀수번 등장하는 알파벳이 2개 이상이면 불가능 
	for(int i=0; i<s.size(); i++) {
		alphabet[s[i]-'A']++;
	}
	for(int i=0; i<26; i++) {
		if(alphabet[i] % 2 != 0) {
			cnt++;
		}	
	}
	
	if(cnt >= 2) {
		cout << "I'm Sorry Hansoo";
		return 0;
	}
	else {
		// A부터 Z까지 각 알파벳 개수/2 만큼 출력 
		for(int i = 0;i<26; i++) {
			for(int j=0; j<alphabet[i]/2; j++) {
				char ch = i + 'A';
				cout << ch;
			}
		}
		
		// 홀수 알파벳 출력
		for(int i = 0; i<26; i++) {
			if(alphabet[i] % 2 != 0) {
				char ch = i + 'A';
				cout << ch;
			}	
		}
		
		// 반대로 Z부터 A까지 각 알파벳 개수/2 만큼 출력 
		for(int i = 25; i>=0; i--) {
			for(int j=0; j<alphabet[i]/2; j++) {
				char ch = i + 'A';
				cout << ch;
			}
		}
	}
}
