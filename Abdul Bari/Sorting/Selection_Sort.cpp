#include <iostream>
#include <algorithm>
using namespace std;

void Insertion_Sort(int a[], int size) //.                      O( n^2 )
{
    for (int i = 0; i < size; i++)
    {
        int j, k;
        j = k = i;

        while (j < size)
        {
            if (a[j] < a[k])
            {
                k = j;
                j++;
            }
            else
                j++;
        }

        swap(a[i], a[k]);
    }
}

int main()
{
    int arr[] = {8,2,5,7,6};
    // int arr[] = {2, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(int);

    Insertion_Sort(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}