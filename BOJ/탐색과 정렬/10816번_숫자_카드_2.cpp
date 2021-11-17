/*
BOJ 10816번: 숫자 카드 2

시간 제한: 1초
메모리 제한: 256 MB

문제
숫자 카드는 정수 하나가 적혀져 있는 카드이다. 상근이는 숫자 카드 N개를 가지고 있다. 정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 상근이가 몇 개 가지고 있는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 상근이가 가지고 있는 숫자 카드의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 둘째 줄에는 숫자 카드에 적혀있는 정수가 주어진다. 숫자 카드에 적혀있는 수는 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.
셋째 줄에는 M(1 ≤ M ≤ 500,000)이 주어진다. 넷째 줄에는 상근이가 몇 개 가지고 있는 숫자 카드인지 구해야 할 M개의 정수가 주어지며, 이 수는 공백으로 구분되어져 있다. 이 수도 -10,000,000보다 크거나 같고, 10,000,000보다 작거나 같다.

출력
첫째 줄에 입력으로 주어진 M개의 수에 대해서, 각 수가 적힌 숫자 카드를 상근이가 몇 개 가지고 있는지를 공백으로 구분해 출력한다. 
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
개수 = upper_bound - lower_bound => vector 이용

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

중복 이진 트리 -> map, upper_bound, lower_bound
개수 = upper_bound - lower_bound

unordered_map: 정렬이 필요없는 map
unordered_map<int,int> //first: 값, second: 개수

unordered_map um

cin n
for n
	cin num
	um[num]++

cin m
for m
	cin num
	cout << um[num]

!! multiset은 안되는 이유
multiset의 Time Complexity = linear in the number of matches이기 때문에, m=50만 X multiset matches=50만으로 시간초과,
std::lower_bound 알고리즘으로 set의 iterator를 넣어 호출하는 경우의 시간복잡도는 O(logN)이 아닌 O(N)이다. (set은 random-access를 지원하지 않기 떄문에 iterator의 위치를 찾기 위해 선형적으로 움직여야 함)
set.lower_bound로 하면 O(logN)이지만, upper_bound - lower_bound의 연산으로 개수를 구하기 위해서는 for문으로 O(n) 구해야 하기 때문에 시간초과 (m=50만 x for문 50만), 개수의 차이를 쉽게 구할 수 있는 vector를 사용하는 것이 더 낫다
std::count 알고리즘을 쓴다 해도 시간복잡도 O(n)이기 때문에 m=50만 x count 50만으로 시간초과

결론: multiset은 시간초과가 남, 차라리 vector로 받고 한번에 sort 해서 lower_bound,upper_bound 하거나 (m=50만 x log50만), 정렬이 필요없는 unordered_map으로 값과 개수를 한번에 저장하는 방식이 더 시간을 절약해 줄 수 있음
*/
