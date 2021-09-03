/*
BOJ 1987번

시간 제한: 2초
메모리 제한: 256 MB

문제
세로 R칸, 가로 C칸으로 된 표 모양의 보드가 있다. 보드의 각 칸에는 대문자 알파벳이 하나씩 적혀 있고, 좌측 상단 칸 (1행 1열) 에는 말이 놓여 있다.
말은 상하좌우로 인접한 네 칸 중의 한 칸으로 이동할 수 있는데, 새로 이동한 칸에 적혀 있는 알파벳은 지금까지 지나온 모든 칸에 적혀 있는 알파벳과는 달라야 한다. 즉, 같은 알파벳이 적힌 칸을 두 번 지날 수 없다.
좌측 상단에서 시작해서, 말이 최대한 몇 칸을 지날 수 있는지를 구하는 프로그램을 작성하시오. 말이 지나는 칸은 좌측 상단의 칸도 포함된다.

입력
첫째 줄에 R과 C가 빈칸을 사이에 두고 주어진다. (1 ≤ R,C ≤ 20) 둘째 줄부터 R개의 줄에 걸쳐서 보드에 적혀 있는 C개의 대문자 알파벳들이 빈칸 없이 주어진다.

출력
첫째 줄에 말이 지날 수 있는 최대의 칸 수를 출력한다. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int r,c;
string s;

char arr[20][20];
bool alphabet[26];

int dx[4] = { 1, 0, -1, 0};
int dy[4] = { 0, 1, 0, -1};

int cnt;
int ans;

void dfs(int x, int y, int cnt) {	
	for(int i=0; i<4; i++) {
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		
		if(new_x >= 0 && new_x < c && new_y >= 0 && new_y < r) {
			if(!alphabet[arr[new_y][new_x] - 65]) {
				alphabet[arr[new_y][new_x] - 65] = true;
				dfs(new_x,new_y,cnt+1);
				alphabet[arr[new_y][new_x] - 65] = false;
			}
			else {
				ans = max(ans, cnt);
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> r >> c;
	for(int i=0; i<r; i++) {
		cin >> s;
		for(int j=0; j<c; j++) {
			arr[i][j] = s[j];
		}
	}
	
	alphabet[arr[0][0] - 65] = true;
	dfs(0,0,0);
	
	cout << ans + 1;
}

/*
backtracking
!! 같은 알파벳이 적힌 칸은 두 번 지날 수 없으므로
boolean visited[]와 지나온 길 정보를 담는 vector<> v 대신
해당 알파벳을 이미 지나왔는지 알려주는 boolean alphabet[26]을 사용하면 시간복잡도와 공간복잡도 둘 다 낮출 수 있음 
*/
