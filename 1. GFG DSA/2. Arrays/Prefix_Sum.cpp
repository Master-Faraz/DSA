#include <iostream>
using namespace std;

int prefix_brute_force(int a[], int size, int l, int r);

int main()
{
    int a[] = {2, 3, 10, 6, 4, 8, 1};
    int size = sizeof(a) / sizeof(int);

    int l = 2, r = 5;

    cout << prefix_brute_force(a, size, l, r) << endl;

    return 0;
}

int prefix_brute_force(int a[], int size, int l, int r)
{
    int sum = 0;
    for (int i = l; i <= r; i++)
    {
        sum += a[i];
    }
    return sum;
}
