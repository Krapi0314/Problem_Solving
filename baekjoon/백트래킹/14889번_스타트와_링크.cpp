/*
baekjoon 14889��: ��ŸƮ�� ��ũ

�ð� ����: 2��
�޸� ����: 512MB

����
������ ��ŸƮ��ũ�� �ٴϴ� ������� �𿩼� �౸�� �غ����� �Ѵ�. �౸�� ���� ���Ŀ� �ϰ� �ǹ� ������ �ƴϴ�. �౸�� �ϱ� ���� ���� ����� �� N���̰� �ű��ϰԵ� N�� ¦���̴�. ���� N/2������ �̷���� ��ŸƮ ���� ��ũ ������ ������� ������ �Ѵ�.
baekjoon�� ��ϴ� ȸ�� ��� ������� ��ȣ�� 1���� N������ �����߰�, �Ʒ��� ���� �ɷ�ġ�� �����ߴ�. �ɷ�ġ Sij�� i�� ����� j�� ����� ���� ���� ������ ��, ���� �������� �ɷ�ġ�̴�. ���� �ɷ�ġ�� ���� ���� ��� ���� �ɷ�ġ Sij�� ���̴�. Sij�� Sji�� �ٸ� ���� ������, i�� ����� j�� ����� ���� ���� ������ ��, ���� �������� �ɷ�ġ�� Sij�� Sji�̴�.
N=4�̰�, S�� �Ʒ��� ���� ��츦 ���캸��.

i\j	1	2	3	4
1	 	1	2	3
2	4	 	5	6
3	7	1	 	2
4	3	4	5	 
���� ���, 1, 2���� ��ŸƮ ��, 3, 4���� ��ũ ���� ���� ��쿡 �� ���� �ɷ�ġ�� �Ʒ��� ����.

��ŸƮ ��: S12 + S21 = 1 + 4 = 5
��ũ ��: S34 + S43 = 2 + 5 = 7
1, 3���� ��ŸƮ ��, 2, 4���� ��ũ ���� ���ϸ�, �� ���� �ɷ�ġ�� �Ʒ��� ����.

��ŸƮ ��: S13 + S31 = 2 + 7 = 9
��ũ ��: S24 + S42 = 6 + 4 = 10
�౸�� ����ְ� �ϱ� ���ؼ� ��ŸƮ ���� �ɷ�ġ�� ��ũ ���� �ɷ�ġ�� ���̸� �ּҷ� �Ϸ��� �Ѵ�. ���� ������ ���� ��쿡�� 1, 4���� ��ŸƮ ��, 2, 3�� ���� ��ũ ���� ���ϸ� ��ŸƮ ���� �ɷ�ġ�� 6, ��ũ ���� �ɷ�ġ�� 6�� �Ǿ ���̰� 0�� �ǰ� �� ���� �ּ��̴�.

�Է�
ù° �ٿ� N(4 �� N �� 20, N�� ¦��)�� �־�����. ��° �ٺ��� N���� �ٿ� S�� �־�����. �� ���� N���� ���� �̷���� �ְ�, i�� ���� j��° ���� Sij �̴�. Sii�� �׻� 0�̰�, ������ Sij�� 1���� ũ�ų� ����, 100���� �۰ų� ���� �����̴�.

���
ù° �ٿ� ��ŸƮ ���� ��ũ ���� �ɷ�ġ�� ������ �ּڰ��� ����Ѵ�. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

vector<int> a;
vector<int> b;
int Min = 123456789;
int n;
int arr[21][21];
bool flag;
int a_sum, b_sum;

void team(int cnt)
{
	if (cnt == n / 2)
	{
		a_sum = 0; b_sum = 0;
		b.clear();

		for (int i = 1; i <= n; i++)
		{
			flag = true;
			for (int j = 0; j < n / 2; j++)
			{
				if (i == a[j])
				{
					flag = false;
					break;
				}
			}

			if (flag)
				b.push_back(i);
		}

		for (int i = 0; i < n / 2; i++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				a_sum += arr[a[i]][a[j]];
			}
		}

		for (int i = 0; i < n / 2; i++)
		{
			for (int j = 0; j < n / 2; j++)
			{
				b_sum += arr[b[i]][b[j]];
			}
		}

		Min = min(Min, abs(a_sum - b_sum));
	}

	for (int i = 1; i <= n; i++)
	{
		if (a.empty() || i > a[cnt - 1])
		{
			a.push_back(i);
			team(++cnt);
			a.pop_back();
			cnt--;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];
		}
	}

	team(0);

	cout << Min;
}

/*
ù° �ٿ� ��ŸƮ ���� ��ũ ���� �ɷ�ġ�� ������ �ּڰ��� ����Ѵ�.
����Ž�� -> ������ ��� �� ������ �ɷ�ġ ����, ��Ʈ��ŷ

��Ʈ��ŷ (����ġ��)�� ���� ���� ����� �ð����⵵: 20P10 = 6e11 
��Ʈ��ŷ (����ġ��, vector a�� ������ ���� ����  ���� ���Һ��� ����ϱ�)�� �� ����� �ð����⵵: 20C10 = 2e5

void team(int i): A�� �ٸ���, i�� ���ݱ��� ���� ���� ��
	if i == n/2
		vector b clear

		for n
			if i not in vector a
				b pushback i
		
		for vector a
			for vector a
				sum += arr[i,j]

		for vector b 
			for vector b
				sum += arr[i,j]

		Min = min(Min,abs(a_sum-b_sum))

	for n
		if i > vector a�� ������ ����
			a pushback i
			team(++i)
			a popback i
			i--

cin n
for n
	for n
		cin arr[i+1,j+1]

team(0)

cout Min
*/
