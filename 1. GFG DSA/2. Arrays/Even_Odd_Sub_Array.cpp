#include <iostream>
#include <algorithm>
using namespace std;

int max_sum(int a[], int size)
{
    int count = 1;
    int curr = 1;

    for (int i = 1; i < size ; i++)
    {
        int j = i - 1, x, y;

        x = a[i];
        y = a[j];

        if (((a[i] % 2 == 0) && (a[j] % 2 == 1)) || ((a[i] % 2 == 1) && (a[j] % 2 == 0)))
        {
            curr++;
            count = max(count, curr);
        }
        else
            curr = 1;
    }

    return count;
}

int main()
{
    // int a[] = {5, 10, 20, 6, 3, 8};
    int a[] = {5, 2, 7, 6, 6, 6};
    int size = sizeof(a) / sizeof(int);

    cout << max_sum(a, size) << endl;

    return 0;
}