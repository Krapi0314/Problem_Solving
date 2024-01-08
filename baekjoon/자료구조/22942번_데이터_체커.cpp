/*
 * https://www.acmicpc.net/problem/22942
 */

#include <bits/stdc++.h>

using namespace std;

int n, x, r;
int r1, r2;
stack<pair<int,int>> st;
vector<pair<int,int>> v;

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x >> r;
        r1 = x - r; r2 = x + r;

        v.push_back({r1, i});
        v.push_back({r2, i});
    }

    sort(v.begin(), v.end());

    // 스택을 이용한 올바른 괄호 문제처럼, 같은 원에 속하는 점을 만나면 빼내고, 아니면 삽입
    for(auto p : v) {
        if(!st.empty() && p.second == st.top().second) {
            st.pop();
        } else {
            st.push(p);
        }
    }

    // 스택이 비어있지 않다는 것은 어딘가에 교점이 존재하는 원들이 존재한다는 의미
    if(st.empty()) cout << "YES";
    else cout << "NO";

    return 0;
}
