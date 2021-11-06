/*
BOJ 9375번: 패션왕 신해빈

시간 제한: 1초
메모리 제한: 128 MB

문제
해빈이는 패션에 매우 민감해서 한번 입었던 옷들의 조합을 절대 다시 입지 않는다. 예를 들어 오늘 해빈이가 안경, 코트, 상의, 신발을 입었다면, 다음날은 바지를 추가로 입거나 안경대신 렌즈를 착용하거나 해야한다. 해빈이가 가진 의상들이 주어졌을때 과연 해빈이는 알몸이 아닌 상태로 며칠동안 밖에 돌아다닐 수 있을까?

입력
첫째 줄에 테스트 케이스가 주어진다. 테스트 케이스는 최대 100이다.
각 테스트 케이스의 첫째 줄에는 해빈이가 가진 의상의 수 n(0 ≤ n ≤ 30)이 주어진다.
다음 n개에는 해빈이가 가진 의상의 이름과 의상의 종류가 공백으로 구분되어 주어진다. 같은 종류의 의상은 하나만 입을 수 있다.
모든 문자열은 1이상 20이하의 알파벳 소문자로 이루어져있으며 같은 이름을 가진 의상은 존재하지 않는다.

출력
각 테스트 케이스에 대해 해빈이가 알몸이 아닌 상태로 의상을 입을 수 있는 경우를 출력하시오. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int t;
int n;
string a,b;
map<string, int> m;
map<string, int>::iterator iter;
int ans;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> t;
	while(t--) {
		ans = 1;
		m.clear();
		
		cin >> n;
		
		for(int i=0; i<n; i++) {
			cin >> a >> b;
			m[b]++;
		}
		
		iter = m.begin();
		while(iter != m.end()) {
			ans *= (iter->second + 1);
			iter++;
		}
		
		cout << ans - 1 << "\n";
	}
}

/* 
(의상1의 개수 + 1 (의상을 안 입는 경우)) * (의상 2의 개수 + ...) * ... - 1 (아무것도 안 입는 경우) 
자료구조: map<string(key), int(value)> 자료구조 (헤시 테이블)로 key에 해당하는 string이 insert 되면 int count++ 
ex: (2 + 1) * (1 + 1) - 1 = 5
ex: (3 + 1) - 1 = 3
*/ 
