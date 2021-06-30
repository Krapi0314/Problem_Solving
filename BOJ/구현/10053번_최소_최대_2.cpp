/*
BOJ 20053: 최소, 최대 2

시간 제한: 1초
메모리 제한: 256 MB

문제
N개의 정수가 주어진다. 이때, 최솟값과 최댓값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T (1 ≤ T ≤ 10)가 주어진다. 각 테스트 케이스는 두 줄로 이루어져 있다.
각 테스트 케이스의 첫째 줄에 정수의 개수 N (1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄에는 N개의 정수를 공백으로 구분해서 주어진다. 모든 정수는 -1,000,000보다 크거나 같고, 1,000,000보다 작거나 같은 정수이다.

출력
각 테스트 케이스마다 주어진 정수 N개의 최솟값과 최댓값을 공백으로 구분해 한 줄에 하나씩 차례대로 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int arr[1000000];
int t,n;
int Max,Min;
bool flag;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> t;
	while(t--) {
		flag = true;
		cin >> n;
		for(int i=0; i<n; i++) {
			cin >> arr[i];
			if(flag) {
				Max = arr[0]; Min = arr[0];
				flag = false;
			}
			Max = max(Max,arr[i]);
			Min = min(Min,arr[i]);
		}
		cout << Min << " " << Max << "\n";
	}
}

/*
implement
*/
