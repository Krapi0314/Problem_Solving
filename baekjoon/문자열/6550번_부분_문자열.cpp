/*
baekjoon 6550��: �κ� ���ڿ�

�ð� ����: 1��
�޸� ����: 128 MB

����
2���� ���ڿ� s�� t�� �־����� �� s�� t�� �κ� ���ڿ����� �Ǵ��ϴ� ���α׷��� �ۼ��϶�. �κ� ���ڿ��� ������ �ִ��� �Ǵ��ϴ� ����� t���� �� ���� ���ڸ� �����ϰ� �̸� ������ �ٲ��� �ʰ� ������ ��� s�� �Ǵ� ��츦 �̾߱� �Ѵ�.

�Է�
�Է��� ���� ���� �׽�Ʈ ���̽��� �̷���� �ִ�. �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� ������, ���ڿ� s �� t�� ��ĭ�� ���̿� �ΰ� ���´�. s�� t�� ���̴� 10���� ���� �ʴ´�.

���
�Էµ� s�� t�� ������� s�� t�� �κ� ���ڿ��� ��� Yes�� ����ϰ� �ƴ� ��� No��� ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

string s ,t;
queue<char> q;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while(true) {
		while(!q.empty()) {
			q.pop();
		}
		
		cin >> s >> t;
		
		if(cin.eof()) {
			break;
		}
		
		for(int i=0; i<(int)s.size(); i++) {
			q.push(s[i]);
		}
		
		for(int i=0; i<(int)t.size(); i++) {
			char ch = q.front();
			
			if(ch == t[i]) {
				q.pop();
			}
		}
		
		if(!q.empty()) {
			cout << "No\n";
		}
		else {
			cout << "Yes\n";
		}
	}
}

/*
���ڿ� 
*/ 
