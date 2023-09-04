/*
baekjoon 18258��: ť 2

�ð� ����: 1��
�޸� ����: 512 MB

����
������ �����ϴ� ť�� ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.
����� �� ���� �����̴�.

push X: ���� X�� ť�� �ִ� �����̴�.
pop: ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ť�� ����ִ� ������ ������ ����Ѵ�.
empty: ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
front: ť�� ���� �տ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ť�� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.

�Է�
ù° �ٿ� �־����� ����� �� N (1 �� N �� 2,000,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����. �־����� ������ 1���� ũ�ų� ����, 100,000���� �۰ų� ����. ������ �������� ���� ����� �־����� ���� ����.

���
����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�. 
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <list>
#include <cstring>

using namespace std;

char command[6];
int input_num;
int n;

list<int> List;

void push(int num)
{
	List.push_back(num);
}

void pop()
{
	if (List.size() == 0)
		printf("-1\n");
	else
	{
		printf("%d\n", List.front());
		List.pop_front();
	}
}

void size()
{
	printf("%d\n", List.size());
}

void empty()
{
	if (List.size() == 0)
	{
		printf("1\n");
	}
	else
	{
		printf("0\n");
	}
}

void front()
{
	if (!List.empty())
	{
		printf("%d\n",List.front());
	}
	else
	{
		printf("-1\n");
	}
}

void back()
{
	if (!List.empty())
	{
		printf("%d\n", List.back());
	}
	else
	{
		printf("-1\n");
	}
}

int main(void)
{
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		scanf("%s", command);

		if (!strncmp(command, "push", 4))
		{
			scanf("%d", &input_num);
			push(input_num);
		}
		else if (!strncmp(command, "pop", 3))
		{
			pop();
		}
		else if (!strncmp(command, "size", 4))
		{
			size();
		}
		else if (!strncmp(command, "empty", 5))
		{
			empty();
		}
		else if(!strncmp(command, "front", 5))
		{
			front();
		}
		else
		{
			back();
		}
	}

}

/*

*/
