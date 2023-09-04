/*
baekjoon 19637��: IF�� �� ��� ����

�ð� ����: 1 �� (�߰� �ð� ����)
�޸� ����: 1024 MB

����
���� �������� �и��� ������ �ý����� �����, ĳ���Ͱ� ���� �������� �������� Īȣ�� �ٿ��ַ��� �Ѵ�.
���� ���, ������ 10,000 ������ ĳ���ʹ� WEAK, 10,000 �ʰ� �׸��� 100,000 ������ ĳ���ʹ� NORMAL, 100,000 �ʰ� �׸��� 1,000,000 ������ ĳ���ʹ� STRONG Īȣ�� �ٿ��شٰ� ����. �̸� IF������ �ۼ��Ѵٸ� �Ʒ��� ���� ������ �� �ִ�.

if power <= 10000
 print WEAK
else if power <= 100000
 print NORMAL
else if power <= 1000000
 print STRONG
 
ȥ�ڼ� ������ �����ϴ��� �ſ� �ٻ� �и��� ����ؼ�, ĳ������ �����¿� �´� Īȣ�� ����ϴ� ���α׷��� �ۼ�����.

�Է�
ù ��° �ٿ��� Īȣ�� ���� N (1 �� N �� 105)�� Īȣ�� ����ؾ� �ϴ� ĳ���͵��� ���� M (1 �� M �� 105)�� ��ĭ�� ���̿� �ΰ� �־�����. (1 �� N, M �� 105)
�� ��° �ٺ��� N���� �ٿ� �� Īȣ�� �̸��� ��Ÿ���� ���� 1 �̻�, 11 ������ ���� �빮�ڷθ� ������ ���ڿ��� �ش� Īȣ�� ������ ���Ѱ��� ��Ÿ���� 109 ������ ���� �ƴ� ������ �־�����. Īȣ�� ������ ���Ѱ��� �񳻸��������� �־�����. 
N + 2��° �ٺ��� M���� �� �ٿ��� ĳ������ �������� ��Ÿ���� ���� �ƴ� ������ �־�����. �ش��ϴ� Īȣ�� ���� �������� �Է����� �־����� �ʴ´�.

���
M���� �ٿ� ���� ĳ������ �����¿� �´� Īȣ�� �Է� ������� ����Ѵ�. � ĳ������ ���������� ����� �� �ִ� Īȣ�� ���� ���� ��� ���� ���� �Էµ� Īȣ �ϳ��� ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAX 100000

int n, m;
int num; string str;
int idx;
vector<int> power;
vector<string> title;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	title.reserve(n);
	power.reserve(n);
	
	for(int i=0; i<n; i++) {
		cin >> str >> num;
		
		if(!power.empty() && power.back() == num) {
			continue; 
		}
		
		power.push_back(num);
		title.push_back(str);
	}
	
	for(int i=0; i<m; i++) {
		cin >> num;
		
		idx = lower_bound(power.begin(),power.end(),num) - power.begin();
		
		cout << title[idx] << "\n";
	}
	
	return 0;
}

/*
�̺�Ž��
vector, �ߺ� ����, lower_bound ��� 

�ٸ� ����: 
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAX 100000

int n, m;
int num;
string str;
pair<int, string> arr[MAX];
int l, r, mid;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	for(int i=0; i<n; i++) {
		cin >> str >> num;
		arr[i] = make_pair(num, str);
	}
	
	for(int i=0; i<m; i++) {
		cin >> num;
		
		l = 0; r = n-1;
		while(l <= r) {
			mid = (l+r) / 2;
			
			if(num <= arr[mid].first) {
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}

		if(r < 0) {
			cout << arr[l].second << "\n";
		}
		else {
			cout << arr[l].second << "\n";
		}
	}
	
	return 0;
}
*/
