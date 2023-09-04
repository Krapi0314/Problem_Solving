/*
baekjoon 11365��: !�к� ����

�ð� ����: 1��
�޸� ����: 256 MB

����
����� ���� ���ٰ� �̻��� ������ �߰��ߴ�. �� �������� ��ȣ�� ���� �־��µ�, �ȶ��� ����� ��ȣ�� �������� �ص��ȴٴ� ���� �߰��ߴ�.
�� ��ȣ�� �ص��ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�� �ٿ� �ϳ��� ��ȣ�� �־�����. ��ȣ�� ���̴� 500�� ���� �ʴ´�.
������ �ٿ��� "END"�� �־�����. (END�� �ص����� �ʴ´�.)

���
�� ��ȣ�� �ص��� ���� �� �ٿ� �ϳ��� ����Ѵ�. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

//#Include <cstdio>

using namespace std;

string s;


int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1)
	{
		getline(cin, s);
		if (s == "END")
		{
			break;
		}

		string::reverse_iterator riter = s.rbegin();

		for (; riter != s.rend(); ++riter)
		{
			cout << *riter;
		}
		cout << "\n";
	}
}

/*

 */
