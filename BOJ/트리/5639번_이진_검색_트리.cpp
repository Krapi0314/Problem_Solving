/*
BOJ 5639번: 이진 검색 트리

시간 제한: 1초
메모리 제한: 256 MB

문제
이진 검색 트리는 다음과 같은 세 가지 조건을 만족하는 이진 트리이다.
노드의 왼쪽 서브트리에 있는 모든 노드의 키는 노드의 키보다 작다.
노드의 오른쪽 서브트리에 있는 모든 노드의 키는 노드의 키보다 크다.
왼쪽, 오른쪽 서브트리도 이진 검색 트리이다.
전위 순회 (루트-왼쪽-오른쪽)은 루트를 방문하고, 왼쪽 서브트리, 오른쪽 서브 트리를 순서대로 방문하면서 노드의 키를 출력한다. 후위 순회 (왼쪽-오른쪽-루트)는 왼쪽 서브트리, 오른쪽 서브트리, 루트 노드 순서대로 키를 출력한다. 예를 들어, 위의 이진 검색 트리의 전위 순회 결과는 50 30 24 5 28 45 98 52 60 이고, 후위 순회 결과는 5 28 24 45 30 60 52 98 50 이다.
이진 검색 트리를 전위 순회한 결과가 주어졌을 때, 이 트리를 후위 순회한 결과를 구하는 프로그램을 작성하시오.

입력
트리를 전위 순회한 결과가 주어진다. 노드에 들어있는 키의 값은 106보다 작은 양의 정수이다. 모든 값은 한 줄에 하나씩 주어지며, 노드의 수는 10,000개 이하이다. 같은 키를 가지는 노드는 없다.

출력
입력으로 주어진 이진 검색 트리를 후위 순회한 결과를 한 줄에 하나씩 출력한다.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>

using namespace std;

struct _node
{
	int value;
	_node* left;
	_node* right;

	_node() :left(NULL), right(NULL), value(0) {}
};

_node tree[10000];

void post_order(_node * root)
{
	if (root == NULL)
	{
		return;
	}

	post_order(root->left);
	post_order(root->right);
	printf("%d\n", root->value);
}

void insert(int idx)
{
	_node* p = &tree[0];
	_node* r = NULL;
	while (p != NULL)
	{
		r = p; //r은 p의 부모노드
		if (tree[idx].value < p->value)
			p = p->left;
		else
			p = p->right;
	}

	if (tree[idx].value > r->value)
		r->right = &tree[idx];
	else
		r->left = &tree[idx];
}

int main(void)
{
	int cnt;
	for (cnt = 0; scanf("%d", &tree[cnt].value) != EOF; cnt++); //몇번 입력받을지 모르므로 이런 형태로 입력받기

	//tree[0]은 루트 노드
	for (int i = 1; i < cnt; i++)
	{
		insert(i);
	}

	post_order(&tree[0]);
}

/*
이진 검색 트리를 전위 순회한 결과가 주어졌을 떄, 이 트리를 후위 순회한 결과를 구하기
재귀를 활용해서
전위 순회로 이진 트리를 만들고, 후위 순회 재귀함수를 만들어서 출력
1. 값을 입력 받아 node 구조체 배열에 저장
2. node 배열에서 이진 검색 트리의 특징에 따라 포인터로 이어주기
3. 후위 순회 재귀함수 구현
4. 후위 순회 재귀함수로 만든 트리를 출력
	
*/
