/*
baekjoon 1978��: �Ҽ� ã��

�ð� ����: 2��
�޸� ����: 128 MB

 ����
�־��� �� N�� �߿��� �Ҽ��� �� ������ ã�Ƽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù �ٿ� ���� ���� N�� �־�����. N�� 100�����̴�. �������� N���� ���� �־����µ� ���� 1,000 ������ �ڿ����̴�.

���
�־��� ���� �� �Ҽ��� ������ ����Ѵ�.
*/

#include <iostream>

using namespace std;

int cnt = 0;

int main(void)
{
	int n;
	int arr[100];
	int num[1001] = { 0, 1 }; //0�� �Ҽ�, 1�� �Ҽ��� �ƴ� ��
	int cnt = 0;

	//ü, 1000 sqrt�� 31������ ���� ����� ����
	for (int i = 2; i <= 31; i++)
	{
		for (int j = 2; j * i <= 1000; j++)
		{
			num[j * i] = 1;
		}
	}

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (num[arr[i]] == 0)
			cnt++;
	}

	cout << cnt;
}

/*
�Ҽ� ���ϱ�: �����佺�׳׽��� ü Ȱ��
	n ������ �Ҽ��� ��� ã���� �� �� 
		for(int i =2; i<= sqrt(n); i++) 
			for(int j=2; j*i <= n; j++)
				not_prime[j*i] = true
				
		for(int i=0; i<n; i++)
			if(!not_prime[i])
				i�� �Ҽ�(prime)�� 
/*
