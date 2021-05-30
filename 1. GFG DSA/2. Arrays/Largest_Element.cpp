#include <iostream>
using namespace std;

int large(int a[], int size)
{
    int l = INT16_MIN;
    int index = 0;

    for (int i = 0; i < size; i++)
    {
        if (a[i] > l)
        {
            l = a[i];
            index = i;
        }
    }

    return index;
}

int large_element(int a[], int size)
{
    int l = INT16_MIN;

    for (int i = 0; i < size; i++)
    {
        if (a[i] > l)
            l = a[i];
    }

    return l;
}

int second_largest(int a[], int size)
{
    int l = INT16_MIN, index = -1;

    for (int i = 0; i < size; i++) //  Finding largest element
    {
        if (a[i] > l)
        {
            l = a[i];
        }
    }

    for (int i = 0; i < size; i++) //  Deleting largest element
    {
        if (a[i] == l)
        {
            a[i] = INT16_MIN;
        }
    }

    l = INT16_MIN;

    for (int i = 0; i < size; i++) //  Finding largest element again
    {
        if (a[i] > l)
        {
            l = a[i];
            index = i;
        }
    }

    return index;
}

int second_Largest_Updated(int a[], int size)
{
    int first = 0, second = 0, index = -1;

    first = large_element(a, size);

    for (int i = 0; i < size; i++)
    {
        if ((a[i] > second) && (a[i] != first))
        {
            second=a[i];
            index=i;
        }
    }
    return first;
}

int main()
{
    int a[] = {544, 5565, 6555, 599, 9};
    cout << large(a, 5) << endl;
    cout << second_largest(a, 5) << endl;
    cout << second_Largest_Updated(a, 5) << endl;
    return 0;
}