/*
baekjoon 2580��: ������

�ð� ����: 1��
�޸� ����: 256 MB

������� 18���� ������ �����ڰ� ���� '��ƾ �簢��'�̶� ���񿡼� ������ ������ ���� ���� �α⸦ ������ �ִ�. �� ������ �Ʒ� �׸��� ���� ����, ���� ���� 9���� �� 81���� ���� ĭ���� �̷���� ���簢�� �� ������ �̷����µ�, ���� ���� �� �Ϻ� ĭ���� 1���� 9������ ���� �� �ϳ��� ���� �ִ�.
������ �� ĭ�� ä��� ����� ������ ����.

������ �����ٰ� �����ٿ��� 1���� 9������ ���ڰ� �� ������ ��Ÿ���� �Ѵ�.
���� ������ ���еǾ� �ִ� 3x3 ���簢�� �ȿ��� 1���� 9������ ���ڰ� �� ������ ��Ÿ���� �Ѵ�.
���� ���� ���, ù° �ٿ��� 1�� ������ ������ 2���� 9������ ���ڵ��� �̹� ��Ÿ�� �����Ƿ� ù° �� ��ĭ���� 1�� ���� �Ѵ�.
���� ���� ��� ��ġ�� 3x3 ���簢���� ��쿡�� 3�� ������ ������ ���ڵ��� �̹� ���������Ƿ� ��� �� ĭ���� 3�� ���� �Ѵ�.
�̿� ���� �� ĭ�� ���ʷ� ä�� ���� ������ ���� ���� ����� ���� �� �ִ�.
���� ���� �� ������ �ǿ� ���� �ִ� ���ڵ��� ������ �־��� �� ��� �� ĭ�� ä���� ���� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
��ȩ �ٿ� ���� �� �ٿ� 9���� ���� ���� �� �������� �� �ٿ� ���� �ִ� ���ڰ� �� ĭ�� ����� ���ʷ� �־�����. ������ ���� �� ĭ�� ��쿡�� 0�� �־�����. ������ ���� ��Ģ��� ä�� �� ���� ����� �Է��� �־����� �ʴ´�.

���
��� �� ĭ�� ä���� ������ ���� ���� ����� ��ȩ �ٿ� ���� �� �ٿ� 9���� �� ĭ�� ����� ����Ѵ�.
������ ���� ä��� ����� ������ ���� �� �� �ϳ����� ����Ѵ�. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

#define MAX 9

int arr[MAX + 1][MAX + 1];

bool promising(int n, int y, int x)
{
	for (int i = 1; i <= MAX; i++)
	{
		if (arr[i][x] == n)
			return false;
	}
	
	for (int j = 1; j <= MAX; j++)
	{
		if (arr[y][j] == n)
			return false;
	}

	int rect_f_y = 3 * ((y-1) / 3) + 1;
	int rect_f_x = 3 * ((x-1) / 3) + 1;
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (arr[rect_f_y + i][rect_f_x + j] == n)
				return false;
		}
	}
	
	return true;
}

void dfs(int y,int x)
{
	for (int i = y; i <= MAX; i++)
	{
		for (int j = 1; j <= MAX; j++)
		{
			if (arr[i][j] == 0)
			{
				for (int k = 1; k <= MAX; k++)
				{
					if (promising(k, i, j))
					{
						arr[i][j] = k;
						dfs(i,j);
						arr[i][j] = 0;
					}
				}
				return;
			}

			if (i == MAX && j == MAX)
			{
				for (int a = 1; a <= MAX; a++)
				{
					for (int b = 1; b <= MAX; b++)
					{
						if (arr[a][b] == 0)
							return;
					}
				}

				for (int a = 1; a <= MAX; a++)
				{
					for (int b = 1; b <= MAX; b++)
					{
						cout << arr[a][b] << " ";
					}
					cout << "\n";
				}
				exit(0);
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= MAX; i++)
	{
		for (int j = 1; j <= MAX; j++)
		{
			cin >> arr[i][j];
		}
	}

	dfs(1,1);
}

/*
����Ž��, ��Ʈ��ŷ

vector number_filled: ���� ���������� ä�� ���� ����

bool promising(int n,int x,int y) //arr[y][x] ��ġ�� n�� �־ ������ �����ϴ���
	//���� Ȯ��
	for 1 to 9
		if arr[i][x] == n
			return false
	//���� Ȯ��
	for 1 to 9
		if arr[y][i] == n
			return false
	//3x3 ���簢�� Ȯ��
		//�ش� ��ġ�� ���簢���� ù �ε��� ���ϱ�
	int rect_first_idx_y = 3 * ((y-1)/3) + 1
	int rect_first_idx_x = 3 * ((x-1)/3) + 1

		//���簢�� �˻�
	for 3
		for 3
			if arr[rect_first_y_idx + i][..] == n
				return false

	//�� ����ϸ�
	return true

void dfs(int x,int y) //������ ä���, x/y: ���ݱ��� ������ ��

	for i = y to 9
		for j = 1 to 9
			if arr[i][j] == 0
				for i = 1 to 9
					if(promising(k,i,j))
						arr[i][j] = k
						dfs(i,j)
						arr[i][j] = 0

				return //�ش�Ǵ� ���� ���� -> �� ���� �߸��� -> return
			if i,y == MAX
					for 1 to 9
						for 1 to 9
							if arr[i][j] == 0
								return

					//�� ä������
					for 1 to 9
						for 1 to 9
							cout arr[i][j]

					exit(0) //���α׷� ����

for 1 to 9
	for 1 to 9
		cin n
		if n == 0
			cnt++
		arr[i][j] = n

dfs(1,1)
*/
