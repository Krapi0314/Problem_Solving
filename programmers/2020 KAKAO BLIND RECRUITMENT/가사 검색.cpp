#include <bits/stdc++.h>

using namespace std;

// 같은 길이의 단어에서 정렬되어야 함
bool comp(string a, string b) {
    if(a.size() < b.size()) return true;
    else if(a.size() == b.size()) return a < b;
    else return false;
}

// trie, 이분 탐색으로 해결 가능 (이분 탐색이 실제 코테 환경에서 더 활용성이 높음)
// fro??? -> froaaa ~ frozzz 사이에 있는 문자 -> upper_bound(frozzz) - lower_bound(froaaa)
// 접미사는 reverse하여 접두사처럼 처리
int match(vector<string>& words, string q) {
    string qa = q;
    for(auto &c : qa) {
        if(c == '?') c = 'a';
    }
    auto lower = lower_bound(words.begin(), words.end(), qa, comp);

    string qz = q;
    for(auto &c : qz) {
        if(c == '?') c = 'z';
    }
    auto upper = upper_bound(words.begin(), words.end(), qz, comp);

    return upper - lower;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<string> rwords(words);
    for(auto& rw : rwords) reverse(rw.begin(), rw.end());

    sort(words.begin(), words.end(), comp);
    sort(rwords.begin(), rwords.end(), comp);

    vector<int> answer;
    for(auto q : queries) {
        if(q[0] == '?') {
            string rq(q); reverse(rq.begin(), rq.end());
            answer.push_back(match(rwords, rq));
        } else {
            answer.push_back(match(words, q));
        }
    }

    return answer;
}
