/*
baekjoon 9613��

����
���� ���� n���� �־����� ��, ������ ��� ���� GCD�� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� t (1 �� t �� 100)�� �־�����. �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ִ�. �� �׽�Ʈ ���̽��� ���� ���� n (1 < n �� 100)�� �־�����, �������� n���� ���� �־�����. �Է����� �־����� ���� 1,000,000�� ���� �ʴ´�.

���
�� �׽�Ʈ ���̽����� ������ ��� ���� GCD�� ���� ����Ѵ�.
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int t;
int n;
int arr[100];
ull ans;

int GCD(int a, int b){
    
    if(b == 0){
        return a;
    }else{
        return GCD(b, a%b);
    }
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> t;
	
	while(t--) {
		ans = 0;
		
		cin >> n;
		for(int i=0; i<n; i++) {
			cin >> arr[i];
		}
		
		for(int i=0; i<n; i++) {
			for(int j=i+1; j<n; j++) {
				ans += GCD(arr[i], arr[j]);
			}
		}
		
		cout << ans << "\n";
	}
}

/*
����, �ִ����� 
*/
