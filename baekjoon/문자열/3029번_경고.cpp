/*
baekjoon 3029��: ���

�ð� ����: 1��
�޸� ����: 128 MB

����
â���������� �������� �ݶ��� ���з� ������. (3028��)
�׷�����Ʈ�� ������ �����̴� â�������� ��� �Ϸ��� �Ѵ�.
��� �����̴� â���������� ���� ���ѻ���̴�. ����, ������� ��ġ�� �ʰ��Ϸ��� �Ѵ�.
��Ʃ�꿡�� ���߿� ���� �������� ã�ƺ��ٰ�, �״� ��Ʈ���� ���� ������ �����Ѵٴ� ����� �˰� �Ǿ���.
�����̴� â�������� �߽��� ������ "���갭" ��ó�� �����ִٰ�, ��Ʈ���� ���� ������ó�� ���� ���� ���̴�.
���� �ð��� �����̰� ��Ʈ���� ���� �ð��� �־����� ��, �����̰� �󸶳� �����־�� �ϴ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. (�����̴� ��� 1�ʸ� ��ٸ���, ���ƾ� 24�ð��� ��ٸ���.)

�Է�
ù° �ٿ� ���� �ð��� hh:mm:ss �������� �־�����. (��, ��, ��) hh�� 0���� ũ�ų� ����, 23���� �۰ų� ������, �а� �ʴ� 0���� ũ�ų� ����, 59���� �۰ų� ����.
��° �ٿ��� ��Ʈ���� ���� �ð��� ���� ���� �������� �־�����.

���
ù° �ٿ� �����̰� ��ٷ��� �ϴ� �ð��� �Է°� ���� �������� ����Ѵ�. 
*/

#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

string start_string, end_string;
int result_sec, start_sec, end_sec;
int hour, minu, sec;
int num;

int main(void)
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	
	vector<int> startv(3), endv(3);
	scanf("%d:%d:%d", &startv[0], &startv[1], &startv[2]);
	scanf("%d:%d:%d", &endv[0], &endv[1], &endv[2]);

	start_sec = startv[0] * 3600 + startv[1] * 60 + startv[2];
	end_sec = endv[0] * 3600 + endv[1] * 60 + endv[2];

	if (start_sec < end_sec)
	{
		result_sec = end_sec - start_sec;
	}
	else if(start_sec == end_sec || start_sec > end_sec)
	{
		result_sec = 24 * 3600 + end_sec - start_sec;
	}

	hour = result_sec / 3600; result_sec -= hour * 3600;
	minu = result_sec / 60; result_sec -= minu * 60;

	printf("%02d:%02d:%02d", hour, minu, result_sec);
}

/*
�ð� ����

��� sec���� �ٲپ� ��� �� ��ȯ

!!�����̴� ��� 1�ʸ� ��ٸ��Ƿ�,
00:00:00
00:00:00�� ���� ���
24�ð��� ��ٸ� ���� ��
*/
