#include <iostream>
#include <algorithm>
using namespace std;

int one(int a[], int size)
{
    int count = 0,temp=0;
    for (int i = 0; i < size; i++)
    {
        if (a[i] == 1 || ((a[i] == 1) && (a[i + 1] == 1)))
        {
            temp++;
            count= max(temp,count);
        }
        else if (a[i] != 1 && ((i + 1) != size))
            temp = 0;
    }
    return count;
}

int main()
{
    // int a[] = {0, 1, 1, 0, 1, 0};
    // int a[] = {1, 1, 1, 1, 1, 1};
    // int a[] = {0, 0, 0, 0};
    // int a[] = {0,1,1,0};
    int a[] = {0,1,1,0,1,1,1,1};
    int size = sizeof(a) / sizeof(int);

    cout << one(a, size) << endl;
    return 0;
}