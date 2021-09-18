/*
BOJ 11000번: 강의실 배정

시간 제한: 1초
메모리 제한: 256 MB

문제
수강신청의 마스터 김종혜 선생님에게 새로운 과제가 주어졌다. 
김종혜 선생님한테는 Si에 시작해서 Ti에 끝나는 N개의 수업이 주어지는데, 최소의 강의실을 사용해서 모든 수업을 가능하게 해야 한다. 
참고로, 수업이 끝난 직후에 다음 수업을 시작할 수 있다. (즉, Ti ≤ Sj 일 경우 i 수업과 j 수업은 같이 들을 수 있다.)
수강신청 대충한 게 찔리면, 선생님을 도와드리자!

입력
첫 번째 줄에 N이 주어진다. (1 ≤ N ≤ 200,000)
이후 N개의 줄에 Si, Ti가 주어진다. (0 ≤ Si < Ti ≤ 109)

출력
강의실의 개수를 출력하라. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
int s,t;
vector<pair<int,int> > v;
int cnt;
int Max;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> s >> t;
		v.push_back(make_pair(s,1));
		v.push_back(make_pair(t,-1));
	}
	
	sort(v.begin(), v.end());

	for(int i=0; i<2*n; i++) {
		cnt += v[i].second;
		Max = max(Max, cnt);
	}
	
	cout << Max;
}

/* 
greedy

cnt: 현재 진행 중인 수업의 수
N개의 회의를 모두 진행할 수 있는 최소 강의실의 개수 = cnt의 최댓값
수업 시작 시 cnt++, 수업 끝날 시 cnt--
수업의 시작은 pair<시간, +1> 끝은 pair<시간, -1>로 같은 배열에 저장 후 시간 순으로 sort, 이후 순서대로 꺼내면서 cnt에 더하기 (+1이면 수업 시작, -1이면 수업 끝이므로 cnt에 더해주면 됨), 최댓값 찾기 

추가: 정렬은 first, 오름차순으로, 같으면 second 오름차순으로 진행되므로, compare 함수 불필요하고, cnt가 계산될때에도 "수업이 끝난 직후에 다음 수업을 시작할 수 있다"는 문제 논리와도 부합함. 
*/ 
