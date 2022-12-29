//THIS CODE IS WRITEN BY SNEHA GUPTA
//2021UCA1859
//DAA PROJECT

#include <iostream>
using namespace std;

struct node 
{
	int key;
	struct node *left, *right;
};

//function to create a new bst node
struct node* new_node(int data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->key=data;
	temp->left=temp->right=NULL;
	return temp;
}

//inorder traversal of bst
void inorder(struct node* root)
{
	if(root != NULL) 
    {
		inorder(root->left);
		cout<<root->key;
		inorder(root->right);
	}
}

//function to insert a new node with given key in bst
struct node* insert(struct node* node, int key)
{
	//returning a new node for when tree is empty
	if(node==NULL)
    {
		return new_node(key);
    }

	//recuring down the tree 
	if(key < node->key)
    {
		node->left=insert(node->left, key);
    }
	else
    {
		node->right=insert(node->right, key);
    }

	//returning the unchanged node pointer
	return node;
}

//returning the node with minimum key value found in that tree
struct node* min_node(struct node* node)
{
	struct node* current=node;

	//looping down to find the leftmost leaf 
	while(current && current->left !=NULL)
    {
		current=current->left;
    }

	return current;
}

//deleteing the key and returning the new root:
struct node* delete_node(struct node* root, int key)
{
	//base case
	if(root==NULL)
    {
		return root;
    }

	//if the key to be deleted is smaller than the root's key, then it lies in left subtree
	if(key< root->key)
    {
		root->left=delete_node(root->left, key);
    }

	//if the key to be deleted is greater than the root's key, then it lies in right subtree
	else if(key > root->key)
    {
		root->right=delete_node(root->right, key);
    }

	//if key is same as root's key, then this is the node to be deleted
	else {
		//node has no child
		if(root->left==NULL and root->right==NULL)
        {
			return NULL;
        }
		
		//node with only one child or no child
		else if(root->left==NULL) 
        {
			struct node* temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL) \
        {
			struct node* temp=root->left;
			free(root);
			return temp;
		}

		//node with two children: getting the inorder successor
		struct node* temp=min_node(root->right);

		//copying the inorder successor's content to this node
		root->key=temp->key;

		//deleting the inorder successor
		root->right=delete_node(root->right, temp->key);
	}
	return root;
}

int main()
{

	struct node* root=NULL;

	root=insert(root, 37);
	root=insert(root, 59);
	root=insert(root, 58);
	root=insert(root, 69);
	root=insert(root, 30);
	root=insert(root, 88);
	root=insert(root, 29);

	cout<<"Inorder traversal of the given tree" <<endl;
	inorder(root);

	cout<<endl<<"Delete 20"<<endl;
	root=delete_node(root, 20);
	cout<<"Inorder traversal of the modified tree" <<endl;
	inorder(root);

	cout<<endl<<"Delete 30"<<endl;
	root=delete_node(root, 30);
	cout<<"Inorder traversal of the modified tree" <<endl;
	inorder(root);

	cout<<endl<<"Delete 50"<<endl;
	root=delete_node(root, 50);
	cout<<"Inorder traversal of the modified tree" <<endl;
	inorder(root);

	return 0;
}


