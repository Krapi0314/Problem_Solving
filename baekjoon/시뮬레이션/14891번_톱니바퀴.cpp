// https://www.acmicpc.net/problem/14891

#include <bits/stdc++.h>

using namespace std;

deque<int> w[5];
int k, n, d;
int ans;

void rotate_one(int num, int direction) {
    int temp = 0;
    if(direction == 1) {
        temp = w[num][7];
        w[num].pop_back();
        w[num].push_front(temp);
    } else {
        temp = w[num][0];
        w[num].pop_front();
        w[num].push_back(temp);
    }
}

void rotate(int num, int direction) {
    switch(num) {
        case 1:
            // check 1 - 2
            if(w[1][2] != w[2][6]) {
                // check 2 - 3
                if(w[2][2] != w[3][6]) {
                    // check 3 - 4
                    if(w[3][2] != w[4][6]) {
                        rotate_one(4, direction * -1);
                    }
                    rotate_one(3, direction);
                }
                rotate_one(2, direction * -1);
            }
            rotate_one(1, direction);
            break;
        case 2:
            // check 2 - 3
            if(w[2][2] != w[3][6]) {
                // check 3 - 4
                if(w[3][2] != w[4][6]) {
                    rotate_one(4, direction);
                }
                rotate_one(3, direction * -1);
            }
            // check 1 - 2
            if(w[2][6] != w[1][2]) {
                rotate_one(1, direction * -1);
            }
            rotate_one(2, direction);
            break;
        case 3:
            // check 2 - 3
            if(w[3][6] != w[2][2]) {
                // check 2 - 1
                if(w[2][6] != w[1][2]) {
                    rotate_one(1, direction);
                }
                rotate_one(2, direction * -1);
            }
            // check 3 - 4
            if(w[3][2] != w[4][6]) {
                rotate_one(4, direction * -1);
            }
            rotate_one(3, direction);
            break;
        case 4:
            // check 4 - 3
            if(w[4][6] != w[3][2]) {
                // check 3 - 2
                if(w[3][6] != w[2][2]) {
                    // check 2 - 1
                    if(w[2][6] != w[1][2]) {
                        rotate_one(1, direction * -1);
                    }
                    rotate_one(2, direction);
                }
                rotate_one(3, direction * -1);
            }
            rotate_one(4, direction);
            break;
    }
}

void cal_score() {
    int n1 = (w[1][0] == 0) ? (0) : (1);
    int n2 = (w[2][0] == 0) ? (0) : (2);
    int n3 = (w[3][0] == 0) ? (0) : (4);
    int n4 = (w[4][0] == 0) ? (0) : (8);

    ans = n1 + n2 + n3 + n4;
}

int main() {
    string s;
    for(int i=1; i<=4; i++) {
        cin >> s;
        for(int j=0; j<8; j++) {
            w[i].push_back(s[j] - '0');
        }
    }

    cin >> k;
    while(k--) {
        cin >> n >> d;
        rotate(n, d);
    }

    cal_score();
    cout << ans;
    return 0;
}