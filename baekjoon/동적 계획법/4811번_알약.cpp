/*
baekjoon 4811��: �˾�

�ð� ����: 1��
�޸� ����: 256 MB

����
70�� ������ �Ҿƹ����� ���� ���� �� �ݾ��� �Դ´�. �ճ� �����̴� ���� �Ҿƹ������� ���� N�� ��� ���� ������ �־���.
ù° ���� ������ ������ �� �ϳ��� ������. �� ����, �� ���� ������ �ɰ��� �� ������ �԰�, �ٸ� ������ �ٽ� ���� �ִ´�.
���� ������ ������ ������ ���� �ϳ� ������. (���� �� ���� ��ü �� ���� �ְ�, �ɰ� �� ���� �� ���� �ִ�) �� �����̶�� �� ���� �԰�, �ƴ϶�� ���� �ɰ��� �� ������ �԰�, �ٸ� ������ �ٽ� ���� �ִ´�.
������ �ճ࿡�� �� ������ ���� ������ W��, �� ������ ���� ������ H ������. �ճ�� �Ҿƹ������� ���� ���ڸ� ���̿� ����� ���´�. �� 2N���� ������ ���̰� 2N�� ���ڿ��� ��������� �ȴ�. �̶�, ������ ���� �ٸ� ���ڿ��� ������ �� �� ���ϱ�?

�Է�
�Է��� �ִ� 1000���� �׽�Ʈ ���̽��� �̷���� �ִ�. �� �׽�Ʈ ���̽��� �� ���̸�, ���� ����ִ� ���� ���� N �� 30 �� �־�����.

�Է��� ������ �ٿ��� 0�� �ϳ� �־�����.

���
�� �׽�Ʈ ���̽��� ���ؼ� ������ ���ڿ��� ������ ����Ѵ�.
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
ull dp[31][31];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// ������ ���� 
	for(int i=0; i<=30; i++) {
		dp[0][i] = 1;	
	}
			
	// ��ȭ�� ���
	for(int i=1; i<=30; i++) {
		for(int j=0; j<=30; j++) {
			if(j == 0) {
				dp[i][0] = dp[i-1][1];
			}
			else {
				dp[i][j] = dp[i-1][j+1] + dp[i][j-1];
			}
		}
	}
	
	while(true) {
		cin >> n;
		
		if(n == 0) {
			break;
		}

		cout << dp[n][0] << "\n"; 
	}
}

/* 
dp

dp[w][h] = �˾��� w,h�� ������ ��, ���� �� �ִ� ���ڿ��� �� 

������: dp[0][0] ~ dp[0][30] = 1 (������ �˾��� 0�� �϶��� ��� = 1) 
��ȭ��
1. �ɰ��� �˾��� ���� ���: dp[w][h=0] = dp[w-1][1] (������ �˾� �ϳ��� ���̰�, �ɰ��� �˾� 1�� �߰�) 
2. ������/�ɰ��� �˾��� ��� �ִ� ���: dp[w][h] = dp[w-1][h+1] + dp[w][h-1] (������ �˾��� �԰�, ���� �ɰ��� �˾��� �ٽ� �־��� ���� ��� + �ɰ��� �˾��� �Ծ��� ���� ���)
 
+ īŻ�� ��
����: 1 1 2 5 14 42 132 429 1430 4862 ...
��ȭ��: Cn+1 = Sigma(i=0, n) CiCn-i (n>=0), C0 = 1
C++ Implementation

// A dynamic programming based function to find nth
// Catalan number
unsigned long int catalanDP(unsigned int n)
{
    // Table to store results of subproblems
    unsigned long int catalan[n + 1];
 
    // Initialize first two values in table
    catalan[0] = catalan[1] = 1;
 
    // Fill entries in catalan[] using recursive formula
    for (int i = 2; i <= n; i++) {
        catalan[i] = 0;
        for (int j = 0; j < i; j++)
            catalan[i] += catalan[j] * catalan[i - j - 1];
    }
 
    // Return last entry
    return catalan[n];
}
 
*/
