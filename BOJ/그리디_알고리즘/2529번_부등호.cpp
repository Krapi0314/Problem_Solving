/*
BOJ 2529번: 부등호

시간 제한: 1초
메모리 제한: 256 MB

문제
두 종류의 부등호 기호 ‘<’와 ‘>’가 k개 나열된 순서열  A가 있다. 우리는 이 부등호 기호 앞뒤에 서로 다른 한 자릿수 숫자를 넣어서 모든 부등호 관계를 만족시키려고 한다. 예를 들어, 제시된 부등호 순서열 A가 다음과 같다고 하자. 
A =>  < < < > < < > < >
부등호 기호 앞뒤에 넣을 수 있는 숫자는 0부터 9까지의 정수이며 선택된 숫자는 모두 달라야 한다. 아래는 부등호 순서열 A를 만족시키는 한 예이다. 
3 < 4 < 5 < 6 > 1 < 2 < 8 > 7 < 9 > 0
이 상황에서 부등호 기호를 제거한 뒤, 숫자를 모두 붙이면 하나의 수를 만들 수 있는데 이 수를 주어진 부등호 관계를 만족시키는 정수라고 한다. 그런데 주어진 부등호 관계를 만족하는 정수는 하나 이상 존재한다. 예를 들어 3456128790 뿐만 아니라 5689023174도 아래와 같이 부등호 관계 A를 만족시킨다. 
5 < 6 < 8 < 9 > 0 < 2 < 3 > 1 < 7 > 4
여러분은 제시된 k개의 부등호 순서를 만족하는 (k+1)자리의 정수 중에서 최댓값과 최솟값을 찾아야 한다. 앞서 설명한 대로 각 부등호의 앞뒤에 들어가는 숫자는 { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }중에서 선택해야 하며 선택된 숫자는 모두 달라야 한다. 

입력
첫 줄에 부등호 문자의 개수를 나타내는 정수 k가 주어진다. 그 다음 줄에는 k개의 부등호 기호가 하나의 공백을 두고 한 줄에 모두 제시된다. k의 범위는 2 ≤ k ≤ 9 이다. 

출력
여러분은 제시된 부등호 관계를 만족하는 k+1 자리의 최대, 최소 정수를 첫째 줄과 둘째 줄에 각각 출력해야 한다. 단 아래 예(1)과 같이 첫 자리가 0인 경우도 정수에 포함되어야 한다. 모든 입력에 답은 항상 존재하며 출력 정수는 하나의 문자열이 되도록 해야 한다. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int k;
char c;
vector<char> oper;
vector<int> Max;
vector<int> Min;

bool valid(vector<int> &arr)
{
	for (int i = 0; i < k; i++)
	{
		if (oper[i] == '<' && arr[i] > arr[i + 1])
			return false;
		else if (oper[i] == '>' && arr[i] < arr[i + 1])
			return false;
	}

	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> c;
		oper.push_back(c);
	}

	//최대
	for (int i = 9; i > 9 - (k + 1); i--)
	{
		Max.push_back(i);
	}
	while (true)
	{
		if (valid(Max))
			break;
		else
			prev_permutation(Max.begin(), Max.end());
	}

	//최소
	for (int i = 0; i < (k + 1); i++)
	{
		Min.push_back(i);
	}
	while (true)
	{
		if (valid(Min))
			break;
		else
			next_permutation(Min.begin(), Min.end());
	}

	for (int i = 0; i < k + 1; i++)
	{
		cout << Max[i];
	}
	cout << "\n";
	for (int i = 0; i < k + 1; i++)
	{
		cout << Min[i];
	}
}

/*
greedy, next_permutation
부등호 순서를 만족하는 최댓값/최솟값을 greedy하게 구할 경우, 최댓값의 경우 9 ~ 9~9-(k+1)의 수들로, 최솟값의 경우 0 ~ k+1의 수들로 이루어져 있음

cin k
for k
	cin char c
	vector oper pushback c

//최댓값
for 9 to 9-(k+1)
	vector m pushback i

while true
	if vaild() //해당 순열과 부동호의 관계가 성립하면
		break
	else
		prev_permutation //이전 순열로 ('순열'이 작아짐)

//최솟값
...
	next_permutation //다음 순열로 ('순열'이 커짐)

bool valid()
	for k
		if oper[i] == '>' && m[i] < m[i+1]
			return false
		else if oper[i] == '<' && m[i] > m[i+1]
			return false

	return true
*/
