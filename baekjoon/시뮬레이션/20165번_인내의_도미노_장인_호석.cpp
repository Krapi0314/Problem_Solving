// https://www.acmicpc.net/problem/20165

#include <bits/stdc++.h>

using namespace std;

#define MAX 100

int n, m;
int r, x, y; char d;
int ans;

int arr[MAX+1][MAX+1];
bool fall[MAX+1][MAX+1];

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int push_domino(int xx, int yy, char direction) {
    if(fall[yy][xx]) return 0;

    int d_idx = 0;
    switch(direction) {
        case 'E':
            d_idx = 2;
            break;
        case 'W':
            d_idx = 3;
            break;
        case 'S':
            d_idx = 0;
            break;
        case 'N':
            d_idx = 1;
            break;
    }

    queue<pair<int,int>> q;
    q.push({yy, xx});
    fall[yy][xx] = true;

    int cnt = 0;
    while(!q.empty()) {
        int fall_y = q.front().first;
        int fall_x = q.front().second;
        q.pop();
        cnt++;

        int height = arr[fall_y][fall_x];
        for(int i=1; i<=height-1; i++) {
            int new_y = fall_y + dy[d_idx] * i;
            int new_x = fall_x + dx[d_idx] * i;

            if(1 <= new_y && new_y <= n && 1 <= new_x && new_x <= m) {
                if(!fall[new_y][new_x]) {
                    fall[new_y][new_x] = true;
                    q.push({new_y, new_x});
                }
            }
        }
    }

    return cnt;
}

void stand_domino(int xx, int yy) {
    if(!fall[yy][xx]) return;

    fall[yy][xx] = false;
}

int main() {
    cin >> n >> m >> r;

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<r; i++) {
        cin >> y >> x >> d;
        ans += push_domino(x, y, d);

        cin >> y >> x;
        stand_domino(x, y);
    }

    cout << ans << "\n";
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cout << (fall[i][j] ? ("F") : ("S")) << " ";
        }
        cout << "\n";
    }

    return 0;
}