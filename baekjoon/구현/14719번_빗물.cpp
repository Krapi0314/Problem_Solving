/*
baekjoon 14719��: ����

�ð� ����: 1��
�޸� ����: 256 MB

����
2���� ���迡 ����� �׿��ִ�. �� ���� ��� ���̿� ������ ���δ�.
��� ����� ���� �´�. ���̴� ������ �ѷ��� ���ϱ�?

�Է�
ù ��° �ٿ��� 2���� ������ ���� ���� H�� 2���� ������ ���� ���� W�� �־�����. (1 �� H, W �� 500)
�� ��° �ٿ��� ����� ���� ���̸� �ǹ��ϴ� 0�̻� H������ ������ 2���� ������ �� ���� ��ġ���� ���ʴ�� W�� �־�����.
���� ��� ������ �� ������ ���� �� ����. �� 2���� ������ �ٴ��� �׻� �����ִٰ� �����Ͽ��� ����.

���
2���� ���迡���� �� ĭ�� �뷮�� 1�̴�. ���̴� ������ �ѷ��� ����Ͽ���.
������ ���� ������ ���� ��� 0�� ����Ͽ���. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int h,w;
int arr[500];
int lefts, rights;
int ans;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> h >> w;
	for(int i=0; i<w; i++) {
		cin >> arr[i];
	}
	
	for(int i=0; i<w; i++) {
		lefts = 0; rights = 0;
		
		for(int j=0; j<i; j++) {
			lefts = max(lefts, arr[j]);
		}
		for(int j=i+1; j<w; j++) {
			rights = max(rights, arr[j]);
		}
		
		ans += min(lefts, rights) - arr[i] > 0 ? min(lefts, rights) - arr[i] : 0;
	}
	
	cout << ans;
}

// implementation

