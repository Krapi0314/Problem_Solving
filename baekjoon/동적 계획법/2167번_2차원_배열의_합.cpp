/*
baekjoon 2167��: 2���� �迭�� ��

�ð� ����: 2��
�޸� ����: 128 MB

����
2���� �迭�� �־����� �� (i, j) ��ġ���� (x, y) ��ġ������ ����Ǿ� �ִ� ������ ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. �迭�� (i, j) ��ġ�� i�� j���� ��Ÿ����.

�Է�
ù° �ٿ� �迭�� ũ�� N, M(1 �� N, M �� 300)�� �־�����. ���� N���� �ٿ��� M���� ������ �迭�� �־�����. �迭�� ���ԵǾ� �ִ� ���� ������ 10,000���� �۰ų� ���� �����̴�. �� ���� �ٿ��� ���� ���� �κ��� ���� K(1 �� K �� 10,000)�� �־�����. ���� K���� �ٿ��� �� ���� ������ i, j, x, y�� �־�����(i �� x, j �� y).

���
K���� �ٿ� ������� �迭�� ���� ����Ѵ�. �迭�� ���� 231-1���� �۰ų� ����. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int i,j,x,y;
int n,m,k;
int dp[301][301]; 
int num;
int ans;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin >> num;
			
			dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + num;
		}
	}
	
	cin >> k;
	while(k--) {
		ans = 0;
		cin >> i >> j >> x >> y;
		
		ans = dp[x][y] - dp[x][j-1] - dp[i-1][y] + dp[i-1][j-1];
		
		cout << ans << "\n";
	}
}

/*
baekjoon 11660��: ���� �� ���ϱ� 5�� ������ �� ���� ����: DP, ������
!! (x,y)���� (i,j)�� ���ִ� ���� �ƴ϶�, i-1 ��,j-1 �࿡ �ش��ϴ� ���������� �� �־�� �� 

�Ʒ��� �ܼ� ������ ���� (������ �۾Ƽ� ����) 
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int i,j,x,y;
int n,m,k;
int arr[301][301]; 
int ans;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin >> arr[i][j];
		}
	}
	
	cin >> k;
	while(k--) {
		ans = 0;
		cin >> i >> j >> x >> y;
		
		for(int a=i; a<=x; a++) {
			for(int b=j; b<=y; b++) {
				ans += arr[a][b];
			}
		}
		
		cout << ans << "\n";
	}
}
*/
