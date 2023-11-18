#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int> m;
    for(auto t : terms) m[t[0]] = stoi(t.substr(2));
    int today_day = (stoi(today.substr(0,4)) * 12 + stoi(today.substr(5,2))) * 28 + stoi(today.substr(8,2));

    for(int i=0; i<privacies.size(); i++) {
        string p = privacies[i];
        char p_type = p[11];
        int p_expire_day = (stoi(p.substr(0,4)) * 12 + stoi(p.substr(5,2)) + m[p_type]) * 28 + stoi(p.substr(8,2));

        if(today_day >= p_expire_day) answer.push_back(i+1);
    }

    return answer;
}
