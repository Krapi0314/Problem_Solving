/*
BOJ 1764번: 듣보잡

시간 제한: 2초
메모리 제한: 256 MB

문제
김진영이 듣도 못한 사람의 명단과, 보도 못한 사람의 명단이 주어질 때, 듣도 보도 못한 사람의 명단을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 듣도 못한 사람의 수 N, 보도 못한 사람의 수 M이 주어진다. 이어서 둘째 줄부터 N개의 줄에 걸쳐 듣도 못한 사람의 이름과, N+2째 줄부터 보도 못한 사람의 이름이 순서대로 주어진다. 이름은 띄어쓰기 없이 알파벳 소문자로만 이루어지며, 그 길이는 20 이하이다. N, M은 500,000 이하의 자연수이다.
듣도 못한 사람의 명단에는 중복되는 이름이 없으며, 보도 못한 사람의 명단도 마찬가지이다.

출력
듣보잡의 수와 그 명단을 사전순으로 출력한다. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

set<string> s1, s2;
string s;
int n, m;
vector<string> v;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		s1.insert(s);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		s2.insert(s);
	}

	set<string>::iterator iter;
	set<string>::iterator f_iter;

	for (iter = s1.begin(); iter != s1.end(); iter++)
	{
		f_iter = s2.find(*iter);
		if (f_iter != s2.end())
			v.push_back(*f_iter);
	}

	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << "\n";
	}
}

/*
두 집합의 교집합 찾기 -> 탐색
n,m 상한: 500,000 => 일반적인 2중 for문을 이용한 탐색 시간복잡도: 2천억회 이상 => 이분 탐색으로 시간 단축해야 함

=> set 컨테이너로 두 집합을 저장(자동 정렬)하고, 비교(이진 트리의 탐색 = 이분 탐색, 두 set의 원소들을 비교, 시간복잡도: O(nlogn)-> 3백만회)해서 시간 단축

cin n m
for n
	cin s (string)
	s1.insert(s)
for m
	cin s (string)
	s2.insert(s)

for s1 iter
	f_iter = s2.find(*iter)
	if(f_iter != s2.end())
		v.pushback(f_iter)

cout v.size
for v
	cout v[i]

*/
