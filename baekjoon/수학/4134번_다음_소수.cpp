/*
baekjoon 4134��: ���� �Ҽ�

�ð� ����: 1��
�޸� ����: 128 MB

����
���� n(0 �� n �� 4*109)�� �־����� ��, n���� ũ�ų� ���� �Ҽ� �� ���� ���� �Ҽ� ã�� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ������ �־�����. �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ְ�, ���� n�� �־�����.

���
������ �׽�Ʈ ���̽��� ���ؼ� n���� ũ�ų� ���� �Ҽ� �� ���� ���� �Ҽ��� �� �ٿ� �ϳ��� ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
ull num;

bool isPrime(ull num) {
	if(num == 1) return false;
	if(num == 2) return true;
	
	// ¦���̸� �ռ��� 
	if(num % 2 == 0) return false;
	
	// N�� �� ���� ���������ٸ�, N = p * q ���°� �ǰ�, p�� q �� �ϳ��� �ݵ�� sqrt(N) ������ ���� �� ���̹Ƿ�, sqrt(N)������ ����� �Ҽ����� �Ǻ� ����
	// 2�� ������ �Ҽ����� ��� Ȧ���̹Ƿ�, i+=2�� Ȧ���� üũ 
	int Max = (int)sqrt(num);
	for(int i=3; i<=Max; i+=2) {
		if(num % i == 0) {
			return false;
		}
	} 
	
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> num;
		
		while(!isPrime(num)) {
			num++;
		}
		
		cout << num << "\n";
	}
}
