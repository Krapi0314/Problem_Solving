/*
 * https://www.acmicpc.net/problem/16719
 */

#include <bits/stdc++.h>

using namespace std;

#define MAX 100

string str;
bool printable[MAX];

int find_dict_first_letter(int idx1, int idx2) {
    for(int j='A'; j<='Z'; j++) {
        for(int i=idx1; i<=idx2; i++) {
            if(str[i] == j) return i;
        }
    }
    return 0;
}

void print() {
    for(int i=0; i<str.size(); i++) {
        if(printable[i]) cout << str[i];
    }
    cout << "\n";
}

void recursive(int idx1, int idx2) {
    if(idx1 > idx2) return;

    int idx = find_dict_first_letter(idx1, idx2);
    printable[idx] = true;

    print();

    recursive(idx+1, idx2);
    recursive(idx1, idx-1);
}

int main() {
    cin >> str;

    recursive(0, str.size()-1);

    return 0;
}
