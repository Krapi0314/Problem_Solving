/*
baekjoon 3613��: Java vs C++

�ð� ����: 1��
�޸� ����: 128 MB

����
Java �������� �赿�Կ� C++ ��ȣ�� �赿���� ���� � ���α׷��� �� �ְ����� �� �ð����� ����� �ϰ� �ߴ�. ���Դ� Java�� ��Ȯ�ϰ� ������ ���� ���α׷��� ����ٰ� �����߰�, �����̴� Java�� ���α׷��� ������, �� �ҽ� �ڵ带 ���� ���� ���׸� �迭�� �ν��Ͻ�ȭ�� ���ɷ��� �������.
��, �赿�Կ� �赿���� ���� �̸��� ���� ��ĵ� ���� �޶���. Java������ ������ �̸��� ���� �ܾ�� �̷�������� ��, ������ ���� ������� �������� ���´�. 
ù �ܾ�� �ҹ��ڷ� ����, ���� �ܾ���ʹ� ù ���ڸ� �빮�ڷ� ����. ��, ��� �ܾ�� �ٿ�����. ���� Java�� �������� javaIdentifier, longAndMnemonicIdentifier, name, bAEKJOON�� ���� �����̴�.
�ݸ鿡 C++������ ������ �ҹ��ڸ� ����Ѵ�. �ܾ�� �ܾ �����ϱ� ���ؼ� ����('_')�� �̿��Ѵ�. C++ �������� c_identifier, long_and_mnemonic_identifier, name, b_a_e_k_j_o_o_n�� ���� �����̴�.
�� ���� �ο��� �������ٰ� ���� ����̴� C++������ �������� Java������ ����������, �Ǵ� �� �ݴ�� �ٲ��ִ� ���α׷��� ������� �Ѵ�. �� ����� ������ ������ ���� ������ ����� �Ѵ�.
������� ���α׷��� ���� ���� �������� �Է����� ���� ��, �� �������� � ��� ���������� �˾Ƴ��� �Ѵ�. �� ����, C++�����̶�� Java��������, Java�����̶�� C++�������� �ٲٸ� �ȴ�. ���� C++���İ� Java���� �� �� �ƴ϶��, ������ �߻���Ų��. �������� ��ȯ�� ��, �ܾ��� ������ �����Ǿ�� �Ѵ�.
����̴� ���α׷��� ������� ������, �ʹ� ������ ������ �̸� ������ �д� ����� ������ �ðܳ���.
����̰� ������� �� ���α׷��� ��� ������.

�Է�
ù° �ٿ� �������� �־�����. ���� ���ĺ��� ����('_')�θ� �̷���� �ְ�, ���̴� 100�� ���� �ʴ´�.

���
�Է����� �־��� �������� Java�����̸�, C++�������� ����ϰ�, C++�����̶�� Java�������� ����Ѵ�. �� �� �ƴ϶�� "Error!"�� ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

string s;
int cnt;
bool java, c_plus, error;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> s;
	
	java = true; c_plus = true; error = false;
	for(int i=0; i<s.size(); i++) {
		if(s[0] >= 'A' && s[0] <= 'Z') {
			java = false;
		}
		if(!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))) {
			java = false;
		}
	}
	
	for(int i=0; i<s.size(); i++) {
		if(s[i] == '_') {
			cnt++;
		}
		if(!((s[i] >= 'a' && s[i] <= 'z') || (s[i] == '_'))) {
			c_plus = false;
		}
		if(i > 1 && (s[i] == '_' && s[i-1] == '_')) {
			c_plus = false;
		}
	}
	
	// error check	
	if(s[0] == '_' || s[s.size()-1] == '_') error = true;
	if(!java && !c_plus) error = true;
	
	
	if(error) {
		cout << "Error!";
	}
	else {
		if(java && c_plus) {
			cout << s;
		}
		else if(java) {
			int prev_idx = 0;
			for(int i=0; i<s.size(); i++) {
				if(s[i] >= 'A' && s[i] <= 'Z') {
					string word = s.substr(prev_idx, i-prev_idx);
					
					if(prev_idx != 0)
						word[0] = word[0] - 'A' + 'a';
					
					cout << word << "_";
					prev_idx = i;
				}
			}
			string word = s.substr(prev_idx,s.size()-prev_idx);
			word[0] = word[0] - 'A' + 'a';
			cout << word;
		}
		else {
			int prev_idx = 0;
			for(int i=0; i<s.size(); i++) {
				if(s[i] == '_') {
					string word = s.substr(prev_idx, i-prev_idx);
					
					if(prev_idx != 0)
						word[0] = word[0] - 'a' + 'A';
					
					cout << word;
					prev_idx = i+1;
				}
			}
			string word = s.substr(prev_idx,s.size()-prev_idx);
			word[0] = word[0] - 'a' + 'A';
			cout << word;
		}		
	}

}

/*
string, many exceptions
*/
