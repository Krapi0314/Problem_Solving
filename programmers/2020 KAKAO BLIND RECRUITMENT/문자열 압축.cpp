#include <bits/stdc++.h>

using namespace std;

string compress(string str, int n) {
    string res;

    for(int i=0; i<str.size(); ) {
        string delim = str.substr(i, n);

        int cnt = 0;
        while(i < str.size() && str.substr(i, n) == delim) {
            cnt++; i += n;
        }

        res += (cnt > 1) ? (to_string(cnt) + delim) : (delim);
    }

    return res;
}

int solution(string s) {
    int answer = 2e9;

    for(int i=1; i<=s.size(); i++) {
        string cs = compress(s, i);
        answer = min(answer, (int)cs.size());
    }

    return answer;
}
