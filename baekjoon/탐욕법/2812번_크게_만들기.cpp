/*
2812��: ũ�� �����

�ð� ����: 1��
�޸� ����: 128 MB

����
N�ڸ� ���ڰ� �־����� ��, ���⼭ ���� K���� ������ ���� �� �ִ� ���� ū ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� K�� �־�����. (1 �� K < N �� 500,000)
��° �ٿ� N�ڸ� ���ڰ� �־�����. �� ���� 0���� �������� �ʴ´�.

���
�Է����� �־��� ���ڿ��� K���� ������ �� ���� �� �ִ� ���� ū ���� ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int k,n;
string s;
deque<char> dq;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	cin >> s;
	
	int len = s.size();
	for(int i=0; i<len; i++) {
		while(k && !dq.empty() && dq.back() < s[i]) {
			dq.pop_back();
			k--;
		}
		
		dq.push_back(s[i]);
	}
	
	len = dq.size() - k;
	for(int i=0; i<len; i++) {
		cout << dq[i];
	}
	
	return 0;
}

/*
Ž���
k > 0�� ���� deque�� ���ڸ� �ְ�, ���� ������ ���ڿ� ��, ������ ���ں��� deque�� ������ ���ڰ� �� ������ pop, ���� deque�� ���ҵ��� n - k ��ŭ ���  
*/
