/*
baekjoon 1422��: ������ ��

�ð� ����: 2��
�޸� ����: 128 MB

����
������ ���� �������� ������, �� �߿� �ڿ����� ���� �������̴�. �������� �ڿ����� ������ �������� ��ٰ� ��� �� ������ �Ű� ������ �ϰ� �Ǿ���. �������� ������ �� �̴ټ��� �̱�����ؼ� ū ���ڸ� ������ �ߴ�.
�������� ���� K���� �ڿ����� ������ �ִ�. �������� K���� �� �߿� ��Ȯ�ϰ� N���� ���� �̾Ƴ��� �� ���� �ٿ��� ���� �� �ִ� ���߿� ���� ū ���� ������� �Ѵ�. ���� ���� ���� �� �̿��ص� �ȴ�. ��, ��� ���� ��� �� ���� �̿�Ǿ�� �Ѵ�.
�������� ���� ������ �ִ� K���� ���� �־����� ��, �� ���� ��� �� �� �̻� �̿��ؼ� ���� �� �ִ� �� �߿� ���� ū ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
���� ��� ���� �������� 2, 3, 7 �̶�� 3���� ���� ������ �ְ�, 4���� ���� �̾ƾ� �Ѵٸ�, 7732�� ����� ���� ū ���� �ȴ�.

�Է�
ù° �ٿ� K�� N�� ������ ���̿� �ΰ� �־�����. K�� N�� ���� 1,000���� �۰ų� ���� �ڿ����̰�, N�� K���� ũ�ų� ����. ��° �ٿ��� K���� ���� �� �ٿ� �ϳ��� �־�����. �� ���� 1,000,000,000���� �۰ų� ���� �ڿ����̴�. �� ���� �ߺ��Ǿ� ���� �� �ִ�. ���� �ߺ��Ǿ ������ ��쿡�� �� ���� ��� �Է����� �־��� ��ŭ �̿�Ǿ�� �Ѵٴ� �Ҹ���.

���
N���� ���� �̾Ƽ� �����ؼ� ���� �� �ִ� ���� ū ���� ����Ѵ�. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int k, n;
ll num;

struct compare {
	bool operator()(ll& a, ll& b) {
		string a_b = to_string(a) + to_string(b);
		string b_a = to_string(b) + to_string(a);

		unsigned long long i_a_b = stoull(a_b);
		unsigned long long i_b_a = stoull(b_a);

		return i_a_b < i_b_a;
	}
};

priority_queue<ll> pq;
priority_queue<ll, vector<ll>, compare> pq2;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k >> n;
	for (int i = 0; i < k; i++)
	{
		cin >> num;
		pq.push(num);
	}

	ll biggest = pq.top(); pq.pop();
	for (int i = k; i <= n; i++)
	{
		pq2.push(biggest);
	}

	while (!pq.empty())
	{
		num = pq.top(); pq.pop();
		pq2.push(num);
	}

	while (!pq2.empty())
	{
		cout << pq2.top();
		pq2.pop();
	}
}

/*
���� �κ� ����, Ž�� ���� �Ӽ� => Ž���
(Ž��) ���� ����:
	1 ����: �ִ��� �� �ڸ����� �������� ����
	2 ����: �� ���� �ٿ��� ���� �� ū ���� ����

��� ���� ��� �� �� �̻� �̿� -> �� ���

pq: �ִ� ��
pq2: �� �� a,b�� a+b, b+a�� �ٿ��� ���� �� ū ���� �ִ밡 �Ǵ� ��

struct compare //�켱���� ť �񱳿����� 
	bool operator()(ll &a, ll &b) //() ������ �����ε�
		//a,b stringȭ �� a+b string ����
		string a+b
		string b+a
		//a+b,b+a string unsigned long long ������ ��ȯ
		ull a+b
		ull b+a

		//�� (a+b�� �� ũ�� a�� �켱������ ����=> false ��ȯ, b+a�� �� ũ�� b�� �켱������ ���� => true ��ȯ)
		return a+b < b+a 

cin k n
for k
	cin num long long
	pq push num //�� �ڸ����� �켱������ ���� ���� �ֱ�

biggest = pq top pop //�ִ� (�ִ� �ڸ��� or �ִ� ��) �̱�
for i = k i<=n i++
	pq2 push biggest //�� ���� �ٿ��� ���� �� ū ���� �켱������ ���� ���� �ֱ�

while pq not empty
	num = pq top pop
	pq2 push num

while pq2 not empty
	cout pq2 top pop
*/
