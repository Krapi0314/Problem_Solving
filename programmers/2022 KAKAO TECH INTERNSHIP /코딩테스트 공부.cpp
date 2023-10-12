#include <string>
#include <vector>
#include <algorithm>

#define MAX 150

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int malp = 0; int mcop = 0;
    int dp[MAX+1][MAX+1];

    for(int i=0; i<=MAX; i++) {
        for(int j=0; j<=MAX; j++) {
            dp[i][j] = 2e9;
        }
    }

    for(auto p : problems) {
        if(p[0] > malp) malp = p[0];
        if(p[1] > mcop) mcop = p[1];
    }

    // dp 연산 범위가 최대 알고력(malp)과 코딩력(mcop)을 넘지 않도록 인덱스(i,j)를 계속 보정

    alp = min(alp, malp);
    cop = min(cop, mcop);

    dp[alp][cop] = 0;
    for(int i=alp; i<=malp; i++) {
        for(int j=cop; j<=mcop; j++) {
            if(i < malp) dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 1);
            if(j < mcop) dp[i][j+1] = min(dp[i][j+1], dp[i][j] + 1);

            for(auto p : problems) {
                if(i >= p[0] && j >= p[1]) {
                    int nalp = min(malp, i+p[2]);
                    int ncop = min(mcop, j+p[3]);
                    dp[nalp][ncop] = min(dp[nalp][ncop], dp[i][j] + p[4]);
                }
            }
        }
    }

    return dp[malp][mcop];
}
