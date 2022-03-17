/*
BOJ 9251번: LCS

시간 제한: 1 초
메모리 제한: 256 MB

문제
LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.
예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

입력
첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.

출력
첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

string s1, s2;
int s1_len, s2_len;
int dp[1001][1001];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> s1 >> s2;
	
	s1_len = s1.size(); s2_len = s2.size();
	for(int i=1; i<=s1_len; i++) {
		for(int j=1; j<=s2_len; j++) {
			if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		}
	}
	
	cout << dp[s1_len][s2_len];
	return 0;
}

/* 
DL: LCS Algorithm
점화식 (암기): 
if s1[i-1] == s2[j-1] (두 문자가 같다면) 
	dp[i][j] = dp[i-1][j-1] + 1 (dp 왼쪽 대각선 + 1)
else (두 문자가 다르다면) 
	dp[i][j] = max(dp[i][j-1], dp[i-1][j]) (max(왼쪽, 위쪽))	
*/ 
