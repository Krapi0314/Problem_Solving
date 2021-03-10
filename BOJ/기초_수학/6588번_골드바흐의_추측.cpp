/*
BOJ 6588번: 골드바흐의 추측

시간 제한: 1초
메모리 제한: 256 MB

문제
1742년, 독일의 아마추어 수학가 크리스티안 골드바흐는 레온하르트 오일러에게 다음과 같은 추측을 제안하는 편지를 보냈다.
4보다 큰 모든 짝수는 두 홀수 소수의 합으로 나타낼 수 있다.
예를 들어 8은 3 + 5로 나타낼 수 있고, 3과 5는 모두 홀수인 소수이다. 또, 20 = 3 + 17 = 7 + 13, 42 = 5 + 37 = 11 + 31 = 13 + 29 = 19 + 23 이다.
이 추측은 아직도 해결되지 않은 문제이다.
백만 이하의 모든 짝수에 대해서, 이 추측을 검증하는 프로그램을 작성하시오.

입력
입력은 하나 또는 그 이상의 테스트 케이스로 이루어져 있다. 테스트 케이스의 개수는 100,000개를 넘지 않는다.
각 테스트 케이스는 짝수 정수 n 하나로 이루어져 있다. (6 ≤ n ≤ 1000000)
입력의 마지막 줄에는 0이 하나 주어진다.

출력
각 테스트 케이스에 대해서, n = a + b 형태로 출력한다. 이때, a와 b는 홀수 소수이다. 숫자와 연산자는 공백 하나로 구분되어져 있다. 만약, n을 만들 수 있는 방법이 여러 가지라면, b-a가 가장 큰 것을 출력한다. 또, 두 홀수 소수의 합으로 n을 나타낼 수 없는 경우에는 "Goldbach's conjecture is wrong."을 출력한다.
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

#define MAX 1000000

bool arr[MAX + 1];
vector<int> prime;
int n;
bool flag;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(arr, true, sizeof(arr));

	int sqrts = (int)sqrt(MAX);
    arr[1] = false;

    for (int i = 2; i <= sqrts; i++)
	{
		if (!arr[i])
			continue;

		for (int j = 2; i * j <= MAX; j++)
		{
			arr[i * j] = false;
		}
	}

	for (int i = 3; i <= MAX; i++)
	{
		if (arr[i] && i % 2 != 0)
			prime.push_back(i);
	}

	//main
	while (1)
	{
		flag = false;

		cin >> n;
		if (n == 0)
			break;

		for (int i = 0; n - prime[i] > 0 ; i++)
		{
			if (arr[n - prime[i]]) //짝수 - 홀수 = 홀수
			{
				cout << n << " = " << prime[i] << " + " << n-prime[i] << '\n';
				flag = true;
				break;
			}

		}

		if (!flag)
			cout << "Goldbach's conjecture is wrong.\n";
	}
}

/*
소수구하기: 에네토스테네스의 체
n = a + b 출력: 

MAX = 100000
bool arr[MAX]

for 2 to sqrt(MAX)
	if arr[i] false
		continue
	for 2 to i*j <= MAX
		arr[] false

for arr
	if arr true
		vector prime pushback arr

while 1
	flag = false
	cin n

	if n == 0
		break

	추측 검증: 한 소수를 p라고 하고, 골드바흐의 추측이 옳으면, n-p는 소수여야 함
	for prime
		if arr[n-prime[i]] == true (고른 소수가 p일떄, n-p가 소수이면 골드바흐 추측 옳음)
			cout << n << " = " << b << " + " << a << '\n';
			flag = true
			break
	if !flag
		cout << "Goldbach's conjecture is wrong." << '\n';
*/
