/*
baekjoon 11663��: ���� ���� ��

�ð� ����: 1 ��
�޸� ����: 256 MB

���� 
������ ��ǥ���� �� N���� ���� M���� �־�����. �̶�, ������ ���� ���� �Է����� �־��� ���� �� �� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� ���� N�� ������ ���� M�� �־�����. (1 �� N, M �� 100,000) ��° �ٿ��� ���� ��ǥ�� �־�����. �� ���� ���� ��ǥ�� ������ ���� ����. ��° �ٺ��� M���� �ٿ��� ������ �������� ������ �־�����. �Է����� �־����� ��� ��ǥ�� 1,000,000,000���� �۰ų� ���� �ڿ����̴�.

���
�Է����� �־��� ������ ���� ����, ���� ���� �Է����� �־��� ���� �� �� �ִ��� ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAX 100000

int n,m;
int point[MAX];
int a, b;
int lower_idx, upper_idx;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> point[i];
	}
	
	sort(point+0, point+n);
	
	for(int i=0; i<m; i++) {
		cin >> a >> b;
		
		lower_idx = lower_bound(point, point+n, a) - point;
		upper_idx = upper_bound(point, point+n, b) - point;
		
		cout << upper_idx - lower_idx << "\n";
	}
	
	return 0;
}

/*
�̺� Ž�� 
*/
