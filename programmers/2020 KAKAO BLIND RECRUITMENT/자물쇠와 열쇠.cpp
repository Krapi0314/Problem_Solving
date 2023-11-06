#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>> key) {
    vector<vector<int>> res = key;
    int kl = key.size();

    for(int i=0; i<kl; i++) {
        for(int j=0; j<kl; j++) {
            res[j][kl-1-i] = key[i][j];
        }
    }

    return res;
}

bool match(vector<vector<int>>& key, vector<vector<int>> elock, int ll, int y, int x) {
    int kl = key.size();

    // elock + key
    for(int i=0; i<kl; i++) {
        for(int j=0; j<kl; j++) {
            elock[i+y][j+x] += key[i][j];
        }
    }

    // check
    bool res = true;
    for(int i=0; i<ll; i++) {
        for(int j=0; j<ll; j++) {
            if(elock[i+kl-1][j+kl-1] != 1) {
                res = false;
                break;
            }
        }
    }

    // elock - key
    for(int i=0; i<kl; i++) {
        for(int j=0; j<kl; j++) {
            elock[i+y][j+x] -= key[i][j];
        }
    }

    return res;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int kl = key.size(); int ll = lock.size();
    int el = 2 * key.size() + lock.size() - 2;

    vector<vector<int>> elock(el, vector<int>(el, 0));
    for(int i=0; i<ll; i++) {
        for(int j=0; j<ll; j++) {
            elock[i+kl-1][j+kl-1] = lock[i][j];
        }
    }

    for(int r=0; r<4; r++) {
        for(int i=0; i<=el-kl; i++) {
            for(int j=0; j<=el-kl; j++) {
                if(match(key, elock, ll, i, j)) {
                    return true;
                }
            }
        }
        key = rotate(key);
    }

    return false;
}
