/*
BOJ 5430번: AC

시간 제한: 1초
메모리 제한: 256 MB

문제
선영이는 주말에 할 일이 없어서 새로운 언어 AC를 만들었다. AC는 정수 배열에 연산을 하기 위해 만든 언어이다. 이 언어에는 두 가지 함수 R(뒤집기)과 D(버리기)가 있다.
함수 R은 배열에 있는 숫자의 순서를 뒤집는 함수이고, D는 첫 번째 숫자를 버리는 함수이다. 배열이 비어있는데 D를 사용한 경우에는 에러가 발생한다.
함수는 조합해서 한 번에 사용할 수 있다. 예를 들어, "AB"는 A를 수행한 다음에 바로 이어서 B를 수행하는 함수이다. 예를 들어, "RDD"는 배열을 뒤집은 다음 처음 두 숫자를 버리는 함수이다.
배열의 초기값과 수행할 함수가 주어졌을 때, 최종 결과를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. T는 최대 100이다.
각 테스트 케이스의 첫째 줄에는 수행할 함수 p가 주어진다. p의 길이는 1보다 크거나 같고, 100,000보다 작거나 같다.
다음 줄에는 배열에 들어있는 수의 개수 n이 주어진다. (0 ≤ n ≤ 100,000)
다음 줄에는 [x1,...,xn]과 같은 형태로 배열에 들어있는 수가 주어진다. (1 ≤ xi ≤ 100)
전체 테스트 케이스에 주어지는 p의 길이의 합과 n의 합은 70만을 넘지 않는다.

출력
각 테스트 케이스에 대해서, 입력으로 주어진 정수 배열에 함수를 수행한 결과를 출력한다. 만약, 에러가 발생한 경우에는 error를 출력한다.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <deque>
#include <cstring>

using namespace std;

deque<int> num;
deque<char> p;
char command[400001];
int input;
int t, n;
int flag;
int error;
int len;

void D()
{
	if (num.empty())
	{
		error = 1;
	}
	else
	{
		if (flag == 0) //정방향
			num.pop_front();
		else //역방향
			num.pop_back();
	}
}

void R()
{
	//flag로 방향을 튼다
	if (flag == 1)
		flag = 0;
	else
		flag = 1;
}

int main(void)
{
	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		
		scanf("%s", &command);
		
		len = strlen(command);
		for (int j = 0; j < len; j++)
		{
			p.push_back(command[j]);
		}

		scanf("%d", &n);

		if (n == 0)
		{
			getchar();
			getchar();
			getchar();
		}
		else if (n == 1)
		{
			getchar();
			getchar();
			scanf("%d", &input);
			num.push_back(input);
			getchar();
		}
		else
		{
			getchar();
			getchar(); //[ 먹기
			for (int j = 0; j < n - 1; j++)
			{
				scanf("%d,", &input);
				num.push_back(input);
			}
			scanf("%d", &input);
			num.push_back(input);
			getchar();
		}

		while (!p.empty())
		{
			if (p.front() == 'R')
				R();
			else
				D();

			p.pop_front();
		}

		if (error == 1)
		{
			printf("error\n");
		}
		else
		{
			if (flag == 0)
			{
				printf("[");

				if (num.empty())
				{
					printf("]\n");
				}
				else
				{
					while (num.size() != 1)
					{
						printf("%d,", num.front());
						num.pop_front();
					}
					printf("%d]\n", num.front());
					num.pop_front();
				}
			}
			else
			{
				printf("[");

				if (num.empty())
				{
					printf("]\n");
				}
				else
				{
					while (num.size() != 1)
					{
						printf("%d,", num.back());
						num.pop_back();
					}
					printf("%d]\n", num.back());
					num.pop_back();
				}			
			}
		}

		//p,num은 초기화됨
		error = 0;
		flag = 0;
	}
}

/*
 테스트 케이스 t, 함수 p -> char형 queue, 배열 크기 n에 들어가있는 수 -> int형 deque (정,역방향 실행 고려)
 1. t,p,n, 배열 입력받기
.2. p 큐가 비워질떄까지
	if 함수 D
		if 숫자 배열이 비어있으면
			에러 처리
			break
		else
			함수 D 실행
	else
		함수 R 실행
			함수 R은 숫자 배열의 숫자를 뒤집지 않고, flag에 따라 정-선입선출, 반-선입선출의 과정으로 D에서 처리할 수 있게 flag 지정
				flag = 0이면 정방향: D 함수에서 pop_front 사용
				flag = 1이면 역방향: D 함수에서 pop_back 사용

3. 숫자 배열 출력
*/
