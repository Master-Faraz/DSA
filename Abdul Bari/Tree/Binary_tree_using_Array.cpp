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
    cout << "Enter data : ";
    cin >> x;

    if (x == 0)
    {
        return NULL;
    }

    t->data = x;

    cout << "Enter left for : " << x << endl;
    t->left = Create();

    cout << "Enter right for : " << x << endl;
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

void Preorder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << "\t";
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(Node *root)
{
    if (root == NULL)
        return;

    Preorder(root->left);
    Preorder(root->right);
    cout << root->data << "\t";
}

int size(Node *root)
{

}

int main()
{
    Node *root = NULL;

    root = Create();

    // cout<<"\n\n Inorder Traversal \n"<<endl;
    // Inorder(root);
    // cout << "\n\n Preorder Traversal \n"
    //      << endl;
    // Preorder(root);
    cout << "\n\n Postorder Traversal \n"
         << endl;
    Postorder(root);

    return 0;
}