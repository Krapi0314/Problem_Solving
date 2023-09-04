/*
baekjoon 9663��: N-Queen

�ð� ����: 10��
�޸� ����: 128 MB

����
N-Queen ������ ũ�Ⱑ N �� N�� ü���� ���� �� N���� ���� ������ �� ���� ���� �����̴�.
N�� �־����� ��, ���� ���� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� �־�����. (1 �� N < 15)

���
ù° �ٿ� �� N���� ���� ������ �� ���� ���� ����� ���� ����Ѵ�. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int n, cnt;
int col[15]; //���� ��ġ(���� ����), ���� �� ���� �ϳ� �ۿ� �������� ���ϹǷ� ���� ��ǥ�� ������ ���� ���� ����

bool promising(int i) //bounding function (���� �Լ�)
{
	for (int j = 0; j < i; j++) //���� ������ ��ġ�� ����
	{
		if (col[j] == col[i] || abs(col[i] - col[j]) == (i - j)) //���ο� ���� ��ġ�� ���� ���̰ų� �밢���� ������
			return false; //�� ���� �Ұ�
	}
	return true; //�� ���� ����
}

void queens(int i)
{
	if (i == n) //�׸��� ������ ������ ������ (���� ���)
	{
		cnt++; //�ϳ��� ����� �� �ϼ���
	}
	else //�̿ܿ���
	{
		for (int j = 0; j < n; j++) //�� ���� ����
		{
			col[i] = j; //���� ���� ���� ��ġ ���� (�� �ϴ� ����)
			if(promising(i)) //������ �˻�
				queens(i + 1); //����Լ� ȣ��
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	queens(0);

	cout << cnt;
}

/*
��Ʈ��ŷ

���� �ϳ� ����,

queens()
����: ���� �� ��������
	cnt++;
���� ���� �� ������ (promising())
	queens()�� ���� ���� ���´�

! ���� �� ���� �ϳ� �ۿ� ���� ���ϹǷ�, �� ������ ���
*/
