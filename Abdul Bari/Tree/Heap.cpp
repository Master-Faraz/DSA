#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int Size;

void insert(int arr[], int key)
{
    int i = Size;
    arr[i] = key;
    while (i > 0 && i / 2 >= 1)
    {
        if (arr[i] > arr[i / 2])
        {
            swap(arr[i], arr[i / 2]);
        }

        i = i / 2;
    }
    Size++;
}

int Delete(int arr[], int s)
{
    int x = arr[1];
    swap(arr[1], arr[s]);

    int i = 1, j = 2 * i; //.          i = Index , J = child

    while (j < s - 1)
    {
        if (arr[j + 1] > arr[j]) //.      Checking max child
            j = j + 1;
        if (arr[i] < arr[j]) //.     Comparing max child with root element
        {
            swap(arr[i], arr[j]);
            i = j;
            j = 2 * i;
        }
        else
            break;
    }

    return x;
}

void Heap_Sort(int arr[], int size)
{
    for (int i = size - 1; i > 0; i--)
        Delete(arr, i);
}

int main()
{

    int arr[8] = {0};
    // Size = 0;
    Size++;

    insert(arr, 50);
    insert(arr, 35);
    insert(arr, 30);
    insert(arr, 15);
    insert(arr, 10);
    insert(arr, 25);
    insert(arr, 5);

    // cout<<Delete(arr, 7)<<endl;
    Heap_Sort(arr, Size);

    for (auto x : arr)
        cout << x << "\t";

    // cout << Size << endl;

    cout << endl;

    return 0;
}