//THIS CODE IS WRITEN BY SNEHA GUPTA
//2021UCA1859
//DAA PROJECT

#include <iostream>
using namespace std;

//binary tree node has value, pointer to left child and a pointer to right child 
class node
{
    public:
	int value;
	node* left;
	node* right;
};

/*
    computing the height of a tree -- 
        the number of nodes along the longest path from the root node down to the farthest leaf node
*/
int height(node* node)
{
	if(node==NULL)
    {
		return 0;
    }
	else 
    {
		//computing the height of each subtree
		int lDepth=height(node->left);
		int rDepth=height(node->right);

		//using the larger one 
		if(lDepth > rDepth)
        {
			return (lDepth+1);
        }
		else
        {
			return (rDepth+1);
        }
	}
}

//function to allocate a new node with the given value and NULL left and right pointers
node* new_node(int value)
{
	node* Node=new node();
	Node->value=value;
	Node->left=NULL;
	Node->right=NULL;

	return (Node);
}

int main()
{
	node* root=new_node(28);

	root->left=new_node(28);
	root->right=new_node(38);
	root->left->left=new_node(93);
	root->left->right=new_node(38);

	cout<<"Height of tree is= "<<height(root);
	return 0;
}

