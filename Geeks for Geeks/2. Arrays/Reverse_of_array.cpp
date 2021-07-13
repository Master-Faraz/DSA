#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main()
{
    int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};

    for(int i=0,j=7;i<j;i++,j--)
    {
        swap(a[i],a[j]);
    }

    for(int i=0;i<8;i++)
        cout<<a[i]<<"\t";

    return 0;
}