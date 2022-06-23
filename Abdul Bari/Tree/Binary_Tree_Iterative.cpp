#include <iostream>
#include <stack>
#include <deque>

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
    stack<Node *> st; // .             It stores address of Node
    Node *t = root;

    while (t != NULL || st.empty() == false)
    {
        if (t != NULL)
        {
            st.push(t);
            t = t->left;
        }
        else
        {
            t = st.top();
            st.pop();

            cout << t->data << "\t";

            t = t->right;
        }
    }
    /*.                                     Procedure ^_^

    1> As it it iterative so we use loop
    2> Check if (t != NULL)   then   PUSH into stack and make t = t-> left
    3> Else make t = St.pop() and then print the data and move right

    */
}

void Preorder(Node *root) //.     Root -> Left -> Right
{
    stack<Node *> st;

    while (root != NULL || st.empty() == false)
    {
        if (root != NULL)
        {
            cout << root->data << "\t";
            st.push(root);
            root = root->left;
        }
        else
        {
            root = st.top();
            st.pop();

            root = root->right;
        }
    }
}

void Level_order(Node *root)
{
    deque<Node *> q;

    cout << root->data << "\t";
    q.push_back(root);

    while (q.empty() == false)
    {
        root = q.front();
        q.pop_front();

        if (root->left)
        {
            cout << root->left->data << "\t";
            q.push_back(root->left);
        }
        if (root->right)
        {
            cout << root->right->data << "\t";
            q.push_back(root->right);
        }
    }
}

int main()
{
    Node *root = NULL;

    root = Create();

    cout << "\n\n Level order Traversal \n"
         << endl;

    Level_order(root);

    return 0;
}