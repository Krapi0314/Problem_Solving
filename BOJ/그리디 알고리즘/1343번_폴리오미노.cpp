/*
BOJ 1343번: 폴리오미노

시간 제한: 2초
메모리 제한: 128 MB

문제
민식이는 다음과 같은 폴리오미노 2개를 무한개만큼 가지고 있다. AAAA와 BB
이제 '.'와 'X'로 이루어진 보드판이 주어졌을 때, 민식이는 겹침없이 'X'를 모두 폴리오미노로 덮으려고 한다. 이때, '.'는 폴리오미노로 덮으면 안 된다.
폴리오미노로 모두 덮은 보드판을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 보드판이 주어진다. 보드판의 크기는 최대 500이다.

출력
첫째 줄에 사전순으로 가장 앞서는 답을 출력한다. 만약 덮을 수 없으면 -1을 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int a,b;
int j;
int len;
string s;
bool flag;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> s;
	
	bool exc = true;
	//exception: only . exists
	for(int i=0; i<s.size(); i++) {
		if(s[i] == 'X')
			exc = false;
	}
	if(exc) {
		cout << s;
		return 0;
	}

	
	for(int i=0; i<s.size(); i++) {
		if(s[i] == 'X') {
			j = i;
			len = 0;
			flag = true;
			
			while(s[j] == 'X') {
				len++;
				j++;
			}
			
			if(len % 2 != 0) {
				flag = false;
				break;
			}
			
			a = len / 4;
			len %= 4;
			b = len / 2;
		
			for(int k=0; k<4*a; k++) {
				s[i++] = 'A';
			}
			for(int k=0; k<2*b; k++) {
				s[i++] = 'B';
			}
		}
	}
	
	if(flag) {
		cout << s;
	}
	else {
		cout << "-1";
	}
	
	return 0;
}

/*
greedy

exception: only . exists

cin string s

for s
	if s[i] = 'X'
		j = i
		len = 0		
		flag  true
		
		while s[j] == 'X'
		 	len++
		 	j++
		 	
		if len % 2 != 0
			flag false
			break
		
		a = len / 4
		len %= 4
		b = len / 2
			
		for a
			s[i++] = 'A'
		for b
			s[i++] = 'B'		
		
if flag
	cout s
else
	cout -1
*/
