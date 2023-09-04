/*
baekjoon 9081��: �ܾ� ���߱�

�ð� ����: 1��
�޸� ����: 128 MB

����
BEER��� �ܾ �̷�� ���ĺ���� ���� �� �ִ� �ܾ���� ���� ������ �����ϰ� �Ǹ�
BEER
BERE
BREE
EBER
EBRE
EEBR
EERB
ERBE
EREB
RBEE
REBE
REEB
�� ���� �ȴ�. �̷��� �������� BEER ������ ���� �ܾ�� BERE�� �ȴ�. �̿� ���� �ܾ �ָ� �� �ܾ �̷�� ���ĺ���� ���� �� �ִ� �ܾ���� ���� ������ ������ ���� �־��� �ܾ� ������ ������ �ܾ ã�� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�Է��� ù �ٿ��� �׽�Ʈ ���̽��� ���� T (1 �� T �� 10)�� �־�����. �� �׽�Ʈ ���̽��� �ϳ��� �ܾ �� �ٷ� �־�����. �ܾ�� ���ĺ� A~Z �빮�ڷθ� �̷������ �׻� ������ ���� ���ӵ� ���ĺ����� �̷������. �ܾ��� ���̴� 100�� ���� �ʴ´�.

���
�� �׽�Ʈ ���̽��� ���ؼ� �־��� �ܾ� �ٷ� ������ ��Ÿ���� �ܾ �� �ٿ� �ϳ��� ����Ͻÿ�. ���� �־��� �ܾ ������ �ܾ��̶�� �׳� �־��� �ܾ ����Ѵ�.
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

string s;
int t;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while(t--) {
		cin >> s;
		if(!next_permutation(s.begin(),s.end()))
			prev_permutation(s.begin(),s.end());
		
		cout << s << "\n";
	}
}

/*
cin t
while t--
	cin string s
	
	next_permutation(s.begin(), s.end())
	cout s
*/
