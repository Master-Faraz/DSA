#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *first = NULL;

//**************************************************************************************************************
void create_using_array(int arr[], int size);
void display(Node *temp);
void Recursive_display(Node *temp);

int Counting_Nodes(Node *t);
int Max_Element(Node *t);
int Min_Element(Node *t);
int Sum_Element(Node *t);
int Search(Node *t, int n);
void Swap(int &a, int &b);

void insert(Node *t, int key, int index);
void insert_last(Node *t, int key);
int delete_node(int index);

int Check_Sort();
void Selection_sort(Node *head);
void Bubble_sort(Node *head);
void Insertion_sort(Node *head);

//**************************************************************************************************************

int main()
{
    // int arr[5] = {1, 2, 3, 4, 5};
    // int size = sizeof(arr) / sizeof(int);
    // create_using_array(arr, size);

    // display(first);
    // Recursive_display(first);

    // cout<<Counting_Nodes(first)<<endl;
    // Max_Element(first);
    // Min_Element(first);
    // Sum_Element(first);

    // Search(first, 5);
    // Search(first, 6);

    insert(first, 100, 0);
    insert(first, 130, 1);
    insert(first, 45, 2);
    insert(first, 400, 3);

    insert_last(first, 169);
    insert_last(first, 49);

    // delete_node(0);
    // Check_Sort();
    
    // Bubble_sort(first);
    Insertion_sort(first);

    display(first);

    return 0;
}

//**************************************************************************************************************
void create_using_array(int arr[], int size)
{
    Node *last;

    first = new Node;
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < size; i++)
    {
        Node *temp; // Temp node for creating LL
        temp = new Node;
        temp->data = arr[i];
        temp->next = NULL;
        last->next = temp;

        last = temp;
    }
}

void display(Node *temp)
{
    int n = Counting_Nodes(temp);
    while (n--)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

void Recursive_display(Node *t)
{
    if (t->next == NULL)
    {
        return;
    }
    cout << t->data << endl;
    Recursive_display(t->next);
}

int Counting_Nodes(Node *t)
{
    int count = 0;
    while (t != 0)
    {
        count++;
        t = t->next;
    }
    return count;
}

int Max_Element(Node *t)
{
    int max = t->data;
    while (t->next != NULL)
    {
        if (t->data > max)
            max = t->data;

        t = t->next;
    }
    cout << "Maximim element is " << max << endl;
    return max;
}

int Min_Element(Node *t)
{
    int min = t->data;
    while (t->next != NULL)
    {
        if (t->data < min)
            min = t->data;

        t = t->next;
    }
    cout << "Maximim element is " << min << endl;
    return min;
}

int Sum_Element(Node *t)
{
    int sum = 0;
    while (t->next != NULL)
    {
        sum += t->data;
        t = t->next;
    }
    cout << "Sum of elements of linked list are " << sum << endl;
    return sum;
}

int Search(Node *t, int key)
{
    int index = 0;
    while (t->next != NULL)
    {
        if (t->data == key)
        {
            cout << "Key " << key << " is found at Index : " << index << endl;
            return index;
        }

        index++;
        t = t->next;
    }
    cout << "Key " << key << " is not present in linked list -_-" << endl;
    return -1;
}

void Swap(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

//**************************************************************************************************************

void insert(Node *t, int key, int index)
{
    int n = Counting_Nodes(t);
    Node *temp, *last, *head;
    temp = new Node;
    temp->data = key;
    temp->next = NULL;

    // if (index > n)
    // {
    //     cout << "Out of index " << endl;
    //     return;
    // }

    if (index == 0)
    {
        temp->next = first;
        first = temp;
    }
    else
    {
        head = first;
        for (int i = 0; i < index; i++)
        {
            last = head;
            head = head->next;
        }
        last->next = temp;
        temp->next = head;
    }
}

void insert_last(Node *t, int key)
{
    Node *temp = new Node;
    temp->data = key;
    temp->next = NULL;

    if (t == NULL)
    {
        first = temp;
    }
    else
    {
        while (t->next != 0)
        {
            t = t->next;
        }
        t->next = temp;
    }
}

int delete_node(int index)
{
    Node *tail, *last, *temp;
    int data;
    tail = first;

    if (first == NULL)
    {
        cout << "Linked List doesn't exist " << endl;
        return -100;
    }
    else if (index == 0)
    {
        last = tail;
        tail = tail->next;

        data = last->data;
        delete last;
        last = NULL;
        first = tail;
    }
    else
    {
        for (int i = 0; i < index; i++)
        {
            last = tail;
            tail = tail->next;
        }
        last->next = tail->next;
        tail->next = NULL;
        data = tail->data;
        delete tail;
        tail = NULL;
    }
    return data;
}

int Check_Sort()
{
    int n = first->data;
    while (first)
    {
        if (first->data < n)
        {
            cout << "Linked List is not sorted " << endl;
            return 0;
        }
        n = first->data;

        first = first->next;
    }
    cout << "Linked list is sorted" << endl;

    return 1;
}

void Selection_sort(Node *head) //.           O( n^2 )
{
    Node *ptr, *iter;
    ptr = head;

    while (ptr->next != NULL)
    {
        iter = ptr->next;
        while (iter != NULL)
        {
            if (ptr->data > iter->data)
            {
                int temp;
                temp = ptr->data;
                ptr->data = iter->data;
                iter->data = temp;
            }
            else
                iter = iter->next;
        }
        ptr = ptr->next;
    }
}

void Bubble_sort(Node *head)
{
    Node *end, *p, *q;

    for (end = NULL; end != head->next; end = p)
    {
        for (p = head; p->next != end; p = p->next)
        {
            q = p->next;
            if (p->data > q->data)
            {
                int temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
}

void Insertion_sort(Node *head)
{
    Node *j, *i, *last;

    for (i = head; i != NULL; i = i->next)
    {
        Node *temp;
        temp->data = i->data;
        temp->next = i->next;

        for (j = first; j != i->next; j = j->next)
        {
        }
    }
}