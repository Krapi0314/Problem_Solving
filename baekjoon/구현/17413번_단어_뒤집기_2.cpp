/*
baekjoon 17413��: �ܾ� ������ 2

�ð� ����: 1��
�޸� ����: 512 MB

����
���ڿ� S�� �־����� ��, �� ���ڿ����� �ܾ ���������� �Ѵ�.
����, ���ڿ� S�� �Ʒ��Ͱ� ���� ��Ģ�� ��Ų��.

���ĺ� �ҹ���('a'-'z'), ����('0'-'9'), ����(' '), Ư�� ����('<', '>')�θ� �̷���� �ִ�.
���ڿ��� ���۰� ���� ������ �ƴϴ�.
'<'�� '>'�� ���ڿ��� �ִ� ��� �����ư��鼭 �����ϸ�, '<'�� ���� �����Ѵ�. ��, �� ������ ������ ����.
�±״� '<'�� �����ؼ� '>'�� ������ ���̰� 3 �̻��� �κ� ���ڿ��̰�, '<'�� '>' ���̿��� ���ĺ� �ҹ��ڿ� ���鸸 �ִ�. �ܾ�� ���ĺ� �ҹ��ڿ� ���ڷ� �̷���� �κ� ���ڿ��̰�, �����ϴ� �� �ܾ�� ���� �ϳ��� �����Ѵ�. �±״� �ܾ �ƴϸ�, �±׿� �ܾ� ���̿��� ������ ����.

�Է�
ù° �ٿ� ���ڿ� S�� �־�����. S�� ���̴� 100,000 �����̴�.

���
ù° �ٿ� ���ڿ� S�� �ܾ ����� ����Ѵ�. 
*/

 #include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

string s;
stack<char> st;
bool tag;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	getline(cin, s);
	
	for(int i=0; i<s.size(); i++) {
		if(s[i] == ' ') {
			while(!st.empty()) {
				char ch = st.top(); st.pop();
				cout << ch;
			}
			cout << " ";
		}
		else if(s[i] == '<') {
			while(!st.empty()) {
				char ch = st.top(); st.pop();
				cout << ch;
			}
			tag = true;
			cout << s[i];
		}
		else if(s[i] == '>') {
			tag = false;
			cout << s[i];
		}
		else if(tag) {
			cout << s[i];
		}
		else if(!tag) {
			st.push(s[i]);
		}
	}
	while(!st.empty()) {
		char ch = st.top(); st.pop();
		cout << ch;
	}
}

/*
implementation OR stack
����: ���Լ����̱� ������ ���ڿ� �����Ⱑ ������! 
*/
