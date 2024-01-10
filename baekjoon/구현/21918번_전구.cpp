/*
 * https://www.acmicpc.net/problem/21918
 */

#include <bits/stdc++.h>

using namespace std;

int n, m;
int a, b, c;
vector<int> v;

int main() {
    cin >> n >> m;
    v.resize(n+1, 0);
    for(int i=1; i<=n; i++) {
        cin >> v[i];
    }

    while(m--) {
        cin >> a >> b >> c;

        switch(a) {
            case 1:
                v[b] = c;
                break;
            case 2:
                for(int i=b; i<=c; i++) {
                    v[i] = (v[i] == 1) ? (0) : (1);
                }
                break;
            case 3:
                for(int i=b; i<=c; i++) {
                    v[i] = 0;
                }
                break;
            case 4:
                for(int i=b; i<=c; i++) {
                    v[i] = 1;
                }
                break;
        }
    }

    for(int i=1; i<=n; i++) {
        cout << v[i] << " ";
    }

    return 0;
}