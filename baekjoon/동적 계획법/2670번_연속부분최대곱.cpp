/*
baekjoon 2670��: ���Ӻκ��ִ��

�ð� ����: 1 ��
�޸� ����: 128 MB

����
N���� �Ǽ��� ���� ��, �� �� �̻��� ���ӵ� ������ ���� �ִ밡 �Ǵ� �κ��� ã��, �� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. ���� ��� �Ʒ��� ���� 8���� ���� �Ǽ��� �־����ٸ�,
| 1.1 | 0.7 | 1.3 | 0.9 | 1.4 | 0.8 | 0.7 | 1.4 |
��ĥ�� �κ��� ���� �ִ밡 �Ǹ�, �� ���� 1.638�̴�.

�Է�
ù° ���� ������ ���� �Ǽ����� ���� N�� �־�����, �� ���� �ٺ��� N���� ���� �� �ٿ� �ϳ��� ��� �ִ�. N�� 10,000 ������ �ڿ����̴�. �Ǽ��� �Ҽ��� ù°�ڸ����� �־�����, 0.0���� ũ�ų� ����, 9.9���� �۰ų� ����.

���
���� �ִ��� �Ҽ��� ���� ��° �ڸ����� �ݿø��Ͽ� �Ҽ��� ���� ��° �ڸ����� ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAX 10000

int n;
double dp[MAX+1];
double Max;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	for(int i=1; i<=n; i++) {
		cin >> dp[i];
	}
	
	for(int i=2; i<=n; i++) {
		dp[i] = max(dp[i-1]*dp[i], dp[i]);
		Max = max(Max, dp[i]);
	}
	
	cout << fixed;
	cout.precision(3);
	cout << Max;
	return 0;
}

/*
������ȹ��
dp[i]: i��° ���ڱ��� �����ϴ�, ���ӵ� ������ ���� �ִ� 
*/
