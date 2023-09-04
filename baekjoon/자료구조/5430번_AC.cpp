/*
baekjoon 5430��: AC

�ð� ����: 1��
�޸� ����: 256 MB

����
�����̴� �ָ��� �� ���� ��� ���ο� ��� AC�� �������. AC�� ���� �迭�� ������ �ϱ� ���� ���� ����̴�. �� ���� �� ���� �Լ� R(������)�� D(������)�� �ִ�.
�Լ� R�� �迭�� �ִ� ������ ������ ������ �Լ��̰�, D�� ù ��° ���ڸ� ������ �Լ��̴�. �迭�� ����ִµ� D�� ����� ��쿡�� ������ �߻��Ѵ�.
�Լ��� �����ؼ� �� ���� ����� �� �ִ�. ���� ���, "AB"�� A�� ������ ������ �ٷ� �̾ B�� �����ϴ� �Լ��̴�. ���� ���, "RDD"�� �迭�� ������ ���� ó�� �� ���ڸ� ������ �Լ��̴�.
�迭�� �ʱⰪ�� ������ �Լ��� �־����� ��, ���� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����. T�� �ִ� 100�̴�.
�� �׽�Ʈ ���̽��� ù° �ٿ��� ������ �Լ� p�� �־�����. p�� ���̴� 1���� ũ�ų� ����, 100,000���� �۰ų� ����.
���� �ٿ��� �迭�� ����ִ� ���� ���� n�� �־�����. (0 �� n �� 100,000)
���� �ٿ��� [x1,...,xn]�� ���� ���·� �迭�� ����ִ� ���� �־�����. (1 �� xi �� 100)
��ü �׽�Ʈ ���̽��� �־����� p�� ������ �հ� n�� ���� 70���� ���� �ʴ´�.

���
�� �׽�Ʈ ���̽��� ���ؼ�, �Է����� �־��� ���� �迭�� �Լ��� ������ ����� ����Ѵ�. ����, ������ �߻��� ��쿡�� error�� ����Ѵ�.
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
		if (flag == 0) //������
			num.pop_front();
		else //������
			num.pop_back();
	}
}

void R()
{
	//flag�� ������ ư��
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
			getchar(); //[ �Ա�
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

		//p,num�� �ʱ�ȭ��
		error = 0;
		flag = 0;
	}
}

/*
 �׽�Ʈ ���̽� t, �Լ� p -> char�� queue, �迭 ũ�� n�� ���ִ� �� -> int�� deque (��,������ ���� ���)
 1. t,p,n, �迭 �Է¹ޱ�
.2. p ť�� �����������
	if �Լ� D
		if ���� �迭�� ���������
			���� ó��
			break
		else
			�Լ� D ����
	else
		�Լ� R ����
			�Լ� R�� ���� �迭�� ���ڸ� ������ �ʰ�, flag�� ���� ��-���Լ���, ��-���Լ����� �������� D���� ó���� �� �ְ� flag ����
				flag = 0�̸� ������: D �Լ����� pop_front ���
				flag = 1�̸� ������: D �Լ����� pop_back ���

3. ���� �迭 ���
*/
