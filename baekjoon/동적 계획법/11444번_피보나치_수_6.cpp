/*
baekjoon 11444��: �Ǻ���ġ �� 6

�ð� ����: 1 ��
�޸� ����: 256 MB

����
�Ǻ���ġ ���� 0�� 1�� �����Ѵ�. 0��° �Ǻ���ġ ���� 0�̰�, 1��° �Ǻ���ġ ���� 1�̴�. �� ���� 2��° ���ʹ� �ٷ� �� �� �Ǻ���ġ ���� ���� �ȴ�.
�̸� ������ �Ẹ�� Fn = Fn-1 + Fn-2 (n �� 2)�� �ȴ�.
n=17�϶� ���� �Ǻ���ġ ���� �Ẹ�� ������ ����.
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597
n�� �־����� ��, n��° �Ǻ���ġ ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� n�� �־�����. n�� 1,000,000,000,000,000,000���� �۰ų� ���� �ڿ����̴�.

���
ù° �ٿ� n��° �Ǻ���ġ ���� 1,000,000,007���� ���� �������� ����Ѵ�. 

���� �Է� 1 

1000

���� ��� 1 

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
Fibonacci number, d'Ocagne's identity (������ �׵��), memoization
Fm+n = Fm-1Fn + FmFn+1

Fn+n = Fn-1Fn + FnFn+1 = Fn(Fn-1+Fn+1)=Fn(Fn+2Fn-1) ->Fn = Fn/2(Fn/2 + 2*Fn/2-1)
Fn+1+n = FnFn + Fn+1Fn+1 = Fn^2Fn+1^2 -> Fn+1 = Fn/2^2Fn/2+1^2

�� ���� �̿��Ͽ� O(logn)���� Fn ��� ���� (���� �׸� ��� ȣ���ϸ� logn �ȿ� n�� ���� ����) 
*/
