//THIS CODE IS WRITEN BY SNEHA GUPTA
//2021UCA1859
//DAA PROJECT

#include <bits/stdc++.h>
using namespace std;
 
enum color{red, black};
 
struct Node
{
    int data;
    bool color;
    Node *left, *right, *parent;
 
    // constructor
    Node(int data)
    {
       this->data=data;
       left=right=parent=NULL;
       this->color=red;
    }
};
 
//class to represent red Black tree
class rb_tree
{
    private:
    Node *root;


    protected:
    void r_left(Node *&, Node *&);
    void r_right(Node *&, Node *&);
    void fix_violations(Node *&, Node *&);


    public:
    // constructor
    rb_tree() { root=NULL; }
    void insert(const int &n);
    void inorder();
    void levelorder();
};
 
//recursive function to do inorder traversal
void inorder_helper(Node *root)
{
    //base case
    if(root==NULL)
    {
        return;
    }

    inorder_helper(root->left);
    cout<<root->data<<"  ";
    inorder_helper(root->right);
}
 
//function to insert a new node with given key in BSt 
Node* bst_insert(Node* root,Node *pointer)
{
    //returning a new node for when tree is empty
    if(root==NULL)
    {
       return pointer;
    }
 
    //Otherwise, recuring down the tree 
    if(pointer->data < root->data)
    {
        root->left=bst_insert(root->left,pointer);
        root->left->parent=root;
    }
    else if(pointer->data > root->data)
    {
        root->right=bst_insert(root->right,pointer);
        root->right->parent=root;
    }
 
    //returning the unchanged node pointer:
    return root;
}
 
//function to do level order traversal:
void levelorder_helper(Node *root)
{
    if(root==NULL)
    {
        return;
    }
 
    std::queue<Node *> q;
    q.push(root);
 
    while(!q.empty())
    {
        Node *temp=q.front();
        cout<<temp->data<<"  ";
        q.pop();
 
        if(temp->left !=NULL)
        {
            q.push(temp->left);
        }
 
        if(temp->right !=NULL)
        {
            q.push(temp->right);
        }
    }
}
 
void rb_tree::r_left(Node *&root,Node *&pointer)
{
    Node *pt_right=pointer->right;
    pointer->right=pt_right->left;
 
    if(pointer->right !=NULL)
    {
        pointer->right->parent=pointer;
    }
 
    pt_right->parent=pointer->parent;
 
    if(pointer->parent==NULL)
    {
        root=pt_right;
    }
 
    else if(pointer==pointer->parent->left)
    {
        pointer->parent->left=pt_right;
    }
 
    else{
        pointer->parent->right=pt_right;
    }
 
    pt_right->left=pointer;
    pointer->parent=pt_right;
}
 

//rotation right
void rb_tree::r_right(Node *&root,Node *&pointer)
{
    Node *pt_left=pointer->left;
 
    pointer->left=pt_left->right;
 
    if(pointer->left !=NULL)
    {
        pointer->left->parent=pointer;
    }
 
    pt_left->parent=pointer->parent;
 
    if(pointer->parent==NULL)
    {
        root=pt_left;
    }
 
    else if(pointer==pointer->parent->left)
    {
        pointer->parent->left=pt_left;
    }
 
    else{
        pointer->parent->right=pt_left;
    }
 
    pt_left->right=pointer;
    pointer->parent=pt_left;
}
 
//function to fix violations caused by bst insertion
void rb_tree::fix_violations(Node *&root,Node *&pointer)
{
    Node *parent_pt=NULL;
    Node *grand_parent_pt=NULL;
 
    while((pointer!=root) && (pointer->color!=black) && (pointer->parent->color==red))
    {
        parent_pt=pointer->parent;
        grand_parent_pt=pointer->parent->parent;
 
        /*  
            case : A
            parent of pointer is left child of grandparent of pointer 
        */
        if(parent_pt==grand_parent_pt->left)
        {
 
            Node *uncle_pt=grand_parent_pt->right;
 
            /* 
                case : 1
                the uncle of pointer is also red->only recoloring required
            */
            if(uncle_pt!=NULL && uncle_pt->color==red)
            {
                grand_parent_pt->color=red;
                parent_pt->color=black;
                uncle_pt->color=black;
                pointer=grand_parent_pt;
            }
 
            else
            {
                /* 
                    case : 2
                    pointer is right child of its parent->left-rotation required 
                */
                if(pointer==parent_pt->right)
                {
                    r_left(root, parent_pt);
                    pointer=parent_pt;
                    parent_pt=pointer->parent;
                }
 
                /* 
                    case : 3
                    pointer is left child of its parent->right-rotation required 
                */
                r_right(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pointer=parent_pt;
            }
        }
 
        /* 
            case : B
            parent of pointer is right child of grand-parent of pointer 
        */

        else
        {
            Node *uncle_pt=grand_parent_pt->left;
 
            /*  
                case : 1
                the uncle of pointer is also red-> only recoloring required 
            */
            if((uncle_pt!=NULL) && (uncle_pt->color==red))
            {
                grand_parent_pt->color=red;
                parent_pt->color=black;
                uncle_pt->color=black;
                pointer=grand_parent_pt;
            }
            else
            {
                /* 
                    case : 2
                    pointer is left child of its parent-> right-rotation required 
                */
                if(pointer==parent_pt->left)
                {
                    r_right(root, parent_pt);
                    pointer=parent_pt;
                    parent_pt=pointer->parent;
                }
 
                /* 
                    case : 3
                    pointer is right child of its parent-> left-rotation required 
                */
                r_left(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pointer=parent_pt;
            }
        }
    }
 
    root->color=black;
}
 
//function to insert a new node with given data
void rb_tree::insert(const int &data)
{
    Node *pointer=new Node(data);
 
    //normal bst insert
    root=bst_insert(root, pointer);
 
    //fixing red Black tree violations
    fix_violations(root, pointer);
}
 
//function to do inorder and level order traversals
void rb_tree::inorder()     { inorder_helper(root);}
void rb_tree::levelorder()  { levelorder_helper(root); }
 






int main()
{
    rb_tree tree;
 
    tree.insert(24);
    tree.insert(678);
    tree.insert(45);
    tree.insert(38);
    tree.insert(47);
    tree.insert(847);
    tree.insert(920);
 
    cout<<"inorder traversal of created tree= "<<endl;
    tree.inorder();
 
    cout<<endl<<endl<<"level Order traversal of created tree= "<<endl;
    tree.levelorder();
 
    return 0;
}