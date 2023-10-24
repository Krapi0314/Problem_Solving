#include <bits/stdc++.h>

using namespace std;

set<string> s;
set<pair<int, string>> ss;
vector<char> p;

bool contains_course(string o) {
    bool exists;

    for(auto c1 : p) {
        exists = false;
        for(auto c2 : o) {
            if(c1 == c2) {
                exists = true;
            }
        }

        if(!exists) {
            return false;
        }
    }

    return true;
}

void possible_course(int idx, int n, string o, vector<string>& orders) {
    if(p.size() == n) {
        int cnt = 0;

        for(auto o : orders) {
            if(contains_course(o)) {
                cnt++;
            }
        }

        if(cnt >= 2) {
            string str;
            for(auto c : p) str += c;
            ss.insert({cnt, str});
        }
    }

    for(int i=idx; i<o.size(); i++) {
        p.push_back(o[i]);
        possible_course(i+1, n, o, orders);
        p.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    for(auto n : course) {
        for(auto o : orders) {
            if(o.size() >= n) {
                possible_course(0, n, o, orders);
            }
        }

        if(!ss.empty()) {
            int max_cnt = 0;
            for(auto c : ss) {
                max_cnt = max(max_cnt, c.first);
            }
            for(auto c : ss) {
                if(c.first == max_cnt) {
                    sort(c.second.begin(), c.second.end());
                    s.insert(c.second);
                }
            }
            ss.clear();
        }
    }

    vector<string> answer;
    for(auto c : s) {
        answer.push_back(c);
    }

    return answer;
}
