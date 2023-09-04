/*
baekjoon 11653��: ���μ�����

�ð� ����: 1��
�޸� ����: 256 MB

����
���� N�� �־����� ��, ���μ������ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� N (1 �� N �� 10,000,000)�� �־�����.

���
N�� ���μ����� ����� �� �ٿ� �ϳ��� ������������ ����Ѵ�. N�� 1�� ��� �ƹ��͵� ������� �ʴ´�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAX 10000000
int n;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	 
	cin >> n;
	
	for(int i=2; i<=sqrt(n); i++) {
		while(n % i == 0) {
			cout << i << "\n";
			n /= i;
		}
	}
	
	if(n != 1) {
		cout << n;
	}
}

/*
����: �ܼ� ������ (���� �Ҽ����� �������� ����������, sqrt(N)���� N�� ������ ��� �Ҽ��� ���ԵǹǷ�, �ᱹ �Ҽ��� ���� ���μ����ط� ������ ��)  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAX 10000001
int n;
bool not_prime[MAX];
vector<int> prime;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	 
	for(int i=2; i<=sqrt(n); i++) {
		for(int j=2; j*i<=n; j++) {
			not_prime[i*j] = true;
		}
	}
	for(int i=2; i<=n; i++) {
		if(!not_prime[i]) {
			prime.push_back(i);
		}
	}
	
	for(int i=0; i<prime.size(); i++) {
		while(n % prime[i] == 0) {
			n /= prime[i];
			cout << prime[i] << "\n";
		}
	}
}

/*
����: �����佺�׳׽��� ü�� ���� ���� 
