/*
 * https://www.acmicpc.net/problem/2493
 */

#include <bits/stdc++.h>

using namespace std;

stack<pair<int,int>> st;
stack<pair<int,int>> temp;
vector<int> ans;
int n, t;

int main() {
    cin >> n;
    ans.resize(n+1, 0);

    for(int i=1; i<=n; i++) {
        cin >> t;
        st.push({t, i});
    }

    while(!st.empty()) {
        auto top = st.top(); st.pop();

        if(st.empty()) {
            while(!temp.empty()) {
                if(top.first >= temp.top().first) {
                    ans[temp.top().second] = top.second;
                    temp.pop();
                } else {
                    break;
                }
            }
        } else {
            if(st.top().first >= top.first)  {
                ans[top.second] = st.top().second;
            } else {
                temp.push(top);
            }

            while(!temp.empty()) {
                if(st.top().first >= temp.top().first) {
                    ans[temp.top().second] = st.top().second;
                    temp.pop();
                } else {
                    break;
                }
            }
        }
    }

    for(int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}