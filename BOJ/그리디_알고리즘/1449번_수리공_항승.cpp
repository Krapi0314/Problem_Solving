/*
BOJ 1449번: 수리공 항승

시간 제한: 2초
메모리 제한: 128 MB

문제
항승이는 품질이 심각하게 나쁜 수도 파이프 회사의 수리공이다. 항승이는 세준 지하철 공사에서 물이 샌다는 소식을 듣고 수리를 하러 갔다.
파이프에서 물이 새는 곳은 신기하게도 가장 왼쪽에서 정수만큼 떨어진 거리만 물이 샌다.
항승이는 길이가 L인 테이프를 무한개 가지고 있다.
항승이는 테이프를 이용해서 물을 막으려고 한다. 항승이는 항상 물을 막을 때, 적어도 그 위치의 좌우 0.5만큼 간격을 줘야 물이 다시는 안 샌다고 생각한다.
물이 새는 곳의 위치와, 항승이가 가지고 있는 테이프의 길이 L이 주어졌을 때, 항승이가 필요한 테이프의 최소 개수를 구하는 프로그램을 작성하시오. 테이프를 자를 수 없고, 테이프를 겹쳐서 붙이는 것도 가능하다.

입력
첫째 줄에 물이 새는 곳의 개수 N과 테이프의 길이 L이 주어진다. 둘째 줄에는 물이 새는 곳의 위치가 주어진다. N과 L은 1,000보다 작거나 같은 자연수이고, 물이 새는 곳의 위치는 1,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 항승이가 필요한 테이프의 개수를 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, l;
vector<int> v;
int ans;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> l;
	for(int i=0; i<n; i++) {
		int num;
		cin >> num;
		v.push_back(num); 
	}
	sort(v.begin(), v.end(), greater<int>());
	
	while(!v.empty()) {
		double left = (double)v.back() - 0.5; v.pop_back();
		double right = left + l;
		
		while(!v.empty() && (double)v.back() + 0.5 <= right) {
			v.pop_back();
		}
		
		ans++;
	}
	
	cout << ans;
}

/*
greedy: 앞에 있는 파이프부터 차례차례 테이프를 붙이면 최소한으로 테이프를 사용할 수 있다
*/
