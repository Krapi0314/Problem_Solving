/*
BOJ 20164번: 홀수 홀릭

문제
호석이는 짝수랑 홀수 중에서 이니셜이 같은 홀수를 더 좋아한다. 운전을 하던 호석이는 앞차의 번호판이 홀수로 가득할 때 사랑스러움을 느낄 정도이다. 전화번호도 홀수만 있고 싶다. 그렇게 홀수 홀릭에 빠진 호석이는 가지고 있는 수 N을 일련의 연산을 거치면서, 등장하는 숫자들에서 홀수를 최대한 많이 많이 보고 싶다.
하나의 수가 주어졌을 때 호석이는 한 번의 연산에서 다음과 같은 순서를 거친다.

수의 각 자리 숫자 중에서 홀수의 개수를 종이에 적는다.
수가 한 자리이면 더 이상 아무것도 하지 못하고 종료한다.
수가 두 자리이면 2개로 나눠서 합을 구하여 새로운 수로 생각한다.
수가 세 자리 이상이면 임의의 위치에서 끊어서 3개의 수로 분할하고, 3개를 더한 값을 새로운 수로 생각한다.
호석이는 연산이 종료된 순간에 종이에 적힌 수들을 모두 더한다. 그렇게 최종적으로 얻은 수를 최종값이라고 하자. 예를 들어, 시작하는 수가 82019 라고 하자. 그럼 아래와 같이 나누게 되면 5개의 홀수를 볼 수 있기 때문에, 최종값이 5가 된다.

시작할 때 호석이가 가진 수를 N 이라고 했을 때, 만들 수 있는 최종값 중 최솟값과 최댓값을 구해주자.

입력
첫번째 줄에 호석이가 처음 시작할 때 가지고 있는 수 N 이 주어진다.

출력
첫 번째 줄에 호석이가 만들 수 있는 최종값 중에서 최솟값과 최댓값을 순서대로 공백으로 구분하여 출력한다.

제한
1 ≤ N ≤ 109-1, N 은 자연수이다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

string s;
int n;
int Max = 0, Min = 2e9;

void cal(string s, int cnt) {
	for(int i=0; i<s.size(); i++) {
		if((s[i] - '0') % 2 != 0) {
			cnt++;	
		}
	}
	
	if(s.size() == 1) {
		Max = max(Max, cnt);
		Min = min(Min, cnt);
	}
	else if(s.size() == 2) {
		n = s[0] - '0' + s[1] - '0';
		cal(to_string(n), cnt);
	}
	else {
		for(int i=0; i<s.size()-2; i++) {
			for(int j=i+1; j<s.size()-1; j++) {
				string s1 = s.substr(0, i+1);
				string s2 = s.substr(i+1, j-i);
				string s3 = s.substr(j+1, s.size()-j);
				
				n = stoi(s1) + stoi(s2) + stoi(s3);
				cal(to_string(n), cnt);
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;
	
	cal(s, 0);
	
	cout << Min << " " << Max;
}

// implementation
// 재귀를 이용한 완전탐색으로 모든 경우에 대해 카운트 후 최댓값, 최솟값 찾기 

