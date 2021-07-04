/*
BOJ 14712번: 넴모넴모 (Easy)

시간 제한: 1초
메모리 제한: 512 MB

문제
네모는 뿌××× 게임에 깊은 감명을 받아, 직사각형 모양의 격자판과 “넴모”라는 수수께끼의 생물을 이용하는 “넴모넴모”라는 게임을 만들었다. 이 게임의 규칙은 아주 간단하다. 격자판의 비어 있는 칸을 임의로 골라 “넴모”를 하나 올려놓거나, “넴모”가 올라간 칸 네 개가 2 × 2 사각형을 이루는 부분을 찾아 그 위에 있는 “넴모”들을 모두 없애는 것을 질릴 때까지 반복하면 된다.
하지만 안타깝게도 게임은 정말 재미가 없었고, 네모는 아주 빨리 질려 버리고 말았다. 실망한 네모는 게임을 적당히 플레이하다가, “넴모”를 없애고 싶은데 격자판 위에 없앨 수 있는 “넴모”가 없으면 게임을 그만두기로 했다. 네모가 게임을 그만두었을 때 나올 수 있는 “넴모”의 배치의 가짓수를 구하여라.

입력
첫 번째 줄에 격자판의 행의 개수 N, 열의 개수 M(1 ≤ N, M ≤ 25, 1 ≤ N × M ≤ 25)이 공백으로 구분되어 주어진다.

출력
첫 번째 줄에 주어진 격자판에서 나올 수 있는, “넴모”들이 올라간 칸이 2 × 2 사각형을 이루지 않는 모든 배치의 가짓수를 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n,m;
int cnt;
bool arr[33][33];

void backtrack(int a, int b) {
	if(a == n && b == m+1) {
		cnt++;
		return;
	}
	
	for(int i=a; i<=n; i++) {
		for(int j=(i==a ? b : 1); j<=m; j++) {
			if(arr[i-1][j] && arr[i][j-1] && arr[i-1][j-1]) continue;
			else {
				arr[i][j] = true;
				backtrack(i,j+1);
				arr[i][j] = false;
			}
		}
	}
	
	cnt++; // n*m을 모두 순회함 -> 경우의 수 하나 만들어짐 
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	
	backtrack(1,1);
	
	cout << cnt;
}

// backtracking
