/*
BOJ 6443번: 애너그램

시간 제한: 1초
메모리 제한: 128 MB

문제
씬디는 애너그램(anagram) 프로그램을 만들어 줄 수 있는 남자를 좋아한다. 참고로 씬디는 매우 예쁘다.
애너그램 프로그램이란, 입력받은 영단어의 철자들로 만들 수 있는 모든 단어를 출력하는 것이다. 가령 "abc" 를 입력받았다면, "abc", "acb", "bac", "bca", "cab", "cba" 를 출력해야 한다.
입력받은 단어내에 몇몇 철자가 중복될 수 있다. 이 경우 같은 단어가 여러 번 만들어 질 수 있는데, 한 번만 출력해야 한다.  또한 출력할 때에 알파벳 순서로 출력해야 한다.

입력
첫째 줄에 단어의 개수 N 이, 둘째 줄부터 N개의 영단어가 들어온다. 영단어는 소문자로 이루어져 있다.

출력
N개의 영단어에 대한 모든 가능한 애너그램을 출력한다. 각각의 영단어에 대한 애너그램을 출력할 때, 알파벳 순서로 중복되지 않게 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
string s;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	while(n--) {
		cin >> s;
		
		sort(s.begin(),s.end());
		
		do {
			cout << s << "\n";
		} while(next_permutation(s.begin(),s.end()));
		
	}
}

/*
백트래킹, 조합
*/
