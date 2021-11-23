/*
BOJ 2217번: 로프

시간 제한: 2초
메모리 제한: 192 MB

문제
N(1 ≤ N ≤ 100,000)개의 로프가 있다. 이 로프를 이용하여 이런 저런 물체를 들어올릴 수 있다. 각각의 로프는 그 굵기나 길이가 다르기 때문에 들 수 있는 물체의 중량이 서로 다를 수도 있다.
하지만 여러 개의 로프를 병렬로 연결하면 각각의 로프에 걸리는 중량을 나눌 수 있다. k개의 로프를 사용하여 중량이 w인 물체를 들어올릴 때, 각각의 로프에는 모두 고르게 w/k 만큼의 중량이 걸리게 된다.
각 로프들에 대한 정보가 주어졌을 때, 이 로프들을 이용하여 들어올릴 수 있는 물체의 최대 중량을 구해내는 프로그램을 작성하시오. 모든 로프를 사용해야 할 필요는 없으며, 임의로 몇 개의 로프를 골라서 사용해도 된다.

입력
첫째 줄에 정수 N이 주어진다. 다음 N개의 줄에는 각 로프가 버틸 수 있는 최대 중량이 주어진다. 이 값은 10,000을 넘지 않는 자연수이다.

출력
첫째 줄에 답을 출력한다. 
*/

//#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int n;
int sum, max_weight;
int num;

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

	sort(v.begin(), v.end(), greater<int>());

	max_weight = v[0];

	for (int i = 1; i < n; i++)
	{
		int w_k = v[i];
		sum = w_k * (i + 1);
		
		if (sum > max_weight)
		{
			max_weight = sum;
		}
	}

	cout << max_weight;
}

/*
greedy
최대 중량(답) = 선택한 로프 중 최소 중량의 로프 x 선택한 로프의 개수 이고, 최대 중량을 만들기 위해서는 최소 중량보다 큰 로프들은 모두 포함해야 하므로 (greedy), 로프를 최대중량순으로 (greater) 정렬하고, 로프를 추가 (로프의 중량이 점점 더 작아짐)하면서 최대 중량 찾기

cin n
for n
	cin num
	vector v pushback num

sort v greater

max_weight = v[0]
for v idx 1 to n-1 //모든 로프에 대해 수행
	//로프 추가했을때 중량 계산
	 w_k = v[i]
	 sum = w_k * (i+1)
	 
	if sum > max_weight //이 로프까지 추가했을때 최대 중량이 더 커지면
		max_weight = sum	

cout max_weight
*/
