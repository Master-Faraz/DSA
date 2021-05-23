#include <iostream>
using namespace std;

int check(int n);
int check_Set_Bit(int n);

int main()
{
    int n;
    cout << "Enter a number " << endl;
    cin >> n;
    cout << check_Set_Bit(n) << endl;
    return 0;
}

int check(int n) //.                 Dividing by 2 until number becomes 1   
{
    if (n == 0)
        return 1;
    else
    {
        while (n != 1)
        {
            if (n % 2 != 0)
                return 1;
            n = n / 2;
        }
        return 0; //.         0   ->  TRUE    ,   1   ->  FALSE
    }
}

int check_Set_Bit(int n)    //.             O(1)
{
    if(n==0)
        return 1;
    else if((n&(n-1))==0)
        return 0;
    else
        return 1;

    /*                  For number to be power of 2 ->  there will be only one setbit
        ex ->   8   ->  1000
                16  ->  10000
                32  ->  100000
    */
}