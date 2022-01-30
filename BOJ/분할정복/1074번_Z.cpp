/*
BOJ 1074번: Z

시간 제한: 0.5 초 (추가 시간 없음)
메모리 제한: 512 MB

문제
한수는 크기가 2N × 2N인 2차원 배열을 Z모양으로 탐색하려고 한다. 예를 들어, 2×2배열을 왼쪽 위칸, 오른쪽 위칸, 왼쪽 아래칸, 오른쪽 아래칸 순서대로 방문하면 Z모양이다.
N > 1인 경우, 배열을 크기가 2N-1 × 2N-1로 4등분 한 후에 재귀적으로 순서대로 방문한다.
N이 주어졌을 때, r행 c열을 몇 번째로 방문하는지 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 N, r, c가 주어진다.

출력
r행 c열을 몇 번째로 방문했는지 출력한다.

제한
1 ≤ N ≤ 15
0 ≤ r, c < 2N 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, r, c;
int cnt; 

void visits(int y, int x, int n) {
	if(n == 1) {
		if(y == r && x == c) {
			cout << cnt;
		}
		else {
			cnt++;	
		}
		return;
	}
	
	int div = n/2;
	// n번째 사분면: Z를 기준으로 한 순서 
	// (r,c)가 4번쨰 사분면에 위치할 경우: 1~3번쨰 사분면까지는 굳이 방문하지 않고 해당 사분면들의 넓이만큼 cnt에 더해주고, 이후 4번째 사분면 방문 
	if(r >= y+div && c >= x+div) {
		cnt += (div*div)*3;
		visits(y+div, x+div, div);
	}
	// (r,c)가 3번쨰 사분면에 위치할 경우: 1~2번쨰 사분면까지는 굳이 방문하지 않고 해당 사분면들의 넓이만큼 cnt에 더해주고, 이후 3번째 사분면 방문 
	else if(r >= y+div) {
		cnt += (div*div)*2;
		visits(y+div, x, div);
	}
	// (r,c)가 2번쨰 사분면에 위치할 경우: 1번쨰 사분면은 굳이 방문하지 않고 해당 사분면의 넓이만큼 cnt에 더해주고, 이후 2번째 사분면 방문 
	else if(c >= x+div) {
		cnt += div*div;
		visits(y, x+div, div);
	}
	// (r,c)가 1번쨰 사분면에 위치할 경우: 그대로 1번째 사분면 방문 
	else {
		visits(y, x, div);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> r >> c;
	
	visits(0,0, pow(2,N));
	return 0;
}

/* 
분할정복 
*/ 
