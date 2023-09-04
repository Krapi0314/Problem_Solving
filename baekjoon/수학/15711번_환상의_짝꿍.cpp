/*
baekjoon 15711��: ȯ���� ¦��

�ð� ����: 1��
�޸� ����: 256 MB

����
ȯ���� ���� ��𷣵忡���� �ο��� ��ǥ�� ���� �ϳ��� ������ �ִ�. �׵��� ������ ����� ������� �� ���� �̿��Ͽ� � �� ����� ȯ���� ¦������ �Ǵ��ϴµ�, �� ����� ���� ���� �̾���̰� �� ���� �ٽ� ���̰� �Ҽ��� �� �ΰ��� ��Ȯ�� ���� �� �ִٸ� �� ����� ȯ���� ¦���̶�� �Ѵ�. ������ �׵��� ���̰� �Ҽ��� �ΰ��� ������ ���� �� �ִ��� �Ǵ��ϴ� ���� ������� ��κ� ���ΰ� �ο����� �𸣰� �׳� �������ٰ� �Ѵ�. �ּ��ϰԵ�...
�׷� �׵��� ���ؼ� � �� ����� ȯ���� ¦������ �Ǵ��ϴ� ���α׷��� �ۼ��϶�.
���ǻ� �� ����� ���� �̾���� ���� ���� �� �սǵǴ� ���� ���̴� 0�̶�� �����Ѵ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� �� T(1 �� T �� 500)�� �־�����.
��° �ٺ��� T�� �ٿ� �� ����� ������ �ִ� ���� ���̸� ��Ÿ���� ���� A, B�� �������� ���еǾ� �־�����. (1 �� A, B �� 2 �� 1012)

���
�� �׽�Ʈ ���̽����� �� �پ� �� ����� ���� �̾���̰� �� ���� �ٽ� ���̰� �Ҽ��� �ΰ��� ������ ��Ȯ�� ���� �� �ִٸ� YES, �Ұ����ϸ� NO�� ����϶�. 
*/

#include <bits/stdc++.h>

#define MAX 2000000
using namespace std;
typedef long long ll;

vector <int> prime;
bool sieve[MAX];

bool isPrime(ll a){
	for(int i = 0; i < (int)prime.size() && (ll)prime[i] * prime[i] <= a; i++)
		if(a % prime[i] == 0) return false;
	return true;
}

int main() {
	int t;
	scanf("%d", &t);
	
    memset(sieve,true,sizeof(sieve));
    
    int nsqrt = (int)sqrt(MAX);
	for(int i = 2; i <= nsqrt; i++) {
		if (sieve[i])
			for(int j = 2; j * i <= MAX; j++)
				sieve[i*j] = false;
	}
	for(int i = 2; i <= MAX; i++)
		if(sieve[i]) prime.push_back(i);
	
	ll a, b;
	while (t--) {
		scanf("%lld %lld", &a, &b);

		a += b;
		if (a < 4) { printf("NO\n"); continue; }
		if (a % 2 == 0) { printf("YES\n"); continue; }
		a -= 2;

		if (isPrime(a)) printf("YES\n");
		else printf("NO\n");
	}
}

/*
!!4�̻��� ¦�� n <= 10^18�� ���鿡 ���� ������ �Ҽ� 2���� n�� ���� �� ���� -> �������� ������ ����

bool arr[200��+1]

memeset(arr,true,sizeof(arr))

200�� ������ ����� ��� ���ϱ�: �����׽��׳׽��� ü
for 200��
	if (sieve[i])
    	for i*j <= 200��
		    sieve[i*j] = false

for arr
	vector prime pushback sieve

cin t
for t
	cin a b
	sum = a + b

	if sum < 4
		cout NO
	else
		if sum % 2 (�������� ����)
			cout YES
		else (Ȧ���̸�, �� �Ҽ��� �������� �� �ִٴ� ���� �Ͽ� �Ҽ� �� �ϳ��� ������ 2, sum-2�� �Ҽ����� ���̸� ��)
			�Ҽ� �Ǻ���: ���� ������ (N�� ���� ������ ������ ����� N�� ������ �� ���̶� ������ �������� �ռ���, �ƴϸ� �Ҽ���� ���� + if �ռ������ �ռ��� = �Ҽ� * ������ �� �̹Ƿ�, N�� ���� ������ ������ �Ҽ���� ������� ��)
			for prime
				if N % prime[i] == 0
					flag = false
			if flag
				cout YES
			else
				cout NO
*/
