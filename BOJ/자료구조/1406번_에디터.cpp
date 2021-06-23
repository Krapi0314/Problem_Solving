/*
BOJ 1406번: 에디터

시간 제한: 0.3초
메모리 제한: 512 MB

문제
한 줄로 된 간단한 에디터를 구현하려고 한다. 이 편집기는 영어 소문자만을 기록할 수 있는 편집기로, 최대 600,000글자까지 입력할 수 있다.
이 편집기에는 '커서'라는 것이 있는데, 커서는 문장의 맨 앞(첫 번째 문자의 왼쪽), 문장의 맨 뒤(마지막 문자의 오른쪽), 또는 문장 중간 임의의 곳(모든 연속된 두 문자 사이)에 위치할 수 있다. 즉 길이가 L인 문자열이 현재 편집기에 입력되어 있으면, 커서가 위치할 수 있는 곳은 L+1가지 경우가 있다.
이 편집기가 지원하는 명령어는 다음과 같다.

L:	커서를 왼쪽으로 한 칸 옮김 (커서가 문장의 맨 앞이면 무시됨)
D:	커서를 오른쪽으로 한 칸 옮김 (커서가 문장의 맨 뒤이면 무시됨)
B:	커서 왼쪽에 있는 문자를 삭제함 (커서가 문장의 맨 앞이면 무시됨) 삭제로 인해 커서는 한 칸 왼쪽으로 이동한 것처럼 나타나지만, 실제로 커서의 오른쪽에 있던 문자는 그대로임
P $	: $라는 문자를 커서 왼쪽에 추가함

초기에 편집기에 입력되어 있는 문자열이 주어지고, 그 이후 입력한 명령어가 차례로 주어졌을 때, 모든 명령어를 수행하고 난 후 편집기에 입력되어 있는 문자열을 구하는 프로그램을 작성하시오. 단, 명령어가 수행되기 전에 커서는 문장의 맨 뒤에 위치하고 있다고 한다.

입력
첫째 줄에는 초기에 편집기에 입력되어 있는 문자열이 주어진다. 이 문자열은 길이가 N이고, 영어 소문자로만 이루어져 있으며, 길이는 100,000을 넘지 않는다. 둘째 줄에는 입력할 명령어의 개수를 나타내는 정수 M(1 ≤ M ≤ 500,000)이 주어진다. 셋째 줄부터 M개의 줄에 걸쳐 입력할 명령어가 순서대로 주어진다. 명령어는 위의 네 가지 중 하나의 형태로만 주어진다.

출력
첫째 줄에 모든 명령어를 수행하고 난 후 편집기에 입력되어 있는 문자열을 출력한다.
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

list<char> lt;
string s;
int m;
char c, input;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		lt.push_back(s[i]);
	}

	list<char>::iterator cur = lt.end();

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> input;
		
		if (input == 'L')
		{
			if (cur != lt.begin())
				cur--;
		}
		else if (input == 'D')
		{
			if (cur != lt.end())
				cur++;
		}
		else if (input == 'B')
		{
			if (cur != lt.begin())
				cur = lt.erase(--cur);
		}
		else
		{
			cin >> c;

			cur = lt.insert(cur, c);
			cur++;
		}
	}

	for (cur = lt.begin(); cur != lt.end(); cur++)
	{
		cout << *cur;
	}
}

/*
자료구조, list

!!deque를 사용하면 dq.insert와 dq.erase 때문에 0.3초 안에 실행 불가
=> 원소를 순회하면서 원소의 삭제와 삽입을 담당하는 list 사용! 

list lt
list iterator cur (커서 = iter, 커서는 커서가 가리키는 원소와 왼쪽 원소 사이에 있다고 생각)

cin string s
for s
	dq pushback s component

cur = lt.end()

cin m
for m
	cin char input
	if input L
		if cur != lt.begin()
			cur--;
	else if input D
		if cur != lt.end()
			cur++;
	else if input B
		if cur != lt.begin()
			cur = lt.erase(--cur) //커서의 왼쪽의 원소를 삭제하므로, --cur 한 뒤에 삭제, 반환값은 다음 원소의 iter이므로 그대로 받아서 cur에 저장
	else
		cin char c
		
		cur = lt.insert (cur,c) //커서의 왼쪽에 삽입, 반환값은 삽입한 원소의 iter이므로 cur에 저장
		cur++ //커서는 삽입한 원소 오른쪽에 있어야 하므로 cur++
*/
