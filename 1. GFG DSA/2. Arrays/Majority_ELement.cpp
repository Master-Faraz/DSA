#include <iostream>
using namespace std;

int maj_Neive(int a[], int size);
int Moors_Voting_Algorithm(int a[], int size);

int main()
{
    int a[] = {1,1,2,3,1};
    int size = sizeof(a) / sizeof(int);

    cout << Moors_Voting_Algorithm(a, size) << endl;
    ;
    return 0;
}

int maj_Neive(int a[], int size) //.                     O(n^2)
{
    int res = -1;

    for (int i = 0; i < size; i++)
    {
        int index = -1;
        int count = 0;

        for (int j = 0; j < size; j++)
        {
            if (a[i] == a[j])
            {
                count++;
                index = i;
            }

            if (count > (size / 2))
            {
                res = index;
            }
        }
    }
    return res;
}

int Moors_Voting_Algorithm(int a[], int size) //.               O(n)    O(1)
{
    int count = 1;
    int ans_index = 0;
    int temp_count = 0;

    for (int i = 1; i < size; i++) //.                 For finding number maj element
    {
        if (a[i] == a[ans_index])
            count++;
        else
            count--;

        if (count == 0)
        {
            ans_index = i;
            count = 1;
        }
    }

    for (int i = 0; i < size; i++) //.                     Checking if it exists (size / 2) times
    {
        if (a[i] == a[ans_index])
            temp_count++;
    }
    if (temp_count > (size / 2))
        return ans_index;
    else
        return -1;
}