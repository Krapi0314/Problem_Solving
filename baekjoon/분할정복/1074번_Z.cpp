/*
baekjoon 1074��: Z

�ð� ����: 0.5 �� (�߰� �ð� ����)
�޸� ����: 512 MB

����
�Ѽ��� ũ�Ⱑ 2N �� 2N�� 2���� �迭�� Z������� Ž���Ϸ��� �Ѵ�. ���� ���, 2��2�迭�� ���� ��ĭ, ������ ��ĭ, ���� �Ʒ�ĭ, ������ �Ʒ�ĭ ������� �湮�ϸ� Z����̴�.
N > 1�� ���, �迭�� ũ�Ⱑ 2N-1 �� 2N-1�� 4��� �� �Ŀ� ��������� ������� �湮�Ѵ�.
N�� �־����� ��, r�� c���� �� ��°�� �湮�ϴ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� N, r, c�� �־�����.

���
r�� c���� �� ��°�� �湮�ߴ��� ����Ѵ�.

����
1 �� N �� 15
0 �� r, c < 2N 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int N, r, c;
int cnt; 

void visits(int y, int x, int n) {
	if(n == 1) {
		if(y == r && x == c) {
			cout << cnt;
		}
		else {
			cnt++;	
		}
		return;
	}
	
	int div = n/2;
	// n��° ��и�: Z�� �������� �� ���� 
	// (r,c)�� 4���� ��и鿡 ��ġ�� ���: 1~3���� ��и������ ���� �湮���� �ʰ� �ش� ��и���� ���̸�ŭ cnt�� �����ְ�, ���� 4��° ��и� �湮 
	if(r >= y+div && c >= x+div) {
		cnt += (div*div)*3;
		visits(y+div, x+div, div);
	}
	// (r,c)�� 3���� ��и鿡 ��ġ�� ���: 1~2���� ��и������ ���� �湮���� �ʰ� �ش� ��и���� ���̸�ŭ cnt�� �����ְ�, ���� 3��° ��и� �湮 
	else if(r >= y+div) {
		cnt += (div*div)*2;
		visits(y+div, x, div);
	}
	// (r,c)�� 2���� ��и鿡 ��ġ�� ���: 1���� ��и��� ���� �湮���� �ʰ� �ش� ��и��� ���̸�ŭ cnt�� �����ְ�, ���� 2��° ��и� �湮 
	else if(c >= x+div) {
		cnt += div*div;
		visits(y, x+div, div);
	}
	// (r,c)�� 1���� ��и鿡 ��ġ�� ���: �״�� 1��° ��и� �湮 
	else {
		visits(y, x, div);
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> r >> c;
	
	visits(0,0, pow(2,N));
	return 0;
}

/* 
�������� 
*/ 
