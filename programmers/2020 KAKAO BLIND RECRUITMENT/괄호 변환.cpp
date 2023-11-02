#include <bits/stdc++.h>

using namespace std;

bool is_balanced(string p) {
    int lc = 0; int rc = 0;

    for(auto c : p) {
        if(c == '(') lc++;
        else rc++;
    }

    return lc == rc;
}

bool is_correct(string p) {
    stack<char> s;

    for(auto c : p) {
        if(c == '(') {
            s.push('(');
        } else {
            if(!s.empty()) {
                s.pop();
            } else {
                return false;
            }
        }
    }

    return s.empty();
}

int find_idx(string p) {
    for(int i=2; i<=p.size(); i++) {
        string u = p.substr(0, i);
        string v = p.substr(i);

        if(is_balanced(u) && (is_balanced(v)) || v.empty()) {
            return i;
        }
    }
}

string recursive(string p) {
    if(p.empty()) return "";

    int idx = find_idx(p);
    string u = p.substr(0, idx);
    string v = p.substr(idx);

    if(is_correct(u)) {
        return u + recursive(v);
    } else {
        for(auto &c : u) c = (c == '(') ? ')' : '(';
        return "(" + recursive(v) + ")" + u.substr(1, u.size()-2);
    }
}

string solution(string p) {
    return recursive(p);
}
