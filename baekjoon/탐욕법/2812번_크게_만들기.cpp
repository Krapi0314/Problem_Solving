/*
2812번: 크게 만들기

시간 제한: 1초
메모리 제한: 128 MB

문제
N자리 숫자가 주어졌을 때, 여기서 숫자 K개를 지워서 얻을 수 있는 가장 큰 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 주어진다. (1 ≤ K < N ≤ 500,000)
둘째 줄에 N자리 숫자가 주어진다. 이 수는 0으로 시작하지 않는다.

출력
입력으로 주어진 숫자에서 K개를 지웠을 때 얻을 수 있는 가장 큰 수를 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int k,n;
string s;
deque<char> dq;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	cin >> s;
	
	int len = s.size();
	for(int i=0; i<len; i++) {
		while(k && !dq.empty() && dq.back() < s[i]) {
			dq.pop_back();
			k--;
		}
		
		dq.push_back(s[i]);
	}
	
	len = dq.size() - k;
	for(int i=0; i<len; i++) {
		cout << dq[i];
	}
	
	return 0;
}

/*
탐욕법
k > 0일 동안 deque에 숫자를 넣고, 이후 들어오는 숫자와 비교, 들어오는 숫자보다 deque의 마지막 숫자가 더 작으면 pop, 이후 deque의 원소들을 n - k 만큼 출력  
*/
