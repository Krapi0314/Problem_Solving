/*
BOJ 11653번: 소인수분해

시간 제한: 1초
메모리 제한: 256 MB

문제
정수 N이 주어졌을 때, 소인수분해하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 N (1 ≤ N ≤ 10,000,000)이 주어진다.

출력
N의 소인수분해 결과를 한 줄에 하나씩 오름차순으로 출력한다. N이 1인 경우 아무것도 출력하지 않는다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAX 10000000
int n;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	 
	cin >> n;
	
	for(int i=2; i<=sqrt(n); i++) {
		while(n % i == 0) {
			cout << i << "\n";
			n /= i;
		}
	}
	
	if(n != 1) {
		cout << n;
	}
}

/*
수학: 단순 나누기 (작은 소수부터 나뉘도록 설계했으며, sqrt(N)까지 N을 나누는 모든 소수가 포함되므로, 결국 소수의 곱인 소인수분해로 나뉘게 됨)  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAX 10000001
int n;
bool not_prime[MAX];
vector<int> prime;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	 
	for(int i=2; i<=sqrt(n); i++) {
		for(int j=2; j*i<=n; j++) {
			not_prime[i*j] = true;
		}
	}
	for(int i=2; i<=n; i++) {
		if(!not_prime[i]) {
			prime.push_back(i);
		}
	}
	
	for(int i=0; i<prime.size(); i++) {
		while(n % prime[i] == 0) {
			n /= prime[i];
			cout << prime[i] << "\n";
		}
	}
}

/*
수학: 에라토스테네스의 체로 구한 버전 
