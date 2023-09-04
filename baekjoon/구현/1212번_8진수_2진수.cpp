/*
baekjoon 1212��: 8���� 2����

�ð� ����: 1��
�޸� ����: 128 MB

����
8������ �־����� ��, 2������ ��ȯ�ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� 8������ �־�����. �־����� ���� ���̴� 333,334�� ���� �ʴ´�.

���
ù° �ٿ� �־��� ���� 2������ ��ȯ�Ͽ� ����Ѵ�. ���� 0�� ��츦 �����ϰ�� �ݵ�� 1�� �����ؾ� �Ѵ�.
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

string s;
string bi;
int digit;
char c;
int num;
bool flag;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> s;

	if (s == "0")
	{
		cout << "0";
		return 0;
	}

	for (int i = 0; i < s.size(); i++)
	{
		bi.clear();

		num = s[i] - '0';

		if (num == 0)
		{
			bi = "000";
		}
		else
		{
			while (num != 0)
			{
				digit = num % 2;
				num /= 2;

				c = digit + '0';
				bi = c + bi;
			}
		}

		if (!flag)
		{
			cout << bi;
			flag = true;
			continue;
		}

		if (bi.size() % 3 == 1)
			bi = "00" + bi;
		else if (bi.size() % 3 == 2)
			bi = "0" + bi;

		cout << bi;
	}
}

/*
8���� -> 2����
8���� 1�ڸ� = 2���� 3�ڸ��� ǥ���ǹǷ� 8���� 1�ڸ��� 2���� 3�ڸ��� ��ȯ

flag = false
cin string s

if s == "0"
	cout 0
	return 0 (exit(1)�� ��Ÿ�� ���� ��, exit(0) = main �Լ� return == return 0, exit(0)���� �ϰų�, return 0�� ��ȯ�ϱ�)

for s.size
	init
		bi = null

	num = s[i]

	if num == 0 //8���� 0 = 2���� 000
		bi = "000"
	else
		while num !=0
			digit = num % 2
			num /= 2
		
			char  c = digit + '0'
			bi = c + bi


	if flag false
		cout bi
		flag = true

	if bi.size % 3 == 1
		bi = "00" + bi
	else if bi.size % 3 == 2
		bi = "0" + bi

	cout bi
*/
