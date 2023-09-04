/*
baekjoon 13699��: ��ȭ��

�ð� ����: 5��
�޸� ����: 512 MB

����
������ ��ȭ�Ŀ� ���� ���ǵ� ���� t(n)�� ��������:
t(0)=1
t(n)=t(0)*t(n-1)+t(1)*t(n-2)+...+t(n-1)*t(0)
�� ���ǿ� ������,
t(1)=t(0)*t(0)=1
t(2)=t(0)*t(1)+t(1)*t(0)=2
t(3)=t(0)*t(2)+t(1)*t(1)+t(2)*t(0)=5
...
�־��� �Է� 0 �� n �� 35�� ���Ͽ� t(n)�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� n (0 �� n �� 35)�� �־�����. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ull dp[36];
int n;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	
	dp[0] = 1;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=i; j++) { 
			dp[i] += dp[j-1] * dp[i-j];
		}
	}
	
	cout << dp[n];	
}

/*
DP

��ȭ��:
t(0)=1
t(n)=t(0)*t(n-1)+t(1)*t(n-2)+...+t(n-1)*t(0) -> for(int i=1; i<=n-1; i++) { t[n] += t[i] * t[n-i] }
*/
