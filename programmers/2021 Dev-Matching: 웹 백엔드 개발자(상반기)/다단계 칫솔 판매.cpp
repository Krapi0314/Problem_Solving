#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, string> refer;
map<string, int> profit;

void updateProfit(string name, int money) {
    if(name == "-") {
        return;
    }

    int tithe = money * 0.1;
    profit[name] += money - tithe;

    if(money) {
        updateProfit(refer[name], tithe);
    }
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;

    for(int i=0; i<enroll.size(); i++) {
        refer[enroll[i]] = referral[i];
    }

    for(int i=0; i<seller.size(); i++) {
        updateProfit(seller[i], amount[i] * 100);
    }

    for(int i=0; i<enroll.size(); i++) {
        answer.push_back(profit[enroll[i]]);
    }

    return answer;
}
