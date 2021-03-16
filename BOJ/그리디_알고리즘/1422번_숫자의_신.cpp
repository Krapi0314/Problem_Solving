/*
BOJ 1422번: 숫자의 신

시간 제한: 2초
메모리 제한: 128 MB

문제
숫자의 신은 여러명이 있지만, 그 중에 자연수의 신은 오세준이다. 오세준은 자연수의 신으로 오래오래 살다가 어느 날 음수의 신과 전쟁을 하게 되었다. 오세준은 음수의 신 이다솜을 이기기위해서 큰 숫자를 만들기로 했다.
오세준은 지금 K개의 자연수를 가지고 있다. 오세준은 K개의 수 중에 정확하게 N개의 수를 뽑아내서 그 수를 붙여서 만들 수 있는 수중에 가장 큰 수를 만들고자 한다. 같은 수를 여러 번 이용해도 된다. 단, 모든 수는 적어도 한 번은 이용되어야 한다.
오세준이 현재 가지고 있는 K개의 수가 주어졌을 때, 이 수를 적어도 한 번 이상 이용해서 만들 수 있는 수 중에 가장 큰 수를 출력하는 프로그램을 작성하시오.
예를 들어 지금 오세준이 2, 3, 7 이라는 3개의 수를 가지고 있고, 4개의 수를 뽑아야 한다면, 7732를 만들면 가장 큰 수가 된다.

입력
첫째 줄에 K와 N이 공백을 사이에 두고 주어진다. K와 N은 각각 1,000보다 작거나 같은 자연수이고, N은 K보다 크거나 같다. 둘째 줄에는 K개의 수가 한 줄에 하나씩 주어진다. 각 수는 1,000,000,000보다 작거나 같은 자연수이다. 이 수는 중복되어 들어올 수 있다. 만약 중복되어서 들어오는 경우에는 각 수가 적어도 입력으로 주어진 만큼 이용되어야 한다는 소리다.

출력
N개의 수를 뽑아서 연결해서 만들 수 있는 가장 큰 수를 출력한다. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int k, n;
ll num;

struct compare {
	bool operator()(ll& a, ll& b) {
		string a_b = to_string(a) + to_string(b);
		string b_a = to_string(b) + to_string(a);

		unsigned long long i_a_b = stoull(a_b);
		unsigned long long i_b_a = stoull(b_a);

		return i_a_b < i_b_a;
	}
};

priority_queue<ll> pq;
priority_queue<ll, vector<ll>, compare> pq2;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k >> n;
	for (int i = 0; i < k; i++)
	{
		cin >> num;
		pq.push(num);
	}

	ll biggest = pq.top(); pq.pop();
	for (int i = k; i <= n; i++)
	{
		pq2.push(biggest);
	}

	while (!pq.empty())
	{
		num = pq.top(); pq.pop();
		pq2.push(num);
	}

	while (!pq2.empty())
	{
		cout << pq2.top();
		pq2.pop();
	}
}

/*
최적 부분 구조, 탐욕 선택 속성 => 탐욕법
(탐욕) 선택 기준:
	1 순위: 최대한 긴 자릿수를 가지도록 선택
	2 순위: 두 수를 붙여서 수가 더 큰 쪽을 선택

모든 수를 적어도 한 번 이상 이용 -> 힙 사용

pq: 최대 힙
pq2: 두 수 a,b를 a+b, b+a로 붙여서 수가 더 큰 쪽이 최대가 되는 힙

struct compare //우선순위 큐 비교연산자 
	bool operator()(ll &a, ll &b) //() 연산자 오버로딩
		//a,b string화 후 a+b string 생성
		string a+b
		string b+a
		//a+b,b+a string unsigned long long 형으로 변환
		ull a+b
		ull b+a

		//비교 (a+b가 더 크면 a가 우선순위가 높음=> false 반환, b+a가 더 크면 b가 우선순위가 높음 => true 반환)
		return a+b < b+a 

cin k n
for k
	cin num long long
	pq push num //긴 자릿수가 우선순위가 높은 힙에 넣기

biggest = pq top pop //최댓값 (최대 자릿수 or 최대 수) 뽑기
for i = k i<=n i++
	pq2 push biggest //두 수를 붙여서 수가 더 큰 쪽이 우선순위가 높은 힙에 넣기

while pq not empty
	num = pq top pop
	pq2 push num

while pq2 not empty
	cout pq2 top pop
*/
