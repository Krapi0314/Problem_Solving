/*
baekjoon 11055��: ���� ū �κ� ����

�ð� ����: 1��
�޸� ����: 256 MB 

����
���� A�� �־����� ��, �� ������ ���� �κ� ���� �߿��� ���� ���� ū ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
���� ���, ���� A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} �� ��쿡 ���� ���� ū ���� �κ� ������ A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} �̰�, ���� 113�̴�.

�Է�
ù° �ٿ� ���� A�� ũ�� N (1 �� N �� 1,000)�� �־�����.
��° �ٿ��� ���� A�� �̷�� �ִ� Ai�� �־�����. (1 �� Ai �� 1,000)

���
ù° �ٿ� ���� A�� ���� ���� ū ���� �κ� ������ ���� ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
int arr[1000];
int dp[1000];
int ans;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	
	for(int i=0; i<n; i++) {
		dp[i] = arr[i];
		for(int j=0; j<i; j++) {
			if(arr[j] < arr[i] && dp[i] < dp[j] + arr[i]) {
				dp[i] = dp[j] + arr[i];
			}
		}
		
		ans = max(ans, dp[i]);
	}
	
	cout << ans;
}

/*
���� ��ȹ�� 
dp[i]: �� ������ ���� �κ� ���� �߿��� ���� ���� ū �� 
*/
