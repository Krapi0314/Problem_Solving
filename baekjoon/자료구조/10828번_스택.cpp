/*
baekjoon 10828��: ����

�ð� ����: 0.5�� (�߰� �ð� ����)
�޸� ����: 256 MB

����
������ �����ϴ� ������ ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.
����� �� �ټ� �����̴�.

push X: ���� X�� ���ÿ� �ִ� �����̴�.
pop: ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ���ÿ� ����ִ� ������ ������ ����Ѵ�.
empty: ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
top: ������ ���� ���� �ִ� ������ ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.

�Է�
ù° �ٿ� �־����� ����� �� N (1 �� N �� 10,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����. �־����� ������ 1���� ũ�ų� ����, 100,000���� �۰ų� ����. ������ �������� ���� ����� �־����� ���� ����.

���
����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�.
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
