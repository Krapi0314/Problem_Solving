/*
BOJ 16916번: 부분 문자열

시간 제한: 1 초
메모리 제한: 512 MB

문제
문자열 S의 부분 문자열이란, 문자열의 연속된 일부를 의미한다.
예를 들어, "aek", "joo", "ekj"는 "baekjoon"의 부분 문자열이고, "bak", "p", "oone"는 부분 문자열이 아니다.
문자열 S와 P가 주어졌을 때, P가 S의 부분 문자열인지 아닌지 알아보자.

입력
첫째 줄에 문자열 S, 둘째 줄에 문자열 P가 주어진다. 두 문자열은 빈 문자열이 아니며, 길이는 100만을 넘지 않는다. 또, 알파벳 소문자로만 이루어져 있다.

출력
P가 S의 부분 문자열이면 1, 아니면 0을 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

string s,p;
bool ans;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ans = false;
	
	cin >> s;
	cin >> p;
	
	int n = s.size();
	int m = p.size(); 
	
	// 전처리: pi 배열 구하기
	vector<int> pi(m,0);
	int j = 0;
	for(int i=1; i<m; i++) {
		while(j>0 && p[i] != p[j]) {
			j = pi[j-1];
		}
		if(p[i] == p[j]) {
			pi[i] = ++j;
		}
	}

	// KMP 알고리즘
	j = 0;
	for(int i=0; i<n; i++) {
		while(j>0 && s[i] != p[j]) {
			j = pi[j-1];
		}
		if(s[i] == p[j]) {
			if(j == m-1) {
				ans = true;
				break;
			}
			else {
				j++;
			}
		}
	}
	
	cout << ans;
	return 0; 
}

/*
문자열: KMP
*/
