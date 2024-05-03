#include <bits/stdc++.h>

using namespace std;

// Should be less than O(nlogn)
int solution(vector<int> &numbers) {
    set<int> s;
    for(auto &n : numbers) s.insert(n);

    int cnt = 0; int p; int same_num_cnt; int diff_num_cnt;
    for(int n=0; n<=20; n++) {
        same_num_cnt = 0; diff_num_cnt = 0;
        p = pow(2, n);
        for(auto &ss : s) {
            if(p == ss * 2) same_num_cnt++;
            else if(s.find(p - ss) != s.end()) diff_num_cnt++;
        }
        cnt += same_num_cnt + diff_num_cnt / 2;
    }

    return cnt;
}

int main() {
    vector<int> numbers = { 1, -1, 2, 3 };
    cout << solution(numbers);
    return 0;
}