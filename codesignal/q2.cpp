#include <bits/stdc++.h>

using namespace std;

bool is_vowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y';
}

bool pattern_matches(string substr, string pattern) {
    for(int i=0; i<(int)substr.size(); i++) {
        if(pattern[i] == '0' && !is_vowel(substr[i])) return false;
        else if(pattern[i] == '1' && is_vowel(substr[i])) return false;
    }

    return true;
}

int solution(string source, string pattern) {
    int cnt = 0; int pattern_size = pattern.size();
    for(int i=0; i<(int)source.size() - pattern_size; i++) {
        if(pattern_matches(source.substr(i, pattern_size), pattern)) cnt++;
    }

    return cnt;
}

int main() {
    string pattern = "010";
    string source = "amazing";
    cout << solution(source, pattern);
    return 0;
}