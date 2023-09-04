/*
baekjoon 11478��: ���� �ٸ� �κ� ���ڿ��� ����

�ð� ����: 1��
�޸� ����: 512 MB

����
���ڿ� S�� �־����� ��, S�� ���� �ٸ� �κ� ���ڿ��� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
�κ� ���ڿ��� S���� ���ӵ� �Ϻκ��� ���ϸ�, ���̰� 1���� ũ�ų� ���ƾ� �Ѵ�.
���� ���, ababc�� �κ� ���ڿ��� a, b, a, b, c, ab, ba, ab, bc, aba, bab, abc, abab, babc, ababc�� �ְ�, ���� �ٸ����� ������ 12���̴�.

�Է�
ù° �ٿ� ���ڿ� S�� �־�����. S�� ���ĺ� �ҹ��ڷθ� �̷���� �ְ�, ���̴� 1,000 �����̴�.

���
ù° �ٿ� S�� ���� �ٸ� �κ� ���ڿ��� ������ ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

string str;
set<string> s;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> str;
	
	for(int i=1; i<=(int)str.size(); i++) {
		for(int j=0; j<=(int)str.size()-i; j++) {
			s.insert(str.substr(j,i));
		}
	}
	
	cout << s.size();
}

/*
string, data structure
�߰�: vector�� �̿��� erase,unique �۾�����, �ߺ��� ������� �ʴ� �ڷᱸ���� set�� �̿��ؼ� ���Ը� �����ϸ� �� ����, ������ ���� 
*/
