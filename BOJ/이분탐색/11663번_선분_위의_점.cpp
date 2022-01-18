/*
BOJ 11663번: 선분 위의 점

시간 제한: 1 초
메모리 제한: 256 MB

문제 
일차원 좌표상의 점 N개와 선분 M개가 주어진다. 이때, 각각의 선분 위에 입력으로 주어진 점이 몇 개 있는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 점의 개수 N과 선분의 개수 M이 주어진다. (1 ≤ N, M ≤ 100,000) 둘째 줄에는 점의 좌표가 주어진다. 두 점이 같은 좌표를 가지는 경우는 없다. 셋째 줄부터 M개의 줄에는 선분의 시작점과 끝점이 주어진다. 입력으로 주어지는 모든 좌표는 1,000,000,000보다 작거나 같은 자연수이다.

출력
입력으로 주어진 각각의 선분 마다, 선분 위에 입력으로 주어진 점이 몇 개 있는지 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAX 100000

int n,m;
int point[MAX];
int a, b;
int lower_idx, upper_idx;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> point[i];
	}
	
	sort(point+0, point+n);
	
	for(int i=0; i<m; i++) {
		cin >> a >> b;
		
		lower_idx = lower_bound(point, point+n, a) - point;
		upper_idx = upper_bound(point, point+n, b) - point;
		
		cout << upper_idx - lower_idx << "\n";
	}
	
	return 0;
}

/*
이분 탐색 
*/
