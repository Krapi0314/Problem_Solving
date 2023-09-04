/*
baekjoon 1991��: Ʈ�� ��ȸ

�ð� ����: 2��
�޸� ����: 128 MB

����
���� Ʈ���� �Է¹޾� ���� ��ȸ(preorder traversal), ���� ��ȸ(inorder traversal), ���� ��ȸ(postorder traversal)�� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
���� ��� ���� ���� ���� Ʈ���� �ԷµǸ�,
���� ��ȸ�� ��� : ABDCEFG // (��Ʈ) (���� �ڽ�) (������ �ڽ�)
���� ��ȸ�� ��� : DBAECFG // (���� �ڽ�) (��Ʈ) (������ �ڽ�)
���� ��ȸ�� ��� : DBEGFCA // (���� �ڽ�) (������ �ڽ�) (��Ʈ)
�� �ȴ�.

�Է�
ù° �ٿ��� ���� Ʈ���� ����� ���� N(1 �� N �� 26)�� �־�����. ��° �ٺ��� N���� �ٿ� ���� �� ���� ���� ���� �ڽ� ���, ������ �ڽ� ��尡 �־�����. ����� �̸��� A���� ���ʴ�� ���ĺ� �빮�ڷ� �Ű�����, �׻� A�� ��Ʈ ��尡 �ȴ�. �ڽ� ��尡 ���� ��쿡�� .���� ǥ���Ѵ�.

���
ù° �ٿ� ���� ��ȸ, ��° �ٿ� ���� ��ȸ, ��° �ٿ� ���� ��ȸ�� ����� ����Ѵ�. �� �ٿ� N���� ���ĺ��� ���� ���� ����ϸ� �ȴ�.
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

//���� ��ȸ (�Ѹ� ����)
void pre_order(TreeNode * root)
{
	if (root == NULL) //�ش� ��尡 ��� ������
	{
		return;
	}


	//�̿ܿ���
	cout << root->node;
	pre_order(root->left);
	pre_order(root ->right);
}
//���� ��ȸ
void in_order(TreeNode * root)
{
	if (root == NULL) //�ش� ��尡 ��� ������
	{
		return;
	}


	//�̿ܿ���
	in_order(root->left);
	cout << root->node;
	in_order(root->right);
}
//���� ��ȸ
void post_order(TreeNode * root)
{
	if (root == NULL) //�ش� ��尡 ��� ������
	{
		return;
	}


	//�̿ܿ���
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
���� Ʈ������ ���� ��ȸ, ���� ��ȸ, ���� ��ȸ�� ��� ���
��� n���� ���� Ʈ��
���� ����
1. Ʈ�� ����
2. n �Է¹ް�, n��ŭ ��� ���Ϳ� ����
3. ����(���� �ڽ� ���, ������ �ڽ� ���) �Է¹޾� ���� Ʈ�� ����
4. ����Լ��� �̿��� ���� ��ȸ, ���� ��ȸ, ���� ��ȸ ����

*/
