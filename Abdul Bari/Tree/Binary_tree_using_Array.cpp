#include <iostream>
using namespace std;

struct Node
{
    Node *left, *right;
    int data;
};

Node *create_tree()
{
    Node *root = new Node;
    int data;

    cout << "Enter data " << endl;
    cin >> data;

    if (data == 0)
        return NULL;

    root->data = data;

    cout << "Enter left for : " << data << endl;
    root->left = create_tree();

    cout << "Enter right for : " << data << endl;
    root->left = create_tree();

    return root;
}

void Inorder(Node *root) //.        Left - Node - Right
{
    if (root == NULL)
        return;

    Inorder(root->left);
    cout << root->data << "\t";
    Inorder(root->right);
}

void printInorder(struct Node *node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    cout << node->data << " ";

    /* now recur on right child */
    printInorder(node->right);
}

int main()
{
    Node *root = create_tree();
    cout << "\n\nvalues are : ->\n"
         << endl;

    // Inorder(root);
    printInorder(root);
    return 0;
}