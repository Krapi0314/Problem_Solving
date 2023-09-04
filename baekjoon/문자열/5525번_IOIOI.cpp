/*
baekjoon 5525��: IOIOI

�ð� ����: 1 ��
�޸� ����: 256 MB

����
N+1���� I�� N���� O�� �̷���� ������, I�� O�� ����� ������ ���ڿ��� PN�̶�� �Ѵ�.
P1 IOI
P2 IOIOI
P3 IOIOIOI
PN IOIOI...OI (O�� N��)
I�� O�θ� �̷���� ���ڿ� S�� ���� N�� �־����� ��, S�ȿ� PN�� �� ���� ���ԵǾ� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� �־�����. ��° �ٿ��� S�� ���� M�� �־�����, ��° �ٿ� S�� �־�����.

���
S�� PN�� �� ���� ���ԵǾ� �ִ��� ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, m;
string s, p;
int ans;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cin >> m;
	cin >> s;
	
	bool flag = true;
	vector<int> pi(2*n+1, 0);
	for(int i=0; i<2*n+1; i++) {
		if(flag) {
			p += "I";
			flag = false;
		}
		else {
			p += "O";
			flag = true;
		}
	}
	
	for(int i=2; i<2*n+1; i++) {
		pi[i] = i-1;
	}
	
	int j = 0;
	for(int i=0; i<m; i++) {
		while(j>0 && s[i] != p[j]) {
			j = pi[j-1];
		}
		if(s[i] == p[j]) {
			if(j == 2*n) {
				ans++;
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
	
	cout << ans;
	return 0;
}

/* 
���ڿ�: KMP
*/ 
