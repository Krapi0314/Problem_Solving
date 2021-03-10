/*
BOJ 1182번: 부분수열의 합

시간 제한: 2초
메모리 제한: 256 MB

문제
N개의 정수로 이루어진 수열이 있을 때, 크기가 양수인 부분수열 중에서 그 수열의 원소를 다 더한 값이 S가 되는 경우의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정수의 개수를 나타내는 N과 정수 S가 주어진다. (1 ≤ N ≤ 20, |S| ≤ 1,000,000) 둘째 줄에 N개의 정수가 빈 칸을 사이에 두고 주어진다. 주어지는 정수의 절댓값은 100,000을 넘지 않는다.

출력
첫째 줄에 합이 S가 되는 부분수열의 개수를 출력한다.
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

deque<int> combi;
vector<int> v;
int num;
int n,s;
int cnt;

void combination(int n,int v_idx)
{
	if (n == 0)
	{
		int sum = 0;
		for (int i = 0; i < combi.size(); i++)
		{
			sum += combi[i];
		}

		if (sum == s) //수열의 원소를 다 더한 값이 S가 되면
			cnt++; //경우의 수++

		return;
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (combi.empty() || i > v_idx)
		{
			combi.push_back(v[i]);
			combination(--n,i);
			combi.pop_back();
			n++;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	for (int i = 1; i <= n; i++)
	{
		combination(i,0);
	}

	cout << cnt;
}

/*
그 수열의 원소를 다 더한 값이 S가 되는 경우의 수를 구하는 프로그램을 작성하시오.
완전탐색, 백트래킹

deque combi[] //뽑은 숫자 저장 배열

void combination(int n) //순열에서 n개를 뽑아 원소합이 0인지 확인
	if(n == 0)
		int sum
		for combi size
			sum += combi
		
		if(sum == 0)
			cnt++
		return
	
	for vector
		combi pushback v[i]
		combination(--n)
		combi popback v[i]
		n++
		


cin n s
for n
	cin num
	vector pushback num

for n
	combination(i)

cout << cnt
*/
