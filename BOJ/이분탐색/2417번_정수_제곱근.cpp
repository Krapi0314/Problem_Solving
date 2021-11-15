/*
BOJ 2417번: 정수 제곱근

시간 제한: 1초
메모리 제한: 128 MB

문제
정수가 주어지면, 그 수의 정수 제곱근을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 n이 주어진다. (0 ≤ n < 263)

출력
첫째 줄에 q2 ≥ n인 가장 작은 음이 아닌 정수 q를 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ull n;
ll l,r,m;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	l = 0; r = sqrt(n) + 1;
	while(l <= r) {
		m = (l + r) / 2;
		
		if(m*m >= n) {
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	
	if(m*m == n) {
		cout << m;
	}
	else {
		cout << l;
	}
}

/*
이분탐색
*/ 

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ull n;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	cout << (ll)ceil(sqrt(n));
}

/*
수학 
*/
