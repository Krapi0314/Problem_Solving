/*
baekjoon 2960��: �����佺�׳׽��� ü

�ð� ����: 1��
�޸� ����: 128 MB

����
�����佺�׳׽��� ü�� N���� �۰ų� ���� ��� �Ҽ��� ã�� ������ �˰����̴�.
�� �˰����� ������ ����.

2���� N���� ��� ������ ���´�.
���� ������ ���� �� �� ���� ���� ���� ã�´�. �̰��� P��� �ϰ�, �� ���� �Ҽ��̴�.
P�� �����, ���� ������ ���� P�� ����� ũ�� ������� �����.
���� ��� ���� ������ �ʾҴٸ�, �ٽ� 2�� �ܰ�� ����.
N, K�� �־����� ��, K��° ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� K�� �־�����. (1 �� K < N, max(2, K) < N �� 1000)

���
ù° �ٿ� K��° ������ ���� ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n,k;
bool arr[1001]; //false = ���� �������� ���� 
int cnt;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> k;
	
	for(int i=2; i<=n; i++) {
		for(int j=1; i*j<=n; j++) {
			if(arr[i*j])
				continue;
			
			if(!arr[i*j]) {
				cnt++;
			}
			
			if(cnt == k) {
				cout << i*j;
				return 0;
			}
			arr[i*j] = true;
		}
	}
}

/*
�����佺�׳׽��� ü 
*/
