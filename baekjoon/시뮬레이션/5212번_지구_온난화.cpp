// https://www.acmicpc.net/problem/5212

#include <bits/stdc++.h>

using namespace std;

int r, c;
char m[12][12];
bool sinked[12][12];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int min_x, min_y, max_x, max_y;

bool can_be_sinked(int i, int j) {
    int cnt = 0;
    for(int k=0; k<4; k++) {
        int new_i = i+dy[k];
        int new_j = j+dx[k];

        if(m[new_i][new_j] == '.') {
            cnt++;
        }
    }

    return cnt >= 3;
}

int main() {
    min_x = 11; min_y = 11;
    for(int i=0; i<12; i++) {
        for(int j=0; j<12; j++) {
            m[i][j] = '.';
        }
    }

    cin >> r >> c;
    for(int i=1; i<=r; i++) {
        for(int j=1; j<=c; j++) {
            cin >> m[i][j];
        }
    }

    for(int i=1; i<=r; i++) {
        for(int j=1; j<=c; j++) {
            if(m[i][j] == 'X') {
                if(can_be_sinked(i,j)) {
                    sinked[i][j] = true;
                } else {
                    min_x = min(min_x, j);
                    min_y = min(min_y, i);
                    max_x = max(max_x, j);
                    max_y = max(max_y, i);
                }
            }
        }
    }

    for(int i=1; i<=r; i++) {
        for(int j=1; j<=c; j++) {
            if(sinked[i][j]) {
                m[i][j] = '.';
            }
        }
    }

    for(int i=min_y; i<=max_y; i++) {
        for(int j=min_x; j<=max_x; j++) {
            cout << m[i][j];
        }
        cout << "\n";
    }

    return 0;
}