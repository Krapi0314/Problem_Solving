// https://www.acmicpc.net/problem/21610

#include <bits/stdc++.h>

using namespace std;

#define MAX 50

int n, m;
int a[MAX][MAX];
bool cloud[MAX][MAX];
int d, s;
int dy[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dx[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int ans;

void move_clouds(int direction, int slide) {
    bool new_cloud[MAX][MAX] = { false, };

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(cloud[i][j]) {
                int new_y = i + dy[direction] * slide;
                int new_x = j + dx[direction] * slide;

                // adjust coordinates
                if(new_y >= n) {
                    while(new_y >= n) new_y -= n;
                } else if(new_y < 0) {
                    while(new_y < 0) new_y += n;
                }
                if(new_x >= n) {
                    while(new_x >= n) new_x -= n;
                } else if(new_x < 0) {
                    while(new_x < 0) new_x += n;
                }

                new_cloud[new_y][new_x] = true;
            }
        }
    }

    // renew cloud
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cloud[i][j] = new_cloud[i][j];
        }
    }
}

void rain_and_fill_by_one() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(cloud[i][j]) a[i][j]++;
        }
    }
}

void copy_water_with_diagonal() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(cloud[i][j]) {
                int cnt = 0;

                for(int k=2; k<=8; k+=2) {
                    int new_y = i+dy[k];
                    int new_x = j+dx[k];

                    if(0 <= new_y && new_y < n && 0 <= new_x && new_x < n) {
                        if(a[new_y][new_x] >= 1) cnt++;
                    }
                }

                a[i][j] += cnt;
            }
        }
    }
}

void create_cloud_and_remove_existed_cloud() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(cloud[i][j]) {
                cloud[i][j] = false;
            } else {
                if(a[i][j] >= 2) {
                    cloud[i][j] = true;
                    a[i][j] -= 2;
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
        }
    }
    // create cloud
    cloud[n-1][0] = true; cloud[n-1][1] = true;
    cloud[n-2][0] = true; cloud[n-2][1] = true;

    // perform operation m times
    while(m--) {
        cin >> d >> s;

        move_clouds(d, s);
        rain_and_fill_by_one();
        copy_water_with_diagonal();
        create_cloud_and_remove_existed_cloud();
    }

    // sum up water
    for(int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            ans += a[i][j];
        }
    }
    cout << ans;
    return 0;
}