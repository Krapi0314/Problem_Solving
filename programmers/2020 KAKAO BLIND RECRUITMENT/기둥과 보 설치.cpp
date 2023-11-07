#include <bits/stdc++.h>

using namespace std;

#define MAX 100

bool column[MAX+1][MAX+1];
bool plate[MAX+1][MAX+1];

bool validate_column_install(int x, int y) {
    if(y == 0) return true;
    if(column[y-1][x]) return true;
    if(plate[y][x] || x > 0 && plate[y][x-1]) return true;

    return false;
}

bool validate_plate_install(int x, int y) {
    if(y > 0 && column[y-1][x] || column[y-1][x+1]) return true;
    if(x > 0 && plate[y][x-1] && plate[y][x+1]) return true;

    return false;
}

bool validate_all(int n) {
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            if(column[i][j] && !validate_column_install(j, i)) return false;
            if(plate[i][j] && !validate_plate_install(j, i)) return false;
        }
    }

    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    for(auto bf : build_frame) {
        int x = bf[0]; int y = bf[1];
        int ty = bf[2]; int op = bf[3];

        if(op == 1) {
            if(ty == 0 && validate_column_install(x, y)) column[y][x] = true;
            else if(ty == 1 && validate_plate_install(x, y)) plate[y][x] = true;
        } else {
            if(ty == 0) {
                column[y][x] = false;
                if(!validate_all(n)) column[y][x] = true;
            } else {
                plate[y][x] = false;
                if(!validate_all(n)) plate[y][x] = true;
            }
        }
    }

    for(int j=0; j<=n; j++) {
        for(int i=0; i<=n; i++) {
            if(column[i][j]) answer.push_back({j, i, 0});
            if(plate[i][j]) answer.push_back({j, i, 1});
        }
    }

    return answer;
}