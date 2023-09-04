/*
baekjoon 1259��: �Ӹ���Ҽ�

�ð� ����: 1 ��
�޸� ����: 128 MB

���� 
� �ܾ �ڿ������� �о �Ȱ��ٸ� �� �ܾ �Ӹ�����̶�� �Ѵ�. 'radar', 'sees'�� �Ӹ�����̴�.
���� �Ӹ�������� ����� �� �ִ�. ���� ���ڵ��� �ڿ������� �о ���ٸ� �� ���� �Ӹ���Ҽ���. 121, 12421 ���� �Ӹ���Ҽ���. 123, 1231�� �ڿ������� ������ �ٸ��Ƿ� �Ӹ���Ҽ��� �ƴϴ�. ���� 10�� �Ӹ���Ҽ��� �ƴѵ�, �տ� ���ǹ��� 0�� �� �� �ִٸ� 010�� �Ǿ� �Ӹ���Ҽ��� ����� ���� ������, Ư���� �̹� ���������� ���ǹ��� 0�� �տ� �� �� ���ٰ� ����.

�Է�
�Է��� ���� ���� �׽�Ʈ ���̽��� �̷���� ������, �� �ٸ��� 1 �̻� 99999 ������ ������ �־�����. �Է��� ������ �ٿ��� 0�� �־�����, �� ���� ������ ���Ե��� �ʴ´�.

���
�� �ٸ��� �־��� ���� �Ӹ���Ҽ��� 'yes', �ƴϸ� 'no'�� ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

string str;
bool flag;
int len;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	while(true) {
		cin >> str;
		
		if(str == "0") {
			break;
		}
		
		flag = true;
		len = str.size();
		
		for(int i=0; i<len/2; i++) {
			if(str[i] != str[len-i-1]) {
				flag = false;
				break;
			}
		}
		
		if(flag) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}
	
	return 0;
}

/*
���ڿ� 
*/
