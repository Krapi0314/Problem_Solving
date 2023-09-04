/*
baekjoon 2529��: �ε�ȣ

�ð� ����: 1��
�޸� ����: 256 MB

����
�� ������ �ε�ȣ ��ȣ ��<���� ��>���� k�� ������ ������  A�� �ִ�. �츮�� �� �ε�ȣ ��ȣ �յڿ� ���� �ٸ� �� �ڸ��� ���ڸ� �־ ��� �ε�ȣ ���踦 ������Ű���� �Ѵ�. ���� ���, ���õ� �ε�ȣ ������ A�� ������ ���ٰ� ����. 
A =>  < < < > < < > < >
�ε�ȣ ��ȣ �յڿ� ���� �� �ִ� ���ڴ� 0���� 9������ �����̸� ���õ� ���ڴ� ��� �޶�� �Ѵ�. �Ʒ��� �ε�ȣ ������ A�� ������Ű�� �� ���̴�. 
3 < 4 < 5 < 6 > 1 < 2 < 8 > 7 < 9 > 0
�� ��Ȳ���� �ε�ȣ ��ȣ�� ������ ��, ���ڸ� ��� ���̸� �ϳ��� ���� ���� �� �ִµ� �� ���� �־��� �ε�ȣ ���踦 ������Ű�� ������� �Ѵ�. �׷��� �־��� �ε�ȣ ���踦 �����ϴ� ������ �ϳ� �̻� �����Ѵ�. ���� ��� 3456128790 �Ӹ� �ƴ϶� 5689023174�� �Ʒ��� ���� �ε�ȣ ���� A�� ������Ų��. 
5 < 6 < 8 < 9 > 0 < 2 < 3 > 1 < 7 > 4
�������� ���õ� k���� �ε�ȣ ������ �����ϴ� (k+1)�ڸ��� ���� �߿��� �ִ񰪰� �ּڰ��� ã�ƾ� �Ѵ�. �ռ� ������ ��� �� �ε�ȣ�� �յڿ� ���� ���ڴ� { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }�߿��� �����ؾ� �ϸ� ���õ� ���ڴ� ��� �޶�� �Ѵ�. 

�Է�
ù �ٿ� �ε�ȣ ������ ������ ��Ÿ���� ���� k�� �־�����. �� ���� �ٿ��� k���� �ε�ȣ ��ȣ�� �ϳ��� ������ �ΰ� �� �ٿ� ��� ���õȴ�. k�� ������ 2 �� k �� 9 �̴�. 

���
�������� ���õ� �ε�ȣ ���踦 �����ϴ� k+1 �ڸ��� �ִ�, �ּ� ������ ù° �ٰ� ��° �ٿ� ���� ����ؾ� �Ѵ�. �� �Ʒ� ��(1)�� ���� ù �ڸ��� 0�� ��쵵 ������ ���ԵǾ�� �Ѵ�. ��� �Է¿� ���� �׻� �����ϸ� ��� ������ �ϳ��� ���ڿ��� �ǵ��� �ؾ� �Ѵ�. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int k;
char c;
vector<char> oper;
vector<int> Max;
vector<int> Min;

bool valid(vector<int> &arr)
{
	for (int i = 0; i < k; i++)
	{
		if (oper[i] == '<' && arr[i] > arr[i + 1])
			return false;
		else if (oper[i] == '>' && arr[i] < arr[i + 1])
			return false;
	}

	return true;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> c;
		oper.push_back(c);
	}

	//�ִ�
	for (int i = 9; i > 9 - (k + 1); i--)
	{
		Max.push_back(i);
	}
	while (true)
	{
		if (valid(Max))
			break;
		else
			prev_permutation(Max.begin(), Max.end());
	}

	//�ּ�
	for (int i = 0; i < (k + 1); i++)
	{
		Min.push_back(i);
	}
	while (true)
	{
		if (valid(Min))
			break;
		else
			next_permutation(Min.begin(), Min.end());
	}

	for (int i = 0; i < k + 1; i++)
	{
		cout << Max[i];
	}
	cout << "\n";
	for (int i = 0; i < k + 1; i++)
	{
		cout << Min[i];
	}
}

/*
greedy, next_permutation
�ε�ȣ ������ �����ϴ� �ִ�/�ּڰ��� greedy�ϰ� ���� ���, �ִ��� ��� 9 ~ 9~9-(k+1)�� �����, �ּڰ��� ��� 0 ~ k+1�� ����� �̷���� ����

cin k
for k
	cin char c
	vector oper pushback c

//�ִ�
for 9 to 9-(k+1)
	vector m pushback i

while true
	if vaild() //�ش� ������ �ε�ȣ�� ���谡 �����ϸ�
		break
	else
		prev_permutation //���� ������ ('����'�� �۾���)

//�ּڰ�
...
	next_permutation //���� ������ ('����'�� Ŀ��)

bool valid()
	for k
		if oper[i] == '>' && m[i] < m[i+1]
			return false
		else if oper[i] == '<' && m[i] > m[i+1]
			return false

	return true
*/
