/*
baekjoon 1759��: ��ȣ �����

�ð� ����: 2��
�޸� ����: 128 MB

����
�ٷ� ���� �ֹ��� ������ �� ���踦 �ָӴϿ� ���� ä �����ϰ� ����� �� ������ Ȳ���� ��Ȳ�� ������ ��������, 702ȣ�� ���ο� ���� �ý����� ��ġ�ϱ�� �Ͽ���. �� ���� �ý����� ���谡 �ƴ� ��ȣ�� �����ϰ� �Ǿ� �ִ� �ý����̴�.
��ȣ�� ���� �ٸ� L���� ���ĺ� �ҹ��ڵ�� �����Ǹ� �ּ� �� ���� ����(a, e, i, o, u)�� �ּ� �� ���� �������� �����Ǿ� �ִٰ� �˷��� �ִ�. ���� ���ĵ� ���ڿ��� ��ȣ�ϴ� �������� �������� �̷�� ���� ��ȣ�� �̷�� ���ĺ��� ��ȣ���� �����ϴ� ������ �迭�Ǿ��� ���̶�� �����ȴ�. ��, abc�� ���ɼ��� �ִ� ��ȣ������ bac�� �׷��� �ʴ�.
�� ���� �ý��ۿ��� �������� ��ȣ�� ������� ���� ������ ������ C������ �ִٰ� �Ѵ�. �� ���ĺ��� �Լ��� �ν�, ���� ������ �������� �濡 ħ���ϱ� ���� ��ȣ�� ������ ������ �Ѵ�. C���� ���ڵ��� ��� �־����� ��, ���ɼ� �ִ� ��ȣ���� ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �� ���� L, C�� �־�����. (3 �� L �� C �� 15) ���� �ٿ��� C���� ���ڵ��� �������� ���еǾ� �־�����. �־����� ���ڵ��� ���ĺ� �ҹ����̸�, �ߺ��Ǵ� ���� ����.

���
�� �ٿ� �ϳ���, ���������� ���ɼ� �ִ� ��ȣ�� ��� ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int l,c;
char ch;
vector<char> v;
vector<char> ans;

void backtrack(int idx, int cnt) {
	if(cnt == l) {
		bool flag = false;
		int count = 0;
		
		for(int i=0; i<cnt; i++) {
			if(ans[i] == 'a' || ans[i] == 'e' || ans[i] == 'i' || ans[i] == 'o' || ans[i] == 'u') {
				flag = true;
			}
			else {
				count++;
			}
		}
		
		if(count >= 2 && flag) {
			for(int i=0; i<cnt; i++) {
				cout << ans[i];
			}
			cout << "\n";
		}
	}
	
	for(int i=idx; i<c; i++) {
		ans.push_back(v[i]);
		backtrack(i+1,cnt+1);
		ans.pop_back();
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> l >> c;
	for(int i=0; i<c; i++) {
		cin >> ch;
		v.push_back(ch);
	}
	
	sort(v.begin(), v.end());
	
	backtrack(0,0);
}

/*
brute force, backtrack
*/
