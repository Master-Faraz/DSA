#include <iostream>
#include <algorithm>
using namespace std;

void Bubble_Sort(int a[], int size) //.                      O( n^2 )
{
    int n = size - 1  , count =0;

    for (int i = 0; i < n ; i++)
    {
        int flag = 0;

        for (int j = 0; j < (n - i); j++) //.                 For every iteration j is decreased by n
        {
            count++;
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                flag = 1;
                
            }
        }
        if(flag == 0)    //.                            Flag is zero when program is already sorted
            break;
    }
    cout<<"***************\t"<<count<<"***************\t"<<endl;
}

int main()
{
    // int arr[] = {8, 5, 7, 3, 2};
    int arr[] = {2,3,5,7,8};
    Bubble_Sort(arr, 5);



    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}