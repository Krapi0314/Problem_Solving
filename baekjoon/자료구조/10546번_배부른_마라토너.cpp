/*
baekjoon 10546��: ��θ� �������

�ð� ����: 1��
�޸� ����: 256 MB

����
������ʶ�� ������ ���̸� �ҹ��ϰ� ������ �����ϰ� �;��ϴ� ���� ������ ��ȸ�� ������. 42.195km�� �޸��� �� �������� ��ΰ� �����ϰ� �;��ߴ� ��ŭ �ų� ��ΰ� �����ؿԴ�. ��, �� �� ����! 
��ΰ� �����ϰ� �; �ȴ��ε� �̷� ���� ������ ��ȸ�� ������ ���� �������� ���� ��θ� ������ �� ���� ������?

�Է�
ù° �ٿ��� ������ �� N�� �־�����. (1 �� N �� 105)
N���� �ٿ��� �������� �̸��� �־�����.
�߰������� �־����� N-1���� �ٿ��� ������ �������� �̸��� ������ �ִ�. 
�����ڵ��� �̸��� ���̰� 1���� ũ�ų� ����, 20���� �۰ų� ���� ���ڿ��̰�, ���ĺ� �ҹ��ڷθ� �̷���� �ִ�.
�����ڵ� �߿� ���������� ���� ���� �ִ�. 

���
�������� �������� ���� �������� �̸��� ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
vector<string> v1;
vector<string> v2;
string s;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> s;
		v1.push_back(s);
	}
	for(int i=0; i<n-1; i++) {
		cin >> s;
		v2.push_back(s);
	}
	
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	
	for(int i=0; i<n-1; i++) {
		int idx = lower_bound(v1.begin(),v1.end(), v2[i]) - v1.begin();
		v1[idx] = "0";
	}
	
	for(int i=0; i<n; i++) {
		if(v1[i] != "0") {
			cout << v1[i];
			break;
		}
	}
}

// binary_search (map�� �̿��� Ǯ�̵� ����) 
