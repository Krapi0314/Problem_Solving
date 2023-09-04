/*
baekjoon 1655��: ����� ���ؿ�

�ð� ����: 0.1��
�޸� ����: 128 MB

����
�����̴� �������� "����� ���ؿ�" ������ �������ְ� �ִ�. �����̰� ������ �ϳ��� ��ĥ������ ������ ���ݱ��� �����̰� ���� �� �߿��� �߰����� ���ؾ� �Ѵ�. ����, �׵��� �����̰� ��ģ ���� ������ ¦������� �߰��� �ִ� �� �� �߿��� ���� ���� ���ؾ� �Ѵ�.
���� ��� �����̰� �������� 1, 5, 2, 10, -99, 7, 5�� ������� ���ƴٰ� �ϸ�, ������ 1, 1, 2, 2, 2, 2, 5�� ���ʴ�� ���ؾ� �Ѵ�. �����̰� ��ġ�� ���� �־����� ��, ������ ���ؾ� �ϴ� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ��� �����̰� ��ġ�� ������ ���� N�� �־�����. N�� 1���� ũ�ų� ����, 100,000���� �۰ų� ���� �ڿ����̴�. �� ���� N�ٿ� ���ļ� �����̰� ��ġ�� ������ ���ʴ�� �־�����. ������ -10,000���� ũ�ų� ����, 10,000���� �۰ų� ����.

���
�� �ٿ� �ϳ��� N�ٿ� ���� �������� ������ ���ؾ��ϴ� ���� ������� ����Ѵ�. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <functional>
#include <cmath>

//#include <cstdio>

using namespace std;

int n;
int input;
priority_queue<int, vector<int>, less<int>> max_heap;
priority_queue<int, vector<int>, greater<int>> min_heap;

void cal()
{
	if (max_heap.size() == min_heap.size())
	{
		max_heap.push(input);
	}
	else //max_heap�� �ϳ� �� ������ ��
	{
		min_heap.push(input);
	}
	
	if (!max_heap.empty() && !min_heap.empty() && max_heap.top() > min_heap.top())
	{
		int a = max_heap.top(), b = min_heap.top();
		max_heap.pop(); min_heap.pop();
		max_heap.push(b);
		min_heap.push(a);
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		cal();
		cout << max_heap.top() << "\n";
	}
}

/*
(������) ������ �ѷ� ������, ���� �� ������ max_heap�� less�� ����, ū �� ������ min_heap�� greater�� �����ϰ�, ������ �� ��Ģ�� �����ϸ�,
	1. max_heap�� min_heap ���� ���Ұ� �ϳ� ���ų� ����
	2. max_heap�� �ִ���Ҵ� min_heap�� �ּ� ���Һ��� ���� (max_heap�� ������ ������, min_heap�� ū �� ������ �����Ƿ�)

	=> max_heap�� ��Ʈ ���� �߰����� �ȴ�

	�̸� �Ӽ��� �����ϱ� ���� ���Ұ� �ϳ� ���Ë�����
		1�� ��Ģ ���� ��
		2�� ��Ģ ���� (���Ұ� max_heap���� ���µ� min_heap�� ���Һ��� ũ�� ���� ��ȯ, ���Ұ� �ϳ� ���Ë����� �����ϹǷ� �׻� max ���� ũ�� < min ���� ũ�� ������)

1. ������ ���� n �Է�
2. ���� �Էµɋ����� ������ ��� �߰����� ����ϴ� �Լ� cal ȣ��
*/
