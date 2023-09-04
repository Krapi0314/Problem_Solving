/*
baekjoon 16916��: �κ� ���ڿ�

�ð� ����: 1 ��
�޸� ����: 512 MB

����
���ڿ� S�� �κ� ���ڿ��̶�, ���ڿ��� ���ӵ� �Ϻθ� �ǹ��Ѵ�.
���� ���, "aek", "joo", "ekj"�� "baekjoon"�� �κ� ���ڿ��̰�, "bak", "p", "oone"�� �κ� ���ڿ��� �ƴϴ�.
���ڿ� S�� P�� �־����� ��, P�� S�� �κ� ���ڿ����� �ƴ��� �˾ƺ���.

�Է�
ù° �ٿ� ���ڿ� S, ��° �ٿ� ���ڿ� P�� �־�����. �� ���ڿ��� �� ���ڿ��� �ƴϸ�, ���̴� 100���� ���� �ʴ´�. ��, ���ĺ� �ҹ��ڷθ� �̷���� �ִ�.

���
P�� S�� �κ� ���ڿ��̸� 1, �ƴϸ� 0�� ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

string s,p;
bool ans;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ans = false;
	
	cin >> s;
	cin >> p;
	
	int n = s.size();
	int m = p.size(); 
	
	// ��ó��: pi �迭 ���ϱ�
	vector<int> pi(m,0);
	int j = 0;
	for(int i=1; i<m; i++) {
		while(j>0 && p[i] != p[j]) {
			j = pi[j-1];
		}
		if(p[i] == p[j]) {
			pi[i] = ++j;
		}
	}

	// KMP �˰���
	j = 0;
	for(int i=0; i<n; i++) {
		while(j>0 && s[i] != p[j]) {
			j = pi[j-1];
		}
		if(s[i] == p[j]) {
			if(j == m-1) {
				ans = true;
				break;
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
