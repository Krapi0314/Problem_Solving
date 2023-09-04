/*
baekjoon 1152: �ܾ��� ����

�ð� ����: 2��
�޸� ����: 128 MB

����
���� ��ҹ��ڿ� �������� �̷���� ���ڿ��� �־�����. �� ���ڿ����� �� ���� �ܾ ������? �̸� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. ��, �� �ܾ ���� �� �����ϸ� ������ Ƚ����ŭ ��� ����� �Ѵ�.

�Է�
ù �ٿ� ���� ��ҹ��ڿ� �������� �̷���� ���ڿ��� �־�����. �� ���ڿ��� ���̴� 1,000,000�� ���� �ʴ´�. �ܾ�� ���� �� ���� ���еǸ�, ������ �����ؼ� ������ ���� ����. ���� ���ڿ��� �������� �����ϰų� ���� �� �ִ�.

���
ù° �ٿ� �ܾ��� ������ ����Ѵ�. 
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void trim_front(string &str) {
	if (str[0] == ' ') {
		str = str.substr(1, str.size());
	}
}

vector<string> split(string sentence, char delimiter) {
	vector<string> words;
	stringstream ss(sentence);
	string word;
	
	while (getline(ss, word, delimiter)) {
		words.push_back(word);
	}
	
	return words;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string sentence;
	vector<string> words;
	
	getline(cin, sentence);
	
	trim_front(sentence);
	words = split(sentence, ' ');
	
	cout << words.size();
	
	return 0;
}

/* 

*/ 
