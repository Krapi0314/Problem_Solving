/*
baekjoon 1920��: �� ã��

�ð� ����: 2��
�޸� ����: 128 MB
 
���� 
N���� ���� A[1], A[2], ��, A[N]�� �־��� ���� ��, �� �ȿ� X��� ������ �����ϴ��� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �ڿ��� N(1��N��100,000)�� �־�����. ���� �ٿ��� N���� ���� A[1], A[2], ��, A[N]�� �־�����. ���� �ٿ��� M(1��M��100,000)�� �־�����. ���� �ٿ��� M���� ������ �־����µ�, �� ������ A�ȿ� �����ϴ��� �˾Ƴ��� �ȴ�. ��� ������ ������ -231 ���� ũ�ų� ���� 231���� �۴�.

���
M���� �ٿ� ���� ����Ѵ�. �����ϸ� 1��, �������� ������ 0�� ����Ѵ�.
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int> vn;
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
		vn.push_back(num);
	}

	sort(vn.begin(), vn.end());

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> num;
		cout << binary_search(vn.begin(), vn.end(), num) << "\n";
	}
}

/*
�̺�Ž��

cin n
for n
	cin vector vn

sort vn (less)

cin m
for m
	cin num
	cout << binary_search(vn.begin,vn,end,num)
*/
