/*
baekjoon 9251��: LCS

�ð� ����: 1 ��
�޸� ����: 256 MB

����
LCS(Longest Common Subsequence, ���� ���� �κ� ����)������ �� ������ �־����� ��, ����� �κ� ������ �Ǵ� ���� �� ���� �� ���� ã�� �����̴�.
���� ���, ACAYKP�� CAPCAK�� LCS�� ACAK�� �ȴ�.

�Է�
ù° �ٰ� ��° �ٿ� �� ���ڿ��� �־�����. ���ڿ��� ���ĺ� �빮�ڷθ� �̷���� ������, �ִ� 1000���ڷ� �̷���� �ִ�.

���
ù° �ٿ� �Է����� �־��� �� ���ڿ��� LCS�� ���̸� ����Ѵ�. 
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
��ȭ�� (�ϱ�): 
if s1[i-1] == s2[j-1] (�� ���ڰ� ���ٸ�) 
	dp[i][j] = dp[i-1][j-1] + 1 (dp ���� �밢�� + 1)
else (�� ���ڰ� �ٸ��ٸ�) 
	dp[i][j] = max(dp[i][j-1], dp[i-1][j]) (max(����, ����))	
*/ 
