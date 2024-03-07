#include <bits/stdc++.h>

using namespace std;

#define MAX 19
#define BLACK 1
#define WHITE 2

int n = MAX;
int arr[MAX][MAX];
bool visited[MAX][MAX];
int color;
int i,j;

int check_left(int x, int y, int cnt) {
    if(arr[x][y] != color) return cnt;

    if(y < n) {
        return check_left(x, y+1, cnt+1);
    }

    return cnt;
}

int check_below(int x, int y, int cnt) {
    if(arr[x][y] != color) return cnt;

    if(x < n) {
        return check_below(x+1, y, cnt+1);
    }

    return cnt;
}

int check_diagonal(int x, int y, int cnt) {
    if(arr[x][y] != color) return cnt;

    if(x < n && y < n) {
        return check_diagonal(x+1, y+1, cnt+1);
    }

    return cnt;
}

int check_reverse_diagonal(int x, int y, int cnt) {
    if(arr[x][y] != color) return cnt;

    if(x >= 0 && y < n) {
        return check_reverse_diagonal(x-1, y+1, cnt+1);
    }

    return cnt;
}

// TODO(krapie): 구현력 매우 부족함.
void check_arr() {
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            color = (arr[i][j] == BLACK) ? BLACK : WHITE;

            if(j < n-1 && arr[i][j+1] == color && !(j >= 1 && arr[i][j - 1] == color && visited[i][j - 1])) {
                if (check_left(i, j, 0) == 5) return;
            }
            if(i < n-1 && arr[i+1][j] == color && !(i >= 1 && arr[i - 1][j] == color && visited[i - 1][j])) {
                if (check_below(i, j, 0) == 5) return;
            }
            if(i < n-1 && j < n-1 && arr[i+1][j+1] == color && !(i >= 1 && j >= 1 && arr[i - 1][j - 1] == color && visited[i - 1][j - 1])) {
                if (check_diagonal(i, j, 0) == 5) return;
            }
            if(i >= 0 && j < n-1 && arr[i-1][j+1] == color && !(i < n-1 && j >= 0 && arr[i + 1][j - 1] == color)) {
                if (check_reverse_diagonal(i, j, 0) == 5) {
                    return;
                }
            }

            visited[i][j] = true;
        }
    }
}

int main() {

    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    check_arr();

    if(i == n && j == n) {
        cout << "0";
    } else {
        cout << color << "\n";
        cout << i+1 << " " << j+1 << "\n";
    }

    return 0;
}