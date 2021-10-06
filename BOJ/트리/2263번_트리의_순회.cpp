/*
BOJ 2263번: 트리의 순회

시간 제한: 5초
메모리 제한: 128 MB

문제
n개의 정점을 갖는 이진 트리의 정점에 1부터 n까지의 번호가 중복 없이 매겨져 있다. 이와 같은 이진 트리의 인오더와 포스트오더가 주어졌을 때, 프리오더를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 n(1≤n≤100,000)이 주어진다. 다음 줄에는 인오더를 나타내는 n개의 자연수가 주어지고, 그 다음 줄에는 같은 식으로 포스트오더가 주어진다.

출력
첫째 줄에 프리오더를 출력한다. 
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>

using namespace std;

int in_order[100001];
int post_order[100001];
int position[100001];
int n;

void print_post_order(int in_begin,int in_end, int post_begin, int post_end) //모두 배열의 인덱스
{
	if (in_begin > in_end || post_begin > post_end)
		return;

	int root = post_order[post_end];
	int ir = position[root]; //in_order에서 root가 있는 인덱스

	int left = ir - in_begin; //왼쪽 서브트리의 길이
	cout << root << " ";
	print_post_order(in_begin, ir - 1, post_begin, post_begin + left - 1);
	print_post_order(ir+1, in_end, post_begin + left, post_end - 1);
}

int main(void)
{
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &in_order[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &post_order[i]);
	}
	
	for (int i = 0; i < n; i++)
		position[in_order[i]] = i; //root의 위치를 바로 찾기 위해 position 배열 설정, in_order의 값을 인덱스로, in_order의 인덱스를 찾는 방식
	
	print_post_order(0, n - 1,0, n - 1);
}

/*
중위 순위와 후위 순위, 전위 순위 모두 재귀적으로 구현하기 때문에, 중위 순위와 후위를 재귀적으로 이용해 전위 순위를 출력
1.n 입력
	중위순위 n개 입력 -> 벡터에 저장
	후위순위 n개 입력 -> 벡터에 저장
2. 재귀함수 print_post_order(후위순위 벡터, 중위순위 벡터)
	각 재귀단계에서
	if 벡터가 비어있으면
		return (잎 노드의 서브트리를 참조한것이므로)

	n은 중위순위.size()
	root는 후위순위의 맨 마지막 원소
	왼쪽 서브트리와 오른쪽 서브트리를 범위를 구하기
		왼쪽 서브트리는 중위순위에서 root를 기준으로 왼쪽편에 있는 원소들
		오른쪽 서브트리는 중위순위에서 root를 기준으로 오른편에 있는 원소들
		l = find(중위순위.begin(), 중위순위.end(), root) - 중위순위.begin()
		r = n - l - 1

	재호출
	루트 노드
	cout << root << " "
	왼쪽 서브트리
	print_post_order((slice(후위순위), 0, l),slice(중위순위),0, l)
	오른쪽 서브트리
	print_post_order((slice(후위순위), l, n-1),slice(중위순위),l+1, n)

# slice(벡터, a,b,) 함수 -> 벡터를 벡터.begin()+a, 벡터.begin()+b의 크기만큼 잘라서 임시 벡터를 return
*/
