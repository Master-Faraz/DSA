#include <iostream>
using namespace std;

int water(int a[], int size)
{
    int low = a[0], high, low_index = 0, high_index, area = 0, sum = low;

    for (int i = 1; i < size; i++)
    {
        sum -= a[i];

        if (a[i] > low)
        {
            low = a[i];
            low_index = i;
        }
        
        if ((sum <= 0) && (a[i] != a[i - 1]))
        {
            high = a[i];
            high_index = i;
            for (int j = low_index + 1; j < high_index; j++)
            {
                area += (low - a[j]);
            }

            
            low=high;
            low_index=high_index;
            sum=low;
        }
    }
    return area;
}

int main()
{
    int a[] = {3, 0, 4, 2, 5};
    int size = sizeof(a) / sizeof(int);

    cout << water(a, size) << endl;
    return 0;
}