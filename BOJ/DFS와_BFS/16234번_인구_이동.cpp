/*
BOJ 16234번: 인구 이동

시간 제한: 2초
메모리 제한: 512 MB

문제
N×N크기의 땅이 있고, 땅은 1×1개의 칸으로 나누어져 있다. 각각의 땅에는 나라가 하나씩 존재하며, r행 c열에 있는 나라에는 A[r][c]명이 살고 있다. 인접한 나라 사이에는 국경선이 존재한다. 모든 나라는 1×1 크기이기 때문에, 모든 국경선은 정사각형 형태이다.
오늘부터 인구 이동이 시작되는 날이다.
인구 이동은 다음과 같이 진행되고, 더 이상 아래 방법에 의해 인구 이동이 없을 때까지 지속된다.

국경선을 공유하는 두 나라의 인구 차이가 L명 이상, R명 이하라면, 두 나라가 공유하는 국경선을 오늘 하루동안 연다.
위의 조건에 의해 열어야하는 국경선이 모두 열렸다면, 인구 이동을 시작한다.
국경선이 열려있어 인접한 칸만을 이용해 이동할 수 있으면, 그 나라를 오늘 하루 동안은 연합이라고 한다.
연합을 이루고 있는 각 칸의 인구수는 (연합의 인구수) / (연합을 이루고 있는 칸의 개수)가 된다. 편의상 소수점은 버린다.
연합을 해체하고, 모든 국경선을 닫는다.
각 나라의 인구수가 주어졌을 때, 인구 이동이 몇 번 발생하는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N, L, R이 주어진다. (1 ≤ N ≤ 50, 1 ≤ L ≤ R ≤ 100)
둘째 줄부터 N개의 줄에 각 나라의 인구수가 주어진다. r행 c열에 주어지는 정수는 A[r][c]의 값이다. (0 ≤ A[r][c] ≤ 100)
인구 이동이 발생하는 횟수가 2,000번 보다 작거나 같은 입력만 주어진다.

출력
인구 이동이 몇 번 발생하는지 첫째 줄에 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int population[50][50];
bool visited[50][50];
int n,l,r;
int ans;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
bool populationDidMove;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> l >> r;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> population[i][j];
		}
	}
	
	while(true){ // while: 매 순간 인구이동이 일어났는지 계산하는 것은 비효쥴적, BFS 안에서 인구이동이 있었으면 populatioNDidMove = true로 체크하는 방법으로 최적화 
		populationDidMove = false;
		
		for(int i=0; i<n; i++) {
			for(int j=0; j<n; j++) {
				if(!visited[i][j]) { // 변수, 함수 간 복잡도를 줄이기 위해 main 안에 bfs 실행, 인구이동 실행					
					queue<pair<int,int>> q;
					queue<pair<int,int>> uni;
					int sum = 0;
					int cnt = 0;
					
					q.push(make_pair(i,j));
					uni.push(make_pair(i,j));
					visited[i][j] = true;
					
					while(!q.empty()) {
						pair<int,int> here = q.front(); q.pop();
						
						cnt++;
						sum += population[here.first][here.second];
					
						for(int i=0; i<4; i++) {
							int there_y = here.first + dy[i];
							int there_x = here.second + dx[i];
							int diff = abs(population[here.first][here.second] - population[there_y][there_x]);

							if(there_y >= 0 && there_y < n && there_x >= 0 && there_x < n && diff >= l && diff <= r && !visited[there_y][there_x]) {
								visited[there_y][there_x] = true;
								q.push(make_pair(there_y,there_x));
								uni.push(make_pair(there_y,there_x));
								
								populationDidMove = true;	
							}
						}
					}
					
					int per = sum / cnt;
					while(!uni.empty()) {
						int y = uni.front().first;
						int x = uni.front().second;
						uni.pop();
						
						population[y][x] = per;
					}
				}
			}
		}
		
		if(populationDidMove) {
			memset(visited, false, sizeof(visited));
			ans++;
		}
		else {
			break;
		}
	}

	cout << ans;
}

// bfs
