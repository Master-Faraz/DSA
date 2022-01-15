#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left = NULL, *right = NULL;
};

Node *Create()
{
    Node *p = new Node;

    int x;
    cout << "Enter data : ";
    cin >> x;

    if (x == 0)
    {
        return NULL;
    }

    p->data = x;

    cout << "Enter left for : " << x << endl;
    p->left = Create();

    cout << "Enter right for : " << x << endl;
    p->left = Create();

    return p;
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
   // cout << "\n\n\n";

    Inorder(root);

    return 0;
}