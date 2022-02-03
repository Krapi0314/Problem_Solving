/*
BOJ 18870번: 좌표 압축

시간 제한: 2 초
메모리 제한: 512 MB

문제
수직선 위에 N개의 좌표 X1, X2, ..., XN이 있다. 이 좌표에 좌표 압축을 적용하려고 한다.
Xi를 좌표 압축한 결과 X'i의 값은 Xi > Xj를 만족하는 서로 다른 좌표의 개수와 같아야 한다.
X1, X2, ..., XN에 좌표 압축을 적용한 결과 X'1, X'2, ..., X'N를 출력해보자.

입력
첫째 줄에 N이 주어진다.
둘째 줄에는 공백 한 칸으로 구분된 X1, X2, ..., XN이 주어진다.

출력
첫째 줄에 X'1, X'2, ..., X'N을 공백 한 칸으로 구분해서 출력한다.

제한
1 ≤ N ≤ 1,000,000
-109 ≤ Xi ≤ 109 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, x;
vector<int> original;
vector<int> compress;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> x;
		original.push_back(x);
		compress.push_back(x);
	}
	
	sort(compress.begin(), compress.end());
	compress.erase(unique(compress.begin(), compress.end()), compress.end());
	
	for(int i=0; i<n; i++) {
		cout << lower_bound(compress.begin(), compress.end(), original[i]) - compress.begin() << " ";
	}
	return 0;
}

/* 
정렬
!! 좌표값들을 오름차순으로 정렬 후 중복을 제거하여 얻은 배열에서의 해당 좌표의 인덱스 값이 좌표압축 값 

-- 다른 풀이 (구조체 활용) --
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef struct _node {
	int idx;
	int coordinate;
	int compressed_coordinate;	
} Node;

int n, x;
int cnt;
vector<Node> v;

bool compare1(Node a, Node b) {
	return a.coordinate < b.coordinate;
}

bool compare2(Node a, Node b) {
	return a.idx < b.idx;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> x;
		Node node;
		node.idx = i;
		node.coordinate = x;
		v.push_back(node);
	}
	
	sort(v.begin(), v.end(), compare1);
	v[0].compressed_coordinate = cnt;
	for(int i=1; i<n; i++) {
		if(v[i].coordinate == v[i-1].coordinate) {
			v[i].compressed_coordinate = cnt;
		}
		else {
			v[i].compressed_coordinate = ++cnt;
		}
	}
	
	sort(v.begin(), v.end(), compare2);
	for(int i=0; i<n; i++) {
		cout << v[i].compressed_coordinate << " ";
	}
	return 0;
}
*/ 
