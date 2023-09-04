/*
baekjoon 6443��: �ֳʱ׷�

�ð� ����: 1��
�޸� ����: 128 MB

����
����� �ֳʱ׷�(anagram) ���α׷��� ����� �� �� �ִ� ���ڸ� �����Ѵ�. ����� ����� �ſ� ���ڴ�.
�ֳʱ׷� ���α׷��̶�, �Է¹��� ���ܾ��� ö�ڵ�� ���� �� �ִ� ��� �ܾ ����ϴ� ���̴�. ���� "abc" �� �Է¹޾Ҵٸ�, "abc", "acb", "bac", "bca", "cab", "cba" �� ����ؾ� �Ѵ�.
�Է¹��� �ܾ�� ��� ö�ڰ� �ߺ��� �� �ִ�. �� ��� ���� �ܾ ���� �� ����� �� �� �ִµ�, �� ���� ����ؾ� �Ѵ�.  ���� ����� ���� ���ĺ� ������ ����ؾ� �Ѵ�.

�Է�
ù° �ٿ� �ܾ��� ���� N ��, ��° �ٺ��� N���� ���ܾ ���´�. ���ܾ�� �ҹ��ڷ� �̷���� �ִ�.

���
N���� ���ܾ ���� ��� ������ �ֳʱ׷��� ����Ѵ�. ������ ���ܾ ���� �ֳʱ׷��� ����� ��, ���ĺ� ������ �ߺ����� �ʰ� ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n;
string s;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	while(n--) {
		cin >> s;
		
		sort(s.begin(),s.end());
		
		do {
			cout << s << "\n";
		} while(next_permutation(s.begin(),s.end()));
		
	}
}

/*
��Ʈ��ŷ, ����
*/
