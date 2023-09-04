/*
baekjoon 2485��: ���μ�

�ð� ����: 1��
�޸� ����: 128 MB

����
�������� �Ǿ��ִ� ������ �� �� ���μ��� ������ �������� �ɾ����ִ�. KOI �ÿ����� ���μ����� ��� ���� ������ �ǵ��� ���μ��� �߰��� �ɴ� ����� �����ϰ� �ִ�. KOI �ÿ����� ���깮���� ������ �� ���� ���� ���� ������ �ɰ� �ʹ�.
���ǻ� ���μ��� ��ġ�� ���������� ���� ������ �ִ� �Ÿ��� ǥ���Ǹ�, ���μ��� ��ġ�� ��� ���� �����̴�.
���� ���, ���μ��� (1, 3, 7, 13)�� ��ġ�� �ִٸ� (5, 9, 11)�� ��ġ�� ���μ��� �� ������ ��� ���μ����� ������ ���� �ȴ�. ����, ���μ��� (2, 6, 12, 18)�� �ִٸ� (4, 8, 10, 14, 16)�� ���μ��� �� �ɾ�� �Ѵ�.
�ɾ��� �ִ� ���μ��� ��ġ�� �־��� ��, ��� ���μ��� ���� ������ �ǵ��� ���� �ɾ�� �ϴ� ���μ��� �ּҼ��� ���ϴ� ���α׷��� �ۼ��϶�. ��, �߰��Ǵ� ������ ������ ������ ���̿��� ���� �� �ִ�.

�Է�
ù° �ٿ��� �̹� �ɾ��� �ִ� ���μ��� ���� ��Ÿ���� �ϳ��� ���� N�� �־�����(3��N��100,000). ��° �ٺ��� N���� �ٿ��� �� �ٸ��� �ɾ��� �ִ� ���μ��� ��ġ�� ���� ������ �־�����, ���μ��� ��ġ�� ��Ÿ���� ������ 100,000,000 �����̴�. ���μ��� ��ġ�� ��Ÿ���� ������ ��� �ٸ���.

���
��� ���μ��� ���� ������ �ǵ��� ���� �ɾ�� �ϴ� ���μ��� �ּҼ��� ù ��° �ٿ� ����Ѵ�.
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;
vector<int> dist;
int ans;
int num;
bool flag;
int GCD;
int possible;

int gcd(int a, int b) //a�� b�� ���� ������
{
	if (a % b == 0)
		return b;

	return gcd(b, a % b);

}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int t = 0; t < n; t++)
	{
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size() - 1; i++)
	{
		dist.push_back(v[i + 1] - v[i]);
	}

	//���μ� ������ �Ÿ� dist�� �� ������ �ִ������� ���ؼ�, �ش� �ִ������� ��� dist�� ���� ����̸�, for�� break = �ִ����� ã�� (���� ��� dist�� �ִ������� ���ؼ� ���� �ʿ� ����, ��� dist�� �ִ������� ���ؼ� ���� ��� �ִ� 10��- �� ���� for �ؾ� ��)
	for (int i = dist.size() - 2; i >= 0; i--)
	{
		possible = gcd(dist[i + 1], dist[i]);
		flag = true;

		for (int j = 0; j < dist.size(); j++)
		{
			if (dist[j] % possible != 0)
			{
				flag = false;
				break;
			}
		}

		if (flag)
		{
			GCD = possible;
			break;
		}
	}

	for (int i = 0; i < dist.size(); i++)
	{
		ans += dist[i] / GCD - 1;
	}

	cout << ans;
}

/*
�ɾ��� �ִ� ���μ��� ��ġ�� �־��� ��, ��� ���μ��� ���� ������ �ǵ��� ���� �ɾ�� �ϴ� ���μ��� �ּҼ��� ���ϴ� ���α׷��� �ۼ��϶�. ��, �߰��Ǵ� ������ ������ ������ ���̿��� ���� �� �ִ�.

����,�ִ�����

cin n
for n
	cin num
	vector v pushback num

sort v
for v
	vector dist pushback v[i+1] - v[i]

for i
	flag = true;
	for dist
		if i % dist != 0
			flag = false
			break

	if flag == true
		min = i
		break

for dist
	ans += dist / min  - 1


cout ans

�ð��ʰ�: ��Ŭ���� ȣ���� ���

cin n
for n
	cin num
	vector v pushback num

sort v
for v
	vector dist pushback v[i+1] - v[i]

for dist
	possible = gcd(dist[i+1],dist[i])

	for dist
		if dist % possible != 0
			flag = false
			break
	if flag
		GCD = possible
		break

for dist
	ans += dist / min  - 1


cout ans
*/
