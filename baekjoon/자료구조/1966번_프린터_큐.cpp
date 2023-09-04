/*

baekjoon 1966��: ������ ť

�ð� ����: 2��
�޸� ����: 128 MB

����
�����е� �˴ٽ��� �������� ������ ���� �������� �μ��ϰ��� �ϴ� ������ �μ� ����� ���� ��������Ρ�, �� ���� ��û�� ���� ���� �μ��Ѵ�. ���� ���� ������ ���δٸ� Queue �ڷᱸ���� �׿��� FIFO - First In First Out - �� ���� �μⰡ �ǰ� �ȴ�. ������ ����̴� ���ο� �����ͱ� ���� ����Ʈ��� �����Ͽ��µ�, �� �����ͱ�� ������ ���� ���ǿ� ���� �μ⸦ �ϰ� �ȴ�.

���� Queue�� ���� �տ� �ִ� ������ ���߿䵵���� Ȯ���Ѵ�.
������ ������ �� ���� �������� �߿䵵�� ���� ������ �ϳ��� �ִٸ�, �� ������ �μ����� �ʰ� Queue�� ���� �ڿ� ���ġ �Ѵ�. �׷��� �ʴٸ� �ٷ� �μ⸦ �Ѵ�.
���� ��� Queue�� 4���� ����(A B C D)�� �ְ�, �߿䵵�� 2 1 4 3 ��� C�� �μ��ϰ�, �������� D�� �μ��ϰ� A, B�� �μ��ϰ� �ȴ�.

�������� �� ����, ���� Queue�� �ִ� ������ ���� �߿䵵�� �־����� ��, � �� ������ �� ��°�� �μ�Ǵ��� �˾Ƴ��� ���̴�. ���� ��� ���� ������ C������ 1��°��, A������ 3��°�� �μ�ǰ� �ȴ�.

�Է�
ù �ٿ� �׽�Ʈ���̽��� ���� �־�����. �� �׽�Ʈ���̽��� �� �ٷ� �̷���� �ִ�.

�׽�Ʈ���̽��� ù ��° �ٿ��� ������ ���� N(1 �� N �� 100)��, �� ��°�� �μ�Ǿ����� �ñ��� ������ ���� Queue���� �� ��°�� ���� �ִ����� ��Ÿ���� ���� M(0 �� M < N)�� �־�����. �̶� �� ������ 0��°��� ����. �� ��° �ٿ��� N�� ������ �߿䵵�� ���ʴ�� �־�����. �߿䵵�� 1 �̻� 9 ������ �����̰�, �߿䵵�� ���� ������ ���� �� ���� ���� �ִ�.

���
�� �׽�Ʈ ���̽��� ���� ������ �� ��°�� �μ�Ǵ��� ����Ѵ�

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
			int flag = 0; //�߿䵵�� �� ���� ���� ������ 1
			int priority_to_check = q.front().priority;
			for (int i = 0; i < q.size(); i++) //�ѹ��� ���鼭 �߿䵵 �˻�
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
			flag = 0; //�߿䵵 ���� Ȯ�� �÷��� �ʱ�ȭ
		}

		printf("%d\n", cnt);
		cnt = 0; //ī���� �ʱ�ȭ
		while (!q.empty()) //ť ����
			q.pop();
	}
}

/*
test case T;
������ �� N
������� �μ�Ǿ����� �ñ��� ������ ť������ ��ġ M
ť�� ��ҵ鿡 �߿䵵 �ο� (�߿䵵�� �ߺ�����)
ī���� cnt

1. ����ü ���� print (priority, qurious)
2. for T
	M,N �Է¹ޱ�
	����ü�� �߿䵵�� �ñ��� �������� �ƴ��� �Է¹ޱ�
	while(1)
		if(ť�� ���� pop�� ť�� top.priority���� ū ���� ������)
			front�ؼ� temp�� ���� �� push
		else //���� �߿䵵�� ���ų�, ���� �߿䵵���� ���� front�̸�
			if(�ñ��ߴ� �����̸� curious == true �̸�)
				cnt++
				break
			else //���� �ñ��� ���Ұ� �� ��������
				pop
				cnt++
3. print cnt
	
*/
