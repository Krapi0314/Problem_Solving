/*
boj 12865번: 평범한 배낭

시간 제한: 2 초
메모리 제한: 512 MB

문제
이 문제는 아주 평범한 배낭에 관한 문제이다.
한 달 후면 국가의 부름을 받게 되는 준서는 여행을 가려고 한다. 세상과의 단절을 슬퍼하며 최대한 즐기기 위한 여행이기 때문에, 가지고 다닐 배낭 또한 최대한 가치 있게 싸려고 한다.
준서가 여행에 필요하다고 생각하는 N개의 물건이 있다. 각 물건은 무게 W와 가치 V를 가지는데, 해당 물건을 배낭에 넣어서 가면 준서가 V만큼 즐길 수 있다. 아직 행군을 해본 적이 없는 준서는 최대 K만큼의 무게만을 넣을 수 있는 배낭만 들고 다닐 수 있다. 준서가 최대한 즐거운 여행을 하기 위해 배낭에 넣을 수 있는 물건들의 가치의 최댓값을 알려주자.

입력
첫 줄에 물품의 수 N(1 ≤ N ≤ 100)과 준서가 버틸 수 있는 무게 K(1 ≤ K ≤ 100,000)가 주어진다. 두 번째 줄부터 N개의 줄에 거쳐 각 물건의 무게 W(1 ≤ W ≤ 100,000)와 해당 물건의 가치 V(0 ≤ V ≤ 1,000)가 주어진다.
입력으로 주어지는 모든 수는 정수이다.

출력
한 줄에 배낭에 넣을 수 있는 물건들의 가치합의 최댓값을 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, k, w, v;
int dp[101][100001];
int item[101][2]; // weight, value

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> k;
	for(int i=1; i<=n; i++) {
		cin >> w >> v;
		item[i][0] = w;
		item[i][1] = v;
	}
	
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=k; j++) {
			if(j < item[i][0]) dp[i][j] = dp[i-1][j];
			else dp[i][j] = max(dp[i-1][j], dp[i-1][j-item[i][0]] + item[i][1]);	
		}
	}
	
	cout << dp[n][k];
	return 0;
}

/* 
0-1 Knapsack Problem: DP
점화식: DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - W[i]] + V[i]) (i는 배낭에 넣을 물건 번호, j는 현재 배낭의 무게)

1. DP[i번째 아이템][배낭 무게 j] 배열 선언 (2차원 메모이제이션) 
2. for i 번째 아이템, i = 1 ~ n
	for 배낭 무게 j = 0 ~ k
		if 아이템을 담을 수 없는 경우
			현재 아이템 i, 현재 무게 j 일때의 가치 = 이전 아이템 i-1, 현재 무게 j 였을 때의 가치
			=> dp[i][j] = dp[i-1][j]
		else 아이템을 담을 수 있는 경우 
			현재 아이템 i, 무게 j 일때의 가치 =
			 	현재 아이템 i 이전 무게 j-1 였을 때의 가치 (물건을 담지 않는다) 
				이전 아이템 i-1, 현재 아이템의 무게만큼 뺀 무게 j-weight 였을 때의 가치 + 현재 아이템의 가치 (물건을 담는다)
				가치가 큰 쪽 선택
			=> dp[i][j] = max(dp[i-1][j], dp[i-1][j-item[i][0]] + item[i][1]) 

!! Brute force: O(2^100)
*/ 
