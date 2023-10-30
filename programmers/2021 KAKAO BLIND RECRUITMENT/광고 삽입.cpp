#include <bits/stdc++.h>

using namespace std;

#define MAX 360000

int cal_sec(string str) {
    int hour = stoi(str.substr(0,2));
    int min = stoi(str.substr(3,2));
    int sec = stoi(str.substr(6,2));

    return hour * 3600 + min * 60 + sec;
}

string sec_to_string(int sec) {
    char str[10];

    int hour = sec / 3600; sec %= 3600;
    int min = sec / 60; sec %= 60;

    sprintf(str, "%02d:%02d:%02d", hour, min, sec);
    return str;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    long long acc[MAX+1] = { 0, };

    int play_time_sec = cal_sec(play_time);
    int adv_time_sec = cal_sec(adv_time);

    for(auto l : logs) {
        int start = cal_sec(l.substr(0, 8));
        int end = cal_sec(l.substr(9, 8));

        acc[start]++;
        acc[end]--;
    }

    // 누적합을 활용하여 한 번에 누적 시청 시간 계산
    for(int i=0; i<play_time_sec; i++) {
        acc[i+1] += acc[i];
    }

    // window를 사용하여 한 칸씩 움직이며 최대 시청 시간 찾기
    long long sum = 0;
    for(int i=0; i<adv_time_sec; i++) {
        sum += acc[i];
    }

    int answer = 0;
    long long max_sum = sum;

    for(int i=0; i<play_time_sec - adv_time_sec; i++) {
        sum -= acc[i];
        sum += acc[adv_time_sec + i];

        if(sum > max_sum) {
            max_sum = sum;
            answer = i + 1;
        }
    }

    return sec_to_string(answer);
}
