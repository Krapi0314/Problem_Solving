/*
BOJ 1676번: 팩토리얼 0의 개수

시간 제한: 2 초
메모리 제한: 128 MB

문제 
N!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (0 ≤ N ≤ 500)

출력
첫째 줄에 구한 0의 개수를 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
int ans;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	for(int i=1; i<=n; i++) {
		int temp = i;
		while(temp != 0 && temp % 5 == 0) {
			ans++;
			temp /= 5;
		}	
	}
	
	cout << ans;
	return 0;
}

/* 
수학: 팩토리얼에서 5의 개수 구하기

!! 개수만을 구하기 때문에 아래와 같은 알고리즘을 사용하면 더 빠르게 해결 가능 
while(n >= 5) {
	ans += n / 5;
	n /= 5;
}
*/ 
