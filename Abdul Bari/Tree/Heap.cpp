#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void insert(int arr[], int key, int i)
{
    arr[i] = key;
    while (i / 2 >= 1)
    {
        if (arr[i] > arr[i / 2])
        {
            swap(arr[i], arr[i / 2]);
        }

        i = i / 2;
    }
}

int main()
{
    int arr[9] = {0, 30, 20, 15, 5, 10, 12, 6};
    insert(arr, 40, 8);

    for (auto x : arr)
        cout << x << "\t";

    cout << endl;

    return 0;
}