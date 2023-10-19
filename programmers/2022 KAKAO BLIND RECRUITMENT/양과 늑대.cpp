#include <bits/stdc++.h>

using namespace std;

int answer;

void bfs(int node, int sheep, int wolf, queue<int> q, vector<int>& info, vector<vector<int>>& graph) {
    // 조건 만족하는지 확인
    int type = info[node];

    if(type == 0) sheep++;
    else wolf++;

    if(wolf >= sheep) return;

    // 최댓값 및 다음에 갈 수 있는 노드 업데이트
    answer = max(answer, sheep);

    for(auto n : graph[node]) {
        q.push(n);
    }

    // 큐 1회 순회하여 완전 탐색 수행
    for(int i=0; i<q.size(); i++) {
        int next = q.front(); q.pop();
        bfs(next, sheep, wolf, q, info, graph);
        q.push(next);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    vector<vector<int>> graph(info.size());
    for(auto e : edges) {
        graph[e[0]].push_back(e[1]);
    }

    // 다음에 갈 수 있는 노드들을 저장하는 큐
    queue<int> q;
    bfs(0, 0, 0, q, info, graph);

    return answer;
}
