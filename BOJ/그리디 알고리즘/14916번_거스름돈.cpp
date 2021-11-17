/*
BOJ 14916번: 거스름돈

시간 제한: 2초
메모리 제한: 512 MB

문제
춘향이는 편의점 카운터에서 일한다.
손님이 2원짜리와 5원짜리로만 거스름돈을 달라고 한다. 2원짜리 동전과 5원짜리 동전은 무한정 많이 가지고 있다. 동전의 개수가 최소가 되도록 거슬러 주어야 한다. 거스름돈이 n인 경우, 최소 동전의 개수가 몇 개인지 알려주는 프로그램을 작성하시오.
예를 들어, 거스름돈이 15원이면 5원짜리 3개를, 거스름돈이 14원이면 5원짜리 2개와 2원짜리 2개로 총 4개를, 거스름돈이 13원이면 5원짜리 1개와 2원짜리 4개로 총 5개를 주어야 동전의 개수가 최소가 된다.

입력
첫째 줄에 거스름돈 액수 n(1 ≤ n ≤ 100,000)이 주어진다.

출력
거스름돈 동전의 최소 개수를 출력한다. 만약 거슬러 줄 수 없으면 -1을 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
int cnt;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	cnt = n / 5;
	n = n % 5;
	
	if(cnt >= 1 && n % 2 != 0) {
		cnt--;
		n += 5;
	}
	
	cnt += n / 2;
	n = n % 2;

	if(n == 0) {
		cout << cnt;
	}
	else {
		cout << "-1";
	}
}

/*
greedy

cin n

cnt = n / 5;
n = n % 5;

if cnt >= 1 & n % 2 != 0
	cnt--
	n += 5

n = n % 2	
cnt += n / 2

if n != 0
	cout cnt	
else
	cout -1		
*/
