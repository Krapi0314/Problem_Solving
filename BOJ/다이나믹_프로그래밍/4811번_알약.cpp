/*
BOJ 4811번: 알약

시간 제한: 1초
메모리 제한: 256 MB

문제
70세 박종수 할아버지는 매일 매일 약 반알을 먹는다. 손녀 선영이는 종수 할아버지에게 약이 N개 담긴 병을 선물로 주었다.
첫째 날에 종수는 병에서 약 하나를 꺼낸다. 그 다음, 그 약을 반으로 쪼개서 한 조각은 먹고, 다른 조각은 다시 병에 넣는다.
다음 날부터 종수는 병에서 약을 하나 꺼낸다. (약은 한 조각 전체 일 수도 있고, 쪼갠 반 조각 일 수도 있다) 반 조각이라면 그 약을 먹고, 아니라면 반을 쪼개서 한 조각을 먹고, 다른 조각은 다시 병에 넣는다.
종수는 손녀에게 한 조각을 꺼낸 날에는 W를, 반 조각을 꺼낸 날에는 H 보낸다. 손녀는 할아버지에게 받은 문자를 종이에 기록해 놓는다. 총 2N일이 지나면 길이가 2N인 문자열이 만들어지게 된다. 이때, 가능한 서로 다른 문자열의 개수는 총 몇 개일까?

입력
입력은 최대 1000개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 한 줄이며, 병에 들어있는 약의 개수 N ≤ 30 가 주어진다.

입력의 마지막 줄에는 0이 하나 주어진다.

출력
각 테스트 케이스에 대해서 가능한 문자열의 개수를 출력한다.
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
ull dp[31][31];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	// 기저값 설정 
	for(int i=0; i<=30; i++) {
		dp[0][i] = 1;	
	}
			
	// 점화식 사용
	for(int i=1; i<=30; i++) {
		for(int j=0; j<=30; j++) {
			if(j == 0) {
				dp[i][0] = dp[i-1][1];
			}
			else {
				dp[i][j] = dp[i-1][j+1] + dp[i][j-1];
			}
		}
	}
	
	while(true) {
		cin >> n;
		
		if(n == 0) {
			break;
		}

		cout << dp[n][0] << "\n"; 
	}
}

/* 
dp

dp[w][h] = 알약이 w,h개 남았을 때, 만들 수 있는 문자열의 수 

기저값: dp[0][0] ~ dp[0][30] = 1 (온전한 알약이 0개 일때의 경우 = 1) 
점화식
1. 쪼개진 알약이 없는 경우: dp[w][h=0] = dp[w-1][1] (온전한 알약 하나를 줄이고, 쪼개진 알약 1개 추가) 
2. 온전한/쪼개진 알약이 모두 있는 경우: dp[w][h] = dp[w-1][h+1] + dp[w][h-1] (온전한 알약을 먹고, 남은 쪼개진 알약을 다시 넣었을 때의 경우 + 쪼개진 알약을 먹었을 때의 경우)
 
+ 카탈랑 수
수열: 1 1 2 5 14 42 132 429 1430 4862 ...
점화식: Cn+1 = Sigma(i=0, n) CiCn-i (n>=0), C0 = 1
C++ Implementation

// A dynamic programming based function to find nth
// Catalan number
unsigned long int catalanDP(unsigned int n)
{
    // Table to store results of subproblems
    unsigned long int catalan[n + 1];
 
    // Initialize first two values in table
    catalan[0] = catalan[1] = 1;
 
    // Fill entries in catalan[] using recursive formula
    for (int i = 2; i <= n; i++) {
        catalan[i] = 0;
        for (int j = 0; j < i; j++)
            catalan[i] += catalan[j] * catalan[i - j - 1];
    }
 
    // Return last entry
    return catalan[n];
}
 
*/
