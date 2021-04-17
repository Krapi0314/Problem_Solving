/*

BOJ 1966번: 프린터 큐

시간 제한: 2초
메모리 제한: 128 MB

문제
여러분도 알다시피 여러분의 프린터 기기는 여러분이 인쇄하고자 하는 문서를 인쇄 명령을 받은 ‘순서대로’, 즉 먼저 요청된 것을 먼저 인쇄한다. 여러 개의 문서가 쌓인다면 Queue 자료구조에 쌓여서 FIFO - First In First Out - 에 따라 인쇄가 되게 된다. 하지만 상근이는 새로운 프린터기 내부 소프트웨어를 개발하였는데, 이 프린터기는 다음과 같은 조건에 따라 인쇄를 하게 된다.

현재 Queue의 가장 앞에 있는 문서의 ‘중요도’를 확인한다.
나머지 문서들 중 현재 문서보다 중요도가 높은 문서가 하나라도 있다면, 이 문서를 인쇄하지 않고 Queue의 가장 뒤에 재배치 한다. 그렇지 않다면 바로 인쇄를 한다.
예를 들어 Queue에 4개의 문서(A B C D)가 있고, 중요도가 2 1 4 3 라면 C를 인쇄하고, 다음으로 D를 인쇄하고 A, B를 인쇄하게 된다.

여러분이 할 일은, 현재 Queue에 있는 문서의 수와 중요도가 주어졌을 때, 어떤 한 문서가 몇 번째로 인쇄되는지 알아내는 것이다. 예를 들어 위의 예에서 C문서는 1번째로, A문서는 3번째로 인쇄되게 된다.

입력
첫 줄에 테스트케이스의 수가 주어진다. 각 테스트케이스는 두 줄로 이루어져 있다.

테스트케이스의 첫 번째 줄에는 문서의 개수 N(1 ≤ N ≤ 100)과, 몇 번째로 인쇄되었는지 궁금한 문서가 현재 Queue에서 몇 번째에 놓여 있는지를 나타내는 정수 M(0 ≤ M < N)이 주어진다. 이때 맨 왼쪽은 0번째라고 하자. 두 번째 줄에는 N개 문서의 중요도가 차례대로 주어진다. 중요도는 1 이상 9 이하의 정수이고, 중요도가 같은 문서가 여러 개 있을 수도 있다.

출력
각 테스트 케이스에 대해 문서가 몇 번째로 인쇄되는지 출력한다

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

typedef struct _Print
{
	int priority;
	bool qurious;
} print;

int t, n, m;
int cnt;
queue<print> q;
print temp;

int main(void)
{
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d %d", &n, &m);
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &temp.priority);
			
			if (j == m)
			{
				temp.qurious = true;
				q.push(temp);
			}
			else
			{
				temp.qurious = false;
				q.push(temp);
			}
		}
		
		while (1)
		{
			int flag = 0; //중요도가 더 높은 값이 있으면 1
			int priority_to_check = q.front().priority;
			for (int i = 0; i < q.size(); i++) //한바퀴 돌면서 중요도 검사
			{
				if (priority_to_check < q.front().priority)
				{
					flag = 1;
					temp = q.front();
					q.pop();
					q.push(temp);
				}
				else
				{
					temp = q.front();
					q.pop();
					q.push(temp);
				}

			}

			if (flag == 1)
			{
				temp = q.front();
				q.pop();
				q.push(temp);
			}
			else
			{
				if (q.front().qurious)
				{
					cnt++;
					break;
				}
				else
				{
					q.pop();
					cnt++;
				}
			}
			flag = 0; //중요도 순서 확인 플래그 초기화
		}

		printf("%d\n", cnt);
		cnt = 0; //카운팅 초기화
		while (!q.empty()) //큐 비우기
			q.pop();
	}
}

/*
test case T;
문서의 수 N
몇번쨰로 인쇄되었는지 궁금한 문서의 큐에서의 위치 M
큐에 요소들에 중요도 부여 (중요도는 중복가능)
카운팅 cnt

1. 구조체 정의 print (priority, qurious)
2. for T
	M,N 입력받기
	구조체로 중요도와 궁금한 문서인지 아닌지 입력받기
	while(1)
		if(큐에 지금 pop할 큐의 top.priority보다 큰 값이 있으면)
			front해서 temp에 저장 후 push
		else //가장 중요도가 높거나, 같은 중요도에서 가장 front이면
			if(궁금했던 원소이면 curious == true 이면)
				cnt++
				break
			else //아직 궁금한 원소가 안 나왔으면
				pop
				cnt++
3. print cnt
	
*/
