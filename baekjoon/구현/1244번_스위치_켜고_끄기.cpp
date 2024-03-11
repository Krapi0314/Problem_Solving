#include <bits/stdc++.h>

using namespace std;

#define MAX 100

int n;
bool arr[MAX+1];
int m;
int sym_idx;
int sex, num;

int find_max_symmetry_offset(int idx) {
    int offset = 1;

    while(idx - offset >= 1 && idx + offset <= n) {
        if(arr[idx-offset] != arr[idx+offset]) break;
        offset++;
    }

    return offset-1;
}

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) cin >> arr[i];

    cin >> m;
    for(int i=0; i<m; i++) {
        cin >> sex >> num;

        // male
        if(sex == 1) {
            for(int j=1; num*j<=n; j++) {
                arr[num*j] = !arr[num*j];
            }
        }
            // female
        else {
            sym_idx = find_max_symmetry_offset(num);
            for(int j=num-sym_idx; j<=num+sym_idx; j++) {
                arr[j] = !arr[j];
            }
        }
    }

    for(int i=1; i<=n; i++) {
        cout << arr[i] << " ";
        if(i % 20 == 0) cout << "\n";
    }
    return 0;
}