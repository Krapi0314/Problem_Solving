#include <bits/stdc++.h>

using namespace std;

vector<int> answer;

bool validate(string s) {
    int len = s.size();

    if(len == 1) return true;
    if(len % 2 == 0) return false;

    // 서브트리의 루트가 0이면, 자식들은 모두 0이여야 함
    // 서브트리의 루트가 1이면, 왼쪽/오른쪽 서브트리를 타고 들어가 추가 검증
    if(s[len/2] == '0') {
        if(s.find("1") != string::npos) return false;
    } else {
        if(!validate(s.substr(0, len/2))) return false;
        if(!validate(s.substr(len/2+1))) return false;
    }

    return true;
}

vector<int> solution(vector<long long> numbers) {
    for(auto n : numbers) {
        string s;
        while(n != 0) {
            s += to_string(n % 2);
            n /= 2;
        }

        int h = 1; int len = s.size();
        while(h - 1 < s.size()) {
            h *= 2;
        }
        for(int i=0; i<h-1-len; i++) s.push_back('0');
        reverse(s.begin(), s.end());

        if(validate(s)) answer.push_back(1);
        else answer.push_back(0);
    }

    return answer;
}
