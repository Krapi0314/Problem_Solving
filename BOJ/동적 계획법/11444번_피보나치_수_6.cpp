/*
BOJ 11444번: 피보나치 수 6

시간 제한: 1 초
메모리 제한: 256 MB

문제
피보나치 수는 0과 1로 시작한다. 0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1이다. 그 다음 2번째 부터는 바로 앞 두 피보나치 수의 합이 된다.
이를 식으로 써보면 Fn = Fn-1 + Fn-2 (n ≥ 2)가 된다.
n=17일때 까지 피보나치 수를 써보면 다음과 같다.
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597
n이 주어졌을 때, n번째 피보나치 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 n이 주어진다. n은 1,000,000,000,000,000,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 n번째 피보나치 수를 1,000,000,007으로 나눈 나머지를 출력한다. 

예제 입력 1 

1000

예제 출력 1 

517691607
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MOD 1000000007

ll n;
map<ll,ll> mem;

int d_ocagne_fibo(ll n) {
	if (mem.find(n) == mem.end()) {
		ll fn;
		ll fn_2 = d_ocagne_fibo(n/2);
		
		if (n % 2 == 0) {
			ll fn_2_minus_1 = d_ocagne_fibo(n/2 - 1);
			fn = ((fn_2 % MOD) * (fn_2 % MOD + 2 * fn_2_minus_1 % MOD) % MOD) % MOD;
			
		} else {
			ll fn_2_plus_1 = d_ocagne_fibo(n/2 + 1);
			fn = (((fn_2 % MOD)* (fn_2 % MOD)) % MOD + ((fn_2_plus_1 % MOD) * (fn_2_plus_1 %MOD)) % MOD) % MOD;
		}
		
		mem.insert({ n , fn });
	}

	return mem[n];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	mem.insert({ 0, 0 });
	mem.insert({ 1, 1 });
	
	cin >> n;
	
	cout << d_ocagne_fibo(n);
	
	return 0;
}

/* 
Fibonacci number, d'Ocagne's identity (도가뉴 항등식), memoization
Fm+n = Fm-1Fn + FmFn+1

Fn+n = Fn-1Fn + FnFn+1 = Fn(Fn-1+Fn+1)=Fn(Fn+2Fn-1) ->Fn = Fn/2(Fn/2 + 2*Fn/2-1)
Fn+1+n = FnFn + Fn+1Fn+1 = Fn^2Fn+1^2 -> Fn+1 = Fn/2^2Fn/2+1^2

이 식을 이용하여 O(logn)으로 Fn 계산 가능 (한쪽 항만 계속 호출하면 logn 안에 n에 도달 가능) 
*/
