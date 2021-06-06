#include <iostream>
using namespace std;

int fun(int a[], int size)
{
    int small = a[0], large = a[1], diff = 0;

    for (int i = 0; i < size; i++)
    {
        if (a[i] > large)
            large = a[i];
        else if (a[i] < small)
            small = a[i];

        if (a[i] == small)
            diff += diff;
            
        if ((large - small) > diff)
            diff += (large - small);
    }

    return diff;
}

int main()
{
    // int a[] = {1, 5, 3, 8, 12};
    // int size = sizeof(a) / sizeof(int);

    // int a[] = {10, 20, 30};
    // int size = sizeof(a) / sizeof(int);

    int a[] = {10, 20, 30};
    int size = sizeof(a) / sizeof(int);

    cout << fun(a, size) << endl;

    return 0;
}