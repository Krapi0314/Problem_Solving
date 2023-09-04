/*
baekjoon 2636��: ġ��

�ð� ����: 1��
�޸� ����: 128 MB

����
�Ʒ� <�׸� 1>�� ���� ���簢�� ĭ��� �̷���� �簢�� ����� ���� �ְ�, �� ���� ���� ġ��(ȸ������ ǥ�õ� �κ�)�� ���� �ִ�. ���� �����ڸ�(<�׸� 1>���� �׸� ĭ�� Xģ �κ�)���� ġ� ���� ���� ������ ġ��� �ϳ� �̻��� ������ ���� �� �ִ�.
�� ġ� ���� �߿� ������ ��� �Ǵµ� ����� ���˵� ĭ�� �� �ð��� ������ ��� ��������. ġ���� ���� �ӿ��� ���Ⱑ ������ ������ �ѷ��� ġ� ��Ƽ� ������ ������ ���� ������ ���Ⱑ ���� �ȴ�. <�׸� 1>�� ���, ġ���� ������ �ѷ��� ġ��� ���� �ʰ� ��c���� ǥ�õ� �κи� �� �ð� �Ŀ� ��� �������� <�׸� 2>�� ���� �ȴ�.
�ٽ� �� �ð� �Ŀ��� <�׸� 2>���� ��c���� ǥ�õ� �κ��� ��� �������� <�׸� 3>�� ���� �ȴ�.
<�׸� 3>�� ���� ġ���� �� �ð� �� ����� ��Ÿ���� ������, ���� �������� �� �ð��� �� ������ ��� ��� ��������. �׷��Ƿ� ó�� ġ� ��� ��� �������� ���� �� �ð��� �ɸ���. <�׸� 3>�� ���� ġ� ��� �������� ���� �������� ������ �� ���� �ִ�.
�Է����� �簢�� ����� ���� ũ��� �� ������ ġ� �� ���� �־����� ��, ���� �߿��� ġ� ��� ��� �������� �� �ɸ��� �ð��� ��� ��� �� �ð� ���� �����ִ� ġ�������� ���� �ִ� ĭ�� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ��� �簢�� ��� ���� ���ο� ������ ���̰� ���� ������ �־�����. ���ο� ������ ���̴� �ִ� 100�̴�. ���� �� �������� ����� �� �ٺ��� ���ʷ� ��° �ٺ��� ������ �ٱ��� �־�����. ġ� ���� ĭ�� 0, ġ� �ִ� ĭ�� 1�� �־����� �� ���� ���̿��� ��ĭ�� �ϳ��� �ִ�.

���
ù° �ٿ��� ġ� ��� ��Ƽ� �������� �� �ɸ��� �ð��� ����ϰ�, ��° �ٿ��� ��� ��� �� �ð� ���� �����ִ� ġ�������� ���� �ִ� ĭ�� ������ ����Ѵ�. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int arr[100][100];
bool discovered[100][100];
bool flag;
int cnt, Time;
int n, m;

queue<pair<int, int>> q;

int dx[4] = { 1, 0 ,-1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool bfs()
{
	flag = true;
	memset(discovered, false, sizeof(discovered));
	q.push(make_pair(0, 0));

	while (!q.empty())
	{
		pair<int, int> here = q.front(); q.pop();
		for (int i = 0; i < 4; i++) 
		{
			int newy = here.first + dy[i];
			int newx = here.second + dx[i];

			if (newy >= 0 && newy < n && newx >= 0 && newx < m && arr[newy][newx] == 0 && !discovered[newy][newx])
			{
				discovered[newy][newx] = true;
				q.push(make_pair(newy, newx));
			}
			else if (newy >= 0 && newy < n && newx >= 0 && newx < m && arr[newy][newx] == 1 && !discovered[newy][newx])
			{
				discovered[newy][newx] = true;
				arr[newy][newx] = 2;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 1)
				flag = false;
		}
	}

	if (flag)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 2)
					cnt++;
			}
		}
		return true;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 2)
					arr[i][j] = 0;
			}
		}
		return false;
	}

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	while (!bfs())
	{
		Time++;
	}

	cout << Time + 1 << "\n" << cnt;
}

/*
���� �߿��� ġ� ��� ��� �������� �� �ɸ��� �ð��� ��� ��� �� �ð� ���� �����ִ� ġ�������� ���� �ִ� ĭ�� ������ ���ϱ�

���� ���� ����� X (0,0)���� BFS, ����� �´���ִ� ġ�� ǥ�� �� ����, ���� �ݺ�

bool BFS()
	init
		flag = true
		memset discovered false
		
		queue push 0,0
		discoverd 0 0 true

	while ! queue empty
		here = queue front pop
		
		for 4
			newy = here + dy
			newx = here + dx

			if newy newx ���� �� && arr[newy][newx] = 0 && discovered[newy][newx] = false //����=0 �� �κ� BFS
				discovered newy newx true
				queue push newy,newx
			else if newy newx ���� �� && arr[newy][newx] = 1 discovered[newy][newx] = false //����� �´���ִ� �κ���
				discovered newy newx true
				arr[newy][newx] = 2 //������ ��� ġ��� ����
			
	
	//������ �������� �Ǻ�
	for n
		for m
			if arr == 1 //���� ������ ���� ġ� ������
				flag = false //��� ��� �� �ð� �� ���� ġ�������� �ƴ�

	if flag true //��� ��� �� �ð� �� ���� ġ�������̸�
		for n
			for m
				if arr == 2
					cnt++
		return true //���� ��
	else //�ƴϸ�
		for n
			for m
				if arr == 2
					arr = 0 //���̱�
		return false //������ BFS ���

cin n m ���� ����

for n
	for m
		cin arr

while(!bfs())
	time++

cout  time+1 cnt
*/
