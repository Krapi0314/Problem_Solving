#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr[101][101];

// x => y축, y = x축
void fill_in_array(int rows, int columns) {
    int num = 1;

    for(int i=1; i<=rows; i++) {
        for(int j=1; j<=columns; j++) {
            arr[i][j] = num++;
        }
    }
}

int rotate_with_min_num_check(int x1, int y1, int x2, int y2) {
    int min_num = 100 * 100;
    int temp = arr[x1][y1];

    for(int i=x1; i<x2; i++) {
        arr[i][y1] = arr[i+1][y1];
        min_num = min(min_num, arr[i][y1]);
    }

    for(int i=y1; i<y2; i++) {
        arr[x2][i] = arr[x2][i+1];
        min_num = min(min_num, arr[x2][i]);
    }

    for(int i=x2; i>x1; i--) {
        arr[i][y2] = arr[i-1][y2];
        min_num = min(min_num, arr[i][y1]);
        if(arr[i][y2] < min_num) min_num = arr[i][y2];
    }

    for(int i=y2; i>y1; i--) {
        arr[x1][i] = arr[x1][i-1];
        min_num = min(min_num, arr[x1][i]);
    }
    arr[x1][y1+1] = temp;
    min_num = min(min_num, arr[x1][y1+1]);

    return min_num;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;

    fill_in_array(rows, columns);
    for(int i=0; i<queries.size(); i++) {
        int x1 = queries[i][0]; int y1 = queries[i][1];
        int x2 = queries[i][2]; int y2 = queries[i][3];

        int min_num = rotate_with_min_num_check(x1, y1, x2, y2);
        answer.push_back(min_num);
    }

    return answer;
}
