/*
baekjoon 7795��: ���� ���ΰ� ���� ���ΰ�

�ð� ����: 1��
�޸� ����: 256 MB

���� 
���ؿ��� �� ������ ����ü A�� B�� �����Ѵ�. A�� B�� �Դ´�. A�� �ڱ⺸�� ũ�Ⱑ ���� ���̸� ���� �� �ִ�. ���� ���, A�� ũ�Ⱑ {8, 1, 7, 3, 1}�̰�, B�� ũ�Ⱑ {3, 6, 1}�� ��쿡 A�� B�� ���� �� �ִ� ���� ������ 7������ �ִ�. 8-3, 8-6, 8-1, 7-3, 7-6, 7-1, 3-1.
�� ����ü A�� B�� ũ�Ⱑ �־����� ��, A�� ũ�Ⱑ B���� ū ���� �� ���� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����. �� �׽�Ʈ ���̽��� ù° �ٿ��� A�� �� N�� B�� �� M�� �־�����. ��° �ٿ��� A�� ũ�Ⱑ ��� �־�����, ��° �ٿ��� B�� ũ�Ⱑ ��� �־�����. ũ��� ���� �����̴�. (1 �� N, M �� 20,000) 

���
�� �׽�Ʈ ���̽�����, A�� B���� ū ���� ������ ����Ѵ�.
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int t;
int n,m;
vector<int> a;
vector<int> b;
int ans;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> t;
	
	while(t--) {
		a.clear(); b.clear();
		ans = 0;
		
		cin >> n >> m;
		
		int num = 0;
		for(int i=0; i<n; i++) {
			cin >> num;
			a.push_back(num);
		}
		for(int i=0; i<m; i++) {
			cin >> num;
			b.push_back(num);
		}
		
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		
		for(int i=0; i<a.size(); i++) {
			ans += lower_bound(b.begin(), b.end(), a[i]) - b.begin();
		}
		
		cout << ans << "\n";
	}
}

/*
binary search -> lower_bound
*/
