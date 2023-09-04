/*
baekjoon 14425��: ���ڿ� ����

�ð� ����: 2��
�޸� ����: 1536 MB

����
�� N���� ���ڿ��� �̷���� ���� S�� �־�����.
�Է����� �־����� M���� ���ڿ� �߿��� ���� S�� ���ԵǾ� �ִ� ���� �� �� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���ڿ��� ���� N�� M (1 �� N �� 10,000, 1 �� M �� 10,000)�� �־�����. 
���� N���� �ٿ��� ���� S�� ���ԵǾ� �ִ� ���ڿ����� �־�����.
���� M���� �ٿ��� �˻��ؾ� �ϴ� ���ڿ����� �־�����.
�Է����� �־����� ���ڿ��� ���ĺ� �ҹ��ڷθ� �̷���� ������, ���̴� 500�� ���� �ʴ´�. ���� S�� ���� ���ڿ��� ���� �� �־����� ���� ����.

���
ù° �ٿ� M���� ���ڿ� �߿� �� �� ���� ���� S�� ���ԵǾ� �ִ��� ����Ѵ�.
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N,M;
string s[10000];
string m;
int cnt;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	
	for(int i=0; i<N; i++) {
		cin >> s[i];
	}
	sort(s+0, s+N);
	
	for(int i=0; i<M; i++) {
		cin >> m;
		
		if(binary_search(s+0,s+N, m)) {
			cnt++;
		}
	}
	
	cout << cnt;
}

/*
data structure: sorted list & binary search
*/
