/*
baekjoon 18870��: ��ǥ ����

�ð� ����: 2 ��
�޸� ����: 512 MB

����
������ ���� N���� ��ǥ X1, X2, ..., XN�� �ִ�. �� ��ǥ�� ��ǥ ������ �����Ϸ��� �Ѵ�.
Xi�� ��ǥ ������ ��� X'i�� ���� Xi > Xj�� �����ϴ� ���� �ٸ� ��ǥ�� ������ ���ƾ� �Ѵ�.
X1, X2, ..., XN�� ��ǥ ������ ������ ��� X'1, X'2, ..., X'N�� ����غ���.

�Է�
ù° �ٿ� N�� �־�����.
��° �ٿ��� ���� �� ĭ���� ���е� X1, X2, ..., XN�� �־�����.

���
ù° �ٿ� X'1, X'2, ..., X'N�� ���� �� ĭ���� �����ؼ� ����Ѵ�.

����
1 �� N �� 1,000,000
-109 �� Xi �� 109 
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
����
!! ��ǥ������ ������������ ���� �� �ߺ��� �����Ͽ� ���� �迭������ �ش� ��ǥ�� �ε��� ���� ��ǥ���� �� 

-- �ٸ� Ǯ�� (����ü Ȱ��) --
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
