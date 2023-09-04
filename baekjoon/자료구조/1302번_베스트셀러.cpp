/*
baekjoon 1302��: ����Ʈ����

�ð� ����: 2�� 
�޸� ����: 128 MB

����
�������� ž������ �����̴�. �������� ���뿡�� ����� �ϴ� �����̴�. �������� �׳� �ٹ��� ���� �Ŀ�, ���� �Ǹ��� å�� ������ ���鼭 ���� ���� �ȸ� å�� ������ ĥ�ǿ� ����� �ϵ� ���� �ϰ� �ִ�.
���� �Ϸ� ���� �ȸ� å�� ������ �Է����� ������ ��, ���� ���� �ȸ� å�� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� �Ϸ� ���� �ȸ� å�� ���� N�� �־�����. �� ���� 1,000���� �۰ų� ���� �ڿ����̴�. ��°���� N���� �ٿ� å�� ������ �Է����� ���´�. å�� ������ ���̴� 50���� �۰ų� ����, ���ĺ� �ҹ��ڷθ� �̷���� �ִ�.

���
ù° �ٿ� ���� ���� �ȸ� å�� ������ ����Ѵ�. ���� ���� ���� �ȸ� å�� ���� ���� ��쿡�� ���� ������ ���� �ռ��� ������ ����Ѵ�. 
*/

 #include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
string s;
int Max;
vector<string> v;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	while(n--) {
		cin >> s;
		v.push_back(s);
	}
	
	sort(v.begin(), v.end());
	
	int cnt = 1; s = v[0];
	for(int i=1; i<=v.size(); i++) {
		if(i == v.size() || v[i] != v[i-1]) {
			if(cnt > Max) {
				Max = cnt;
				s = v[i-1];
			}	
			cnt = 1;
		}
		else {
			cnt++;
		}
	}
	
	cout << s;
}

/*
�ڷᱸ��
1. vector<string>�� sort �� ��ȸ�ϸ� ���ϴ� ���
2. map<string, int>�� ���� �� ��ȸ�ϸ� ���ϴ� ���
*/
