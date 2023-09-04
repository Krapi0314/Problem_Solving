/*
baekjoon 2417��: ���� ������

�ð� ����: 1��
�޸� ����: 128 MB

����
������ �־�����, �� ���� ���� �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� n�� �־�����. (0 �� n < 263)

���
ù° �ٿ� q2 �� n�� ���� ���� ���� �ƴ� ���� q�� ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ull n;
ll l,r,m;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	l = 0; r = sqrt(n) + 1;
	while(l <= r) {
		m = (l + r) / 2;
		
		if(m*m >= n) {
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	
	if(m*m == n) {
		cout << m;
	}
	else {
		cout << l;
	}
}

/*
�̺�Ž��
*/ 

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

ull n;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	cout << (ll)ceil(sqrt(n));
}

/*
���� 
*/
