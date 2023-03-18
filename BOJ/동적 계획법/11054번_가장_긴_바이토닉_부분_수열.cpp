/*
BOJ 11054��: ���� �� ������� �κ� ����
https://www.acmicpc.net/problem/11054

�ð� ����: 1��
�޸� ����: 256 MB

����
���� S�� � �� Sk�� �������� S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN�� �����Ѵٸ�, �� ������ ������� �����̶�� �Ѵ�.
���� ���, {10, 20, 30, 25, 20}�� {10, 20, 30, 40}, {50, 40, 25, 10} �� ������� ����������,  {1, 2, 3, 2, 1, 2, 3, 2, 1}�� {10, 20, 30, 40, 20, 30} �� ������� ������ �ƴϴ�.
���� A�� �־����� ��, �� ������ �κ� ���� �� ������� �����̸鼭 ���� �� ������ ���̸� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� A�� ũ�� N�� �־�����, ��° �ٿ��� ���� A�� �̷�� �ִ� Ai�� �־�����. (1 �� N �� 1,000, 1 �� Ai �� 1,000)

���
ù° �ٿ� ���� A�� �κ� ���� �߿��� ���� �� ������� ������ ���̸� ����Ѵ�.

���� �Է� 1 
10
1 5 2 1 4 3 4 5 2 1

���� ��� 1 
7 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAX 1000

int arr[MAX+1];
int LIS[MAX+1];
int LIS_Reverse[MAX+1];
int ans;
int n;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> arr[i];
	}
	
	// Calculate LIS
	for(int i=1; i<=n; i++) {	
		LIS[i] = 1;
		
		for(int j=1; j<i; j++) {
			if(arr[i] > arr[j]) {
				LIS[i] = max(LIS[i], LIS[j]+1);
			}
		}
	}
	
	// Calculate LIS_Reverse
	for(int i=n; i>=1; i--) {
		LIS_Reverse[i] = 1;
				
		for(int j=n; j>i; j--) {
			if(arr[i] > arr[j]) {
				LIS_Reverse[i] = max(LIS_Reverse[i], LIS_Reverse[j]+1);
			}
		}
	}
	
	// Calculate LBS
	for(int i=1; i<=n; i++) {
		ans = max(ans, LIS[i]+LIS_Reverse[i]-1);
	}
	
	cout << ans;
	return 0;
}

/* 
LIS + LDS
LBS[k] = LIS[k] + LIS_Reverse(LDS)[k]
������ �������� LIS�� ���ϰ�, ������ �������� LIS�� ����
k���� LIS[k] + LIS_Reverse[k]�� �ִ��� ��, Sk�� LBS 
*/ 
