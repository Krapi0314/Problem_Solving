/*
BOJ 2485번: 가로수

시간 제한: 1초
메모리 제한: 128 MB

문제
직선으로 되어있는 도로의 한 편에 가로수가 임의의 간격으로 심어져있다. KOI 시에서는 가로수들이 모두 같은 간격이 되도록 가로수를 추가로 심는 사업을 추진하고 있다. KOI 시에서는 예산문제로 가능한 한 가장 적은 수의 나무를 심고 싶다.
편의상 가로수의 위치는 기준점으로 부터 떨어져 있는 거리로 표현되며, 가로수의 위치는 모두 양의 정수이다.
예를 들어, 가로수가 (1, 3, 7, 13)의 위치에 있다면 (5, 9, 11)의 위치에 가로수를 더 심으면 모든 가로수들의 간격이 같게 된다. 또한, 가로수가 (2, 6, 12, 18)에 있다면 (4, 8, 10, 14, 16)에 가로수를 더 심어야 한다.
심어져 있는 가로수의 위치가 주어질 때, 모든 가로수가 같은 간격이 되도록 새로 심어야 하는 가로수의 최소수를 구하는 프로그램을 작성하라. 단, 추가되는 나무는 기존의 나무들 사이에만 심을 수 있다.

입력
첫째 줄에는 이미 심어져 있는 가로수의 수를 나타내는 하나의 정수 N이 주어진다(3≤N≤100,000). 둘째 줄부터 N개의 줄에는 각 줄마다 심어져 있는 가로수의 위치가 양의 정수로 주어지며, 가로수의 위치를 나타내는 정수는 100,000,000 이하이다. 가로수의 위치를 나타내는 정수는 모두 다르다.

출력
모든 가로수가 같은 간격이 되도록 새로 심어야 하는 가로수의 최소수를 첫 번째 줄에 출력한다.
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

int gcd(int a, int b) //a로 b를 나눈 나머지
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

	//가로수 사이의 거리 dist가 먼 값부터 최대공약수를 구해서, 해당 최대공약수가 모든 dist에 대해 약수이면, for문 break = 최대공약수 찾음 (굳이 모든 dist의 최대공약수를 구해서 비교할 필요 없음, 모든 dist의 최대공약수를 구해서 비교할 경우 최대 10만- 번 정도 for 해야 함)
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
심어져 있는 가로수의 위치가 주어질 때, 모든 가로수가 같은 간격이 되도록 새로 심어야 하는 가로수의 최소수를 구하는 프로그램을 작성하라. 단, 추가되는 나무는 기존의 나무들 사이에만 심을 수 있다.

수학,최대공약수

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

시간초과: 유클리드 호제법 사용

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
