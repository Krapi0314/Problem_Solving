/*
baekjoon 6603��: �ζ�

�ð� ����: 1��
�޸� ����: 128MB
 
����
���� �ζǴ� {1, 2, ..., 49}���� �� 6���� ����.
�ζ� ��ȣ�� �����ϴµ� ���Ǵ� ���� ������ ������ 49���� �� �� k(k>6)���� ���� ��� ���� S�� ���� ���� �� ���� ������ ��ȣ�� �����ϴ� ���̴�.
���� ���, k=8, S={1,2,3,5,8,13,21,34}�� ��� �� ���� S���� ���� �� �� �ִ� ����� ���� �� 28�����̴�. ([1,2,3,5,8,13], [1,2,3,5,8,21], [1,2,3,5,8,34], [1,2,3,5,13,21], ..., [3,5,8,13,21,34])
���� S�� k�� �־����� ��, ���� ���� ��� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�Է��� ���� ���� �׽�Ʈ ���̽��� �̷���� �ִ�. �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ִ�. ù ��° ���� k (6 < k < 13)�̰�, ���� k�� ���� ���� S�� ���ԵǴ� ���̴�. S�� ���Ҵ� ������������ �־�����.
�Է��� ������ �ٿ��� 0�� �ϳ� �־�����. 

���
�� �׽�Ʈ ���̽����� ���� ���� ��� ����� ����Ѵ�. �̶�, ���� ������ ����Ѵ�.
�� �׽�Ʈ ���̽� ���̿��� �� ���� �ϳ� ����Ѵ�.
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int k;
deque<int> dq;
vector<int> v;
int num;

void lotto(int n)
{
	if (n == 7)
	{
		for (int i = 0; i < 6; i++)
		{
			cout << dq[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < k; i++)
	{
		if (dq.empty() || v[i] > dq[n-2]) //promising �˻� (v ���Ұ� dq�� ���������� ����� ���Һ��� Ŭ�� = ������ �����Ҷ�)
		{
			dq.push_back(v[i]);
			lotto(++n);
			dq.pop_back();
			n--;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1)
	{
		v.clear();
		dq.clear();

		cin >> k;
		
		if (k == 0)
			return 0;

		for (int i = 0; i < k; i++)
		{
			cin >> num;
			v.push_back(num);
		}

		lotto(1);
		cout << "\n";
	}

}

/*
���� S�� k�� �־����� ��, ���� ���� ��� ����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
����Ž��, ��Ʈ��ŷ

void lotto(int n)
	if(n == 6)
		for 6
			cout possible deque
	
	for k
		if i >= n-1
			possible pushback arr[i]
			lotto(n+1)
			possible popback arr[i]
	

while 1
	cin k

	if(k == 0)
		return 0;

	for k
		cin arr

	lotto(int n) //��� ��� ���, n���� ������ �� �� ����
	cout << "\n"
	

*/
