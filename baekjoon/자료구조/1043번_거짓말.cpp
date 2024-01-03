/*
 * https://www.acmicpc.net/problem/1043
 */

#include <bits/stdc++.h>

using namespace std;

int n, m, t;
int ans;
int temp;

set<int> truth;
vector<set<int>> party;
vector<int> parent;

int Find(int x) {
    if(x == parent[x]) {
        return x;
    } else {
        int p = Find(parent[x]);
        parent[x] = p;
        return p;
    }
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if(x != y) parent[y] = x;
}

bool exists(set<int> &s) {
    for(auto tr : truth) {
        for(auto ss : s) {
            if(Find(ss) == Find(tr)) return true;
        }
    }

    return false;
}

int main() {
    cin >> n >> m;

    parent.resize(n+1);
    for(int i=1; i<=n; i++) parent[i] = i;

    cin >> t;
    while(t--) {
        cin >> temp;
        truth.insert(temp);
    }

    for(int i=0; i<m; i++) {
        set<int> s;
        int first;

        cin >> t;
        cin >> first;
        s.insert(first);

        t--;
        while(t--) {
            cin >> temp;
            s.insert(temp);
        }
        for(auto ss : s) {
            Union(first, ss);
        }
        party.push_back(s);
    }

    for(auto ss : parent) cout << ss << " ";
    cout << "\n";

    // check existence of people who should not lie to
    for(auto p : party) {
        if(!exists(p)) ans++;
    }

    cout << ans;

    return 0;
}