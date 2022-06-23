#include <iostream>
#include <algorithm>
using namespace std;

int max_sum(int a[], int size)
{
    int last = a[0];
    int maxim = a[0];

    for (int i = 1; i < size; i++)
    {
        last = max((last + a[i]), a[i]);
        maxim = max(last, maxim);
    }

    return maxim;
}

int main()
{
    int a[] = {-3,8,-2,4,-5,6};
    int size = sizeof(a) / sizeof(int);

    cout << max_sum(a, size) << endl;

    return 0;
}