#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    int temp = 0;
    int i = 0;

    queue<int> q1;
    queue<int> q2;

    long q_opt = 0;
    long q1_sum = 0;
    long q2_sum = 0;

    for(i=0; i<queue1.size(); i++) {
        q1_sum += queue1[i];
        q2_sum += queue2[i];

        q1.push(queue1[i]);
        q2.push(queue2[i]);
    }
    q_opt = (q1_sum + q2_sum) / 2;

    // 한쪽 큐가 합/2 되도록 탐욕법으로 수행
    // 단 수행 횟수가 큐의 최대 길이 x 2 (큐에 가능한 모든 조합을 수행)이면 중단
    i = 0;
    while(true) {
        if(i == 600000 || q1_sum == 0) {
            answer = -1;
            break;
        }
        else if(q1_sum == q_opt) {
            break;
        } else if(q1_sum > q_opt) {
            temp = q1.front();
            q1.pop();
            q2.push(temp);
            q1_sum -= temp;
        } else if(q1_sum < q_opt) {
            temp = q2.front();
            q2.pop();
            q1.push(temp);
            q1_sum += temp;
        }
        answer++;
        i++;
    }

    return answer;
}
