/*
baekjoon 11728��: �迭 ��ġ��

�ð� ����: 1.5 ��
�޸� ����: 256 MB

����
���ĵǾ��ִ� �� �迭 A�� B�� �־�����. �� �迭�� ��ģ ���� �����ؼ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �迭 A�� ũ�� N, �迭 B�� ũ�� M�� �־�����. (1 �� N, M �� 1,000,000)
��° �ٿ��� �迭 A�� ������, ��° �ٿ��� �迭 B�� ������ �־�����. �迭�� ����ִ� ���� ������ 109���� �۰ų� ���� �����̴�.

���
ù° �ٿ� �� �迭�� ��ģ �� ������ ����� ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAX 1000000

int n,m;
int a[MAX];
int b[MAX];
int a_idx, b_idx;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	for(int i=0; i<m; i++) {
		cin >> b[i];
	}
	
	while(a_idx < n && b_idx < m) {
		if(a[a_idx] <= b[b_idx]) {
			cout << a[a_idx++] << " ";
		}
		else {
			cout << b[b_idx++] << " ";
		}
	}
	
	if(a_idx == n) {
		for(int i=b_idx; i<m; i++) {
			cout << b[i] << " ";
		}
	}
	else {
		for(int i=a_idx; i<n; i++) {
			cout << a[i] << " ";
		}
	}
	
	return 0;
}

/*
�� ������ 
*/
