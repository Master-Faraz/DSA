#include <iostream>
#include <algorithm>
using namespace std;

void Insertion_Sort(int a[], int size) //.                      O( n )
{
    for (int i = 1; i < size; i++)
    {
        int j = i - 1;
        int x = a[i];

        while ((j > -1) && (x < a[j]))
        {
            a[j + 1] = a[j]; //.             Shifting the element
            j--;
        }

        a[j + 1] = x; //.                  When location is found
    }
}

int main()
{
    int arr[] = {8,2,5,7,6};
    // int arr[] = {2,5,6,7,8};
    int size = sizeof(arr) / sizeof(int);

    Insertion_Sort(arr , size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}