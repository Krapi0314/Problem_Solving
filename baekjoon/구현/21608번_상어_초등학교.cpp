/*
 * https://www.acmicpc.net/problem/21608
 */

#include <bits/stdc++.h>

using namespace std;

#define MAX 400

int n, ans;
int stu_n;
int friendly_stu[MAX + 1][4];
int arr[MAX+1][MAX+1];
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int cal_adj_friendly_stu(int y, int x, int num) {
    int cur_stu;
    if(num != 0) cur_stu = num;
    else cur_stu = arr[y][x];
    int cnt = 0;

    for(int i=0; i<4; i++) {
        int adj_y = dy[i] + y;
        int adj_x = dx[i] + x;

        if(0 <= adj_y && adj_y < n && 0 <= adj_x && adj_x < n) {
            int adj_stu = arr[adj_y][adj_x];

            for(int j=0; j<4; j++) {
                if(friendly_stu[cur_stu][j] == adj_stu) {
                    cnt++;
                    break;
                }
            }
        }
    }

    return cnt;
}

int cal_empty_adj(int y, int x) {
    int cnt = 0;

    for(int i=0; i<4; i++) {
        int adj_y = dy[i] + y;
        int adj_x = dx[i] + x;

        if(0 <= adj_y && adj_y < n && 0 <= adj_x && adj_x < n) {
            if(arr[adj_y][adj_x] == 0) cnt++;
        }
    }

    return cnt;
}

vector<pair<int,int>> condition_one(int num) {
    vector<pair<int,int>> zero, one, two, three, four;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(arr[i][j] == 0) {
                switch(cal_adj_friendly_stu(i, j, num)) {
                    case 0:
                        zero.push_back({i,j});
                        break;
                    case 1:
                        one.push_back({i,j});
                        break;
                    case 2:
                        two.push_back({i,j});
                        break;
                    case 3:
                        three.push_back({i,j});
                        break;
                    case 4:
                        four.push_back({i,j});
                        break;
                }
            }
        }
    }

    if(!four.empty()) return four;
    else if(!three.empty()) return three;
    else if(!two.empty()) return two;
    else if(!one.empty()) return one;
    else return zero;
}

vector<pair<int,int>> condition_two(vector<pair<int,int>> &v) {
    vector<pair<int,int>> zero, one, two, three, four;

    for(auto &idx : v) {
        int i = idx.first; int j = idx.second;
        switch(cal_empty_adj(i, j)) {
            case 0:
                zero.push_back({i,j});
                break;
            case 1:
                one.push_back({i,j});
                break;
            case 2:
                two.push_back({i,j});
                break;
            case 3:
                three.push_back({i,j});
                break;
            case 4:
                four.push_back({i,j});
                break;
        }
    }

    if(!four.empty()) return four;
    else if(!three.empty()) return three;
    else if(!two.empty()) return two;
    else if(!one.empty()) return one;
    else return zero;
}

int main() {
    cin >> n;
    stu_n = n*n;
    for(int i=0; i<stu_n; i++) {
        int num; cin >> num;
        for(int j=0; j<4; j++) cin >> friendly_stu[num][j];

        vector<pair<int,int>> t = condition_one(num);
        if(t.size() == 1) {
            arr[t[0].first][t[0].second] = num;
            continue;
        }

        t = condition_two(t);
        if(t.size() == 1) {
            arr[t[0].first][t[0].second] = num;
            continue;
        }

        // condition_three
        arr[t[0].first][t[0].second] = num;
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            switch(cal_adj_friendly_stu(i, j, 0)) {
                case 0:
                    ans += 0;
                    break;
                case 1:
                    ans += 1;
                    break;
                case 2:
                    ans += 10;
                    break;
                case 3:
                    ans += 100;
                    break;
                case 4:
                    ans += 1000;
                    break;
            }
        }
    }
    cout << ans;

    return 0;
}
