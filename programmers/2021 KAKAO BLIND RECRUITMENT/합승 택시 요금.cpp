#include <bits/stdc++.h>

using namespace std;

#define MAX 200

vector<vector<pair<int,int>>> g(MAX+1);

int dijkstra(int start, int end, int num) {
    int dist[num+1];
    fill(dist+0, dist+num+1, 2e9);
    dist[start] = 0;

    priority_queue<pair<int,int>> pq;
    pq.push({0, start});

    while(!pq.empty()) {
        int d = -pq.top().first;
        int n = pq.top().second;
        pq.pop();

        if(n == end) {
            break;
        }

        if(dist[n] < d) {
            continue;
        }

        for(auto t : g[n]) {
            int nn = t.first;
            int nd = t.second;

            if(nd + d < dist[nn]) {
                dist[nn] = nd + d;
                pq.push({-dist[nn], nn});
            }
        }
    }

    return dist[end];
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    for(auto f : fares) {
        g[f[0]].push_back({f[1], f[2]});
        g[f[1]].push_back({f[0], f[2]});
    }

    int answer = 2e9;
    for(int c=1; c<=n; c++) {
        int sc = dijkstra(s, c, n);
        int ca = dijkstra(c, a, n);
        int cb = dijkstra(c, b, n);
        answer = min(answer, sc+ca+cb);
    }

    return answer;
}
