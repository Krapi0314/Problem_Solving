#include <bits/stdc++.h>

using namespace std;

unordered_map<string, vector<int>> m;
string str;

void generate(int cnt, vector<string>& v) {
    if(cnt == 4) {
        m[str].push_back(stoi(v[4]));
        return;
    }

    str += v[cnt];
    generate(cnt+1, v);
    str = str.substr(0, str.size()-v[cnt].size());

    str += "-";
    generate(cnt+1, v);
    str = str.substr(0, str.size()-1);
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<string> v(5);
    string tmp;

    for(auto& i : info) {
        stringstream ss(i);
        ss >> v[0] >> v[1] >> v[2] >> v[3] >> v[4];

        // 해당 info가 나오는 모든(16가지) 조합의 query를 key로 만들어 저장
        generate(0, v);
    }

    for(auto& t : m) {
        sort(t.second.begin(), t.second.end());
    }

    vector<int> answer;
    for(auto& q : query) {
        stringstream ss(q);
        ss >> v[0] >> tmp >> v[1] >> tmp >> v[2] >> tmp >> v[3] >> v[4];

        tmp = v[0] + v[1] + v[2] + v[3];
        answer.push_back(m[tmp].end() - lower_bound(m[tmp].begin(), m[tmp].end(), stoi(v[4])));
    }

    return answer;
}
