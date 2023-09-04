/*
baekjoon 11651��: ��ǥ �����ϱ� 2

�ð� ����: 1��
�޸� ����: 256 MB

����
2���� ��� ���� �� N���� �־�����. ��ǥ�� y��ǥ�� �����ϴ� ������, y��ǥ�� ������ x��ǥ�� �����ϴ� ������ ������ ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� ���� N (1 �� N �� 100,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� i������ ��ġ xi�� yi�� �־�����. (-100,000 �� xi, yi �� 100,000) ��ǥ�� �׻� �����̰�, ��ġ�� ���� �� ���� ����.

���
ù° �ٺ��� N���� �ٿ� ���� ������ ����� ����Ѵ�. 
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef struct _coordinate
{
	int x;
	int y;
} coordinate;

int N;
vector<coordinate> v;

bool pred(coordinate& a, coordinate& b)
{
	if (a.y != b.y)
	{
		return a.y < b.y;
	}
	else
	{
		return a.x < b.x;
	}

}

int main(void)
{
	scanf("%d", &N);

	coordinate input;
	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &input.x, &input.y);
		v.push_back(input);
	}

	sort(v.begin(), v.end(), pred);

	for (int i = 0; i < N; i++)
	{
		printf("%d %d\n", v[i].x, v[i].y);
	}
}

/*
����, sort pred: a_x < b_x / a_x == b_x �̸� a_y < b_y ����
1. ��ǥ�� ����ü�� ����
2. �Է� �޾Ƽ� vector�� ���� (int������)
3. �����ڸ� �����ؼ� sort
4. ���
*/
