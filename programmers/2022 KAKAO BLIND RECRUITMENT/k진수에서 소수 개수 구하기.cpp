#include <bits/stdc++.h>

using namespace std;

bool is_prime(long long num) {
    int to = sqrt(num);
    for(int i=2; i<=to; i++) {
        if(num % i == 0) {
            return false;
        }
    }

    return true;
}

int solution(int n, int k) {
    // k진수로 변환 (문자열로)
    string str;

    while(n != 0) {
        int digit = n % k;
        n /= k;
        str = to_string(digit) + str;
    }

    // 0을 delimiter로 문자열 slice
    vector<long long> nums;
    stringstream ss(str);
    string s;

    while(getline(ss, s, '0')) {
        if(s != "" && s != "1") {
            long long num = stoll(s);
            nums.push_back(num);
        }
    }

    // 소수 여부 판단
    int answer = 0;

    for(auto n : nums) {
        if(is_prime(n)) answer++;
    }

    return answer;
}
