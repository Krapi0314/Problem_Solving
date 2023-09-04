/*
baekjoon 2696��: �߾Ӱ� ���ϱ�

�ð� ����: 1��
�޸� ����: 128 MB

����
� ������ �а�, Ȧ����° ���� ���� �� ����, ���ݱ��� �Է¹��� ���� �߾Ӱ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
���� ���, ������ 1, 5, 4, 3, 2 �̸�, Ȧ����° ���� 1��° ��, 3��° ��, 5��° ���̰�, 1��° ���� �о��� �� �߾Ӱ��� 1, 3��° ���� �о��� ���� 4, 5��° ���� �о��� ���� 3�̴�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T(1 �� T �� 1,000)�� �־�����. �� �׽�Ʈ ���̽��� ù° �ٿ��� ������ ũ�� M(1 �� M �� 9999, M�� Ȧ��)�� �־�����, �� ���� �ٺ��� �� ������ ���Ұ� ���ʴ�� �־�����. ���Ҵ� �� �ٿ� 10���� ���������ְ�, 32��Ʈ ��ȣ�ִ� �����̴�.

���
�� �׽�Ʈ ���̽��� ���� ù° �ٿ� ����ϴ� �߾Ӱ��� ������ ����ϰ�, ��° �ٿ��� Ȧ�� ��° ���� ���� �� ���� ���� �߾Ӱ��� ���ʴ�� �������� �����Ͽ� ����Ѵ�. �̶�, �� �ٿ� 10���� ����ؾ� �Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int t;
int n;
int num;
priority_queue<int, vector<int>, less<int> > maxHeap; // �ִ��� -> �߾Ӱ����� ���� �� �� ���� ū ���� ��Ʈ 
priority_queue<int, vector<int>, greater<int> > minHeap; // �ּ��� -> �߾Ӱ����� ū �� �� ���� ���� ���� ��Ʈ 
vector<int> ans;
int mid;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while(t--) {
		while(!minHeap.empty()) {
			minHeap.pop();
		}
		while(!maxHeap.empty()) {
			maxHeap.pop();
		}
		ans.clear();
		
		cin >> n;
		
		for(int i=1; i<=n; i++) {
			cin >> num;
			
			if(i == 1) {
				mid = num;
			}
			else {
				if(num > mid) minHeap.push(num);
				else maxHeap.push(num);
			}
			
			if(i % 2 == 1) { 
				while(minHeap.size() > maxHeap.size()) {
					maxHeap.push(mid);
					mid = minHeap.top(); minHeap.pop();
				}
				while(minHeap.size() < maxHeap.size()) {
					minHeap.push(mid);
					mid = maxHeap.top(); maxHeap.pop();
				}
				ans.push_back(mid);
			}
		}
		
		cout << ans.size() << "\n";
		for(int i=0; i < (int)ans.size(); i++) {
			if(i != 0 && i % 10 == 0)  cout << "\n";
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
}

/*
Data structure
�߾Ӱ� ���ϱ� -> minHeap (�߾Ӱ����� ū �� �� ���� ���� ���� ��Ʈ), maxHeap (�߾Ӱ����� ���� �� �� ���� ū ���� ��Ʈ) 2���� priorty_queue�� ����Ͽ� �߾Ӱ� ���� �� ���� 

multiset���� �ذ��� ����

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int t;
int n;
int num;
multiset<int> ms;
multiset<int>::iterator iter;
vector<int> v;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> t;
	while(t--) {
		ms.clear();
		v.clear();
		
		cin >> n;
		
		for(int i=1; i<=n; i++) {
			cin >> num;
			ms.insert(num);
			
			if(i % 2 != 0) {
				iter = ms.begin();
				int cnt = i / 2;
				while(cnt--) {
					iter++;
				}
				v.push_back(*iter);
			}
		}
		
		cout << v.size() << "\n";
		
		int cnt = 0;
		for(int i=0; i < (int)v.size(); i++, cnt++) {
			if(cnt == 10) {
				cout << "\n";
				cnt = 0;
			}
			cout << v[i] << " ";
		}
		
		cout << "\n";
	}
}
*/ 
