/*
baekjoon 2504��: ��ȣ�� ��

�ð� ����: 1 ��
�޸� ����: 128 MB

����
4���� ��ȣ ��(��, ��)��, ��[��, ��]���� �̿��ؼ� ��������� ��ȣ�� �߿��� �ùٸ� ��ȣ���̶� ������ ���� ���ǵȴ�.

�� ���� ��ȣ�θ� �̷���� ��()���� ��[]���� �ùٸ� ��ȣ���̴�. 
���� X�� �ùٸ� ��ȣ���̸� ��(X)���̳� ��[X]���� ��� �ùٸ� ��ȣ���� �ȴ�. 
X�� Y ��� �ùٸ� ��ȣ���̶�� �̵��� ������ XY�� �ùٸ� ��ȣ���� �ȴ�.
���� ��� ��(()[[]])���� ��(())[][]�� �� �ùٸ� ��ȣ�������� ��([)]�� �� ��(()()[]�� �� ��� �ùٸ� ��ȣ���� �ƴϴ�. �츮�� � �ùٸ� ��ȣ�� X�� ���Ͽ� �� ��ȣ���� ��(��ȣ��)�� �Ʒ��� ���� �����ϰ� ��(X)�� ǥ���Ѵ�. 

��()�� �� ��ȣ���� ���� 2�̴�.
��[]�� �� ��ȣ���� ���� 3�̴�.
��(X)�� �� ��ȣ���� 2����(X) ���� ���ȴ�.
��[X]�� �� ��ȣ���� 3����(X) ���� ���ȴ�.

�ùٸ� ��ȣ�� X�� Y�� ���յ� XY�� ��ȣ���� ��(XY)= ��(X)+��(Y) �� ���ȴ�.
���� ��� ��(()[[]])([])�� �� ��ȣ���� ���غ���. ��()[[]]�� �� ��ȣ���� 2 + 3��3=11 �̹Ƿ� ��(()[[]])���� ��ȣ���� 2��11=22 �̴�. �׸��� ��([])���� ���� 2��3=6 �̹Ƿ� ��ü ��ȣ���� ���� 22 + 6 = 28 �̴�.
�������� Ǯ��� �� ������ �־��� ��ȣ���� �а� �� ��ȣ���� �տ��� �����Ѵ�� ����Ͽ� ����ϴ� ���̴�. 

�Է�
ù° �ٿ� ��ȣ���� ��Ÿ���� ���ڿ�(��Ʈ��)�� �־�����. �� �� ���̴� 1 �̻�, 30 �����̴�.

���
ù° �ٿ� �� ��ȣ���� ���� ��Ÿ���� ������ ����Ѵ�. ���� �Է��� �ùٸ��� ���� ��ȣ���̸� �ݵ�� 0�� ����ؾ� �Ѵ�.  
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

string str;
stack<string> st;
int ans;

bool calInnerLoop(string str1, string str2, int value) {
	int sum = 0;
	
	if(st.empty()) {
		return false;
	}
	
	while(!st.empty()) {
		if(st.top() == str1) { // ¦�� �´� ���� ��ȣ�� �� 
			st.pop();
			sum *= value;
			st.push(to_string(sum));
			break;
		}
		else if(st.top() == str2) { // ¦�� ���� �ʴ� ���� ��ȣ�� �� 
			return false;
		}
		else { // ������ �� 
			sum += stoi(st.top());
			st.pop();
		}
	}
	
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> str;
	
	bool valid = true;
	for(int i=0; i<(int)str.size(); i++) {
		if(!valid) {
			break;
		}
		
		if(str[i] == '(') {
			st.push("(");
		}
		else if(str[i] == '[') {
			st.push("[");
		}
		else if(str[i] == ')') {
			if(!st.empty() && st.top() == "(") {
				st.pop();
				st.push("2");
			}
			else {
				valid = calInnerLoop("(", "[", 2);
			}
		}
		else if(str[i] == ']') {
			if(!st.empty() && st.top() == "[") {
				st.pop();
				st.push("3");
			}
			else {
				valid = calInnerLoop("[", "(", 3);
			}
		}
	}
		
	while(!st.empty()) {
		if(st.top() == "(" || st.top() == "[" || st.top() == ")" || st.top() == "]") {
			ans = 0;
			break;
		}
		else {
			ans += stoi(st.top());
			st.pop();
		}
	}
	
	cout << ans;
	
	return 0;
}

/*
�ڷᱸ��: ����
���ÿ� ���ڱ��� �����Ͽ� ��Ģ������ �������� ����ϴ� ��ó�� ���
*/
