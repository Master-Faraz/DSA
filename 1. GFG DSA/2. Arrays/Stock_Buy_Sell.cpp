#include <iostream>
using namespace std;

int stock(int a[], int size)
{
    int profit = 0;

    for (int i = 1; i < size; i++)
    {
        if (a[i] > a[i - 1])
            profit += (a[i] - a[i - 1]);
    }
    return profit;
}

int main()
{
    int a[] = {1, 5, 3, 8, 12};
    int size = sizeof(a) / sizeof(int);

    cout << stock(a, size) << endl;

    return 0;
}