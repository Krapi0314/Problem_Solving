/*
baekjoon 2877��: 4�� 7

�ð� ����: 1��
�޸� ����: 128 MB

����
â���̴� 4�� 7�� �̷���� ���� �����Ѵ�. â���̰� �����ϴ� �� �߿� K��° ���� ���� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� K(1 �� K �� 109)�� �־�����.

���
ù° �ٿ� â���̰� �����ϴ� ���� �� K��° ���� ���� ����Ѵ�.
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ll k; 
deque<int> dq;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k;
	
	k++;
	while(k != 0) {
		int digit = k % 2;
		dq.push_front(digit);
		k /= 2;
	}
	dq.pop_front();
	
	for(int i=0; i<(int)dq.size(); i++) {
		if(dq[i] == 0) {
			cout << "4";
		}
		else {
			cout << "7";
		}
	}
}

/*
����: ��Ģ�� ã�� -> 4 -> 0, 7 -> 1�� �����ϰ� k+1�� ���������� MSB�� ���ָ� k��° ���� 1,0 ��ȯ ���¿� ���� 
*/
