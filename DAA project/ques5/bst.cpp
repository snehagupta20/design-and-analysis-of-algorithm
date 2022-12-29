//THIS CODE IS WRITEN BY SNEHA GUPTA
//2021UCA1859
//DAA PROJECT

#include <iostream>
using namespace std;

class bst 
{
	int data;
	bst *left, *right;

	public:
	//default constructor
	bst();

	//parameterized constructor
	bst(int);

	//insert function
	bst* insert(bst*, int);

	//inorder traversal
	void inorder(bst*);
};

//default constructor definition
bst ::bst()
	: data(0)
	, left(NULL)
	, right(NULL)
{
}

//parameterized constructor definition
bst ::bst(int value)
{
	data=value;
	left=right=NULL;
}

//insert function definition
bst* bst ::insert(bst* root, int value)
{
	if (!root) 
	{
		//inserting the first node, if root is NULL
		return new bst(value);
	}

	//inserting data
	if (value>root->data) 
	{
		//inserting right node data
		root->right=insert(root->right, value);
	}
	else if (value < root->data)
	{
		//inserting left node data
		root->left=insert(root->left, value);
	}

	//returning 'root' node, after insertion
	return root;
}

//inorder traversal function
//this gives data in sorted order
void bst ::inorder(bst* root)
{
	if (!root) 
	{
		return;
	}
	inorder(root->left);
	cout << root->data << endl;
	inorder(root->right);
}

int main()
{
	bst b, *root=NULL;
	root=b.insert(root, 50);
	b.insert(root, 30);
	b.insert(root, 20);
	b.insert(root, 40);
	b.insert(root, 70);
	b.insert(root, 60);
	b.insert(root, 80);

	b.inorder(root);
	return 0;
}

