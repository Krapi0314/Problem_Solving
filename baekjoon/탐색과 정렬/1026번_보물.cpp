/*
baekjoon 1026��: ����

�ð� ����: 2��
�޸� ����: 128 MB

����
���� ������ ������ �׻� ū ��ĩ�Ÿ����� ���� �־���. �� ������ ���� �������� ������ ���� ������ ���� ū ����� �ɾ���.
���̰� N�� ���� �迭 A�� B�� �ִ�. ������ ���� �Լ� S�� ��������.
S = A[0]��B[0] + ... + A[N-1]��B[N-1]
S�� ���� ���� �۰� ����� ���� A�� ���� ��迭����. ��, B�� �ִ� ���� ��迭�ϸ� �� �ȴ�.
S�� �ּڰ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� �־�����. ��° �ٿ��� A�� �ִ� N���� ���� ������� �־�����, ��° �ٿ��� B�� �ִ� ���� ������� �־�����. N�� 50���� �۰ų� ���� �ڿ����̰�, A�� B�� �� ���Ҵ� 100���� �۰ų� ���� ���� �ƴ� �����̴�.

���
ù° �ٿ� S�� �ּڰ��� ����Ѵ�. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

vector<int> a;
vector<int> b;
int n;
int ans;
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
		a.push_back(num);
	}
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		b.push_back(num);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for (int i = 0; i < n; i++)
	{
		ans += a[i] * b[n - i - 1];
	}
	cout << ans;
}

/*
n �Է�
	a ���� �Է�
	b ���� �Է�

	b ���� ����
	a ���� ����
	for b_new
		ans += a ���ĺ����� ���� * b ���ĺ����� ����
		
	cout << ans
	
*/
