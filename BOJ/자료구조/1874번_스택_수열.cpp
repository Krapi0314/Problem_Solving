/*
BOJ 1874번: 스택 수열

시간 제한: 2초
메모리 제한: 128 MB

문제
스택 (stack)은 기본적인 자료구조 중 하나로, 컴퓨터 프로그램을 작성할 때 자주 이용되는 개념이다. 스택은 자료를 넣는 (push) 입구와 자료를 뽑는 (pop) 입구가 같아 제일 나중에 들어간 자료가 제일 먼저 나오는 (LIFO, Last in First out) 특성을 가지고 있다.
1부터 n까지의 수를 스택에 넣었다가 뽑아 늘어놓음으로써, 하나의 수열을 만들 수 있다. 이때, 스택에 push하는 순서는 반드시 오름차순을 지키도록 한다고 하자. 임의의 수열이 주어졌을 때 스택을 이용해 그 수열을 만들 수 있는지 없는지, 있다면 어떤 순서로 push와 pop 연산을 수행해야 하는지를 알아낼 수 있다. 이를 계산하는 프로그램을 작성하라.

입력
첫 줄에 n (1 ≤ n ≤ 100,000)이 주어진다. 둘째 줄부터 n개의 줄에는 수열을 이루는 1이상 n이하의 정수가 하나씩 순서대로 주어진다. 물론 같은 정수가 두 번 나오는 일은 없다.

출력
입력된 수열을 만들기 위해 필요한 연산을 한 줄에 한 개씩 출력한다. push연산은 +로, pop 연산은 -로 표현하도록 한다. 불가능한 경우 NO를 출력한다.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>

using namespace std;

int n;
queue<int> input;
queue<int> num;
queue<char> result;
stack<int> Stack;
int max_num;
int flag;

void cal()
{
	flag = 1;
	max_num = 0;
	for (int i = 1; i <= n; i++)
	{
		num.push(i);
	}

	while (!input.empty())
	{
		if (input.front() > max_num)
		{
			max_num = input.front();
			while (1)
			{
				if (num.front() == input.front())
				{
					Stack.push(num.front());
					num.pop();
					result.push('+');
					break;
				}
				Stack.push(num.front());
				num.pop();
				result.push('+');
			}

			Stack.pop();
			result.push('-');
		}
		else
		{
			if (input.front() == Stack.top())
			{
				Stack.pop();
				result.push('-');
			}
			else
			{
				flag = 0;
				break;
			}
		}

		input.pop();
	}

	if (flag == 1)
	{
		while (!result.empty())
		{
			printf("%c\n", result.front());
			result.pop();
		}
	}
	else
	{
		printf("NO\n");
	}
}

int main(void)
{
	int num;
	scanf("%d", &n);
	for (int i=0; i<n; i++)
	{
		scanf("%d", &num);
		input.push(num);
	}

	cal();
}

/*
* 안되는 경우: 뽑아야 할 값 이미 스택에 들어가 있지만, 스택의 top이 아니면
* 
* 1. n 입력, 1~n까지 큐 input에 push
* 2. 되는지 안되는지 판단
*	판단 함수 cal
*		연산 가능 flag = 1 로 초기설정
*		스택에 들어간 최댓값 = 0으로 설정
*		num 큐 설정 -> 1~n까지 오름차순으로 들어가 있음
*		
*		for 큐 input이 다 빌떄까지 
*			input 큐 top
*			if(top한 값이 최대값보다 크면)
				top한 값만큼 stack 스택에 num 큐를 top한 값이 나올떄까지 push
				이떄 push한 만큼 +를 result 큐에 저장
				그리고 Stack의 맨 위를 pop (result에도 저장)
			else //top한 값이 최대값보다 작으면 -> 이미 스택에 들어가 있음
				if(stack 스택에 맨 위에 있으면 -> top값이면)
					stack 스택 pop 하고 계속 진행
				else -> 스택의 맨 위가 아닌 어딘가에 있으면
					flag = 0 //연산 불가능 설정
					break
			
		if flag = 1
			result 큐 출력
		else
			NO 출력
*		
*/
