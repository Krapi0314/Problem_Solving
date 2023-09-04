/*
baekjoon 1343��: �������̳�

�ð� ����: 2��
�޸� ����: 128 MB

����
�ν��̴� ������ ���� �������̳� 2���� ���Ѱ���ŭ ������ �ִ�. AAAA�� BB
���� '.'�� 'X'�� �̷���� �������� �־����� ��, �ν��̴� ��ħ���� 'X'�� ��� �������̳�� �������� �Ѵ�. �̶�, '.'�� �������̳�� ������ �� �ȴ�.
�������̳�� ��� ���� �������� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �������� �־�����. �������� ũ��� �ִ� 500�̴�.

���
ù° �ٿ� ���������� ���� �ռ��� ���� ����Ѵ�. ���� ���� �� ������ -1�� ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int a,b;
int j;
int len;
string s;
bool flag;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> s;
	
	bool exc = true;
	//exception: only . exists
	for(int i=0; i<s.size(); i++) {
		if(s[i] == 'X')
			exc = false;
	}
	if(exc) {
		cout << s;
		return 0;
	}

	
	for(int i=0; i<s.size(); i++) {
		if(s[i] == 'X') {
			j = i;
			len = 0;
			flag = true;
			
			while(s[j] == 'X') {
				len++;
				j++;
			}
			
			if(len % 2 != 0) {
				flag = false;
				break;
			}
			
			a = len / 4;
			len %= 4;
			b = len / 2;
		
			for(int k=0; k<4*a; k++) {
				s[i++] = 'A';
			}
			for(int k=0; k<2*b; k++) {
				s[i++] = 'B';
			}
		}
	}
	
	if(flag) {
		cout << s;
	}
	else {
		cout << "-1";
	}
	
	return 0;
}

/*
greedy

exception: only . exists

cin string s

for s
	if s[i] = 'X'
		j = i
		len = 0		
		flag  true
		
		while s[j] == 'X'
		 	len++
		 	j++
		 	
		if len % 2 != 0
			flag false
			break
		
		a = len / 4
		len %= 4
		b = len / 2
			
		for a
			s[i++] = 'A'
		for b
			s[i++] = 'B'		
		
if flag
	cout s
else
	cout -1
*/
