#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left = NULL, *right = NULL;
};

Node *root = NULL;

void insert(int key)
{
    Node *t = root;
    Node *p, *r; //.            r is tailing pointer of t

    if (root == NULL) //.                              First Node
    {
        p = new Node;
        p->data = key;
        p->left = p->right = NULL;
        root = p;
        return;
    }
    while (t != NULL)
    {
        r = t;
        if (key < t->data)
            t = t->left;
        else if (key > t->data)
            t = t->right;
        else //.                                If key is already present
            return;

        //.                 At the end r holds the value where new node should be inserted
    }

    p = new Node;
    p->data = key;
    p->left = p->right = NULL;

    if (key < r->data)
        r->left = p;
    else
        r->right = p;
}

void Inorder(Node *root) //.               It gives sorted order
{
    if (root == NULL)
        return;

    Inorder(root->left);
    cout << root->data << "\t";
    Inorder(root->right);
}

void Preorder(Node *root)
{
    if (root == NULL)
        return;

    cout << root->data << "\t";
    Preorder(root->left);
    Preorder(root->right);
}

Node *Search(int key)
{
    Node *t = root;

    while (t != NULL)
    {
        if (key == t->data) //.      Key found
            return t;
        else if (key < t->data)
            t = t->left;
        else
            t = t->right;
    }

    return NULL;
}

Node *Recurssive_Insert(Node *p, int key) //.             For delete function
{
    Node *temp = NULL;

    if (p == NULL) //.                 Base case
    {
        temp = new Node;
        temp->data = key;
        temp->left = temp->right = NULL;
        return temp;
    }

    if (key < p->data)
    {
        p->left = Recurssive_Insert(p->left, key);
    }
    else if (key > p->data)
    {
        p->right = Recurssive_Insert(p->right, key);
    }

    return p;
}

int height(Node *root)
{
    if (root == NULL)
        return 0;

    return (max(height(root->left), height(root->right)) + 1);
}

Node *inorder_Predecessor(Node *p)
{
    while (p && p->right != NULL)
        p = p->right;

    return p;
}

Node *inorder_Successor(Node *p)
{
    while (p && p->left != NULL)
        p = p->left;

    return p;
}

Node *Delete(Node *p, int key)
{
    Node *q;

    if (p == NULL)
        return NULL;

    if (p->left == NULL && p->right == NULL) //. if it is leaf node
    {
        if (p == root)
            root = NULL;
        delete p;
        return NULL;
    }

    if (key < p->data)
        p->left = Delete(p->left, key);
    else if (key > p->data)
        p->right = Delete(p->right, key);
    else //.        Key is found
    {
        if (height(p->left) > height(p->right))
        {
            q = inorder_Predecessor(p->left);
            p->data = q->data;
            p->left = Delete(p->left, q->data);
        }
        else
        {
            q = inorder_Successor(p->right);
            p->data = q->data;
            p->right = Delete(p->right, q->data);
        }
    }

    return p;
}

int main()

{
    // int arr[] = {20, 10, 2, 5, 11, 30, 25, 40, 35, 60, 50};

    // for (auto x : arr)
    //     insert(x);

    // Inorder(root);
    // cout << "\n\n";
    // Preorder(root);

    root = Recurssive_Insert(root, 10);
    Recurssive_Insert(root, 20);
    Recurssive_Insert(root, 2);
    Recurssive_Insert(root, 1);
    Recurssive_Insert(root, 50);
    Recurssive_Insert(root, 40);
    Recurssive_Insert(root, 60);

    Delete(root, 20);

    Node *t;
    t = Search(20);
    if (t)
        cout << "\nKey found ^_^" << endl;
    else
        cout << "\nKey not found -_- " << endl;

    return 0;
}