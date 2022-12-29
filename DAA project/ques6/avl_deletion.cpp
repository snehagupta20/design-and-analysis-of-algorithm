//THIS CODE IS WRITEN BY SNEHA GUPTA
//2021UCA1859
//DAA PROJECT

#include<bits/stdc++.h>
using namespace std;

//AVL tree node:
class Node
{
	public:
	int key;
	Node *left;
	Node *right;
	int deapth;
};

// //function to get maximum of two integers
// int max(int a, int b);

//function to get deapth(height) of the tree
int deapth(Node *n)
{
	if(n==NULL)
    {
		return 0;
    }
	return n->deapth;
}

//function to get maximum of two integers
int get_max(int a,int b)
{
    int max;
    if(a < b)
    {
        max=a;
    }
    else{
        max=b;
    }

    return max;
}

// Helper function to allocate a new node with the given key 
Node* create_node(int key)
{
    //created a Node using dynamic memory allocation
	Node* node=new Node();

    //initialization

	node->key=key;
	node->left=NULL;
	node->right=NULL;
    //new node is initially added at leaf
	node->deapth=1; 

	return(node);
}

////function to right rotate the subtree in order to balance it
Node *r_rotate(Node *y)
{
	Node *x=y->left;
	Node *T2=x->right;

	//Performing rotation
	x->right=y;
	y->left=T2;

	//Updating heights
	y->deapth=get_max(deapth(y->left), deapth(y->right)) + 1;
	x->deapth=get_max(deapth(x->left), deapth(x->right)) + 1;

	//Returning new root
	return x;
}

////function to left rotate the subtree in order to balance it
Node *l_rotate(Node *x)
{
	Node *y=x->right;
	Node *T2=y->left;

	//Performing rotation
	y->left=x;
	x->right=T2;

	//Updating heights
	x->deapth=get_max(deapth(x->left), deapth(x->right)) + 1;
	y->deapth=get_max(deapth(y->left), deapth(y->right)) + 1;

	//Returning new root
	return y;
}

//Getting Balance factor of node n
int get_bf(Node *n)
{
    //base case
	if(n==NULL)
    {
		return 0;
    }

	return deapth(n->left)-deapth(n->right);
}


//recursive funtion to insert a key into the subtree
Node* insert(Node* node,int key)
{
    //performing normal bst insertion:
    if(node==NULL)
    {
        return(create_node(key));
    }

    if(key<node->key)
    {
        node->left=insert(node->left,key);
    }
    else if(key>node->key)
    {
        node->right=insert(node->right,key);
    }

    //equal keys are not allowed in bst
    else{
        return node;
    }


    //updating height of its ancestor node
    node->deapth=1+max(deapth(node->left),deapth(node->right));

    //getting balance factor of this ancestor node
    int bf=get_bf(node);


    //for when the node becomes unbalanced:

    //left left case
    if(bf>1 && key<node->left->key)
    {
        return r_rotate(node);
    }

    //right right case
    if(bf<-1 && key>node->right->key)
    {
        return l_rotate(node);
    }

    //left right case
    if(bf>1 && key>node->left->key)
    {
        node->left=l_rotate(node->left);
        return r_rotate(node);
    }

    //right left case
    if(bf<-1 && key<node->right->key)
    {
        node->right=r_rotate(node->right);
        return l_rotate(node);
    }

    //return unchanged node pointer
    return node;
}



Node * min_node(Node* node)
{
	Node* current=node;

	//looping down to find the leftmost leaf 
	while(current->left != NULL)
    {
		current=current->left;
    }

	return current;
}

//Recursive function to delete a node
Node* delete_node(Node* root, int key)
{
	
	//performing standard bst delete
	if(root==NULL)
    {
		return root;
    }

	//if the key to be deleted is smaller than the root's key, then it lies in left subtree
	if( key < root->key )
    {
		root->left=delete_node(root->left, key);
    }

	//if the key to be deleted is greater than the root's key, then it lies in right subtree
	else if( key > root->key )
    {
		root->right=delete_node(root->right, key);
    }

	//if key is same as root's key, then this is the node to be deleted
	else
	{
		//node with only one child or no child
		if((root->left==NULL) || (root->right==NULL))
		{
			Node *temp= root->left ?
					    root->left :
						root->right;

			//No child case
			if(temp==NULL)
			{
				temp=root;
				root=NULL;
			}
            //One child case
			else
			*root=*temp;
            //Copying the contents of the non-empty child
			free(temp);
		}
		else
		{
			//node with two children: Get the inorder successor
			Node* temp=min_node(root->right);

			//Copying the inorder successor's data to this node
			root->key=temp->key;

			//Deleting the inorder successor
			root->right=delete_node(root->right,temp->key);
		}
	}

	//if the tree had only one node then return
	if(root==NULL)
    {
	    return root;
    }

	//updating height of the current node:
	root->deapth=1 + get_max(deapth(root->left), deapth(root->right));

	//getting the balance factor of this node
	int balance=get_bf(root);

	//for when it becomes unbalanced:

	//left left Case
	if(balance > 1 && get_bf(root->left) >= 0)
    {
		return r_rotate(root);
    }

	//left right Case
	if(balance > 1 && get_bf(root->left) < 0)
	{
		root->left=l_rotate(root->left);
		return r_rotate(root);
	}

	//right right Case
	if(balance < -1 && get_bf(root->right) <= 0)
    {
		return l_rotate(root);
    }

	//right left Case
	if(balance < -1 && get_bf(root->right) > 0)
	{
		root->right=r_rotate(root->right);
		return l_rotate(root);
	}

	return root;
}

//function to print preorder traversal of the tree.
void preorder(Node *root)
{
	if(root != NULL)
	{
		cout<<root->key<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

int main()
{
    Node *root=NULL;


	root=insert(root, 9);
	root=insert(root, 5);
	root=insert(root, 10);
	root=insert(root, 0);
	root=insert(root, 6);
	root=insert(root, 11);
	root=insert(root, -1);
	root=insert(root, 1);
	root=insert(root, 2);



	cout << "Preorder traversal of the constructed AVL tree is "<<endl;
	preorder(root);

	root=delete_node(root, 10);


	cout <<endl<<"Preorder traversal after deletion of 10 "<<endl;
	preorder(root);

	return 0;
}

