/*
 * https://www.acmicpc.net/problem/15787
 */

#include <bits/stdc++.h>

using namespace std;

#define MAX 100000

int n, m;
int op, i, x;
bool train[MAX+1][21];
set<int> hashed_train;

int hash_array(bool arr[]) {
    int res = 0;
    for(int j=1; j<=20; j++) {
        res += (int)arr[j] * pow(2, j);
    }

    return res;
}

int main() {
    cin >> n >> m;
    // perform m operations
    while(m--) {
        cin >> op >> i;

        switch(op) {
            case 1:
                cin >> x;
                train[i][x] = true;
                break;
            case 2:
                cin >> x;
                train[i][x] = false;
                break;
            case 3:
                for(int j=19; j>=1; j--) {
                    train[i][j+1] = train[i][j];
                }
                train[i][1] = false;
                break;
            case 4:
                for(int j=2; j<=20; j++) {
                    train[i][j-1] = train[i][j];
                }
                train[i][20] = false;
                break;
        }
    }

    // for n trains
    // hash each and save in hashed_train set
    for(int j=1; j<=n; j++) {
        hashed_train.insert(hash_array(train[j]));
    }

    cout << hashed_train.size();

    return 0;
}
