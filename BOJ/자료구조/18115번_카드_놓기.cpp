/*
BOJ 18115번: 카드 놓기

시간 제한: 2초 (추가 시간 없음)
메모리 제한: 1024 MB

문제
수현이는 카드 기술을 연습하고 있다. 수현이의 손에 들린 카드를 하나씩 내려놓아 바닥에 쌓으려고 한다. 수현이가 쓸 수 있는 기술은 다음 3가지다.

제일 위의 카드 1장을 바닥에 내려놓는다.
위에서 두 번째 카드를 바닥에 내려놓는다. 카드가 2장 이상일 때만 쓸 수 있다.
제일 밑에 있는 카드를 바닥에 내려놓는다. 카드가 2장 이상일 때만 쓸 수 있다.
수현이는 처음에 카드 N장을 들고 있다. 카드에는 1부터 N까지의 정수가 중복되지 않게 적혀 있다. 기술을 N번 사용하여 카드를 다 내려놓았을 때, 놓여 있는 카드들을 확인했더니 위에서부터 순서대로 1, 2, …, N이 적혀 있었다!

놀란 수현이는 처음에 카드가 어떻게 배치되어 있었는지 궁금해졌다. 처음 카드의 상태를 출력하여라.

입력
첫 번째 줄에는 N (1 ≤ N ≤ 106)이 주어진다.
두 번째 줄에는 길이가 N인 수열 A가 주어진다. Ai가 x이면, i번째로 카드를 내려놓을 때 x번 기술을 썼다는 뜻이다. Ai는 1, 2, 3 중 하나이며, An은 항상 1이다.

출력
초기 카드의 상태를 위에서부터 순서대로 출력하여라. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
int arr[1000000];
deque<int> dq;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	}
	
	int cnt=1;
	for(int i=n-1; i>=0; i--, cnt++) {
		if(arr[i] == 1) {
			dq.push_front(cnt);
		}
		else if(arr[i] == 2) {
			int temp = dq.front();
			dq.pop_front();
			dq.push_front(cnt);
			dq.push_front(temp);
		}
		else {
			dq.push_back(cnt);
		}
	}
	
	for(int i=0; i<n; i++) {
		cout << dq[i] << " ";
	}
}

/*
자료구조, 앞/뒤 (위/아래)를 모두 사용할 수 있는 자료구조인 deque를 선택 
*/
