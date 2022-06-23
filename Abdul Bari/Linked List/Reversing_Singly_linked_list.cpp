#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
};

Node *first = NULL, *res = NULL;

void create(int arr[], int size);
void display(Node *p);
// void reverse(Node *p);

int main()
{
    int arr[] = {1, 2, 3, 4, 5}, size = sizeof(arr) / sizeof(int);
    create(arr, size);
    // display(first);
    // reverse(first);
    display(first);

    return 0;
}

void create(int arr[], int size)
{
    Node *last;

    first = new Node;
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < size; i++)
    {
        Node *temp = new Node;
        temp->data = arr[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}

void display(Node *p)
{
    while (p)
    {
        cout << p->data << endl;
        p = p->next;
    }
}

// void reverse(Node *p)
// {


// }