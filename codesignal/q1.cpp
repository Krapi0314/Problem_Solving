#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> &a) {
    int a_size = a.size();
    vector<int> b(a_size);
    for(int i=0; i<a_size; i++) {
        if(i-1 < 0) b[i] = 0+a[i]+a[i+1];
        else if(i+1 >= a_size) b[i] = a[i-1]+a[i]+0;
        else b[i] = a[i-1]+a[i]+a[i+1];
    }

    return b;
}

int main() {
    vector<int> given = { 4, 0, 1, -2, 3};
    vector<int> result = solution(given);
    for(auto &r : result) cout << r << " ";
    return 0;
}