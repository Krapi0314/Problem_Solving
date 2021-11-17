/*
BOJ 19598번: 최소 회의실 개수

시간 제한: 2초
메모리 제한: 256 MB

문제
서준이는 아빠로부터 N개의 회의를 모두 진행할 수 있는 최소 회의실 개수를 구하라는 미션을 받았다. 각 회의는 시작 시간과 끝나는 시간이 주어지고 한 회의실에서 동시에 두 개 이상의 회의가 진행될 수 없다. 단, 회의는 한번 시작되면 중간에 중단될 수 없으며 한 회의가 끝나는 것과 동시에 다음 회의가 시작될 수 있다. 회의의 시작 시간은 끝나는 시간보다 항상 작다. N이 너무 커서 괴로워 하는 우리 서준이를 도와주자.

입력
첫째 줄에 배열의 크기 N(1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N+1 줄까지 공백을 사이에 두고 회의의 시작시간과 끝나는 시간이 주어진다. 시작 시간과 끝나는 시간은 231?1보다 작거나 같은 자연수 또는 0이다.

출력
첫째 줄에 최소 회의실 개수를 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
vector<pair<int,int>> v; // first: time, second: cnt + 1 or cnt - 1
int a,b;
int cnt;
int ans;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> a >> b;
		v.push_back(make_pair(a, 1));
		v.push_back(make_pair(b, -1));
	}
	
	sort(v.begin(), v.end());
	
	for(int i=0; i<(int)v.size(); i++) {
		cnt += v[i].second;
		
		ans = max(ans, cnt);
	}
	
	cout << ans;
}

// greedy
/*
cnt: 현재 진행 중인 회의의 수
N개의 회의를 모두 진행할 수 있는 최소 회의실의 개수 = cnt의 최댓값
회의 시작 시 cnt++, 회의 끝날 시 cnt--
회의의 시작과 끝은 따로 저장 후 시간 순으로 sort, 이후 순서대로 꺼내면서 cnt 측정, 최댓값 찾기 
*/ 
