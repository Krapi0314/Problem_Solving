/*
baekjoon 20053: �ּ�, �ִ� 2

�ð� ����: 1��
�޸� ����: 256 MB

����
N���� ������ �־�����. �̶�, �ּڰ��� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T (1 �� T �� 10)�� �־�����. �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ִ�.
�� �׽�Ʈ ���̽��� ù° �ٿ� ������ ���� N (1 �� N �� 1,000,000)�� �־�����. ��° �ٿ��� N���� ������ �������� �����ؼ� �־�����. ��� ������ -1,000,000���� ũ�ų� ����, 1,000,000���� �۰ų� ���� �����̴�.

���
�� �׽�Ʈ ���̽����� �־��� ���� N���� �ּڰ��� �ִ��� �������� ������ �� �ٿ� �ϳ��� ���ʴ�� ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int arr[1000000];
int t,n;
int Max,Min;
bool flag;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> t;
	while(t--) {
		flag = true;
		cin >> n;
		for(int i=0; i<n; i++) {
			cin >> arr[i];
			if(flag) {
				Max = arr[0]; Min = arr[0];
				flag = false;
			}
			Max = max(Max,arr[i]);
			Min = min(Min,arr[i]);
		}
		cout << Min << " " << Max << "\n";
	}
}

/*
implement
*/
