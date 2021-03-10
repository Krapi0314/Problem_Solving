/*
BOJ 6603번: 로또

시간 제한: 1초
메모리 제한: 128MB
 
문제
독일 로또는 {1, 2, ..., 49}에서 수 6개를 고른다.
로또 번호를 선택하는데 사용되는 가장 유명한 전략은 49가지 수 중 k(k>6)개의 수를 골라 집합 S를 만든 다음 그 수만 가지고 번호를 선택하는 것이다.
예를 들어, k=8, S={1,2,3,5,8,13,21,34}인 경우 이 집합 S에서 수를 고를 수 있는 경우의 수는 총 28가지이다. ([1,2,3,5,8,13], [1,2,3,5,8,21], [1,2,3,5,8,34], [1,2,3,5,13,21], ..., [3,5,8,13,21,34])
집합 S와 k가 주어졌을 때, 수를 고르는 모든 방법을 구하는 프로그램을 작성하시오.

입력
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 한 줄로 이루어져 있다. 첫 번째 수는 k (6 < k < 13)이고, 다음 k개 수는 집합 S에 포함되는 수이다. S의 원소는 오름차순으로 주어진다.
입력의 마지막 줄에는 0이 하나 주어진다. 

출력
각 테스트 케이스마다 수를 고르는 모든 방법을 출력한다. 이때, 사전 순으로 출력한다.
각 테스트 케이스 사이에는 빈 줄을 하나 출력한다.
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int k;
deque<int> dq;
vector<int> v;
int num;

void lotto(int n)
{
	if (n == 7)
	{
		for (int i = 0; i < 6; i++)
		{
			cout << dq[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < k; i++)
	{
		if (dq.empty() || v[i] > dq[n-2]) //promising 검사 (v 원소가 dq에 마지막으로 저장된 원소보다 클때 = 수열이 성립할때)
		{
			dq.push_back(v[i]);
			lotto(++n);
			dq.pop_back();
			n--;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1)
	{
		v.clear();
		dq.clear();

		cin >> k;
		
		if (k == 0)
			return 0;

		for (int i = 0; i < k; i++)
		{
			cin >> num;
			v.push_back(num);
		}

		lotto(1);
		cout << "\n";
	}

}

/*
집합 S와 k가 주어졌을 때, 수를 고르는 모든 방법을 구하는 프로그램을 작성하시오.
완전탐색, 백트래킹

void lotto(int n)
	if(n == 6)
		for 6
			cout possible deque
	
	for k
		if i >= n-1
			possible pushback arr[i]
			lotto(n+1)
			possible popback arr[i]
	

while 1
	cin k

	if(k == 0)
		return 0;

	for k
		cin arr

	lotto(int n) //모든 방법 출력, n번쨰 순열에 들어갈 수 선택
	cout << "\n"
	

*/
