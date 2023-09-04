/*
baekjoon 1167번: 트리의 지름

시간 제한: 2초
메모리 제한: 256 MB

문제
트리의 지름이란, 트리에서 임의의 두 점 사이의 거리 중 가장 긴 것을 말한다. 트리의 지름을 구하는 프로그램을 작성하시오.

입력
트리가 입력으로 주어진다. 먼저 첫 번째 줄에서는 트리의 정점의 개수 V가 주어지고 (2 ≤ V ≤ 100,000)둘째 줄부터 V개의 줄에 걸쳐 간선의 정보가 다음과 같이 주어진다. 정점 번호는 1부터 V까지 매겨져 있다.
먼저 정점 번호가 주어지고, 이어서 연결된 간선의 정보를 의미하는 정수가 두 개씩 주어지는데, 하나는 정점번호, 다른 하나는 그 정점까지의 거리이다. 예를 들어 네 번째 줄의 경우 정점 3은 정점 1과 거리가 2인 간선으로 연결되어 있고, 정점 4와는 거리가 3인 간선으로 연결되어 있는 것을 보여준다. 각 줄의 마지막에는 -1이 입력으로 주어진다. 주어지는 거리는 모두 10,000 이하의 자연수이다.

출력
첫째 줄에 트리의 지름을 출력한다.

예제 입력 1:
5
1 3 2 -1
2 4 4 -1
3 1 2 4 3 -1
4 2 4 3 3 5 6 -1
5 4 6 -1

예제 출력 1:
11
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAX 100000

int v;
int vn, avn, dist;
int farthest_dist;
int farthest_vertex_from_root;

vector<pair<int,int> > tree[MAX+1];
bool visited[MAX+1];

void dfs(int vertex, int dist_sum) {
    visited[vertex] = true;

    if (dist_sum > farthest_dist) {
        farthest_dist = dist_sum;
        farthest_vertex_from_root = vertex;
    }

    for(int i = 0; i < tree[vertex].size(); i++) {
        int next_vertex = tree[vertex][i].first;
        int dist = tree[vertex][i].second;

        if (!visited[next_vertex]) {
            dfs(next_vertex, dist_sum + dist);
        }
    }
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    cin >> v;
    while(v--) {
        cin >> vn;

        while(true) {
            cin >> avn;
            
            if (avn == -1) {
                break;
            }
            cin >> dist;
            
            tree[vn].push_back({ avn, dist });
        }
    }

    dfs(1, 0);
    memset(visited, false, sizeof(visited));
    dfs(farthest_vertex_from_root, 0);

    cout << farthest_dist << "\n";
    return 0;
}

/*
DFS 2번 수행:
1. 임의의 점에서 DFS 수행하여 가장 먼 정점 찾기
2. 가장 먼 정점에서 다시 DFS 수행하여 트리의 지름 찾기
*/
