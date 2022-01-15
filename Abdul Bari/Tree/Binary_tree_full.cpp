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

int no_nodes(Node *root)
{
    if (root == NULL)
        return 0;

    return (1 + no_nodes(root->left) + no_nodes(root->right));
}

int height_of_binary_tree(Node *root)
{
    if (root == NULL)
        return 0;

    return (max(height_of_binary_tree(root->left), height_of_binary_tree(root->right)) + 1);
}

int Max_in_tree(Node *root)
{
    if (root == NULL)
        return -1;

    return (max(root->data, max(Max_in_tree(root->left), Max_in_tree(root->right))));
}

int no_Leaf_nodes(Node *root)
{
    int x, y;
    if (root != NULL)
    {
        x = no_Leaf_nodes(root->left);
        y = no_Leaf_nodes(root->right);

        if (root->left == NULL && root->right == NULL)
        {
            return (x + y + 1);
        }
        else
        {
            return (x + y);
        }
    }
    return 0;
}

int main()
{
    Node *root = NULL;

    root = Create();

    // cout<<"\n\n Inorder Traversal \n"<<endl;
    // Inorder(root);

    // cout << "\n\n Preorder Traversal \n"<< endl;
    // Preorder(root);

    // cout << "\n\n Postorder Traversal \n"<< endl;
    // Postorder(root);

    // cout << "\nNumbe rof nodes are \n"<< endl;
    // cout << no_nodes(root) << endl;

    // cout << "\n Height of binary tree \n"<< endl;
    // cout << height_of_binary_tree(root) << endl;

    // cout << "\n Max in binary tree \n"<< endl;
    // cout << Max_in_tree(root) << endl;

    cout << "\n Leaf nodes in binary tree \n"<< endl;
    cout << no_Leaf_nodes(root) << endl;

    return 0;
}