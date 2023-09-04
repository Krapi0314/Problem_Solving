/*
baekjoon 19598��: �ּ� ȸ�ǽ� ����

�ð� ����: 2��
�޸� ����: 256 MB

����
�����̴� �ƺ��κ��� N���� ȸ�Ǹ� ��� ������ �� �ִ� �ּ� ȸ�ǽ� ������ ���϶�� �̼��� �޾Ҵ�. �� ȸ�Ǵ� ���� �ð��� ������ �ð��� �־����� �� ȸ�ǽǿ��� ���ÿ� �� �� �̻��� ȸ�ǰ� ����� �� ����. ��, ȸ�Ǵ� �ѹ� ���۵Ǹ� �߰��� �ߴܵ� �� ������ �� ȸ�ǰ� ������ �Ͱ� ���ÿ� ���� ȸ�ǰ� ���۵� �� �ִ�. ȸ���� ���� �ð��� ������ �ð����� �׻� �۴�. N�� �ʹ� Ŀ�� ���ο� �ϴ� �츮 �����̸� ��������.

�Է�
ù° �ٿ� �迭�� ũ�� N(1 �� N �� 100,000)�� �־�����. ��° �ٺ��� N+1 �ٱ��� ������ ���̿� �ΰ� ȸ���� ���۽ð��� ������ �ð��� �־�����. ���� �ð��� ������ �ð��� 231?1���� �۰ų� ���� �ڿ��� �Ǵ� 0�̴�.

���
ù° �ٿ� �ּ� ȸ�ǽ� ������ ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
vector<pair<int,int>> v; // first: time, second: cnt + 1 or cnt - 1
int a,b;
int cnt;
int ans;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> a >> b;
		v.push_back(make_pair(a, 1));
		v.push_back(make_pair(b, -1));
	}
	
	sort(v.begin(), v.end());
	
	for(int i=0; i<(int)v.size(); i++) {
		cnt += v[i].second;
		
		ans = max(ans, cnt);
	}
	
	cout << ans;
}

// greedy
/*
cnt: ���� ���� ���� ȸ���� ��
N���� ȸ�Ǹ� ��� ������ �� �ִ� �ּ� ȸ�ǽ��� ���� = cnt�� �ִ�
ȸ�� ���� �� cnt++, ȸ�� ���� �� cnt--
ȸ���� ���۰� ���� ���� ���� �� �ð� ������ sort, ���� ������� �����鼭 cnt ����, �ִ� ã�� 
*/ 
