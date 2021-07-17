/*
BOJ 2668번: 숫자고르기

시간 제한: 1초
메모리 제한: 128 MB

문제
세로 두 줄, 가로로 N개의 칸으로 이루어진 표가 있다. 첫째 줄의 각 칸에는 정수 1, 2, …, N이 차례대로 들어 있고 둘째 줄의 각 칸에는 1이상 N이하인 정수가 들어 있다. 첫째 줄에서 숫자를 적절히 뽑으면, 그 뽑힌 정수들이 이루는 집합과, 뽑힌 정수들의 바로 밑의 둘째 줄에 들어있는 정수들이 이루는 집합이 일치한다. 이러한 조건을 만족시키도록 정수들을 뽑되, 최대로 많이 뽑는 방법을 찾는 프로그램을 작성하시오. 예를 들어, N=7인 경우 아래와 같이 표가 주어졌다고 하자.
이 경우에는 첫째 줄에서 1, 3, 5를 뽑는 것이 답이다. 첫째 줄의 1, 3, 5밑에는 각각 3, 1, 5가 있으며 두 집합은 일치한다. 이때 집합의 크기는 3이다. 만약 첫째 줄에서 1과 3을 뽑으면, 이들 바로 밑에는 정수 3과 1이 있으므로 두 집합이 일치한다. 그러나, 이 경우에 뽑힌 정수의 개수는 최대가 아니므로 답이 될 수 없다.

입력
첫째 줄에는 N(1≤N≤100)을 나타내는 정수 하나가 주어진다. 그 다음 줄부터는 표의 둘째 줄에 들어가는 정수들이 순서대로 한 줄에 하나씩 입력된다.

출력
첫째 줄에 뽑힌 정수들의 개수를 출력하고, 그 다음 줄부터는 뽑힌 정수들을 작은 수부터 큰 수의 순서로 한 줄에 하나씩 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
int arr[101];
bool visited[101];
vector<int> cycle;
vector<int> ans;
vector<int> ans_plus;
int cnt;
int first;

void dfs(int vertex) {

	// 이미 방문했던 첫번째 정점으로 돌아왔다면 -> 사이클 완성됨 
	if(vertex == first && visited[vertex]) {
		// !! 사이클이 여러 개 나오면 해당 사이클들을 모두 합한 집합이 답이 됨 !!
		ans.insert(ans.begin(), cycle.begin(), cycle.end());
	}
	// 방문하지 않았다면 
	else if(!visited[vertex]) {
		visited[vertex] = true;
		cycle.push_back(vertex);
		dfs(arr[vertex]);
	}
	// 이외의 경우: 방문했지만 사이클이 아닌 경우 
	else {
		return;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	// 사이클을 이루는 정점들 찾기
	
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> arr[i];
	}

	// 모든 정점에 대해 dfs
	for(int i=1; i<=n; i++) {
		// 방문 기록 초기화
		// 자기참조 정점이면 -> ans_plus에 저장
		if(arr[i] == i) {
			ans_plus.push_back(i);
		}
		else {
			memset(visited, false, sizeof(visited));
			cycle.clear();
			first = i;
			dfs(i);
		}
	}
		
	// ans + ans_plus 벡터 합친후 sort
	ans.insert(ans.end(), ans_plus.begin(), ans_plus.end());
	sort(ans.begin(),ans.end());
	
	// 집합이므로 같은 원소 삭제
	ans.erase(unique(ans.begin(), ans.end()),ans.end());
	cnt = ans.size();
	
	// 출력
	cout << cnt << "\n";
	for(int i=0; i<cnt; i++) {
		cout << ans[i] << "\n";
	}  
}

/*
dfs - cycle
*/
