/*
baekjoon 11723��: ����

�ð� ����: 1.5 ��
�޸� ����: 4 MB

����
����ִ� ������ S�� �־����� ��, �Ʒ� ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

- add x: S�� x�� �߰��Ѵ�. (1 �� x �� 20) S�� x�� �̹� �ִ� ��쿡�� ������ �����Ѵ�.
- remove x: S���� x�� �����Ѵ�. (1 �� x �� 20) S�� x�� ���� ��쿡�� ������ �����Ѵ�.
- check x: S�� x�� ������ 1��, ������ 0�� ����Ѵ�. (1 �� x �� 20)
- toggle x: S�� x�� ������ x�� �����ϰ�, ������ x�� �߰��Ѵ�. (1 �� x �� 20)
- all: S�� {1, 2, ..., 20} ���� �ٲ۴�.
- empty: S�� ���������� �ٲ۴�. 

�Է�
ù° �ٿ� �����ؾ� �ϴ� ������ �� M (1 �� M �� 3,000,000)�� �־�����.
��° �ٺ��� M���� �ٿ� �����ؾ� �ϴ� ������ �� �ٿ� �ϳ��� �־�����.

���
check ������ �־���������, ����� ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int m;
int s, x;
string cmd;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> m;
	for(int i=0; i<m; i++) {
		cin >> cmd;
		
		if(cmd == "add") {
			cin >> x;
			// ex) 1000 ! 100 = 1100
			s |= (1 << x);
		}
		else if(cmd == "remove") {
			cin >> x;
			// ex) 1000 & ~(1000) = 0000 
			s &= ~(1 << x);
		}
		else if(cmd == "check") {
			cin >> x;
			// ex) 1011 & 1000 = 1 (true)
			// ex) 0011 & 1000 = 0 (false)
			if(s & (1 << x)) {
				cout << "1\n";
			}
			else {
				cout << "0\n";	
			}
		}
		else if(cmd == "toggle") {
			cin >> x;
			// ex) 1011 ^ 1000 = 0011
			// ex) 0011 ^ 1000 = 1011
 			s ^= (1 << x);
		}
		else if(cmd == "all") {
			// ex) 10000 - 1 = 1111
			s = (1 << 21) - 1;
		}
		else {
			// ex) 0000
			s = 0;
		}
	}
	
	return 0;
}

/* 
���� - ��Ʈ����ũ 
*/ 
