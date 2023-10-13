#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    unordered_map<string, vector<string>> m;
    unordered_map<string, int> fre;
    unordered_map<string, int> conv;

    for(int i=0; i<id_list.size(); i++) {
        conv.insert({id_list[i], i});
    }

    sort(report.begin(), report.end());
    report.erase(unique(report.begin(), report.end()), report.end());

    for(auto str : report) {
        string reporter, reported;
        stringstream ss(str);
        ss >> reporter >> reported;

        m[reporter].push_back(reported);
        fre[reported]++;
    }

    for(auto s : m) {
        int cnt = 0;

        for(auto reported : s.second) {
            if(fre[reported] >= k) {
                cnt++;
            }
        }

        answer[conv[s.first]] = cnt;
    }

    return answer;
}
