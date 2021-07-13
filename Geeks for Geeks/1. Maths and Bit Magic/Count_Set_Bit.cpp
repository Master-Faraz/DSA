#include <iostream>
using namespace std;

int bit(int n);

int count_Bit(int n);

int main()
{
    int n;
    cout << "Enter a number : " << endl;
    cin >> n;

    cout << count_Bit(n) << endl;

    return 0;
}

int bit(int n) //.                         Time complexity = O(n)
{
    int count = 0;
    while (n != 0)
    {
        if (n & 1 == 1)
            count++;

        n = (n >> 1);
    }
    return count;
}

int count_Bit(int n)
{
    int count = 0;

    while (n != 0)
    {
        n = (n & (n - 1));
        count++;
    }
    /*                       n=40   ->  101000
                             n=39   ->  100111
                    ( n & (n-1) )   ->  100000

    Here using AND operator of ( n & (n-1) ) set last ON bit to OFF
                            
                        
    */

    return count;
}