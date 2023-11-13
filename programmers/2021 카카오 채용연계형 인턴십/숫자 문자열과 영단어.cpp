#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    string answer;
    string num[10] = { "zero", "one", "two", "three", "four",
                       "five", "six", "seven", "eight", "nine"};

    for(int i=0; i<s.size(); ) {
        if('0' <= s[i] && s[i] <= '9') {
            answer += s[i]; i++;
        } else {
            for(int j=0; j<10; j++) {
                if(s.substr(i, num[j].size()) == num[j]) {
                    answer += to_string(j); i+=num[j].size();
                    break;
                }
            }
        }
    }

    return stoi(answer);
}
