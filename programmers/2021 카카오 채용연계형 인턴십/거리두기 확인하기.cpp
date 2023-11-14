#include <bits/stdc++.h>

using namespace std;

char arr[5][5];
bool visited[5][5];
bool valid;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void dfs(int y, int x, int move) {
    if(move != 0 && arr[y][x] == 'P') {
        valid = false;
        return;
    }

    visited[y][x] = true;

    for(int i=0; i<4; i++) {
        int newx = x + dx[i];
        int newy = y + dy[i];

        if((0 <= newx && newx < 5) && (0 <= newy && newy < 5)) {
            if(valid && move < 2 && arr[newy][newx] != 'X' && !visited[newy][newx]) {
                dfs(newy, newx, move+1);
            }
        }
    }
}

bool validate() {
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            if(arr[i][j] == 'P') {
                memset(visited, false, sizeof(visited));
                valid = true;
                dfs(i, j, 0);

                if(!valid) {
                    return false;
                }
            }
        }
    }

    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            for(int k=0; k<5; k++) {
                arr[j][k] = places[i][j][k];
            }
        }

        if(validate()) answer.push_back(1);
        else answer.push_back(0);
    }

    return answer;
}
