/*
baekjoon 1107��: ������

�ð� ����: 2 ��
�޸� ����: 256 MB

����
�����̴� TV�� ���� �ִ�. �����̴� ä���� �������� ������, ��ư�� �ʹ� ���� ������ �ٶ���, �Ϻ� ���� ��ư�� ���峵��.
���������� ��ư�� 0���� 9���� ����, +�� -�� �ִ�. +�� ������ ���� �����ִ� ä�ο��� +1�� ä�η� �̵��ϰ�, -�� ������ -1�� ä�η� �̵��Ѵ�. ä�� 0���� -�� ���� ��쿡�� ä���� ������ �ʰ�, ä���� ���Ѵ� ��ŭ �ִ�.
�����̰� ���� �̵��Ϸ��� �ϴ� ä���� N�̴�. � ��ư�� ���峵���� �־����� ��, ä�� N���� �̵��ϱ� ���ؼ� ��ư�� �ּ� �� �� �������ϴ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. 
�����̰� ���� ���� �ִ� ä���� 100���̴�.

�Է�
ù° �ٿ� �����̰� �̵��Ϸ��� �ϴ� ä�� N (0 �� N �� 500,000)�� �־�����.  ��° �ٿ��� ���峭 ��ư�� ���� M (0 �� M �� 10)�� �־�����. ���峭 ��ư�� �ִ� ��쿡�� ��° �ٿ��� ���峭 ��ư�� �־�����, ���� ��ư�� ���� �� �־����� ���� ����.

���
ù° �ٿ� ä�� N���� �̵��ϱ� ���� ��ư�� �ּ� �� �� ������ �ϴ����� ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, nn, m;
int n_len, num;
bool broken[10];
int ans;

// num: �Է� ������ ä��, n: �̵��Ϸ��� �ϴ� ä�� 
void dfs(int num, int len) {
	// num�� �� ���̶� �Է����鼭 num�� �ڸ����� n�� �ڸ������� 1 ���� �� 
	if(len > 0 && len == n_len - 1) {
		ans = min(ans, abs(n-num) + len);
	}
	// num�� �ڸ����� n�� �ڸ����� ���� �� 
	if(len == n_len) {
		ans = min(ans, abs(n-num) + len);
	}
	// num�� �ڸ����� n�� �ڸ������� 1 Ŭ ��
	if(len == n_len + 1) {
		ans = min(ans, abs(n-num) + len);
		return;
	}
	
	for(int i=0; i<10; i++) {
		if(!broken[i]) {
			dfs(num * 10 + i, len + 1);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	cin >> m;
	for(int i=0; i<m; i++) {
		cin >> num;
		broken[num] = true;
	}
	
	nn = n;
	do {
		nn /= 10;
		n_len++;
	} while(nn != 0);
	
	ans = INT_MAX;
	dfs(0, 0);
	ans = min(ans, abs(100-n));
	
	cout << ans;
	return 0;
}

/* 
Bruce Force
*/ 
