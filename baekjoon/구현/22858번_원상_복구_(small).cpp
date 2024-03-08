#include <bits/stdc++.h>

using namespace std;

#define MAX 10000

int s[MAX+1];
int p[MAX+1];
int d[MAX+1];

int n, k;

int main() {
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> s[i];
    for(int i=1; i<=n; i++) cin >> d[i];

    while(k--) {
        for(int i=1; i<=n; i++) p[d[i]] = s[i];
        memcpy(s, p, sizeof(int) * (n+1));
    }

    for(int i=1; i<=n; i++) cout << s[i] << " ";

    return 0;
}