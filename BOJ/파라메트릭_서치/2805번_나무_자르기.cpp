/*
BOJ 2805번: 나무 자르기

시간 제한: 1초
메모리 제한: 256 MB

문제
상근이는 나무 M미터가 필요하다. 근처에 나무를 구입할 곳이 모두 망해버렸기 때문에, 정부에 벌목 허가를 요청했다. 정부는 상근이네 집 근처의 나무 한 줄에 대한 벌목 허가를 내주었고, 상근이는 새로 구입한 목재절단기를 이용해서 나무를 구할것이다.
목재절단기는 다음과 같이 동작한다. 먼저, 상근이는 절단기에 높이 H를 지정해야 한다. 높이를 지정하면 톱날이 땅으로부터 H미터 위로 올라간다. 그 다음, 한 줄에 연속해있는 나무를 모두 절단해버린다. 따라서, 높이가 H보다 큰 나무는 H 위의 부분이 잘릴 것이고, 낮은 나무는 잘리지 않을 것이다. 예를 들어, 한 줄에 연속해있는 나무의 높이가 20, 15, 10, 17이라고 하자. 상근이가 높이를 15로 지정했다면, 나무를 자른 뒤의 높이는 15, 15, 10, 15가 될 것이고, 상근이는 길이가 5인 나무와 2인 나무를 들고 집에 갈 것이다. (총 7미터를 집에 들고 간다) 절단기에 설정할 수 있는 높이는 양의 정수 또는 0이다.
상근이는 환경에 매우 관심이 많기 때문에, 나무를 필요한 만큼만 집으로 가져가려고 한다. 이때, 적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 나무의 수 N과 상근이가 집으로 가져가려고 하는 나무의 길이 M이 주어진다. (1 ≤ N ≤ 1,000,000, 1 ≤ M ≤ 2,000,000,000)
둘째 줄에는 나무의 높이가 주어진다. 나무의 높이의 합은 항상 M을 넘기 때문에, 상근이는 집에 필요한 나무를 항상 가져갈 수 있다. 높이는 1,000,000,000보다 작거나 같은 양의 정수 또는 0이다.

출력
적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값을 출력한다.
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

vector<int> v;
long long n, M;
long long m, l, h;

bool choppedTreeSumExceed(long long m)
{
	long long sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] >= m)
			sum += v[i] - m;
	}

	if (sum >= M)
		return true;
	else
		return false;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> M;
	for (int i = 0; i < n; i++)
	{
		long long num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	l = 0;
	h = v[n - 1];

	while (l < h)
	{
		m = (l + h + 1) / 2;
		
		if (choppedTreeSumExceed(m))
		{
			l = m;
		}
		else
		{
			h = m - 1;
		}
	}
	
	cout << h;
}

/*
파라메트릭 서치
결정문제로 변환: 1~20억의 정수 범위에 대해, 해당 정수로 절단기 높이를 설정하면 잘린 나무의 합이 M보다 같거나 큰가?

최댓값: m = (l+h+1) / 2

cin n m
for n
	vector pushback num

init
	sort vector less
	l = 1 //절단기가 주어진 n개의 나무 길이의 최솟값보다 작아질 수 있음. (M이 너무 커서 n개의 나무 길이의 최솟값으로 잘라도 충족이 되지 않을때)
	h = v[n-1]

while l < h 이분탐색, 절단기 높이의 최댓값 찾기 , l = h이 될때까지
	m = (l+h+1) / 2

	if(choppedTreeSumExceed(m)) //잘린 나무의 합이 m 이상일때 (m 이하의 값들은 모두 조건을 만족함)
		l = m //m~h 탐색하기
	else //너무 높게 설정함, m이상 나무들은 조건 불충족 
		h = m-1 //l~m-1 탐색하기
		
cout h

bool choppedTreeSum(long long m)
	for vector
		sum += v[i] - m

	if sum >= m
		return true
	else
		return false
*/
