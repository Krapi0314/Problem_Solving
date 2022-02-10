/*
BOJ 5525번: IOIOI

시간 제한: 1 초
메모리 제한: 256 MB

문제
N+1개의 I와 N개의 O로 이루어져 있으면, I와 O이 교대로 나오는 문자열을 PN이라고 한다.
P1 IOI
P2 IOIOI
P3 IOIOIOI
PN IOIOI...OI (O가 N개)
I와 O로만 이루어진 문자열 S와 정수 N이 주어졌을 때, S안에 PN이 몇 군데 포함되어 있는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. 둘째 줄에는 S의 길이 M이 주어지며, 셋째 줄에 S가 주어진다.

출력
S에 PN이 몇 군데 포함되어 있는지 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, m;
string s, p;
int ans;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> m;
	cin >> s;
	
	bool flag = true;
	vector<int> pi(2*n+1, 0);
	for(int i=0; i<2*n+1; i++) {
		if(flag) {
			p += "I";
			flag = false;
		}
		else {
			p += "O";
			flag = true;
		}
	}
	
	for(int i=2; i<2*n+1; i++) {
		pi[i] = i-1;
	}
	
	int j = 0;
	for(int i=0; i<m; i++) {
		while(j>0 && s[i] != p[j]) {
			j = pi[j-1];
		}
		if(s[i] == p[j]) {
			if(j == 2*n) {
				ans++;
				j = pi[j];
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
