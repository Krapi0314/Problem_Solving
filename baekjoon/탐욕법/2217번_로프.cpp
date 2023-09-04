/*
baekjoon 2217��: ����

�ð� ����: 2��
�޸� ����: 192 MB

����
N(1 �� N �� 100,000)���� ������ �ִ�. �� ������ �̿��Ͽ� �̷� ���� ��ü�� ���ø� �� �ִ�. ������ ������ �� ���⳪ ���̰� �ٸ��� ������ �� �� �ִ� ��ü�� �߷��� ���� �ٸ� ���� �ִ�.
������ ���� ���� ������ ���ķ� �����ϸ� ������ ������ �ɸ��� �߷��� ���� �� �ִ�. k���� ������ ����Ͽ� �߷��� w�� ��ü�� ���ø� ��, ������ �������� ��� ���� w/k ��ŭ�� �߷��� �ɸ��� �ȴ�.
�� �����鿡 ���� ������ �־����� ��, �� �������� �̿��Ͽ� ���ø� �� �ִ� ��ü�� �ִ� �߷��� ���س��� ���α׷��� �ۼ��Ͻÿ�. ��� ������ ����ؾ� �� �ʿ�� ������, ���Ƿ� �� ���� ������ ��� ����ص� �ȴ�.

�Է�
ù° �ٿ� ���� N�� �־�����. ���� N���� �ٿ��� �� ������ ��ƿ �� �ִ� �ִ� �߷��� �־�����. �� ���� 10,000�� ���� �ʴ� �ڿ����̴�.

���
ù° �ٿ� ���� ����Ѵ�. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int n;
int sum, max_weight;
int num;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end(), greater<int>());

	max_weight = v[0];

	for (int i = 1; i < n; i++)
	{
		int w_k = v[i];
		sum = w_k * (i + 1);
		
		if (sum > max_weight)
		{
			max_weight = sum;
		}
	}

	cout << max_weight;
}

/*
greedy
�ִ� �߷�(��) = ������ ���� �� �ּ� �߷��� ���� x ������ ������ ���� �̰�, �ִ� �߷��� ����� ���ؼ��� �ּ� �߷����� ū �������� ��� �����ؾ� �ϹǷ� (greedy), ������ �ִ��߷������� (greater) �����ϰ�, ������ �߰� (������ �߷��� ���� �� �۾���)�ϸ鼭 �ִ� �߷� ã��

cin n
for n
	cin num
	vector v pushback num

sort v greater

max_weight = v[0]
for v idx 1 to n-1 //��� ������ ���� ����
	//���� �߰������� �߷� ���
	 w_k = v[i]
	 sum = w_k * (i+1)
	 
	if sum > max_weight //�� �������� �߰������� �ִ� �߷��� �� Ŀ����
		max_weight = sum	

cout max_weight
*/
