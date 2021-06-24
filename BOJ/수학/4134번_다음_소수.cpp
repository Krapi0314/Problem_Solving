/*
BOJ 4134번: 다음 소수 

시간 제한: 1초
메모리 제한: 128 MB

문제
정수 n(0 ≤ n ≤ 4*109)가 주어졌을 때, n보다 크거나 같은 소수 중 가장 작은 소수 찾는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다.

출력
각각의 테스트 케이스에 대해서 n보다 크거나 같은 소수 중 가장 작은 소수를 한 줄에 하나씩 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
ull num;

bool isPrime(ull num) {
	if(num == 1) return false;
	if(num == 2) return true;
	
	// 짝수이면 합성수 
	if(num % 2 == 0) return false;
	
	// N이 두 수로 나누어진다면, N = p * q 형태가 되고, p나 q 중 하나는 반드시 sqrt(N) 이하의 값이 될 것이므로, sqrt(N)까지만 나누어도 소수인지 판별 가능
	// 2를 제외한 소수들은 모두 홀수이므로, i+=2로 홀수만 체크 
	int Max = (int)sqrt(num);
	for(int i=3; i<=Max; i+=2) {
		if(num % i == 0) {
			return false;
		}
	} 
	
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> num;
		
		while(!isPrime(num)) {
			num++;
		}
		
		cout << num << "\n";
	}
}
