//THIS CODE IS WRITEN BY SNEHA GUPTA
//2021UCA1859
//DAA PROJECT

#include <iostream>
#include <queue>
using namespace std;

enum COLOR{red,black};

class Node 
{
    public:
    int value;
    COLOR color;
    Node *left, *right, *parent;

    Node(int value):value(value)
    {
        parent=left=right=NULL;

        //node is created during insertion
        //node is red at insertion
        color=red;
    }

    //returns pointer to uncle
    Node *uncle() 
    {
        //if no parent or grandparent, then no uncle
        if(parent==NULL or parent->parent==NULL)
        return NULL;

        if(parent->is_left())
        {
            //uncle on right
            return parent->parent->right;
        }
        else
        {
            //uncle on left
            return parent->parent->left;
        }
    }

    //checking if node is left child of parent
    bool is_left()
    { 
        return this==parent->left;
    }

    //returning pointer to sibling
    Node *sibling() 
    {
        //sibling null if no parent
        if(parent==NULL)
        {
            return NULL;
        }

        if(is_left())
        {
            return parent->right;
        }

        return parent->left;
    }

    //moveing node down and given node in its place
    void down(Node *new_parent) 
    {
        if(parent !=NULL) 
        {
            if(is_left()) 
            {
                parent->left=new_parent;
            } 
            else 
            {
                parent->right=new_parent;
            }
        }
        new_parent->parent=parent;
        parent=new_parent;
    }

    bool hasRedChild() 
    {
        return (left != NULL and left->color==red) or (right != NULL and right->color==red);
    }
};

class red_blackt 
{
    Node *root;

    //left rotating the given node
    void left_rotate(Node *x) {
        //new parent will be node's right child
        Node *new_parent=x->right;

        //updating root if current node is root
        if(x==root)
        {
            root=new_parent;
        }

        x->down(new_parent);

        //connecting x with new parent's left element
        x->right=new_parent->left;

        //connecting new parent's left element with node if it is not null
        if(new_parent->left != NULL)
        {
            new_parent->left->parent=x;
        }

        //connecting new parent with x
        new_parent->left=x;
    }

    void right_rotate(Node *x) {
        //new parent will be node's left child
        Node *new_parent=x->left;

        //updating root if current node is root
        if(x==root)
        {
            root=new_parent;
        }

        x->down(new_parent);

        //connecting x with new parent's right element
        x->left=new_parent->right;

        //connecting new parent's right element with node if it is not null
        if(new_parent->right != NULL)
        new_parent->right->parent=x;

        //connect new parent with x
        new_parent->right=x;
    }

    void swap_colors(Node *x1, Node *x2) 
    {
        COLOR temp;
        temp=x1->color;
        x1->color=x2->color;
        x2->color=temp;
    }

    void swap_values(Node *u, Node *v) 
    {
        int temp;
        temp=u->value;
        u->value=v->value;
        v->value=temp;
    }

    //fixing red red at given node
    void fix_rr(Node *x) 
    {
        //if x is root color it black and then, return
        if(x==root) 
        {
            x->color=black;
            return;
        }

        //initializing parent, grandparent, uncle
        Node *parent=x->parent, *grandparent=parent->parent,
            *uncle=x->uncle();

        if(parent->color !=black) 
        {
            if(uncle !=NULL && uncle->color==red) 
            {
                //uncle red-> perform recoloring and recurse
                parent->color=black;
                uncle->color=black;
                grandparent->color=red;
                fix_rr(grandparent);
            } 
            else 
            {
                //else performing LR, LL, RL, RR
                if(parent->is_left()) 
                {
                    if(x->is_left()) 
                    {
                        //for left right
                        swap_colors(parent, grandparent);
                    } 
                    else 
                    {
                        left_rotate(parent);
                        swap_colors(x, grandparent);
                    }
                    //for left left and left right
                    right_rotate(grandparent);
                } 
                else 
                {
                    if(x->is_left()) 
                    {
                        //for right left
                        right_rotate(parent);
                        swap_colors(x, grandparent);
                    } 
                    else 
                    {
                        swap_colors(parent, grandparent);
                    }

                    //for right right and right left
                    left_rotate(grandparent);
                }
            }
        }
    }

    //finding node that does not have a left child in the subtree of the given node
    Node *successor(Node *x) 
    {
        Node *temp=x;
        while (temp->left != NULL)
        {
            temp=temp->left;
        }
        return temp;
    }

    //find node that replaces a deleted node in BST
    Node *bst_replace(Node *x) 
    {
        //when node have 2 children:

        if(x->left != NULL and x->right != NULL)
        {
            return successor(x->right);
        }

        //when node is a leaf
        if(x->left==NULL and x->right==NULL)
        {
            return NULL;
        }

        //when node is a single child
        if(x->left != NULL)
        {
            return x->left;
        }

        else{
            return x->right;
        }

    }

    //deleting the given node
    void delete_node(Node *v) 
    {
        Node *u=bst_replace(v);

        //true when u and v are both black
        bool uvBlack=((u==NULL or u->color==black) and (v->color==black));
        Node *parent=v->parent;

        if(u==NULL) 
        {
            //u is NULL therefore v is leaf
            if(v==root) 
            {
                //v is root, making root null
                root=NULL;
            } 
            else 
            {
                if(uvBlack) 
                {
                    //u and v both black
                    //v is leaf, fixing double black at v
                    fix_dblack(v);
                } 
                else 
                {
                    //u or v is red
                    if(v->sibling() != NULL)
                    {
                        //sibling is not null, making it red
                        v->sibling()->color=red;
                    }
                }

                //deleting v from the tree
                if(v->is_left()) 
                {
                    parent->left=NULL;
                } 
                else 
                {
                    parent->right=NULL; 
                }
            }
            delete v;
            return;
        }

        if(v->left==NULL or v->right==NULL) 
        {
            //v has 1 child:
            if(v==root) 
            {
                //if v is root, then assigning the value of u to v, and deleting u
                v->value=u->value;
                v->left=v->right=NULL;
                delete u;
            } 
            else 
            {
                //detach v from tree and move u up
                if(v->is_left()) 
                {
                    parent->left=u;
                } 
                else 
                {
                    parent->right=u;
                }
                delete v;
                u->parent=parent;
                if(uvBlack) 
                {
                    //u and v both black, fix double black at u
                    fix_dblack(u);
                } 
                else 
                {
                    //u or v red, color u black
                    u->color=black;
                }
            }
            return;
        }

        //v has 2 children, swap values with successor and recurse
        swap_values(u, v);
        delete_node(u);
    }

    void fix_dblack(Node *x) 
    {
        if(x==root)
        {
            //reached root
            return;
        }

        Node *sibling=x->sibling(), *parent=x->parent;
        if(sibling==NULL) 
        {
            //No sibiling, double black pushed up
            fix_dblack(parent);
        } 
        else 
        {
            if(sibling->color==red) 
            {
                //Sibling red
                parent->color=red;
                sibling->color=black;

                if(sibling->is_left()) 
                {
                    //left case
                    right_rotate(parent);
                } 
                else 
                {
                    //right case
                    left_rotate(parent);
                }

                fix_dblack(x);
            } 
            else 
            {
                //Sibling black
                if(sibling->hasRedChild()) 
                {
                    //at least 1 red children
                    if(sibling->left != NULL and sibling->left->color==red) 
                    {
                        if(sibling->is_left()) 
                        {
                            //left left
                            sibling->left->color=sibling->color;
                            sibling->color=parent->color;
                            right_rotate(parent);
                        } 
                        else 
                        {
                            //right left
                            sibling->left->color=parent->color;
                            right_rotate(sibling);
                            left_rotate(parent);
                        }
                    } 
                    else 
                    {
                        if(sibling->is_left()) 
                        {
                            //left right
                            sibling->right->color=parent->color;
                            left_rotate(sibling);
                            right_rotate(parent);
                        }
                        else 
                        {
                            //right right
                            sibling->right->color=sibling->color;
                            sibling->color=parent->color;
                            left_rotate(parent);
                        }
                    }
                    parent->color=black;
                } 
                else 
                {
                    //2 black children
                    sibling->color=red;
                    if(parent->color==black)
                    {
                        fix_dblack(parent);
                    }
                    else
                    {
                        parent->color=black;
                    }
                }
            }
        }
    }

    //printing level order for given node
    void levelorder(Node *x) 
    {
        if(x==NULL)
        {
            //return if node is null
            return;
        }

        //queue for level order
        queue<Node *> q;
        Node *curr;

        //push x
        q.push(x);

        while (!q.empty()) 
        {
            //while q is not empty
            //dequeue
            curr=q.front();
            q.pop();

            //print node value
            cout<<curr->value<<" ";

            //pushing children to queue
            if(curr->left != NULL)
            {
                q.push(curr->left);
            }

            if(curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }

    //printing inorder recursively
    void inorder(Node *x) 
    {
        if(x==NULL)
        {
            return;
        }

        inorder(x->left);
        cout<<x->value<<" ";
        inorder(x->right);
    }

    public:
    //constructor-> initializing root

    red_blackt() 
    { 
        root=NULL; 
    }

    Node *getRoot() 
    { 
        return root; 
    }

    //searcheing for given value-> if found, returning the node (used for delete)
    //else returning the last node while traversing (used in insert)
    Node *search(int n) 
    {
        Node *temp=root;
        while(temp != NULL) 
        {
            if(n < temp->value) 
            {
                if(temp->left==NULL)
                {
                    break;
                }
                else
                {
                    temp=temp->left;
                }
            } 
            else if(n==temp->value) 
            {
                break;
            } 
            else 
            {
                if(temp->right==NULL)
                break;
                else
                temp=temp->right;
            }
        }
        return temp;
    }

    //inserting the given value to tree
    void insert(int n) 
    {
        Node *new_node=new Node(n);
        if(root==NULL) 
        {
            //when root is null, simply inserting value at root
            new_node->color=black;
            root=new_node;
        } 
        else 
        {
            Node *temp=search(n);

            if(temp->value==n) 
            {
                //return if value already exists
                return;
            }

            //if value is not found, search returns the node where the value is to be inserted
            //connecting new node to correct node
            new_node->parent=temp;

            if(n < temp->value)
            {
                temp->left=new_node;
            }
            else
            {
                temp->right=new_node;
            }

            //fix red red voilaton if exists
            fix_rr(new_node);
        }
    }

    //utility function that deletes the node with given value
    void deleting_byvalue(int n) 
    {
        if(root==NULL)
        {
            //tree is empty
            return;
        }

        Node *v=search(n), *u;

        if(v->value != n) 
        {
            cout<<"No node found to delete with value:"<<n<<endl;
            return;
        }

        delete_node(v);
    }

    //printing inorder of the tree
    void printInOrder() 
    {
        cout<<"Inorder: "<<endl;
        if(root==NULL)
        {
            cout<<"Tree is empty"<<endl;
        }
        else
        {
            inorder(root);
        }
        cout<<endl;
    }

    //printing level order of the tree
    void printLevelOrder() 
    {
        cout<<"Level order: "<<endl;
        if(root==NULL)
        {
            cout<<"Tree is empty"<<endl;
        }
        else
        {
            levelorder(root);
        }
        cout<<endl;
    }
};

int main() 
{
    red_blackt tree;

    tree.insert(7);
    tree.insert(3);
    tree.insert(18);
    tree.insert(10);
    tree.insert(22);
    tree.insert(8);
    tree.insert(11);
    tree.insert(26);
    tree.insert(2);
    tree.insert(6);
    tree.insert(13);

    tree.printInOrder();
    tree.printLevelOrder();

    cout<<endl<<"Deleting 18, 11, 3, 10, 22"<<endl;

    tree.deleting_byvalue(18);
    tree.deleting_byvalue(11);
    tree.deleting_byvalue(3);
    tree.deleting_byvalue(10);
    tree.deleting_byvalue(22);

    tree.printInOrder();
    tree.printLevelOrder();
    return 0;
}
