/*
BOJ 2696번: 중앙값 구하기

시간 제한: 1초
메모리 제한: 128 MB

문제
어떤 수열을 읽고, 홀수번째 수를 읽을 때 마다, 지금까지 입력받은 값의 중앙값을 출력하는 프로그램을 작성하시오.
예를 들어, 수열이 1, 5, 4, 3, 2 이면, 홀수번째 수는 1번째 수, 3번째 수, 5번째 수이고, 1번째 수를 읽었을 때 중앙값은 1, 3번째 수를 읽었을 때는 4, 5번째 수를 읽었을 때는 3이다.

입력
첫째 줄에 테스트 케이스의 개수 T(1 ≤ T ≤ 1,000)가 주어진다. 각 테스트 케이스의 첫째 줄에는 수열의 크기 M(1 ≤ M ≤ 9999, M은 홀수)이 주어지고, 그 다음 줄부터 이 수열의 원소가 차례대로 주어진다. 원소는 한 줄에 10개씩 나누어져있고, 32비트 부호있는 정수이다.

출력
각 테스트 케이스에 대해 첫째 줄에 출력하는 중앙값의 개수를 출력하고, 둘째 줄에는 홀수 번째 수를 읽을 때 마다 구한 중앙값을 차례대로 공백으로 구분하여 출력한다. 이때, 한 줄에 10개씩 출력해야 한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int t;
int n;
int num;
priority_queue<int, vector<int>, less<int> > maxHeap; // 최대힙 -> 중앙값보다 작은 수 중 가장 큰 수가 루트 
priority_queue<int, vector<int>, greater<int> > minHeap; // 최소힙 -> 중앙값보다 큰 수 중 가장 작은 수가 루트 
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
중앙값 구하기 -> minHeap (중앙값보다 큰 수 중 가장 작은 수가 루트), maxHeap (중앙값보다 작은 수 중 가장 큰 수가 루트) 2개의 priorty_queue를 사용하여 중앙값 구할 수 있음 

multiset으로 해결한 버전

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
