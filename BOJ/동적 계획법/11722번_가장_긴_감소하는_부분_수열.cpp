/*
BOJ 11722번: 가장 긴 감소하는 부분 수열

시간 제한: 1초
메모리 제한: 256 MB

문제
수열 A가 주어졌을 때, 가장 긴 감소하는 부분 수열을 구하는 프로그램을 작성하시오.
예를 들어, 수열 A = {10, 30, 10, 20, 20, 10} 인 경우에 가장 긴 감소하는 부분 수열은 A = {10, 30, 10, 20, 20, 10}  이고, 길이는 3이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.
둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 가장 긴 감소하는 부분 수열의 길이를 출력한다.
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
int arr[1000];
int dp[1000];
int Max;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	
	for(int i=0; i<n; i++) {
		dp[i] = 1;
		
		for(int j=0; j<i; j++) {
			if(arr[i] < arr[j]) {
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
		
		Max = max(Max, dp[i]);
	} 
	
	cout << Max;
}

/*
dp, LIS 응용문제 
dp[i]: i 까지의 수열에서 가장 긴 감소하는 부분 수열의 길이
점화식: dp[i] = i-1 까지의 수열에서 가장 긴 감소하는 부분 수열의 길이 dp[j] + 1 (단, arr[i] < arr[j])  
*/
