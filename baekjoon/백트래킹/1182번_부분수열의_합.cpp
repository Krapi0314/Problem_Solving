/*
baekjoon 1182��: �κм����� ��

�ð� ����: 2��
�޸� ����: 256 MB

����
N���� ������ �̷���� ������ ���� ��, ũ�Ⱑ ����� �κм��� �߿��� �� ������ ���Ҹ� �� ���� ���� S�� �Ǵ� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ������ ��Ÿ���� N�� ���� S�� �־�����. (1 �� N �� 20, |S| �� 1,000,000) ��° �ٿ� N���� ������ �� ĭ�� ���̿� �ΰ� �־�����. �־����� ������ ������ 100,000�� ���� �ʴ´�.

���
ù° �ٿ� ���� S�� �Ǵ� �κм����� ������ ����Ѵ�.
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

deque<int> combi;
vector<int> v;
int num;
int n,s;
int cnt;

void combination(int n,int v_idx)
{
	if (n == 0)
	{
		int sum = 0;
		for (int i = 0; i < combi.size(); i++)
		{
			sum += combi[i];
		}

		if (sum == s) //������ ���Ҹ� �� ���� ���� S�� �Ǹ�
			cnt++; //����� ��++

		return;
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (combi.empty() || i > v_idx)
		{
			combi.push_back(v[i]);
			combination(--n,i);
			combi.pop_back();
			n++;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	for (int i = 1; i <= n; i++)
	{
		combination(i,0);
	}

	cout << cnt;
}

/*
�� ������ ���Ҹ� �� ���� ���� S�� �Ǵ� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
����Ž��, ��Ʈ��ŷ

deque combi[] //���� ���� ���� �迭

void combination(int n) //�������� n���� �̾� �������� 0���� Ȯ��
	if(n == 0)
		int sum
		for combi size
			sum += combi
		
		if(sum == 0)
			cnt++
		return
	
	for vector
		combi pushback v[i]
		combination(--n)
		combi popback v[i]
		n++
		


cin n s
for n
	cin num
	vector pushback num

for n
	combination(i)

cout << cnt
*/
