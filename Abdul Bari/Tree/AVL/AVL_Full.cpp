#include <iostream>
using namespace std;

struct Node
{
    int data, height;
    Node *right = NULL, *left = NULL;
};
Node *root = NULL;

int height_node(Node *p)
{
    int hl, hr;                              //. height left and right
    hl = p && p->left ? p->left->height : 0; //.      If p and p->left != NULL
    hr = p && p->right ? p->right->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

int bf(Node *p) //.  balance_factor
{
    int hl, hr;
    hl = p && p->left ? p->left->height : 0;
    hr = p && p->right ? p->right->height : 0;

    return hl - hr;
}

Node *LL_rotation(Node *p)
{
    Node *pl = p->left;
    Node *plr = p->right;

    pl->right = p;
    p->left = plr;
    p->height = height_node(p);
    pl->height = height_node(pl);

    if (root == p)
        root = pl;

    return pl;
}

Node *RR_rotation(Node *p)
{
    Node *pr = p->right;
    Node *prl = pr->left;

    pr->left = p;
    p->right = prl;
    p->height = height_node(p);
    pr->height = height_node(pr);

    if (root == p)
        root = pr;

    return pr;
}

Node *LR_rotation(Node *p)
{
    Node *pl = p->left;
    Node *plr = pl->right;

    pl->right = plr->left;
    p->left = plr->right;

    plr->left = pl;
    plr->right = p;

    pl->height = height_node(pl);
    plr->height = height_node(plr);
    p->height = height_node(p);

    if (root == p)
        root = plr;

    return plr; //.     Root
}

Node *RL_rotation(Node *p)
{
    Node *pr = p->right;
    Node *prl = pr->left;

    pr->left = prl->right;
    p->right = prl->left;

    prl->right = pr;
    prl->left = p;

    pr->height = height_node(pr);
    prl->height = height_node(prl);
    p->height = height_node(p);

    if (root == p)
        root = prl;

    return prl; //.     Root
}

Node *Insert(Node *p, int key)
{
    Node *temp = NULL;

    if (p == NULL) //.                 Base case
    {
        temp = new Node;
        temp->data = key;
        temp->height = 1;
        temp->left = temp->right = NULL;
        return temp;
    }

    if (key < p->data)
    {
        p->left = Insert(p->left, key);
    }
    else if (key > p->data)
    {
        p->right = Insert(p->right, key);
    }

    p->height = height_node(p);

    //. Performing Rotation based on BF

    if (bf(p) == 2 && bf(p->left) == 1)
        return LL_rotation(p);
    else if (bf(p) == 2 && bf(p->left) == -1)
        return LR_rotation(p);
    else if (bf(p) == -2 && bf(p->right) == -1)
        return RR_rotation(p);
    else if (bf(p) == -2 && bf(p->right) == 1)
        return RL_rotation(p);
    return p;
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

int main()
{
    root = Insert(root, 10);
    Insert(root, 30);
    Insert(root, 20);

    Preorder(root);

    return 0;
}