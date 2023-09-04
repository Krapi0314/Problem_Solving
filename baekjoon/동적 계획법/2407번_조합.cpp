/*
baekjoon 2407��: ����

�ð� ����: 2��
�޸� ����: 128 MB

����
nCm�� ����Ѵ�.

�Է�
n�� m�� �־�����. (5 �� n �� 100, 5 �� m �� 100, m �� n)

���
nCm�� ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n,m;
string dp[101][101]; //nCm

string addBigInt(string num, string num2) {
	int carry = 0;
		
	while(num.size() < num2.size()) {
		num = '0' + num;
	}
	while(num.size() > num2.size()) {
		num2 = '0' + num2;
	}
		
	int length = num.size();
	string result(length,'0');
		
	for(int i=length-1; i>=0; i--) {
		int sum = (int)(num[i]-'0') + (int)(num2[i]-'0') + carry;
		carry = sum / 10;
		sum %= 10;
		
		result[i] = sum+'0';
	}
	if(carry != 0) {	
		result = '1' + result;
	}
		
	return result;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	for(int i=0; i<=n; i++) {
		dp[i][0] = to_string(1); dp[i][1] = to_string(i);	
	}
	
	for(int i=1; i<=m; i++) {
		for(int j=1; j<=n; j++) {
			if(n >= m) {
				dp[j][i] = addBigInt(dp[j-1][i],dp[j-1][i-1]);
			}
		}
	}
	
	cout << dp[n][m];
}

/*
dp
nCr = n-1Cr + n-1Cr-1
*/
