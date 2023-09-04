/*
baekjoon 1157��: �ܾ� ����

�ð� ����: 2��
�޸� ����: 128 MB

����
���ĺ� ��ҹ��ڷ� �� �ܾ �־�����, �� �ܾ�� ���� ���� ���� ���ĺ��� �������� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�. ��, �빮�ڿ� �ҹ��ڸ� �������� �ʴ´�.

�Է�
ù° �ٿ� ���ĺ� ��ҹ��ڷ� �̷���� �ܾ �־�����. �־����� �ܾ��� ���̴� 1,000,000�� ���� �ʴ´�.

���
ù° �ٿ� �� �ܾ�� ���� ���� ���� ���ĺ��� �빮�ڷ� ����Ѵ�. ��, ���� ���� ���� ���ĺ��� ���� �� �����ϴ� ��쿡�� ?�� ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int alphabet[26];
string word;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> word;
	
	int len = word.size();
	for (int i=0; i<len; i++) {
		if ( 'a' <= word[i] && word[i] <= 'z') {
			word[i] = word[i] - 'a' + 'A';
		}
	}
	
	for (int i=0; i<len; i++) {
		alphabet[word[i]-'A']++;
	}
	
	pair<char, int> ans; // alphabet, count
	for (int i=0; i<26; i++) {
		if (alphabet[i] > ans.second) {
			ans.first = 'A' + i;
			ans.second = alphabet[i];
		}
	}
	
	int dup = 0;
	for (int i=0; i<26; i++) {
		if (alphabet[i] == ans.second) {
			dup++;
		}
	}
	
	if (dup >= 2) {
		cout << "?\n";
	}
	else {
		cout << ans.first << "\n";
	}
	
	return 0;
}

/* 

*/ 
