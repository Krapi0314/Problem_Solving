/*
baekjoon 1003��: �Ǻ���ġ �Լ�

�ð� ����: 0.25�� (�߰� �ð� ����)
�޸� ����: 128 MB
 
����
���� �ҽ��� N��° �Ǻ���ġ ���� ���ϴ� C++ �Լ��̴�.

int fibonacci(int n) {
    if (n == 0) {
        printf("0");
        return 0;
    } else if (n == 1) {
        printf("1");
        return 1;
    } else {
        return fibonacci(n?1) + fibonacci(n?2);
    }
}

fibonacci(3)�� ȣ���ϸ� ������ ���� ���� �Ͼ��.

fibonacci(3)�� fibonacci(2)�� fibonacci(1) (ù ��° ȣ��)�� ȣ���Ѵ�.
fibonacci(2)�� fibonacci(1) (�� ��° ȣ��)�� fibonacci(0)�� ȣ���Ѵ�.
�� ��° ȣ���� fibonacci(1)�� 1�� ����ϰ� 1�� �����Ѵ�.
fibonacci(0)�� 0�� ����ϰ�, 0�� �����Ѵ�.
fibonacci(2)�� fibonacci(1)�� fibonacci(0)�� ����� ���, 1�� �����Ѵ�.
ù ��° ȣ���� fibonacci(1)�� 1�� ����ϰ�, 1�� �����Ѵ�.
fibonacci(3)�� fibonacci(2)�� fibonacci(1)�� ����� ���, 2�� �����Ѵ�.
1�� 2�� ��µǰ�, 0�� 1�� ��µȴ�. N�� �־����� ��, fibonacci(N)�� ȣ������ ��, 0�� 1�� ���� �� �� ��µǴ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����.
�� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ְ�, N�� �־�����. N�� 40���� �۰ų� ���� �ڿ��� �Ǵ� 0�̴�.

���
�� �׽�Ʈ ���̽����� 0�� ��µǴ� Ƚ���� 1�� ��µǴ� Ƚ���� �������� �����ؼ� ����Ѵ�.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, T;
//0�� ȣ�� Ƚ���� ������ cache (�迭)
int zero_cache[41];

int fibo_cnt_zero(int n) //n���� �Ǻ���ġ ���� ȣ���ϸ鼭 ȣ��� 0�� Ƚ�� ���ϱ�
{
	if (n == 0)
		return 1;
	else if (n == 1)
		return 0;

	int& ret = zero_cache[n];
	if (zero_cache[n] != -1) //cache�� ���� ����Ǿ� ������ �ߺ� ������� �ʰ� ����Ǿ� �ִ� �� ���
		return ret;

	return ret = fibo_cnt_zero(n - 1) + fibo_cnt_zero(n - 2);
}

int one_cache[41];

int fibo_cnt_one(int n) //n���� �Ǻ���ġ ���� ȣ���ϸ鼭 ȣ��� 0�� Ƚ�� ���ϱ�
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;

	int& ret = one_cache[n];
	if (one_cache[n] != -1) //cache�� ���� ����Ǿ� ������ �ߺ� ������� �ʰ� ����Ǿ� �ִ� �� ���
		return ret;

	return ret = fibo_cnt_one(n - 1) + fibo_cnt_one(n - 2);
}

int main(void)
{
	memset(zero_cache, -1, sizeof(zero_cache));
	memset(one_cache, -1, sizeof(one_cache));

	scanf("%d", &T);
	
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &n);

		printf("%d %d\n", fibo_cnt_zero(n), fibo_cnt_one(n));
	}
	
}

/*
* ���� ��ȹ�� DP+
* 1. �Է�
* 2. ��� �Լ��� �ĺ���ġ���� 1�� 0�� ȣ��Ǵ� Ƚ�� ��� (ȣ��Ƚ���� �Ǻ���ġ�� ���� ������� ����)
* 3. �޸������̼����� �ߺ��Ǵ� �κ� ���� �ߺ� ������� �ʱ� (�ӵ� �⼧)
* 4. ���
*
* 
* 
* */
