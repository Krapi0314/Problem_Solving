/*
BOJ 1991번: 트리 순회

시간 제한: 2초
메모리 제한: 128 MB

문제
이진 트리를 입력받아 전위 순회(preorder traversal), 중위 순회(inorder traversal), 후위 순회(postorder traversal)한 결과를 출력하는 프로그램을 작성하시오.
예를 들어 위와 같은 이진 트리가 입력되면,
전위 순회한 결과 : ABDCEFG // (루트) (왼쪽 자식) (오른쪽 자식)
중위 순회한 결과 : DBAECFG // (왼쪽 자식) (루트) (오른쪽 자식)
후위 순회한 결과 : DBEGFCA // (왼쪽 자식) (오른쪽 자식) (루트)
가 된다.

입력
첫째 줄에는 이진 트리의 노드의 개수 N(1 ≤ N ≤ 26)이 주어진다. 둘째 줄부터 N개의 줄에 걸쳐 각 노드와 그의 왼쪽 자식 노드, 오른쪽 자식 노드가 주어진다. 노드의 이름은 A부터 차례대로 알파벳 대문자로 매겨지며, 항상 A가 루트 노드가 된다. 자식 노드가 없는 경우에는 .으로 표현한다.

출력
첫째 줄에 전위 순회, 둘째 줄에 중위 순회, 셋째 줄에 후위 순회한 결과를 출력한다. 각 줄에 N개의 알파벳을 공백 없이 출력하면 된다.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef struct _node
{
	char node;
	struct _node * left;
	struct _node * right;
} TreeNode;

int n;
char node, input_left, input_right;

//전위 순회 (뿌리 먼저)
void pre_order(TreeNode * root)
{
	if (root == NULL) //해당 노드가 비어 있으면
	{
		return;
	}


	//이외에는
	cout << root->node;
	pre_order(root->left);
	pre_order(root ->right);
}
//중위 순회
void in_order(TreeNode * root)
{
	if (root == NULL) //해당 노드가 비어 있으면
	{
		return;
	}


	//이외에는
	in_order(root->left);
	cout << root->node;
	in_order(root->right);
}
//후위 순회
void post_order(TreeNode * root)
{
	if (root == NULL) //해당 노드가 비어 있으면
	{
		return;
	}


	//이외에는
	post_order(root->left);
	post_order(root->right);
	cout << root->node;
}

int main(void)
{	
	cin >> n;

	vector<TreeNode> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> node >> input_left >> input_right;
		
		v[node - 'A'].node = node;
		if (input_left == '.')
			v[node - 'A'].left = NULL;
		else
			v[node - 'A'].left = &v[input_left - 'A'];

		if (input_right == '.')
			v[node - 'A'].right = NULL;
		else
			v[node - 'A'].right = &v[input_right - 'A'];
	}

	pre_order(&v[0]);
	cout << endl;
	in_order(&v[0]);
	cout << endl;
	post_order(&v[0]);
}

/*
이진 트리에서 전위 순회, 중위 순회, 후위 순회한 결과 출력
노드 n개인 이진 트리
직접 구현
1. 트리 구현
2. n 입력받고, n만큼 노드 백터에 생성
3. 노드들(왼쪽 자식 노드, 오른쪽 자식 노드) 입력받아 이진 트리 구현
4. 재귀함수를 이용해 전위 순회, 중위 순회, 후위 순회 구현

*/
