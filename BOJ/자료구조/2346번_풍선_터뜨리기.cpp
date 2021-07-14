/*
BOJ 2346번: 풍선 터뜨리기

시간 제한: 2초
메모리 제한: 4 MB 

문제
N개의 풍선이 있다. 각 풍선 안에는 -N부터 N까지의 수가 적혀있는 종이가 들어 있다. 이 풍선들을 다음과 같은 규칙으로 터뜨린다.
우선, 제일 처음에는 1번 풍선을 터뜨린다. 다음에는 풍선 안에 있는 종이를 꺼내어 그 종이에 적혀있는 값만큼 이동하여 다음 풍선을 터뜨린다. 양수가 적혀 있을 경우에는 오른쪽으로, 음수가 적혀 있을 때는 왼쪽으로 이동한다. 풍선은 원형으로 놓여 있다고 생각한다. 즉, 1번 풍선의 왼쪽에 N번 풍선이 있고, N번 풍선의 오른쪽에 1번 풍선이 있는 것이다. 이동할 때에는 이미 터진 풍선은 빼고 생각한다.
예를 들어 다섯 개의 풍선 안에 차례로 3, 2, 1, -3, -1이 적혀 있었다고 하자. 이 경우 3이 적혀 있는 1번 풍선, -3이 적혀 있는 4번 풍선, -1이 적혀 있는 5번 풍선, 1이 적혀 있는 3번 풍선, 2가 적혀 있는 2번 풍선의 순서대로 터지게 된다.

입력
첫째 줄에 자연수 N(1≤N≤1,000)이 주어진다. 다음 줄에는 차례로 각 풍선 안의 종이에 적혀 있는 수가 주어진다. 편의상 0은 적혀있지 않다고 가정하자.

출력
첫째 줄에 터진 풍선의 번호를 차례로 나열한다.
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

vector<pair<int,int>> v;
int n;
int num;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	for(int i=0; i<n; i++) {
		cin >> num;
		
		v.push_back(make_pair(num,i+1));
	}
	
	
	int idx = 0;
	int move = 0;
	int N = n;
	
	for(int i=0; i<N; i++) {
		cout << v[idx].second << " ";
		
		move = v[idx].first;
		if(move > 0)
			move--;
		
		v.erase(v.begin() + idx);
		
		idx += move;
		if(--n == 0) // n = 0이면 나머지 연산 불가 
			break;
		
		idx = (idx >= 0) ? (idx) : (n + idx % n);
		idx %= n;
	}
} 

// 원형 리스트
// vector, list 모두 erase 인터페이스  사용 가능 
