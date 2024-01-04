/*
 * https://www.acmicpc.net/problem/2096
 */

#include <bits/stdc++.h>

using namespace std;

// dp[0/1][idx]: 현재, idx가 가질 수 있는 최대/최소 값
// 반대로 생각: idx가 이전 줄에서 점수를 받는다고 생각
int dp[2][3];
int n, t1, t2, t3, max1, max2, max3, min1, min2, min3;
int Max, Min;

int main() {
    Max = 0; Min = 2e9;

    cin >> n;
    for(int i=0; i<3; i++) {
        cin >> t1;
        dp[0][i] = t1; dp[1][i] = t1;
    }
    for(int i=0; i<n-1; i++) {
        cin >> t1 >> t2 >> t3;

        // idx = 0
        max1 = t1 + dp[0][0];
        max1 = max(max1, t1 + dp[0][1]);

        min1 = t1 + dp[1][0];
        min1 = min(min1, t1 + dp[1][1]);

        // idx = 1
        max2 = t2 + dp[0][0];
        max2 = max(max2, t2 + dp[0][1]);
        max2 = max(max2, t2 + dp[0][2]);

        min2 = t2 + dp[1][0];
        min2 = min(min2, t2 + dp[1][1]);
        min2 = min(min2, t2 + dp[1][2]);

        // idx = 2
        max3 = t3 + dp[0][1];
        max3 = max(max3, t3 + dp[0][2]);

        min3 = t3 + dp[1][1];
        min3 = min(min3, t3 + dp[1][2]);

        // update
        dp[0][0] = max1; dp[0][1] = max2; dp[0][2] = max3;
        dp[1][0] = min1; dp[1][1] = min2; dp[1][2] = min3;
    }

    Max = max(Max, dp[0][0]); Max = max(Max, dp[0][1]); Max = max(Max, dp[0][2]);
    Min = min(Min, dp[1][0]); Min = min(Min, dp[1][1]); Min = min(Min, dp[1][2]);

    cout << Max << " " << Min;
    return 0;
}