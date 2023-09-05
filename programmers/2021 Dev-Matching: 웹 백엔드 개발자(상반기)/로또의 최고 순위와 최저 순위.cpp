#include <string>
#include <vector>

using namespace std;

int count_min_match(vector<int> lottos, vector<int> win_nums) {
    int n = 0;

    for(int i=0; i<6; i++) {
        for(int j=0; j<6; j++) {
            if(lottos[i] == win_nums[j]) n++;
        }
    }

    return n;
}

int count_zero(vector<int> lottos) {
    int n = 0;

    for(int i=0; i<6; i++) {
        if(lottos[i] == 0) n++;
    }

    return n;
}

int cal_rank(int matched) {
    switch(matched) {
        case 6:
            return 1;
        case 5:
            return 2;
        case 4:
            return 3;
        case 3:
            return 4;
        case 2:
            return 5;
        default:
            return 6;
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer(2);

    // 최고 순위 = 일치하는 번호의 개수 + 0의 개수
    // 최저 순위 = 일치하는 번호의 개수
    int min_match = count_min_match(lottos, win_nums);
    int zero_n = count_zero(lottos);

    answer[0] = cal_rank(min_match + zero_n);
    answer[1] = cal_rank(min_match);

    return answer;
}
