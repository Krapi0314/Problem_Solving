/*
 * https://www.acmicpc.net/problem/20529
 */
#include <bits/stdc++.h>

using namespace std;

int t, n, ans;
string arr[100000];
vector<string> v;

int diff(string a, string b) {
    int cnt = 0;
    for(int i=0; i<4; i++) {
        if(a[i] != b[i]) cnt++;
    }

    return cnt;
}

void backtrack(int idx, int cnt) {
    if(cnt == 3) {
        int dist = diff(v[0], v[1]) + diff(v[1], v[2]) + diff(v[2], v[0]);
        ans = min(ans, dist);
        return;
    }

    for(int i=idx; i<n; i++) {
        v.push_back(arr[i]);
        backtrack(i+1, cnt+1);
        v.pop_back();
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> arr[i];

        //  비둘기집 원리: 마리보다 더 많은 비둘기가 n개의 구멍으로 들어갔다면, 당연히 적어도 하나의 구멍으로 두 마리 이상이 들어가야 함
        //  n이 32보다 크면(MBTI 종류의 개수인 16보다 2배), 중복되는 MBTI 3개가 반드시 존재하므로, n > 32 이상의 경우에서는 모두 거리가 0
        if(n > 32) {
            ans = 0;
        } else {
            ans = 2e9;
            backtrack(0, 0);
        }
        cout << ans << "\n";
    }

    return 0;
}
