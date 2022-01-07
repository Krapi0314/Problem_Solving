/*
BOJ 11728번: 배열 합치기

시간 제한: 1.5 초
메모리 제한: 256 MB

문제
정렬되어있는 두 배열 A와 B가 주어진다. 두 배열을 합친 다음 정렬해서 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 배열 A의 크기 N, 배열 B의 크기 M이 주어진다. (1 ≤ N, M ≤ 1,000,000)
둘째 줄에는 배열 A의 내용이, 셋째 줄에는 배열 B의 내용이 주어진다. 배열에 들어있는 수는 절댓값이 109보다 작거나 같은 정수이다.

출력
첫째 줄에 두 배열을 합친 후 정렬한 결과를 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAX 1000000

int n,m;
int a[MAX];
int b[MAX];
int a_idx, b_idx;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	for(int i=0; i<m; i++) {
		cin >> b[i];
	}
	
	while(a_idx < n && b_idx < m) {
		if(a[a_idx] <= b[b_idx]) {
			cout << a[a_idx++] << " ";
		}
		else {
			cout << b[b_idx++] << " ";
		}
	}
	
	if(a_idx == n) {
		for(int i=b_idx; i<m; i++) {
			cout << b[i] << " ";
		}
	}
	else {
		for(int i=a_idx; i<n; i++) {
			cout << a[i] << " ";
		}
	}
	
	return 0;
}

/*
투 포인터 
*/
