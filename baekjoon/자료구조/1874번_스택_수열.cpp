/*
baekjoon 1874��: ���� ����

�ð� ����: 2��
�޸� ����: 128 MB

����
���� (stack)�� �⺻���� �ڷᱸ�� �� �ϳ���, ��ǻ�� ���α׷��� �ۼ��� �� ���� �̿�Ǵ� �����̴�. ������ �ڷḦ �ִ� (push) �Ա��� �ڷḦ �̴� (pop) �Ա��� ���� ���� ���߿� �� �ڷᰡ ���� ���� ������ (LIFO, Last in First out) Ư���� ������ �ִ�.
1���� n������ ���� ���ÿ� �־��ٰ� �̾� �þ�������ν�, �ϳ��� ������ ���� �� �ִ�. �̶�, ���ÿ� push�ϴ� ������ �ݵ�� ���������� ��Ű���� �Ѵٰ� ����. ������ ������ �־����� �� ������ �̿��� �� ������ ���� �� �ִ��� ������, �ִٸ� � ������ push�� pop ������ �����ؾ� �ϴ����� �˾Ƴ� �� �ִ�. �̸� ����ϴ� ���α׷��� �ۼ��϶�.

�Է�
ù �ٿ� n (1 �� n �� 100,000)�� �־�����. ��° �ٺ��� n���� �ٿ��� ������ �̷�� 1�̻� n������ ������ �ϳ��� ������� �־�����. ���� ���� ������ �� �� ������ ���� ����.

���
�Էµ� ������ ����� ���� �ʿ��� ������ �� �ٿ� �� ���� ����Ѵ�. push������ +��, pop ������ -�� ǥ���ϵ��� �Ѵ�. �Ұ����� ��� NO�� ����Ѵ�.
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
* �ȵǴ� ���: �̾ƾ� �� �� �̹� ���ÿ� �� ������, ������ top�� �ƴϸ�
* 
* 1. n �Է�, 1~n���� ť input�� push
* 2. �Ǵ��� �ȵǴ��� �Ǵ�
*	�Ǵ� �Լ� cal
*		���� ���� flag = 1 �� �ʱ⼳��
*		���ÿ� �� �ִ� = 0���� ����
*		num ť ���� -> 1~n���� ������������ �� ����
*		
*		for ť input�� �� �􋚱��� 
*			input ť top
*			if(top�� ���� �ִ밪���� ũ��)
				top�� ����ŭ stack ���ÿ� num ť�� top�� ���� ���Ë����� push
				�̋� push�� ��ŭ +�� result ť�� ����
				�׸��� Stack�� �� ���� pop (result���� ����)
			else //top�� ���� �ִ밪���� ������ -> �̹� ���ÿ� �� ����
				if(stack ���ÿ� �� ���� ������ -> top���̸�)
					stack ���� pop �ϰ� ��� ����
				else -> ������ �� ���� �ƴ� ��򰡿� ������
					flag = 0 //���� �Ұ��� ����
					break
			
		if flag = 1
			result ť ���
		else
			NO ���
*		
*/
