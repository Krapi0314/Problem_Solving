/*
baekjoon 2661��: ��������

�ð� ����: 1��
�޸� ����: 128 MB

����
���� 1, 2, 3���θ� �̷������ ������ �ִ�. ������ ������ ������ �� ���� �κ� ������ ������ ���� ������, �� ������ ���� �����̶�� �θ���. �׷��� ���� ������ ���� �����̴�.
������ ���� ������ ���̴�.

33
32121323
123123213
������ ���� ������ ���̴�.

2
32
32123
1232123
���̰� N�� ���� �������� N�ڸ��� ������ ���� ���� ���� ���� ���� ��Ÿ���� ������ ���ϴ� ���α׷��� �ۼ��϶�. ���� ���, 1213121�� 2123212�� ��� ���� ���������� �� �߿��� ���� ���� ��Ÿ���� ������ 1213121�̴�.

�Է�
�Է��� ���� N�ϳ��� �̷������. N�� 1 �̻� 80 �����̴�.

���
ù ��° �ٿ� 1, 2, 3���θ� �̷���� �ִ� ���̰� N�� ���� ������ �߿��� ���� ���� ���� ��Ÿ���� ������ ����Ѵ�. ������ �̷�� 1, 2, 3�� ���̿��� ��ĭ�� ���� �ʴ´�. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

vector<int> ans;
int n;
bool flag;

bool promising(int num)
{
	ans.push_back(num);
	int len = ans.size();

	for (int i = 1; i <= len/2; i++)
	{
		string s1 = "";
		string s2 = "";

		for (int j = 0; j < i; j++)
		{
			s1 += to_string(ans[len - (2 * i) + j]);
			s2 += to_string(ans[len - i + j]);
		}

		if (s1 == s2)
		{
			ans.pop_back();
			return false;
		}
	}

	ans.pop_back();
	return true;
}

void dfs(int cnt)
{
	if (flag)
		return;

	if (cnt == n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << ans[i];
		}
		flag = true;
		return;
	}

	for (int i = 1; i <= 3; i++)
	{
		if (ans.empty() || promising(i))
		{
			ans.push_back(i);
			dfs(++cnt);
			ans.pop_back();
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
	dfs(0);
}

/*
����Ž��, ��Ʈ��ŷ

vector<int> ans //n�ڸ� ���� ���� ���� ����
int arr[3] = {1,2,3}

bool promising(int num) //num���� �߰����� �� ���� ������ �Ǵ��� Ȯ��
	�� Ƚ���� ������ ������ ����
	ex) ���̰� 6�̸� for 3��, ������ ���� i�� substr 2�� �˻�

	int len = ans.size()
	
	for i 1 to len/2 //������ ���ݸ�ŭ �˻�
		string s1 = "";
		string s2 = "";

		for j 0 to j<i //���� i��ŭ ans ���Ϳ��� ������ string s1,s2�� ���� substr �� ��
			s1 += to_string(ans[len - (2 * i) + j]);
			s2 += to_string(ans[len - i + j]);
		
		if(s1 == s2) //���� ������ ���� ����
			return false
	
	return true
			

void dfs(int cnt) //n�ڸ� ���� ���� ���� ����, cnt�� ���ݱ����� �ڸ���(����)
	if(flag)
		return

	if(cnt == n)
		//���� ù��°�� ã�� ���� ������ ��
		for n
			cout vector ans
			flag = true
		return
	
	for(int i=0; i<3; i++) //���� �ڸ� ����: 1,2,3 ��
		if(ans.empty || promising(arr[i])) //�����ϸ�
			vector pushback arr[i]
			dfs(++cnt) //dfs
			vector popback
			cnt--

cin >> n
dfs(0)
cout << ans
*/
