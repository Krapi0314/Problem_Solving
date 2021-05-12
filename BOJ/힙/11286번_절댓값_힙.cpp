/*
BOJ 11286번: 절댓값 힙

시간 제한: 1초
메모리 제한: 256 MB

문제
절댓값 힙은 다음과 같은 연산을 지원하는 자료구조이다.

배열에 정수 x (x ≠ 0)를 넣는다.
배열에서 절댓값이 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다. 절댓값이 가장 작은 값이 여러개일 때는, 가장 작은 수를 출력하고, 그 값을 배열에서 제거한다.
프로그램은 처음에 비어있는 배열에서 시작하게 된다.

입력
첫째 줄에 연산의 개수 N(1≤N≤100,000)이 주어진다. 다음 N개의 줄에는 연산에 대한 정보를 나타내는 정수 x가 주어진다. 만약 x가 0이 아니라면 배열에 x라는 값을 넣는(추가하는) 연산이고, x가 0이라면 배열에서 절댓값이 가장 작은 값을 출력하고 그 값을 배열에서 제거하는 경우이다. 입력되는 정수는 -231보다 크고, 231보다 작다.

출력
입력에서 0이 주어진 회수만큼 답을 출력한다. 만약 배열이 비어 있는 경우인데 절댓값이 가장 작은 값을 출력하라고 한 경우에는 0을 출력하면 된다. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <functional>
#include <cmath>

//#include <cstdio>

using namespace std;

int n;
int input;

struct compare { //비교연산자는 함수 객체로 선언: operator() 오버로딩해서 사용
	bool operator()(int a, int b)
	{
		if (abs(a) == abs(b))
		{
			return a > b;
		}
		else
		{
			return abs(a) > abs(b);
		}
	}
};


priority_queue<int, vector<int>, compare> pq; //선언할떄 사용자 정의 비교연산 함수는 함수 객체 형태로.

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input;

		if (input == 0)
		{
			if (pq.empty())
			{
				cout << "0" << "\n";
			}
			else
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else //자연수
		{
			pq.push(input);
		}
	}

}

/*
절대값 힙 연산
	1. 0을 제외한 정수 push
	2. 정렬 기준 (priority_queue에 사용자 정의 연산자를 사용)
		1. 절댓값이 작은 값이 우선순위 높음
		2. 절댓값이 같으면 원래 값이 작은 수가 우선순위 높음

연산의 수 n

*/
