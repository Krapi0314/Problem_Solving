/*
BOJ 2294번: 동전 2
시간 제한: 1초 (추가 시간 없음)
메모리 제한: 128 MB

제
n가지 종류의 동전이 있다. 이 동전들을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다. 그러면서 동전의 개수가 최소가 되도록 하려고 한다. 각각의 동전은 몇 개라도 사용할 수 있다.
사용한 동전의 구성이 같은데, 순서만 다른 것은 같은 경우이다.

입력
첫째 줄에 n, k가 주어진다. (1 ≤ n ≤ 100, 1 ≤ k ≤ 10,000) 다음 n개의 줄에는 각각의 동전의 가치가 주어진다. 동전의 가치는 100,000보다 작거나 같은 자연수이다. 가치가 같은 동전이 여러 번 주어질 수도 있다.

출력
첫째 줄에 사용한 동전의 최소 개수를 출력한다. 불가능한 경우에는 -1을 출력한다.
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
동적계획법
dp[k]: 동전들의 가치의 합 k를 만들기 위해 필요한 동전의 최소 개수 
*/ 
