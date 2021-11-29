/*
BOJ 2877번: 4와 7

시간 제한: 1초
메모리 제한: 128 MB

문제
창영이는 4와 7로 이루어진 수를 좋아한다. 창영이가 좋아하는 수 중에 K번째 작은 수를 구해 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 K(1 ≤ K ≤ 109)가 주어진다.

출력
첫째 줄에 창영이가 좋아하는 숫자 중 K번째 작은 수를 출력한다.
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll k; 
deque<int> dq;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k;
	
	k++;
	while(k != 0) {
		int digit = k % 2;
		dq.push_front(digit);
		k /= 2;
	}
	dq.pop_front();
	
	for(int i=0; i<(int)dq.size(); i++) {
		if(dq[i] == 0) {
			cout << "4";
		}
		else {
			cout << "7";
		}
	}
}

/*
수학: 규칙성 찾기 -> 4 -> 0, 7 -> 1로 생각하고 k+1의 이진수에서 MSB를 없애면 k번째 수의 1,0 변환 형태와 같음 
*/
