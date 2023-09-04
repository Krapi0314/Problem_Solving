/*
baekjoon 1181��: �ܾ� ����

�ð� ����: 2��
�޸� ����: 256 MB

����
���ĺ� �ҹ��ڷ� �̷���� N���� �ܾ ������ �Ʒ��� ���� ���ǿ� ���� �����ϴ� ���α׷��� �ۼ��Ͻÿ�.
���̰� ª�� �ͺ���
���̰� ������ ���� ������

�Է�
ù° �ٿ� �ܾ��� ���� N�� �־�����. (1 �� N �� 20,000) ��° �ٺ��� N���� �ٿ� ���� ���ĺ� �ҹ��ڷ� �̷���� �ܾ �� �ٿ� �ϳ��� �־�����. �־����� ���ڿ��� ���̴� 50�� ���� �ʴ´�.

���
���ǿ� ���� �����Ͽ� �ܾ���� ����Ѵ�. ��, ���� �ܾ ���� �� �Էµ� ��쿡�� �� ������ ����Ѵ�. 
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

#define MAX	50

int N;
vector<char*> v;
int cnt; //��� �ߺ������ ��

bool pred(char*& a, char*& b)
{
	if (strlen(a) != strlen(b))
	{
		return strlen(a) < strlen(b);
	}
	else
	{
		if (strcmp(a, b) < 0) //b�� �� ũ��
			return true;
		else
			return false;
	}
}

bool unique_pred(char*& a, char*& b)
{
	if (strcmp(a, b) == 0)
	{
		cnt++;
		return true;
	}
	else
		return false;
}

int main(void)
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		char* str = new char[MAX + 1];
		scanf("%s", str);
		v.push_back(str);
	}

	sort(v.begin(), v.end(), pred);
	unique(v.begin(), v.end(),unique_pred);
	
	for (int i = 0; i < v.size()-cnt; i++)
	{
		printf("%s\n", v[i]);
	}
}

/*
* �ܾ� ����: sort �Լ�, ������ pred: ���� ª�� �ܾ� ����, ���̰� ������ ���� ������
* ���ĺ� �ҹ��ڷ� �̷����
* ���ڿ��� ���̴� 51 (�ι��� ����)
* ���� �ܾ ������ �Է����� �ѹ��� ��� = unique �Լ�
* 
* 1. �Է�: vector�� ����
* 2. ����: sort �Լ�, ������ pred ���
* 3. ����: unique �Լ� ���
* 4. ���: vector ����� ������ ���
*/
