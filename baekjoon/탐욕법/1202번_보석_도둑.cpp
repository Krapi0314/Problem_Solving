/*
baekjoon 1202��: ���� ����

�ð� ����: 1��
�޸� ����: 256 MB

����
�������� ���� ����̴� �������� �б�� ����ߴ�.
����̰� �� ���������� ������ �� N�� �ִ�. �� ������ ���� Mi�� ���� Vi�� ������ �ִ�. ����̴� ������ K�� ������ �ְ�, �� ���濡 ���� �� �ִ� �ִ� ���Դ� Ci�̴�. ���濡�� �ִ� �� ���� ������ ���� �� �ִ�.
����̰� ��ĥ �� �ִ� ������ �ִ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� K�� �־�����. (1 �� N, K �� 300,000)
���� N�� �ٿ��� �� ������ ���� Mi�� Vi�� �־�����. (0 �� Mi, Vi �� 1,000,000)
���� K�� �ٿ��� ���濡 ���� �� �ִ� �ִ� ���� Ci�� �־�����. (1 �� Ci �� 100,000,000)
��� ���ڴ� ���� �����̴�.

���
ù° �ٿ� ����̰� ��ĥ �� �ִ� ���� ������ ���� �ִ��� ����Ѵ�. 

*/
//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

int n, k;
int m, v;
int c;
vector<pair<int, int>> jewelry;
vector<int> bag;
unsigned long long ans;
int idx;
priority_queue<int> pq;

bool compare(pair<int, int>& a, pair<int, int>& b)
{
	if (a.first == b.first)
	{
		return a.second < b.second;

	}
	return a.first < b.first;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> m >> v;
		jewelry.push_back(make_pair(m, v));
	}
	for (int i = 0; i < k; i++)
	{
		cin >> c;
		bag.push_back(c);
	}

	sort(jewelry.begin(), jewelry.end(), compare);
	sort(bag.begin(), bag.end());

	
	for (int i = 0; i < k; i++)
	{
		while (idx < n && bag[i] >= jewelry[idx].first)
		{
			pq.push(jewelry[idx].second);
			idx++;
		}

		if (!pq.empty()) //������ ������ ���� �� ���� ��찡 ���� �� ����, �� ��� ���� ��������Ƿ� ����ִ� ���� �����ϸ� ��Ÿ�� ���� �߻���. �� ����ִ��� ���� Ȯ�� �ʿ�
		{
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans;
}

/*
��� ����� �� Ž�� �Ұ�: 30��Combination1~30��...
���� �κ� ����: �� �ܰ踶�� �ִ��� ��� ������ �ִ��� ������ ���濡 ��� ����, ���� ������� ����鵵 ���� ���������� ����
Ž�� ���� �Ӽ�: �׻� �ִ��� ��� ������ �ִ��� ������ ���濡 ��Ƶ� (Ž��������) ��ü �����ظ� ���� �� ����

//���� ���� ���� ������ sort
//���� �ּ� ���� ������ sort
/���� �������� �ִ��� ��� ���� ���
sort vector jewelry greater
sort vector bag

for bag
	for jewerly
		if bag >= jewerly m
			ans += jewerly v
			jwerly m = 100000001
			break
=> O(nk)�� 30��*30�� = 90��, �ð��ʰ�

!!�׻� �ִ��� ��� ������ �־�� �� -> ������ �ּ� ���� ������ ���������� Ž���ϰ�, ���濡 ���� �� �ִ� �ִ��� ��� ������ Ž���Ҷ�, ���� ���濡�� Ž���� �������� �ٽ� �� �ʿ䰡 ���� (���� ���濡�� ����� ���� �� �����鼭, ���� ��� �������� �ƴϱ� ����)
=> �� �� �� ������ �ٽ� �� �ʿ� ����, �ð�����

cin n k
for n
	cin m v
	vector jewel pushback make pair m v
for k
	cin c
	vector bag pushback c

sort bag less (���� ���� ��)
sort jewel less (���� ���� ��)

for bag
	while idx < n && bag >= jewel[idx].first //�ش� ���濡 ���� �������� ��� �켱���� ť�� �ֱ� (idx�� �����ϹǷν� �� �� �� ������ �ٽ� ���� ����)
		prioirty_queue push jewel[idx].second
		
	ans += pq top, pop //�ִ� ��(�켱���� ť)�� ��Ʈ = ���� ���� �ִ� (�ִ��� ��� ������ �ִ��� ������ ���濡 ����)

cout ans

