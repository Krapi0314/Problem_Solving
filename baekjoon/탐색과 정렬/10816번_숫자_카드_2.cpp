/*
baekjoon 10816��: ���� ī�� 2

�ð� ����: 1��
�޸� ����: 256 MB

����
���� ī��� ���� �ϳ��� ������ �ִ� ī���̴�. ����̴� ���� ī�� N���� ������ �ִ�. ���� M���� �־����� ��, �� ���� �����ִ� ���� ī�带 ����̰� �� �� ������ �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ����̰� ������ �ִ� ���� ī���� ���� N(1 �� N �� 500,000)�� �־�����. ��° �ٿ��� ���� ī�忡 �����ִ� ������ �־�����. ���� ī�忡 �����ִ� ���� -10,000,000���� ũ�ų� ����, 10,000,000���� �۰ų� ����.
��° �ٿ��� M(1 �� M �� 500,000)�� �־�����. ��° �ٿ��� ����̰� �� �� ������ �ִ� ���� ī������ ���ؾ� �� M���� ������ �־�����, �� ���� �������� ���еǾ��� �ִ�. �� ���� -10,000,000���� ũ�ų� ����, 10,000,000���� �۰ų� ����.

���
ù° �ٿ� �Է����� �־��� M���� ���� ���ؼ�, �� ���� ���� ���� ī�带 ����̰� �� �� ������ �ִ����� �������� ������ ����Ѵ�. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>=
using namespace std;

vector<int> v;
int n, m;
int num;
vector<int>::iterator uiter;
vector<int>::iterator liter;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> num;

		uiter = upper_bound(v.begin(), v.end(), num);
		liter = lower_bound(v.begin(), v.end(), num);

		cout << uiter - liter << " ";
	}
}

/*
 -> upper_bound, lower_bound
���� = upper_bound - lower_bound => vector �̿�

vector v

cin n
for n
	cin num
	v pushback num

sort v

cin m
for m
	cin num
	uiter = upper_bound v,num
	liter = lower_bound v,num

	cout << uiter - liter

�ߺ� ���� Ʈ�� -> map, upper_bound, lower_bound
���� = upper_bound - lower_bound

unordered_map: ������ �ʿ���� map
unordered_map<int,int> //first: ��, second: ����

unordered_map um

cin n
for n
	cin num
	um[num]++

cin m
for m
	cin num
	cout << um[num]

!! multiset�� �ȵǴ� ����
multiset�� Time Complexity = linear in the number of matches�̱� ������, m=50�� X multiset matches=50������ �ð��ʰ�,
std::lower_bound �˰������� set�� iterator�� �־� ȣ���ϴ� ����� �ð����⵵�� O(logN)�� �ƴ� O(N)�̴�. (set�� random-access�� �������� �ʱ� ������ iterator�� ��ġ�� ã�� ���� ���������� �������� ��)
set.lower_bound�� �ϸ� O(logN)������, upper_bound - lower_bound�� �������� ������ ���ϱ� ���ؼ��� for������ O(n) ���ؾ� �ϱ� ������ �ð��ʰ� (m=50�� x for�� 50��), ������ ���̸� ���� ���� �� �ִ� vector�� ����ϴ� ���� �� ����
std::count �˰����� ���� �ص� �ð����⵵ O(n)�̱� ������ m=50�� x count 50������ �ð��ʰ�

���: multiset�� �ð��ʰ��� ��, ���� vector�� �ް� �ѹ��� sort �ؼ� lower_bound,upper_bound �ϰų� (m=50�� x log50��), ������ �ʿ���� unordered_map���� ���� ������ �ѹ��� �����ϴ� ����� �� �ð��� ������ �� �� ����
*/
