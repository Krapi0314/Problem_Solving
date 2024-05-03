#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> drop_figure(int idx, vector<vector<int>> field, vector<vector<int>> figure) {
    for(int i=(int)field.size()-3; i>=0; i--) {
        bool fits = true;
        for(int a=0; a<3; a++) {
            for(int b=0; b<3; b++) {
                if(figure[a][b] == 1 && field[a+i][b+idx] == 1) {
                    fits = false;
                    break;
                }
            }
        }

        if(fits) {
            for(int a=0; a<3; a++) {
                for(int b=0; b<3; b++) {
                    if(field[a+i][b+idx] == 0) {
                        field[a+i][b+idx] = figure[a][b];
                    }
                }
            }

            return field;
        }
    }

    return field;
}

bool full_row_filled(vector<vector<int>> &field) {
    for(int i=(int)field.size()-1; i>=0; i--) {
        bool full = true;
        for(int j=0; j<(int)field[0].size(); j++) {
            if(field[i][j] == 0) {
                full = false;
                break;
            }
        }

        if(full) return true;
    }

    return false;
}

int solution(vector<vector<int>> &field, vector<vector<int>> &figure) {
    for(int i=0; i<=(int)field[0].size() - 3; i++) {
        vector<vector<int>> dropped = drop_figure(i, field, figure);
        if(full_row_filled(dropped)) return i;
    }

    return -1;
}

int main() {
    vector<vector<int>> field = {
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {1, 1, 0, 1, 0},
            {1, 0, 1, 0, 1}
    };

    vector<vector<int>> figure = {
            {1, 1, 1},
            {1, 0, 1},
            {1, 0, 1}
    };
    cout << solution(field, figure);
    return 0;
}