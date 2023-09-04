/*
baekjoon 10845��: ť
�ð� ����: 0.5�� (�߰� �ð� ����0
�޸� ����: 256 MB

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
ù° �ٿ� �־����� ����� �� N (1 �� N �� 10,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����. �־����� ������ 1���� ũ�ų� ����, 100,000���� �۰ų� ����. ������ �������� ���� ����� �־����� ���� ����.

���
����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�.
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

queue<int> q;
char command[10];
int n;
int input_num;

void qpush(int num)
{
	q.push(num);
}

void qfront()
{
	if (!q.empty())
	{
		cout << q.front() << "\n";
	}
	else
	{
		cout << "-1\n";
	}
}

void qpop()
{
	if (!q.empty())
	{
		cout << q.front() << "\n";
		q.pop();
	}
	else
	{
		cout << "-1\n";
	}
}

void qsize()
{
	cout << q.size() << "\n";
}

void qback()
{
	if (!q.empty())
	{
		cout << q.back() << "\n";
	}
	else
	{
		cout << "-1\n";
	}
}

void qempty()
{
	if (!q.empty())
	{
		cout << "0\n";
	}
	else
	{
		cout << "1\n";
	}
}

int main(void)
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		scanf("%s", command);

		if(!strncmp(command,"push",4))
		{
			scanf("%d", &input_num);
			qpush(input_num);
		}
		else if (!strncmp(command, "pop",3))
		{
			qpop();
		}
		else if (!strncmp(command, "size",4))
		{
			qsize();
		}
		else if (!strncmp(command, "empty",5))
		{
			qempty();
		}
		else if (!strncmp(command, "front",5))
		{
			qfront();
		}
		else
		{
			qback();
		}
	}
}

/*

*/
