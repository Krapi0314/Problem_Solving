#include <bits/stdc++.h>

using namespace std;

string solution(string new_id) {
    string temp;

    // 1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
    for(auto& c : new_id) {
        if('A' <= c && c <= 'Z') c = c - 'A' + 'a';
    }

    // 2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
    temp = new_id; new_id = "";
    for(auto& c : temp) {
        if(('a' <= c && c <= 'z') || ('0' <= c && c <= '9') || (c == '-') || (c == '_') || (c == '.')) new_id += c;
    }

    // 3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
    temp = new_id; new_id = "";
    for(int i=0; i<temp.size(); ) {
        if(temp[i] == '.') {
            new_id += '.';
            while(temp[i] == '.') i++;
        } else {
            new_id += temp[i];
            i++;
        }
    }

    // 4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
    if(!new_id.empty() && new_id[0] == '.') new_id = new_id.erase(0,1);
    if(!new_id.empty() && new_id[new_id.size()-1] == '.') new_id = new_id.erase(new_id.size()-1,1);

    // 5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
    if(new_id.empty()) new_id += "a";

    // 6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
    // 만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
    if(new_id.size() >= 16) {
        new_id = new_id.substr(0,15);
        if(new_id[14] == '.') new_id = new_id.substr(0,14);
    }

    // 7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
    if(new_id.size() <= 2) {
        char last = new_id[new_id.size()-1];
        while(new_id.size() < 3) {
            new_id += last;
        }
    }

    return new_id;
}
