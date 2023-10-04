#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer;
    map<char, int> m;

    for(int i=0; i<survey.size(); i++) {
        m[survey[i][choices[i] / 4]] += choices[i] / 4 == 0 ? 4 - choices[i] : choices[i] - 4;
    }

    answer += m['R'] >= m['T'] ? "R" : "T";
    answer += m['C'] >= m['F'] ? "C" : "F";
    answer += m['J'] >= m['M'] ? "J" : "M";
    answer += m['A'] >= m['N'] ? "A" : "N";

    return answer;
}
