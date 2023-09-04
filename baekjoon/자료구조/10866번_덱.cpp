/*

baekjoon 10866��: ��

�ð� ����: 0.5�� (�߰� �ð� ����)
�޸� ����: 256 MB

����
������ �����ϴ� ��(Deque)�� ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

����� �� ���� �����̴�.
push_front X: ���� X�� ���� �տ� �ִ´�.
push_back X: ���� X�� ���� �ڿ� �ִ´�.
pop_front: ���� ���� �տ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
pop_back: ���� ���� �ڿ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
size: ���� ����ִ� ������ ������ ����Ѵ�.
empty: ���� ��������� 1��, �ƴϸ� 0�� ����Ѵ�.
front: ���� ���� �տ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
back: ���� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.

�Է�
ù° �ٿ� �־����� ����� �� N (1 �� N �� 10,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����. �־����� ������ 1���� ũ�ų� ����, 100,000���� �۰ų� ����. ������ �������� ���� ����� �־����� ���� ����.

���
����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <list>
#include <cstring>

using namespace std;

char command[11];
int input_num;
int n;

list<int> List;

void push_front(int num)
{
	List.push_front(num);
}

void push_back(int num)
{
	List.push_back(num);
}

void pop_front()
{
	if (List.empty())
		printf("-1\n");
	else
	{
		printf("%d\n", List.front());
		List.pop_front();
	}
}

void pop_back()
{
	if (List.empty())
		printf("-1\n");
	else
	{
		printf("%d\n", List.back());
		List.pop_back();
	}
}

void size()
{
	printf("%d\n", List.size());
}

void empty()
{
	if (List.empty())
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

		if (!strncmp(command, "push_front", 10))
		{
			scanf("%d", &input_num);
			push_front(input_num);
		}
		else if (!strncmp(command, "push_back", 9))
		{
			scanf("%d", &input_num);
			push_back(input_num);
		}
		else if (!strncmp(command, "pop_front", 9))
		{
			pop_front();
		}
		else if (!strncmp(command, "pop_back", 9))
		{
			pop_back();
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
