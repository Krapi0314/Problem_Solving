/*
 * https://www.acmicpc.net/problem/9935
 */

#include <bits/stdc++.h>

using namespace std;

string str;
string pattern;
deque<char> dq;
int str_len;
int pattern_len;
int len;
bool matched;

int main() {
    cin >> str;
    cin >> pattern;

    // 문자열 폭발 이후 다시 폭발 문자열이 생길 수 있기 떄문에, 스택 자료구조로 처리하는 것이 좋음: ex) C(C4)4
    str_len = str.size(); pattern_len = pattern.size();

    for(int i=0; i<str_len; i++) {
        matched = true;
        dq.push_back(str[i]);
        len = dq.size();

        if(len < pattern_len || dq[len-1] != pattern[pattern_len-1]) continue;

        for(int j=0; j<pattern_len; j++) {
            if(dq[len-1-j] != pattern[pattern_len-1-j]) {
                matched = false;
                break;
            }
        }

        if(matched) for(int j=0; j<pattern_len; j++) dq.pop_back();
    }

    if(dq.empty()) cout << "FRULA";
    else {
        len = dq.size();
        for(int i=0; i<len; i++) {
            cout << dq[i];
        }
    }

    return 0;
}
