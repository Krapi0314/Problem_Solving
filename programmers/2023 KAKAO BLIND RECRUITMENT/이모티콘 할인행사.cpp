#include <bits/stdc++.h>

using namespace std;

int n, m;
int possible[4] = { 10, 20, 30, 40 };
vector<int> discount;
vector<int> answer(2);

void backtrack(int cnt, vector<vector<int>>& users, vector<int>& emoticons) {
    if(cnt == m) {
        int signup_cnt = 0;
        int profit = 0;

        vector<int> emo_price(m);
        for(int i=0; i<m; i++) {
            emo_price[i] = emoticons[i] / 100 * (100 - discount[i]);
        }

        for(auto user : users) {
            int user_paid = 0;
            for(int i=0; i<m; i++) {
                if(discount[i] >= user[0]) {
                    user_paid += emo_price[i];
                }
            }

            if(user_paid >= user[1]) signup_cnt++;
            else profit += user_paid;
        }

        answer = max(answer, { signup_cnt, profit });

        return;
    }

    for(int i=0; i<4; i++) {
        discount.push_back(possible[i]);
        backtrack(cnt+1, users, emoticons);
        discount.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    n = users.size(); m = emoticons.size();

    backtrack(0, users, emoticons);

    return answer;
}
