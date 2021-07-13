#include <iostream>
using namespace std;

void rotate(int arr[], int d, int size)
{
    int n = (d >= size) ? (n = d % size) : n = d;
    int index=size-d;

    int *temp = new int[n-1];

    for (int i = 0; i < n; i++) // .                    Copying element in temp array
        temp[i] = arr[i];

    for (int i = n; i <= size; i++) //.                     Copying element main array
        arr[i - n] = arr[i];


    for (int i = 0; i < n; i++)
    {
        arr[index] = temp[i];
        index++;
    }

    // for (int i = 0; i < size; i++)
    //     cout << arr[i] << endl;

    // for (int i = 0; i < n; i++)
    //     cout << temp[i] << endl;
    cout<<n<<endl;

    delete temp;
    temp=NULL;
}

int main()
{
    int a[6] = {1, 2, 3, 4, 5, 6};
    rotate(a, 8, 6);
    return 0;
}