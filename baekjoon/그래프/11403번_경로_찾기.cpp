/*
baekjoon 11403��: ��� ã��

�ð� ����: 1 ��
�޸� ����: 256 MB

����
����ġ ���� ���� �׷��� G�� �־����� ��, ��� ���� (i, j)�� ���ؼ�, i���� j�� ���� ��ΰ� �ִ��� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ���� N (1 �� N �� 100)�� �־�����. ��° �ٺ��� N�� �ٿ��� �׷����� ���� ����� �־�����. i��° ���� j��° ���ڰ� 1�� ��쿡�� i���� j�� ���� ������ �����Ѵٴ� ���̰�, 0�� ���� ���ٴ� ���̴�. i��° ���� i��° ���ڴ� �׻� 0�̴�.

���
�� N���� �ٿ� ���ļ� ������ ������ ������� �������� ����Ѵ�. ���� i���� j�� ���� ��ΰ� ������ i��° ���� j��° ���ڸ� 1��, ������ 0���� ����ؾ� �Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAX 100

int n;
int arr[MAX][MAX];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> arr[i][j];
		}
	}
	
	for(int k=0; k<n; k++) {
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(arr[i][k] && arr[k][j]) {
					arr[i][j] = 1;
				}
			}
		}
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}

/* 
�׷���: �÷��̵� �ͼ� �˰��� 
*/ 
