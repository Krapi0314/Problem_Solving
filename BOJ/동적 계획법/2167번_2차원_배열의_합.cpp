/*
BOJ 2167번: 2차원 배열의 합

시간 제한: 2초
메모리 제한: 128 MB

문제
2차원 배열이 주어졌을 때 (i, j) 위치부터 (x, y) 위치까지에 저장되어 있는 수들의 합을 구하는 프로그램을 작성하시오. 배열의 (i, j) 위치는 i행 j열을 나타낸다.

입력
첫째 줄에 배열의 크기 N, M(1 ≤ N, M ≤ 300)이 주어진다. 다음 N개의 줄에는 M개의 정수로 배열이 주어진다. 배열에 포함되어 있는 수는 절댓값이 10,000보다 작거나 같은 정수이다. 그 다음 줄에는 합을 구할 부분의 개수 K(1 ≤ K ≤ 10,000)가 주어진다. 다음 K개의 줄에는 네 개의 정수로 i, j, x, y가 주어진다(i ≤ x, j ≤ y).

출력
K개의 줄에 순서대로 배열의 합을 출력한다. 배열의 합은 231-1보다 작거나 같다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int i,j,x,y;
int n,m,k;
int dp[301][301]; 
int num;
int ans;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin >> num;
			
			dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + num;
		}
	}
	
	cin >> k;
	while(k--) {
		ans = 0;
		cin >> i >> j >> x >> y;
		
		ans = dp[x][y] - dp[x][j-1] - dp[i-1][y] + dp[i-1][j-1];
		
		cout << ans << "\n";
	}
}

/*
BOJ 11660번: 구간 합 구하기 5의 제한이 더 작은 문제: DP, 구간합 
!! (x,y)에서 (i,j)을 빼주는 것이 아니라, i-1 열,j-1 행에 해당하는 영역까지를 빼 주어야 함 

아래의 단순 구현도 가능 (제한이 작아서 가능) 
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int i,j,x,y;
int n,m,k;
int arr[301][301]; 
int ans;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin >> arr[i][j];
		}
	}
	
	cin >> k;
	while(k--) {
		ans = 0;
		cin >> i >> j >> x >> y;
		
		for(int a=i; a<=x; a++) {
			for(int b=j; b<=y; b++) {
				ans += arr[a][b];
			}
		}
		
		cout << ans << "\n";
	}
}
*/
