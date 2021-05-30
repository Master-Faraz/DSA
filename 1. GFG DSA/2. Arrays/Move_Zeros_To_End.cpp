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
    int a[9] = {5, 0, 8, 9, 0, 0, 99, 22, 55}, count = 0;

    for (int i = 0; i < 9; i++)
    {
        if ((a[i] != 0)&&(i!=0))
        {
            swap(a[i], a[count]);
            count++;
        }
        else if ((a[i] != 0)&&(i==0))
        {
            count++;
        }
    }

    for (int i = 0; i < 9; i++)
    {
        cout << a[i] << endl;
    }

    return 0;
}