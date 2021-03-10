/*
BOJ 10828번: 스택

시간 제한: 0.5초 (추가 시간 없음)
메모리 제한: 256 MB

문제
정수를 저장하는 스택을 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.
명령은 총 다섯 가지이다.

push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.

입력
첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

출력
출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

char command[6];
int input_num;
int n;

vector<int> stack;

void push(int num)
{
	stack.push_back(num);
}

void pop()
{
	if (stack.size() == 0)
		printf("-1\n");
	else
	{
		printf("%d\n", stack.back());
		stack.pop_back();
	}
}

void size()
{
	printf("%d\n", stack.size());
}

void empty()
{
	if (stack.size() == 0)
	{
		printf("1\n");
	}
	else
	{
		printf("0\n");
	}
}

void top()
{
	if (stack.size() == 0)
	{
		printf("-1\n");
	}
	else
	{
		printf("%d\n", stack.back());
	}
}

int main(void)
{
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		scanf("%s", command);

		if(!strncmp(command,"push",4))
		{
			scanf("%d", &input_num);
			push(input_num);
		}
		else if (!strncmp(command, "pop",3))
		{
			pop();
		}
		else if (!strncmp(command, "size",4))
		{
			size();
		}
		else if (!strncmp(command, "empty",5))
		{
			empty();
		}
		else
		{
			top();
		}
	}

}

/*

*/
