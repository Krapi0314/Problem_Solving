/*
baekjoon 1676��: ���丮�� 0�� ����

�ð� ����: 2 ��
�޸� ����: 128 MB

���� 
N!���� �ڿ������� ó�� 0�� �ƴ� ���ڰ� ���� ������ 0�� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� �־�����. (0 �� N �� 500)

���
ù° �ٿ� ���� 0�� ������ ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
int ans;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	for(int i=1; i<=n; i++) {
		int temp = i;
		while(temp != 0 && temp % 5 == 0) {
			ans++;
			temp /= 5;
		}	
	}
	
	cout << ans;
	return 0;
}

/* 
����: ���丮�󿡼� 5�� ���� ���ϱ�

!! �������� ���ϱ� ������ �Ʒ��� ���� �˰����� ����ϸ� �� ������ �ذ� ���� 
while(n >= 5) {
	ans += n / 5;
	n /= 5;
}
*/ 
