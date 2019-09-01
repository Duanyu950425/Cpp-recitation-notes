#include<iostream>
using namespace std;

class TreeNode
{
public:
	TreeNode()
	{
		LeftChild = NULL;
		RightChild = NULL;
	}
	char data;
	TreeNode *LeftChild;
	TreeNode *RightChild;
};

class Tree
{
public:
	Tree();
	void PreoderTreeTraversal(TreeNode *currentNode);//前序遍历
	void InorderTraversal(TreeNode *currentNode);//中序
	void PostorderTraversal(TreeNode *currentNode);//后序
	TreeNode *root;
};

Tree::Tree()
{
	root = new TreeNode();
	root->LeftChild = NULL;
	root->RightChild = NULL;
}

void Tree::PreoderTreeTraversal(TreeNode *currentNode)
{
	if (currentNode)
	{
		cout << currentNode->data << " ";
		PreoderTreeTraversal(currentNode->LeftChild);
		PreoderTreeTraversal(currentNode->RightChild);
	}
}

void Tree::InorderTraversal(TreeNode *currentNode)
{
	if (currentNode)
	{
		InorderTraversal(currentNode->LeftChild);
		cout << currentNode->data << " ";
		InorderTraversal(currentNode->RightChild);
	}
}

void Tree::PostorderTraversal(TreeNode *currentNode)
{
	if (currentNode)
	{
		PostorderTraversal(currentNode->LeftChild);
		PostorderTraversal(currentNode->RightChild);
		cout << currentNode->data << " ";
	}
}

int main()
{
	TreeNode add, minus, multi, divide, a, b, c, d, e;

	Tree t;

	add.data = '+';
	minus.data = '-';
	multi.data = '*';
	divide.data = '/';
	a.data = 'A';
	b.data = 'B';
	c.data = 'C';
	d.data = 'D';
	e.data = 'E';

	t.root = &add;
	add.LeftChild = &minus;
	add.RightChild = &e;
	minus.LeftChild = &multi;
	minus.RightChild = &d;
	multi.LeftChild = &divide;
	multi.RightChild = &c;
	divide.LeftChild = &a;
	divide.RightChild = &b;

	cout << "中序遍历：";
	t.InorderTraversal(t.root);
	cout << endl;

	cout << "前序遍历：";
	t.PreoderTreeTraversal(t.root);
	cout << endl;

	cout << "后序遍历：";
	t.PostorderTraversal(t.root);
	cout << endl;

	return 0;
}