#include <bits/stdc++.h>

using namespace std;

vector<int> ryan;
vector<int> answer;
int max_diff;

bool smaller() {
    for(int i = 10; i >= 0; i--) {
        if(ryan[i] < answer[i]) return true;
        else if (ryan[i] > answer[i]) return false;
    }
    return false;
}

void backtrack(int idx, int arrow, int n, vector<int>& apeach) {
    if(idx == 11) {
        // 남은 화살 처리
        ryan[10] = n - arrow;

        int ryan_sum = 0;
        int apeach_sum = 0;

        for(int i=0; i<10; i++) {
            if(ryan[i] > apeach[i]) {
                ryan_sum += 10-i;
            } else if(apeach[i] > 0) {
                apeach_sum += 10-i;
            }
        }

        int diff = ryan_sum - apeach_sum;

        if(diff > 0 && diff >= max_diff) {
            if(diff == max_diff && smaller()) return;
            max_diff = diff;
            answer = ryan;
        }

        return;
    }

    // 화살 쏨
    int lion_shot = apeach[idx] + 1;

    if(arrow + lion_shot <= n) {
        ryan.push_back(lion_shot);
        backtrack(idx + 1, arrow + lion_shot, n, apeach);
        ryan.pop_back();
    }

    // 화살 안 쏨
    ryan.push_back(0);
    backtrack(idx + 1, arrow, n, apeach);
    ryan.pop_back();
}

vector<int> solution(int n, vector<int> info) {
    backtrack(0, 0, n, info);

    if(answer.empty()) answer.push_back(-1);

    return answer;
}
