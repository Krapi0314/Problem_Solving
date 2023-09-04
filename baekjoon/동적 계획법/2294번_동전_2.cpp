/*
baekjoon 2294��: ���� 2
�ð� ����: 1�� (�߰� �ð� ����)
�޸� ����: 128 MB

��
n���� ������ ������ �ִ�. �� �������� ������ ����ؼ�, �� ��ġ�� ���� k���� �ǵ��� �ϰ� �ʹ�. �׷��鼭 ������ ������ �ּҰ� �ǵ��� �Ϸ��� �Ѵ�. ������ ������ �� ���� ����� �� �ִ�.
����� ������ ������ ������, ������ �ٸ� ���� ���� ����̴�.

�Է�
ù° �ٿ� n, k�� �־�����. (1 �� n �� 100, 1 �� k �� 10,000) ���� n���� �ٿ��� ������ ������ ��ġ�� �־�����. ������ ��ġ�� 100,000���� �۰ų� ���� �ڿ����̴�. ��ġ�� ���� ������ ���� �� �־��� ���� �ִ�.

���
ù° �ٿ� ����� ������ �ּ� ������ ����Ѵ�. �Ұ����� ��쿡�� -1�� ����Ѵ�.
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n,k,num;
int dp[100001];
int ans;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> k;
	for(int i=1; i<=k; i++) {
		dp[i] = INT_MAX;
	}
	for(int i=0; i<n; i++) {
		cin >> num;
		dp[num] = 1;
	}
	
	for(int i=1; i<=k; i++) {
		for(int j=1; j<i; j++) {
			if(dp[j] != INT_MAX && dp[i%j] != INT_MAX) {
				dp[i] = min(dp[i], (i / j) * dp[j] + dp[i%j]);
			}
		}
	}
	
	if(dp[k] != INT_MAX) {
		cout << dp[k];
	}
	else {
		cout << "-1";
	}
	
	return 0;
}

/* 
������ȹ��
dp[k]: �������� ��ġ�� �� k�� ����� ���� �ʿ��� ������ �ּ� ���� 
*/ 
