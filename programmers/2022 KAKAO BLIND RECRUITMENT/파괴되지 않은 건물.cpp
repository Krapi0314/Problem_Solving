#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int n = board.size();
    int m = board[0].size();

    // 2차원 Prefix Sum (구간합)
    // skill 순회하며 구간합 계산
    vector<vector<int>> prefix_sum(n+1, vector<int>(m+1, 0));
    for(auto s : skill) {
        int delta = (s[0] == 1) ? (-1 * s[5]) : (s[5]);

        prefix_sum[s[1]][s[2]] += delta;
        prefix_sum[s[1]][s[4]+1] += -1 * delta;
        prefix_sum[s[3]+1][s[2]] += -1 * delta;
        prefix_sum[s[3]+1][s[4]+1] += delta;
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            prefix_sum[i+1][j] += prefix_sum[i][j];
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            prefix_sum[i][j+1] += prefix_sum[i][j];
        }
    }

    // board와 더하여 결과 계산
    int answer = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(board[i][j] + prefix_sum[i][j] >= 1) answer++;
        }
    }

    return answer;
}
