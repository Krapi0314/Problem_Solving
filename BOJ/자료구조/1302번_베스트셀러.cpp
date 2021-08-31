/*
BOJ 1302번: 베스트셀러

시간 제한: 2초 
메모리 제한: 128 MB

문제
김형택은 탑문고의 직원이다. 김형택은 계산대에서 계산을 하는 직원이다. 김형택은 그날 근무가 끝난 후에, 오늘 판매한 책의 제목을 보면서 가장 많이 팔린 책의 제목을 칠판에 써놓는 일도 같이 하고 있다.
오늘 하루 동안 팔린 책의 제목이 입력으로 들어왔을 때, 가장 많이 팔린 책의 제목을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 오늘 하루 동안 팔린 책의 개수 N이 주어진다. 이 값은 1,000보다 작거나 같은 자연수이다. 둘째부터 N개의 줄에 책의 제목이 입력으로 들어온다. 책의 제목의 길이는 50보다 작거나 같고, 알파벳 소문자로만 이루어져 있다.

출력
첫째 줄에 가장 많이 팔린 책의 제목을 출력한다. 만약 가장 많이 팔린 책이 여러 개일 경우에는 사전 순으로 가장 앞서는 제목을 출력한다. 
*/

 #include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
string s;
int Max;
vector<string> v;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	while(n--) {
		cin >> s;
		v.push_back(s);
	}
	
	sort(v.begin(), v.end());
	
	int cnt = 1; s = v[0];
	for(int i=1; i<=v.size(); i++) {
		if(i == v.size() || v[i] != v[i-1]) {
			if(cnt > Max) {
				Max = cnt;
				s = v[i-1];
			}	
			cnt = 1;
		}
		else {
			cnt++;
		}
	}
	
	cout << s;
}

/*
자료구조
1. vector<string>로 sort 후 순회하며 구하는 방식
2. map<string, int>로 삽입 후 순회하며 구하는 방식
*/
