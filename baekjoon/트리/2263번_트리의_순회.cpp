/*
baekjoon 2263��: Ʈ���� ��ȸ

�ð� ����: 5��
�޸� ����: 128 MB

����
n���� ������ ���� ���� Ʈ���� ������ 1���� n������ ��ȣ�� �ߺ� ���� �Ű��� �ִ�. �̿� ���� ���� Ʈ���� �ο����� ����Ʈ������ �־����� ��, ���������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� n(1��n��100,000)�� �־�����. ���� �ٿ��� �ο����� ��Ÿ���� n���� �ڿ����� �־�����, �� ���� �ٿ��� ���� ������ ����Ʈ������ �־�����.

���
ù° �ٿ� ���������� ����Ѵ�. 
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>

using namespace std;

int in_order[100001];
int post_order[100001];
int position[100001];
int n;

void print_post_order(int in_begin,int in_end, int post_begin, int post_end) //��� �迭�� �ε���
{
	if (in_begin > in_end || post_begin > post_end)
		return;

	int root = post_order[post_end];
	int ir = position[root]; //in_order���� root�� �ִ� �ε���

	int left = ir - in_begin; //���� ����Ʈ���� ����
	cout << root << " ";
	print_post_order(in_begin, ir - 1, post_begin, post_begin + left - 1);
	print_post_order(ir+1, in_end, post_begin + left, post_end - 1);
}

int main(void)
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &in_order[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &post_order[i]);
	}
	
	for (int i = 0; i < n; i++)
		position[in_order[i]] = i; //root�� ��ġ�� �ٷ� ã�� ���� position �迭 ����, in_order�� ���� �ε�����, in_order�� �ε����� ã�� ���
	
	print_post_order(0, n - 1,0, n - 1);
}

/*
���� ������ ���� ����, ���� ���� ��� ��������� �����ϱ� ������, ���� ������ ������ ��������� �̿��� ���� ������ ���
1.n �Է�
	�������� n�� �Է� -> ���Ϳ� ����
	�������� n�� �Է� -> ���Ϳ� ����
2. ����Լ� print_post_order(�������� ����, �������� ����)
	�� ��ʹܰ迡��
	if ���Ͱ� ���������
		return (�� ����� ����Ʈ���� �����Ѱ��̹Ƿ�)

	n�� ��������.size()
	root�� ���������� �� ������ ����
	���� ����Ʈ���� ������ ����Ʈ���� ������ ���ϱ�
		���� ����Ʈ���� ������������ root�� �������� ������ �ִ� ���ҵ�
		������ ����Ʈ���� ������������ root�� �������� ������ �ִ� ���ҵ�
		l = find(��������.begin(), ��������.end(), root) - ��������.begin()
		r = n - l - 1

	��ȣ��
	��Ʈ ���
	cout << root << " "
	���� ����Ʈ��
	print_post_order((slice(��������), 0, l),slice(��������),0, l)
	������ ����Ʈ��
	print_post_order((slice(��������), l, n-1),slice(��������),l+1, n)

# slice(����, a,b,) �Լ� -> ���͸� ����.begin()+a, ����.begin()+b�� ũ�⸸ŭ �߶� �ӽ� ���͸� return
*/
