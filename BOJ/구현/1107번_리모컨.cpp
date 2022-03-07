/*
BOJ 1107번: 리모컨

시간 제한: 2 초
메모리 제한: 256 MB

문제
수빈이는 TV를 보고 있다. 수빈이는 채널을 돌리려고 했지만, 버튼을 너무 세게 누르는 바람에, 일부 숫자 버튼이 고장났다.
리모컨에는 버튼이 0부터 9까지 숫자, +와 -가 있다. +를 누르면 현재 보고있는 채널에서 +1된 채널로 이동하고, -를 누르면 -1된 채널로 이동한다. 채널 0에서 -를 누른 경우에는 채널이 변하지 않고, 채널은 무한대 만큼 있다.
수빈이가 지금 이동하려고 하는 채널은 N이다. 어떤 버튼이 고장났는지 주어졌을 때, 채널 N으로 이동하기 위해서 버튼을 최소 몇 번 눌러야하는지 구하는 프로그램을 작성하시오. 
수빈이가 지금 보고 있는 채널은 100번이다.

입력
첫째 줄에 수빈이가 이동하려고 하는 채널 N (0 ≤ N ≤ 500,000)이 주어진다.  둘째 줄에는 고장난 버튼의 개수 M (0 ≤ M ≤ 10)이 주어진다. 고장난 버튼이 있는 경우에는 셋째 줄에는 고장난 버튼이 주어지며, 같은 버튼이 여러 번 주어지는 경우는 없다.

출력
첫째 줄에 채널 N으로 이동하기 위해 버튼을 최소 몇 번 눌러야 하는지를 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, nn, m;
int n_len, num;
bool broken[10];
int ans;

// num: 입력 가능한 채널, n: 이동하려고 하는 채널 
void dfs(int num, int len) {
	// num이 한 번이라도 입력됬으면서 num의 자리수가 n의 자리수보다 1 작을 때 
	if(len > 0 && len == n_len - 1) {
		ans = min(ans, abs(n-num) + len);
	}
	// num의 자리수가 n의 자리수와 같을 때 
	if(len == n_len) {
		ans = min(ans, abs(n-num) + len);
	}
	// num의 자리수가 n의 자리수보다 1 클 때
	if(len == n_len + 1) {
		ans = min(ans, abs(n-num) + len);
		return;
	}
	
	for(int i=0; i<10; i++) {
		if(!broken[i]) {
			dfs(num * 10 + i, len + 1);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	cin >> m;
	for(int i=0; i<m; i++) {
		cin >> num;
		broken[num] = true;
	}
	
	nn = n;
	do {
		nn /= 10;
		n_len++;
	} while(nn != 0);
	
	ans = INT_MAX;
	dfs(0, 0);
	ans = min(ans, abs(100-n));
	
	cout << ans;
	return 0;
}

/* 
Bruce Force
*/ 
