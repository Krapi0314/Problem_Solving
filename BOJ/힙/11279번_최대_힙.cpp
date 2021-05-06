/*
BOJ 11279번: 최대 힙

시간 제한: 1초
메모리 제한: 256 MB

문제
널리 잘 알려진 자료구조 중 최대 힙이 있다. 최대 힙을 이용하여 다음과 같은 연산을 지원하는 프로그램을 작성하시오.

배열에 자연수 x를 넣는다.
배열에서 가장 큰 값을 출력하고, 그 값을 배열에서 제거한다.
프로그램은 처음에 비어있는 배열에서 시작하게 된다.

입력
첫째 줄에 연산의 개수 N(1 ≤ N ≤ 100,000)이 주어진다. 다음 N개의 줄에는 연산에 대한 정보를 나타내는 정수 x가 주어진다. 만약 x가 자연수라면 배열에 x라는 값을 넣는(추가하는) 연산이고, x가 0이라면 배열에서 가장 큰 값을 출력하고 그 값을 배열에서 제거하는 경우이다. 입력되는 자연수는 231보다 작다.

출력
입력에서 0이 주어진 회수만큼 답을 출력한다. 만약 배열이 비어 있는 경우인데 가장 큰 값을 출력하라고 한 경우에는 0을 출력하면 된다. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>

//#include <cstdio>

using namespace std; 

int n;
int input;
priority_queue<int> pq;

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
힙 구현 (최대 힙)

자연수(int)가 나오면 힙에 값 추가
0이 나오면 힙의 루트 값 출력 후 제거

1. 연산의 개수 n 입력
2. n번 입력받기
	자연수가 나오면 힙 push 연산
	0이 나오면
		if 힙이 비어있으면
			0 출력
		else
			top 후 pop
*/
