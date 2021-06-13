/*
BOJ 2164번: 카드2

시간 제한: 2초
메모리 제한: 128 MB

문제
N장의 카드가 있다. 각각의 카드는 차례로 1부터 N까지의 번호가 붙어 있으며, 1번 카드가 제일 위에, N번 카드가 제일 아래인 상태로 순서대로 카드가 놓여 있다.
이제 다음과 같은 동작을 카드가 한 장 남을 때까지 반복하게 된다. 우선, 제일 위에 있는 카드를 바닥에 버린다. 그 다음, 제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로 옮긴다.
예를 들어 N=4인 경우를 생각해 보자. 카드는 제일 위에서부터 1234 의 순서로 놓여있다. 1을 버리면 234가 남는다. 여기서 2를 제일 아래로 옮기면 342가 된다. 3을 버리면 42가 되고, 4를 밑으로 옮기면 24가 된다. 마지막으로 2를 버리고 나면, 남는 카드는 4가 된다.

N이 주어졌을 때, 제일 마지막에 남게 되는 카드를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 N(1 ≤ N ≤ 500,000)이 주어진다.

출력
첫째 줄에 남게 되는 카드의 번호를 출력한다. 
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

queue<int> card;

int n;
int temp;

int main(void)
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		card.push(i);
	}

	while (card.size() != 1)
	{
		card.pop();
		temp = card.front();
		card.pop();
		card.push(temp);
	}

	cout << card.front();
}

/*
* 큐로 단순 구현
* 1. n 입력
* 2. 큐에 1~n까지 순차적으로 push
* 3. while(큐에 하나의 숫자만이 남을 떄까지)
*		맨 위의 카드 버리기 (pop)
*		그 다음 카드 temp에 저장 후 큐에 다시 집어넣기 (top -> pop -> push)
* 4. 마지막으로 남은 숫자 출력 
*/
