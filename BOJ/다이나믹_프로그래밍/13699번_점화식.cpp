/*
BOJ 13699번: 점화식

시간 제한: 5초
메모리 제한: 512 MB

문제
다음의 점화식에 의해 정의된 수열 t(n)을 생각하자:
t(0)=1
t(n)=t(0)*t(n-1)+t(1)*t(n-2)+...+t(n-1)*t(0)
이 정의에 따르면,
t(1)=t(0)*t(0)=1
t(2)=t(0)*t(1)+t(1)*t(0)=2
t(3)=t(0)*t(2)+t(1)*t(1)+t(2)*t(0)=5
...
주어진 입력 0 ≤ n ≤ 35에 대하여 t(n)을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 n (0 ≤ n ≤ 35)이 주어진다. 
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

점화식:
t(0)=1
t(n)=t(0)*t(n-1)+t(1)*t(n-2)+...+t(n-1)*t(0) -> for(int i=1; i<=n-1; i++) { t[n] += t[i] * t[n-i] }
*/
