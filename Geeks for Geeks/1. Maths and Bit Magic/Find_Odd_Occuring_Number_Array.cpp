#include <iostream>
#include <algorithm>
using namespace std;

void Neive_Solution(int A[]);

void XOR(int A[]);

int main()
{
    int A[] = {4, 3, 4, 4, 4, 5, 5};

    // Neive_Solution(A);
    // XOR(A);

    //.         ******      My Algorithm        ******

    int count = 0, size = (sizeof(A) / sizeof(int));

    sort(A, A + size);
    for(int i=0;i<size;i++)
    {
        cout<<A[i]<<"\t";
    }

    return 0;
}

void Neive_Solution(int A[]) //.                 O( n^2 )
{
    int size = 7;

    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            if (A[j] == A[i])
                count++;
        }
        if (count % 2 != 0)
            cout << A[i] << endl;
    }
}

void XOR(int A[]) //.         O(1)        ->      works only when one number is occuring odd times
{
    int count = 0, size = 7;
    for (int i = 0; i < size; i++)
        count = (count ^ A[i]);
    cout << count << endl;
}
