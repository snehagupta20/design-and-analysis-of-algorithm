//THIS CODE IS WRITEN BY SNEHA GUPTA
//2021UCA1859
//DAA PROJECT

#include<iostream>
using namespace std;

//introducing AVL tree Node
class Node
{
    public:
    int key;
    Node *left;
    Node *right;

    //to get the balance factor, we need deapth (height)
    int deapth;
};

//function to get the deapth(height) of the tree
int deapth(Node *n)
{
    //base case:
    if(n==NULL)
    {
        return 0;
    }

    //else:
    return n->deapth;
}

//function to get maximum of two integers
int get_max(int a,int b)
{
    int max;
    if(a < b)
    {
        max = a;
    }
    else{
        max = b;
    }

    return max;
}

//helper function to create a new Node with the given key 
Node* createnode(int key)
{
    //created a Node using dynamic memory allocation
    Node* node=new Node();

    //initializing

    node->key=key;
    node->left=NULL;
    node->right=NULL;
    //new node is added as leaf node and its height is 1, and height will get incremented as we add new nodes.
    node->deapth=1;

    return(node);
} 

//function to right rotate the subtree in order to balance it
Node *r_rotate(Node *y)
{
    Node *x=y->right;
    Node *T2=x->left;

    //performing rotation
    y->left=T2;
    x->right=y;

    //updating height
    x->deapth=max(deapth(x->left), deapth(x->right)) +1;

    y->deapth=max(deapth(y->left),deapth(y->right))+1;

    //returning new root
    return x;
}


//function to left rotate the subtree in order to balance it
Node *l_rotate(Node *x)
{
    Node *y=x->right;
    Node *T2=y->left;

    //performing rotation
    y->left=x;
    x->right=T2;

    //updating height
    x->deapth=max(deapth(x->left), deapth(x->right)) +1;

    y->deapth=max(deapth(y->left),deapth(y->right))+1;

    //returning new root
    return y;
}

//getting balance factor
int get_bf(Node *n)
{
    //base case;
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
        return(createnode(key));
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

//function to print preorder traversal of the tree to show that insertion has been successfull.
void preorder(Node *root)
{
    if(root!=NULL)
    {
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}





int main()
{
    Node *root=NULL;

    //inserting 
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,4);
    root=insert(root,5);
    root=insert(root,6);

    cout<<"preorder traversal of the constructed AVL tree is:"<<endl;
    preorder(root);

    return 0;
}