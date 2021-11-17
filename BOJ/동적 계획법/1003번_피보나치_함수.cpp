/*
BOJ 1003번: 피보나치 함수

시간 제한: 0.25초 (추가 시간 없음)
메모리 제한: 128 MB
 
문제
다음 소스는 N번째 피보나치 수를 구하는 C++ 함수이다.

int fibonacci(int n) {
    if (n == 0) {
        printf("0");
        return 0;
    } else if (n == 1) {
        printf("1");
        return 1;
    } else {
        return fibonacci(n?1) + fibonacci(n?2);
    }
}

fibonacci(3)을 호출하면 다음과 같은 일이 일어난다.

fibonacci(3)은 fibonacci(2)와 fibonacci(1) (첫 번째 호출)을 호출한다.
fibonacci(2)는 fibonacci(1) (두 번째 호출)과 fibonacci(0)을 호출한다.
두 번째 호출한 fibonacci(1)은 1을 출력하고 1을 리턴한다.
fibonacci(0)은 0을 출력하고, 0을 리턴한다.
fibonacci(2)는 fibonacci(1)과 fibonacci(0)의 결과를 얻고, 1을 리턴한다.
첫 번째 호출한 fibonacci(1)은 1을 출력하고, 1을 리턴한다.
fibonacci(3)은 fibonacci(2)와 fibonacci(1)의 결과를 얻고, 2를 리턴한다.
1은 2번 출력되고, 0은 1번 출력된다. N이 주어졌을 때, fibonacci(N)을 호출했을 때, 0과 1이 각각 몇 번 출력되는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다.
각 테스트 케이스는 한 줄로 이루어져 있고, N이 주어진다. N은 40보다 작거나 같은 자연수 또는 0이다.

출력
각 테스트 케이스마다 0이 출력되는 횟수와 1이 출력되는 횟수를 공백으로 구분해서 출력한다.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, T;
//0의 호출 횟수를 저장할 cache (배열)
int zero_cache[41];

int fibo_cnt_zero(int n) //n번쨰 피보나치 값을 호출하면서 호출된 0의 횟수 구하기
{
	if (n == 0)
		return 1;
	else if (n == 1)
		return 0;

	int& ret = zero_cache[n];
	if (zero_cache[n] != -1) //cache에 값이 저장되어 있으면 중복 계산하지 않고 저장되어 있는 값 사용
		return ret;

	return ret = fibo_cnt_zero(n - 1) + fibo_cnt_zero(n - 2);
}

int one_cache[41];

int fibo_cnt_one(int n) //n번쨰 피보나치 값을 호출하면서 호출된 0의 횟수 구하기
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;

	int& ret = one_cache[n];
	if (one_cache[n] != -1) //cache에 값이 저장되어 있으면 중복 계산하지 않고 저장되어 있는 값 사용
		return ret;

	return ret = fibo_cnt_one(n - 1) + fibo_cnt_one(n - 2);
}

int main(void)
{
	memset(zero_cache, -1, sizeof(zero_cache));
	memset(one_cache, -1, sizeof(one_cache));

	scanf("%d", &T);
	
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &n);

		printf("%d %d\n", fibo_cnt_zero(n), fibo_cnt_one(n));
	}
	
}

/*
* 동적 계획법 DP+
* 1. 입력
* 2. 재귀 함수로 파보나치에서 1과 0이 호출되는 횟수 계산 (호출횟수는 피보나치와 같은 방식으로 계산됨)
* 3. 메모이제이션으로 중복되는 부분 문제 중복 계산하지 않기 (속도 향샹)
* 4. 출력
*
* 
* 
* */
