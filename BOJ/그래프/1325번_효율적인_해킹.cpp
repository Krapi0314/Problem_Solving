/*
BOJ 1325번: 효율적인 해킹

시간 제한: 5초
메모리 제하: 256 MB

문제
해커 김지민은 잘 알려진 어느 회사를 해킹하려고 한다. 이 회사는 N개의 컴퓨터로 이루어져 있다. 김지민은 귀찮기 때문에, 한 번의 해킹으로 여러 개의 컴퓨터를 해킹 할 수 있는 컴퓨터를 해킹하려고 한다.
이 회사의 컴퓨터는 신뢰하는 관계와, 신뢰하지 않는 관계로 이루어져 있는데, A가 B를 신뢰하는 경우에는 B를 해킹하면, A도 해킹할 수 있다는 소리다.
이 회사의 컴퓨터의 신뢰하는 관계가 주어졌을 때, 한 번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에, N과 M이 들어온다. N은 10,000보다 작거나 같은 자연수, M은 100,000보다 작거나 같은 자연수이다. 둘째 줄부터 M개의 줄에 신뢰하는 관계가 A B와 같은 형식으로 들어오며, "A가 B를 신뢰한다"를 의미한다. 컴퓨터는 1번부터 N번까지 번호가 하나씩 매겨져 있다.

출력
첫째 줄에, 김지민이 한 번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호를 오름차순으로 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAX 10001

vector<int> adj[MAX];
bool discovered[MAX];
vector<int> v;
queue<int> q;
int n,m,a,b;
int Max,cnt;

void bfs(int vertex) {
	discovered[vertex] = true;
	q.push(vertex);
	
	while(!q.empty()) {
		int here = q.front(); q.pop();
		for(int i=0; i<adj[here].size(); i++) {
			int there = adj[here][i];
			if(!discovered[there]) {
				q.push(there);
				cnt++;
				discovered[there] = true;
			}
		}
	}

}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for(int i=0; i<m; i++) {
		cin >> a >> b;
		adj[b].push_back(a);
	}
	
	for(int i=1; i<=n; i++) {
		memset(discovered,false,sizeof(discovered));
		cnt = 0;
		bfs(i);
		if(cnt > Max) {
			v.clear();
			v.push_back(i);
			Max = cnt;
		}
		else if(cnt == Max) {
			v.push_back(i);
		}
	}
	
	for(int i=0; i<v.size(); i++) {
		cout << v[i] << " ";
	}
}

/*
bfs

vector<int> adj[MAX] : vector<int>들을 MAX개 나열한, 하나하나가 vector<int>인 array임 

bfs(vertex)
	discovered vertex
	cnt++
	queue push vertex
	
	while ! queue empty
		int here = queue front pop
		for n
			int there = adj[here][i]
			if !discovered[there]
				queue push there
				discovered[there]

cin n m
for m
	cin a b
	adj[b].push_back(b)

for n
	memset discovered false
	bfs()
	if cnt > max
		vector clear
		vector pushback i
	else if cnt == max
		vector pushback i
	
for vector
	cout v[i]					
*/
