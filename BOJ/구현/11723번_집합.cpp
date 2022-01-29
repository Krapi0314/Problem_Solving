/*
BOJ 11723번: 집합

시간 제한: 1.5 초
메모리 제한: 4 MB

문제
비어있는 공집합 S가 주어졌을 때, 아래 연산을 수행하는 프로그램을 작성하시오.

- add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
- remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
- check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
- toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
- all: S를 {1, 2, ..., 20} 으로 바꾼다.
- empty: S를 공집합으로 바꾼다. 

입력
첫째 줄에 수행해야 하는 연산의 수 M (1 ≤ M ≤ 3,000,000)이 주어진다.
둘째 줄부터 M개의 줄에 수행해야 하는 연산이 한 줄에 하나씩 주어진다.

출력
check 연산이 주어질때마다, 결과를 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int m;
int s, x;
string cmd;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m;
	for(int i=0; i<m; i++) {
		cin >> cmd;
		
		if(cmd == "add") {
			cin >> x;
			// ex) 1000 ! 100 = 1100
			s |= (1 << x);
		}
		else if(cmd == "remove") {
			cin >> x;
			// ex) 1000 & ~(1000) = 0000 
			s &= ~(1 << x);
		}
		else if(cmd == "check") {
			cin >> x;
			// ex) 1011 & 1000 = 1 (true)
			// ex) 0011 & 1000 = 0 (false)
			if(s & (1 << x)) {
				cout << "1\n";
			}
			else {
				cout << "0\n";	
			}
		}
		else if(cmd == "toggle") {
			cin >> x;
			// ex) 1011 ^ 1000 = 0011
			// ex) 0011 ^ 1000 = 1011
 			s ^= (1 << x);
		}
		else if(cmd == "all") {
			// ex) 10000 - 1 = 1111
			s = (1 << 21) - 1;
		}
		else {
			// ex) 0000
			s = 0;
		}
	}
	
	return 0;
}

/* 
구현 - 비트마스크 
*/ 
