#include <bits/stdc++.h>

using namespace std;

string str;
vector<bool> visited;
int duck_stack;
bool signal_invalid;
bool duck_identified;
int cnt;

int main() {
    cin >> str;
    visited.resize(str.size(), false);

    while(true) {
        duck_identified = false;
        for(int i=0; i<str.size(); i++) {
            if(str[i] == 'q' && !visited[i] && duck_stack == 0) {
                duck_stack++;
                visited[i] = true;
            } else if(str[i] == 'u' && !visited[i] && duck_stack == 1) {
                duck_stack++;
                visited[i] = true;
            } else if(str[i] == 'a' && !visited[i] && duck_stack == 2) {
                duck_stack++;
                visited[i] = true;
            } else if(str[i] == 'c' && !visited[i] && duck_stack == 3) {
                duck_stack++;
                visited[i] = true;
            } else if(str[i] == 'k' && !visited[i] && duck_stack == 4) {
                duck_stack++;
                visited[i] = true;
            }

            if(duck_stack == 5) {
                duck_identified = true;
                duck_stack = 0;
            }
        }

        if(duck_identified && duck_stack == 0) cnt++;
        else break;
    }

    if(duck_stack != 0) signal_invalid = true;
    for(int i=0; i<str.size(); i++) {
        if(!visited[i]) {
            signal_invalid = true;
            break;
        }
    }

    if(signal_invalid) cout << -1;
    else cout << cnt;

    return 0;
}