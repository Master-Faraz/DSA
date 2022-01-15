#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left = NULL, *right = NULL;
};

Node *Create()
{
    Node *t = new Node;

    int x;
    cout << "Enter data of Node ( or Enter 0 for no node ) :  ";
    cin >> x;

    if (x == 0)
    {
        return NULL;
    }

    t->data = x;

    cout << "Enter left child of " << x << endl;
    t->left = Create();
    
    cout << "Enter right child of " << x << endl;
    t->right = Create();

    return t;
}

void Inorder(Node *root) //.        Left - Node - Right
{
    if (root == NULL)
        return;

    Inorder(root->left);
    cout << root->data << "\t";
    Inorder(root->right);

    return;
}

int main()
{
    Node *root = NULL;

    root = Create();

    cout<<"\n\n Inorder Traversal \n"<<endl;

    Inorder(root);

    return 0;
}