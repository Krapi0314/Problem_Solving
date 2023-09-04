/*
baekjoon 11720��: ������ ��

�ð� ����: 1��
�޸� ����: 256 MB

����
N���� ���ڰ� ���� ���� �����ִ�. �� ���ڸ� ��� ���ؼ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ���� N (1 �� N �� 100)�� �־�����. ��° �ٿ� ���� N���� ������� �־�����.

���
�Է����� �־��� ���� N���� ���� ����Ѵ�. 
*/

#include <iostream>

using namespace std;

int main(void)
{
	int N;
	char arr[101];
	int result = 0;
	cin >> N;
	cin >> arr;
	
	for (int i = 0; i < N; i++)
	{
		result += arr[i] - '0';
	}
	cout << result << endl;
	return 0;
}
