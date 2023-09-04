/*
baekjoon 17829��: 222-Ǯ��

�ð� ����: 1��
�޸� ����: 256 MB

����
���� ������ �޲ٴ� �����̴� ���� ���� �������� �����ϴ� ��, �̹��� ó���� ���� ���̴� �ռ��� �Ű��(Convolutional Neural Network, CNN)�� Ǯ�� ���꿡 ������ �޾� �ڽŸ��� Ǯ���� ����� �̸� 222-Ǯ���̶� �θ���� �ߴ�.
������ 8��8 ����� �־����ٰ� �������� �� 222-Ǯ���� 1ȸ �����ϴ� ������ ������ ���̴�

1. ����� 2��2 ���簢������ ������.
2. �� ���簢������ 2��°�� ū ���� �����. ���⼭ 2��°�� ū ����, ���簢���� �� ���Ҹ� ũ������� a4 �� a3 �� a2 �� a1 �� ���� ��, ���� a2�� ���Ѵ�.
3. 2�� ������ ���� ����� ũ�Ⱑ �پ��� �ȴ�.

�����̴� N��N ��Ŀ� 222-Ǯ���� �ݺ��ؼ� �����Ͽ� ũ�⸦ 1��1�� ������� �� � ���� ���������� �ñ����Ѵ�.
���� Ȱ���� ġ�� ���� ����� �����̸� �ֵ��ϸ� �������� �ñ����� ��� �ذ�������.

�Է�
ù° �ٿ� N(2 �� N �� 1024)�� �־�����. N�� �׻� 2�� �ŵ����� ���̴�. (N=2K, 1 �� K �� 10)
���� N���� �ٸ��� �� ���� ���� N���� ���ʴ�� �־�����. ����� ��� ������ -10,000 �̻� 10,000 ������ �����̴�. 

���
�������� ���� ���� ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
int arr[1025][1025];

int two3pulling(int x, int y, int len) {
	if(len == 1) {
		return arr[x][y];
	}
	
	vector<int> v(4);
	
	v[0] = two3pulling(x,y,len/2);
	v[1] = two3pulling(x, y-len/2,len/2);
	v[2] = two3pulling(x-len/2, y,len/2);
	v[3] = two3pulling(x-len/2, y-len/2,len/2);
	
	sort(v.begin(), v.end());
	
	return v[2]; 
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin >> arr[i][j];
		}
	}
	
	cout << two3pulling(n, n, n);
}

/*
�������� 
*/
