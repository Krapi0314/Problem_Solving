/*
baekjoon 1342��: ����� ���ڿ�

�ð� ����: 2��
�޸� ����: 256 MB

����
�ν��̿� �ؿ��̴� �ڱ� �濡�� ���ڿ��� �����ϰ� �ִ�. �ν��̰� ���ϱ� ������ �ִ� ��� ���ڰ� ���� ���� ���ڿ��� ����� ���ڿ��̶�� �Ѵٰ� �Ѵ�. �ؿ��̴� ���ڿ� S�� �м��ϱ� �����ߴ�. �ؿ��̴� ���ڿ� S�� ������ ���ڸ� ���ġ�ϸ� ���� �ٸ� ����� ���ڿ��� �� �� �������� �ñ�������. ���� ���� ���ڿ� S�� ����� ���ڿ��̶�� �װ͵� ������ �����Ѵ�.

�Է�
ù° �ٿ� ���ڿ� S�� �־�����. S�� ���̴� �ִ� 10�̰�, ���ĺ� �ҹ��ڷθ� �̷���� �ִ�.

���
ù° �ٿ� ��ġ�� ���ġ�ؼ� ���� ���� �ٸ� ����� ���ڿ��� ������ ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

string s;
bool flag;
int cnt;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> s;
	sort(s.begin(), s.end());
	
	do {
		flag = true;
		
		for(int i=1; i<s.size()-1; i++) {
			if(s[i] == s[i-1] || s[i] == s[i+1]) {
				flag = false;
				break;
			}
		}
		
		if(flag) {
			cnt++;
		}
	} while(next_permutation(s.begin(),s.end()));
	
	cout << cnt;
}
