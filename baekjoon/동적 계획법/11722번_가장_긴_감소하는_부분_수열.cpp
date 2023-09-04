/*
baekjoon 11722��: ���� �� �����ϴ� �κ� ����

�ð� ����: 1��
�޸� ����: 256 MB

����
���� A�� �־����� ��, ���� �� �����ϴ� �κ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
���� ���, ���� A = {10, 30, 10, 20, 20, 10} �� ��쿡 ���� �� �����ϴ� �κ� ������ A = {10, 30, 10, 20, 20, 10}  �̰�, ���̴� 3�̴�.

�Է�
ù° �ٿ� ���� A�� ũ�� N (1 �� N �� 1,000)�� �־�����.
��° �ٿ��� ���� A�� �̷�� �ִ� Ai�� �־�����. (1 �� Ai �� 1,000)

���
ù° �ٿ� ���� A�� ���� �� �����ϴ� �κ� ������ ���̸� ����Ѵ�.
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
int arr[1000];
int dp[1000];
int Max;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	
	for(int i=0; i<n; i++) {
		dp[i] = 1;
		
		for(int j=0; j<i; j++) {
			if(arr[i] < arr[j]) {
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
		
		Max = max(Max, dp[i]);
	} 
	
	cout << Max;
}

/*
dp, LIS ���빮�� 
dp[i]: i ������ �������� ���� �� �����ϴ� �κ� ������ ����
��ȭ��: dp[i] = i-1 ������ �������� ���� �� �����ϴ� �κ� ������ ���� dp[j] + 1 (��, arr[i] < arr[j])  
*/
