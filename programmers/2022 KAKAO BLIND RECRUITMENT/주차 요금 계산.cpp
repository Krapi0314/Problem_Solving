#include <bits/stdc++.h>

using namespace std;

int to_min(string time) {
    string hour = time.substr(0,2);
    string min = time.substr(3,2);

    return stoi(hour) * 60 + stoi(min);
}

vector<int> solution(vector<int> fees, vector<string> records) {
    // 차량 번호별 입출차 기록 저장
    map<string, stack<string>> m;

    for(auto record : records) {
        string time, car, type;
        stringstream ss(record);

        ss >> time >> car >> type;

        m[car].push(time);
    }

    // 차량 번호별 입출차 기록을 누적 주차 시간으로 변환 후 주차 요금 계산
    vector<int> answer;
    for(auto car : m) {
        auto cs = car.second;
        if(cs.size() % 2 != 0) cs.push("23:59");

        int acc = 0;
        while(!cs.empty()) {
            string end = cs.top(); cs.pop();
            string start = cs.top(); cs.pop();

            acc += to_min(end) - to_min(start);
        }

        int fee = (acc <= fees[0]) ? (fees[1]) : (ceil((acc-fees[0]) / (double)fees[2]) * fees[3] + fees[1]);
        answer.push_back(fee);
    }

    return answer;
}
