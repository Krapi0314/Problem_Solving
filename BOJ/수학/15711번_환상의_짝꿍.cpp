/*
BOJ 15711번: 환상의 짝꿍

시간 제한: 1초
메모리 제한: 256 MB

문제
환상의 나라 디디랜드에서는 인연의 증표로 끈을 하나씩 가지고 있다. 그들은 지극히 평범한 방법으로 이 끈을 이용하여 어떤 두 사람이 환상의 짝꿍인지 판단하는데, 두 사람의 끈을 서로 이어붙이고 그 끈을 다시 길이가 소수인 끈 두개로 정확히 나눌 수 있다면 두 사람은 환상의 짝꿍이라고 한다. 하지만 그들은 길이가 소수인 두개의 끈으로 나눌 수 있는지 판단하는 것이 어려워서 대부분 서로가 인연임을 모르고 그냥 지나간다고 한다. 애석하게도...
그런 그들을 위해서 어떤 두 사람이 환상의 짝꿍인지 판단하는 프로그램을 작성하라.
편의상 두 사람의 끈을 이어붙일 때와 나눌 때 손실되는 끈의 길이는 0이라고 가정한다.

입력
첫째 줄에 테스트 케이스의 수 T(1 ≤ T ≤ 500)가 주어진다.
둘째 줄부터 T개 줄에 두 사람이 가지고 있는 끈의 길이를 나타내는 정수 A, B가 공백으로 구분되어 주어진다. (1 ≤ A, B ≤ 2 × 1012)

출력
각 테스트 케이스마다 한 줄씩 두 사람의 끈을 이어붙이고 그 끈을 다시 길이가 소수인 두개의 끈으로 정확히 나눌 수 있다면 YES, 불가능하면 NO를 출력하라. 
*/

#include <bits/stdc++.h>

#define MAX 2000000
using namespace std;
typedef long long ll;

vector <int> prime;
bool sieve[MAX];

bool isPrime(ll a){
	for(int i = 0; i < (int)prime.size() && (ll)prime[i] * prime[i] <= a; i++)
		if(a % prime[i] == 0) return false;
	return true;
}

int main() {
	int t;
	scanf("%d", &t);
	
    memset(sieve,true,sizeof(sieve));
    
    int nsqrt = (int)sqrt(MAX);
	for(int i = 2; i <= nsqrt; i++) {
		if (sieve[i])
			for(int j = 2; j * i <= MAX; j++)
				sieve[i*j] = false;
	}
	for(int i = 2; i <= MAX; i++)
		if(sieve[i]) prime.push_back(i);
	
	ll a, b;
	while (t--) {
		scanf("%lld %lld", &a, &b);

		a += b;
		if (a < 4) { printf("NO\n"); continue; }
		if (a % 2 == 0) { printf("YES\n"); continue; }
		a -= 2;

		if (isPrime(a)) printf("YES\n");
		else printf("NO\n");
	}
}

/*
!!4이상인 짝수 n <= 10^18인 수들에 대해 임의의 소수 2개로 n을 만들 수 있음 -> 골드바흐의 추측이 참임

bool arr[200만+1]

memeset(arr,true,sizeof(arr))

200만 이하의 약수를 모두 구하기: 에네테스테네스의 체
for 200만
	if (sieve[i])
    	for i*j <= 200만
		    sieve[i*j] = false

for arr
	vector prime pushback sieve

cin t
for t
	cin a b
	sum = a + b

	if sum < 4
		cout NO
	else
		if sum % 2 (골드바흐의 추측)
			cout YES
		else (홀수이면, 두 소수로 나누어질 수 있다는 가정 하에 소수 중 하나는 무조건 2, sum-2가 소수임을 보이면 됨)
			소수 판별법: 직접 나누기 (N의 양의 제곱근 이하의 수들로 N을 나눠서 한 번이라도 나누어 떨어지면 합성수, 아니면 소수라고 판정 + if 합성수라면 합성수 = 소수 * 임의의 수 이므로, N의 양의 제곱근 이하의 소수들로 나누어보면 됨)
			for prime
				if N % prime[i] == 0
					flag = false
			if flag
				cout YES
			else
				cout NO
*/
