#include <iostream>
using namespace std;

void Neive_Solution(int A[]);

int main()
{
    int A[] = {4, 3, 4, 4, 4, 5, 5};
    Neive_Solution(A);
    return 0;
}

void Neive_Solution(int A[])
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