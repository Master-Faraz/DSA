#include <iostream>
using namespace std;

void leaders(int a[], int size) //.                O( n^2 )
{

    for (int i = 0; i < size; i++)
    {
        bool cond = false;
        for (int j = (i + 1); j < size; j++)
        {
            if (a[i] <= a[j])
            {
                cond = true;
                break;
            }
        }

        if (cond == false)
            cout << a[i] << endl;
    }
}

void leaders_1(int a[], int size) //.                     O( n )
{
    int l = a[size - 1];
    cout<<l<<endl;
    for (int i = size - 2; i >= 0; i--)
    {
        if (a[i] > l)
        {
            cout << a[i]<<endl;
            l=a[i];
        }
    }
}

int main()
{
    int a[] = {7, 10, 4, 10, 6, 5, 2};
    int size = sizeof(a) / sizeof(int);

    leaders_1(a, size);
    return 0;
}