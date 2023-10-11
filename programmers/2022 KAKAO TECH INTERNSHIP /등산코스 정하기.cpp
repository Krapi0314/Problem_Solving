#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 50000

vector<vector<pair<int,int>>> adj(MAX+1);
vector<int> answer(2);
int intensity[MAX+1];
bool is_summit[MAX+1];

void dijkstra(int n, vector<int>& gates, vector<int>& summits) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<pair<int,int>> course;

    fill(intensity, intensity+n+1, 2e9);

    for(auto g : gates) {
        intensity[g] = 0;
        pq.push({0, g});
    }

    for(auto s : summits) {
        is_summit[s] = true;
    }

    while(!pq.empty()) {
        int intense = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(intense > intensity[node]) {
            continue;
        }

        if(is_summit[node]) {
            course.push_back({intensity[node], node});
            continue;
        }

        for(auto adj_node : adj[node]) {
            int next_intense = adj_node.second;
            int next_node = adj_node.first;

            int v = max(intense, next_intense);
            if(v < intensity[next_node]) {
                intensity[next_node] = v;
                pq.push({v, next_node});
            }
        }
    }

    sort(course.begin(), course.end());
    answer[0] = course[0].second;
    answer[1] = course[0].first;
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    for(auto p : paths) {
        int a = p[0];
        int b = p[1];
        int d = p[2];

        adj[a].push_back({b, d});
        adj[b].push_back({a, d});
    }

    dijkstra(n, gates, summits);

    return answer;
}
