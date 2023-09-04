/*
baekjoon 1987��

�ð� ����: 2��
�޸� ����: 256 MB

����
���� Rĭ, ���� Cĭ���� �� ǥ ����� ���尡 �ִ�. ������ �� ĭ���� �빮�� ���ĺ��� �ϳ��� ���� �ְ�, ���� ��� ĭ (1�� 1��) ���� ���� ���� �ִ�.
���� �����¿�� ������ �� ĭ ���� �� ĭ���� �̵��� �� �ִµ�, ���� �̵��� ĭ�� ���� �ִ� ���ĺ��� ���ݱ��� ������ ��� ĭ�� ���� �ִ� ���ĺ����� �޶�� �Ѵ�. ��, ���� ���ĺ��� ���� ĭ�� �� �� ���� �� ����.
���� ��ܿ��� �����ؼ�, ���� �ִ��� �� ĭ�� ���� �� �ִ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. ���� ������ ĭ�� ���� ����� ĭ�� ���Եȴ�.

�Է�
ù° �ٿ� R�� C�� ��ĭ�� ���̿� �ΰ� �־�����. (1 �� R,C �� 20) ��° �ٺ��� R���� �ٿ� ���ļ� ���忡 ���� �ִ� C���� �빮�� ���ĺ����� ��ĭ ���� �־�����.

���
ù° �ٿ� ���� ���� �� �ִ� �ִ��� ĭ ���� ����Ѵ�. 
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
!! ���� ���ĺ��� ���� ĭ�� �� �� ���� �� �����Ƿ�
boolean visited[]�� ������ �� ������ ��� vector<> v ���
�ش� ���ĺ��� �̹� �����Դ��� �˷��ִ� boolean alphabet[26]�� ����ϸ� �ð����⵵�� �������⵵ �� �� ���� �� ���� 
*/
