#include <iostream>
using namespace std;

int max_diff(int a[], int size) //.                 O(n^2)
{
    int diff = INT16_MIN;

    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if ((a[i] < a[j]) && ((a[j] - a[i]) > diff))
            {
                diff = a[j] - a[i];
            }
        }
    }

    return diff;
}

int maxDiff(int arr[], int arr_size) //.              O(n)
{



    // Maximum difference found so far
    int max_diff = arr[1] - arr[0];

    // Minimum number visited so far
    int min_element = arr[0];
    for (int i = 1; i < arr_size; i++)
    {
        if (arr[i] - min_element > max_diff)
            max_diff = arr[i] - min_element;

        if (arr[i] < min_element)
            min_element = arr[i];
    }

    return max_diff;
}

int main()
{
    int a[] = {2, 3, 10, 6, 4, 8, 1};
    int size = sizeof(a) / sizeof(int);

    cout << maxDiff(a, size) << endl;

    return 0;
}