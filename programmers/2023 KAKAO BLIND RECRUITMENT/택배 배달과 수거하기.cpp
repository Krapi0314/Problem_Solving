#include <bits/stdc++.h>

using namespace std;

int update(vector<int>& v, int idx, int cap) {
    while(cap > 0 && idx >= 0) {
        if(cap > v[idx]) {
            cap -= v[idx];
            v[idx] = 0;
            idx--;
        } else {
            v[idx] -= cap;
            cap = 0;
        }
    }

    return idx;
}

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int idx = n - 1;

    // greedy
    while(true) {
        while(deliveries[idx] == 0 && pickups[idx] == 0) idx--;

        if(idx < 0) break;

        answer += (idx+1);
        idx = max(update(deliveries, idx, cap), update(pickups, idx, cap));
    }

    return answer * 2;
}
