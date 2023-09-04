/*
baekjoon 11726��: 2xn Ÿ�ϸ�

�ð� ����: 1��
�޸� ����: 256 MB

����
2��n ũ���� ���簢���� 1��2, 2��1 Ÿ�Ϸ� ä��� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
�Ʒ� �׸��� 2��5 ũ���� ���簢���� ä�� �� ���� ����� ���̴�.

�Է�
ù° �ٿ� n�� �־�����. (1 �� n �� 1,000)

���
ù° �ٿ� 2��n ũ���� ���簢���� ä��� ����� ���� 10,007�� ���� �������� ����Ѵ�. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int n;
int dp[1001];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007; //�̹� i ���� ������ 10007 ������ ������ ����Ǿ� �����Ƿ�, % ������ �ѹ���
	}

	cout << dp[n];
}

/*
Bottom-up DP �ݺ���
��ȭ��: dp[n] = dp[n-2] + dp[n-1]
+ ��ⷯ ����

n �Է�

dp[1] = 1
dp[2] = 2

for i 3 to n
	dp[n] = ((dp[n-2] % 10007) + (dp[n-3] % 10007)) % 10007

cout dp[n]
	
*/
