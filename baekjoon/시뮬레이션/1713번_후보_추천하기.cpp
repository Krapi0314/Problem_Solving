// https://www.acmicpc.net/problem/1713

#include <bits/stdc++.h>

using namespace std;

int n, student_n;
int num;

map<int,pair<int,int>> candidates; // student_num, <upvote, age>
int min_upvote = 2e9;

int main() {
    cin >> n;
    cin >> student_n;

    while(student_n--) {
        cin >> num;

        // also consider that student is already exists even if candidates is not filled.
        if(candidates.find(num) != candidates.end()) {
            candidates[num] = {candidates[num].first + 1, candidates[num].second};
            bool min_exists = false;
            for(auto &ele : candidates) {
                if(ele.second.first == min_upvote) {
                    min_exists = true;
                    break;
                }
            }

            if(!min_exists) min_upvote++;
        } else {
            if(candidates.size() == n) {
                int min_upvoted_student_num = 0;
                int min_upvoted_student_num_age = 0;
                for(auto &ele : candidates) {
                    if(ele.second.first == min_upvote) {
                        if(ele.second.second > min_upvoted_student_num_age) {
                            min_upvoted_student_num = ele.first;
                            min_upvoted_student_num_age = ele.second.second;
                        }
                    }
                }

                candidates.erase(min_upvoted_student_num);
                candidates[num] = {1, student_n};
                min_upvote = 1;
            } else {
                candidates[num] = {1, student_n};
                min_upvote = 1;
            }
        }
    }

    for(auto &ele : candidates) {
        cout << ele.first << " ";
    }

    return 0;
}