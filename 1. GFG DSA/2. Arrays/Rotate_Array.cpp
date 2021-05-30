#include <iostream>
using namespace std;

int main()
{
    int a[6] = {1, 2, 3, 4, 5, 6}, temp = a[0];

    for (int i=1; i < 6; i++)
    {
        a[i - 1] = a[i];
    }
    a[6-1] = temp;

    for (int i=0; i < 6; i++)
    {
        cout<<a[i]<<"\t";
    }

    return 0;
}