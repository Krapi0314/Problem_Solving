/*
baekjoon 1213��: �Ӹ���� �����

�ð� ����: 2��
�޸� ����: 128 MB

����
���Ѽ��� �ӹ����� ���� ����ϴ� �����̴�.
���Ѽ��� ���󿡼� �Ӹ������ ���ڿ��� �ʹ� �����ϱ� ������, ���� ������ ����ؼ� �ӹ����� �Ӹ������ �������ַ��� �Ѵ�.
�ӹ����� ���Ѽ��� ���� �̸����� �Ӹ������ ������� �ϴµ�, ���Ѽ��� ���� �̸��� ���ĺ� ������ ������ �ٲ㼭 �Ӹ������ ������� �Ѵ�.
�ӹ����� ���� ���Ѽ��� ���� �̸��� �Ӹ�������� �ٲٴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���Ѽ��� ���� �̸��� �ִ�. ���ĺ� �빮�ڷθ� �� �ִ� 50�����̴�.

���
ù° �ٿ� ������ ������ ����Ѵ�. ���� �Ұ����� ���� "I'm Sorry Hansoo"�� ����Ѵ�. ������ ���� ���� ��쿡�� ���������� �ռ��� ���� ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

string s;
int alphabet[26];
int cnt;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> s;
	
	sort(s.begin(), s.end());
	
	// Ȧ���� �����ϴ� ���ĺ��� 2�� �̻��̸� �Ұ��� 
	for(int i=0; i<s.size(); i++) {
		alphabet[s[i]-'A']++;
	}
	for(int i=0; i<26; i++) {
		if(alphabet[i] % 2 != 0) {
			cnt++;
		}	
	}
	
	if(cnt >= 2) {
		cout << "I'm Sorry Hansoo";
		return 0;
	}
	else {
		// A���� Z���� �� ���ĺ� ����/2 ��ŭ ��� 
		for(int i = 0;i<26; i++) {
			for(int j=0; j<alphabet[i]/2; j++) {
				char ch = i + 'A';
				cout << ch;
			}
		}
		
		// Ȧ�� ���ĺ� ���
		for(int i = 0; i<26; i++) {
			if(alphabet[i] % 2 != 0) {
				char ch = i + 'A';
				cout << ch;
			}	
		}
		
		// �ݴ�� Z���� A���� �� ���ĺ� ����/2 ��ŭ ��� 
		for(int i = 25; i>=0; i--) {
			for(int j=0; j<alphabet[i]/2; j++) {
				char ch = i + 'A';
				cout << ch;
			}
		}
	}
}
