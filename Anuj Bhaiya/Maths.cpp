#include <iostream>
using namespace std;

int fact(int n);
int fact_trailing_zeros(int n);
bool palindrome_number(int n);

int main()      
{
    // cout << fact(5) << endl;
    // cout << fact_trailing_zeros(12) << endl;
    // cout << palindrome_number(123) << endl;
    // cout << palindrome_number(1221) << endl;
    return 0;
}

//. ***********************************************************************************************

int fact(int n)
{
    int res = 1;

    for (int i = 1; i <= n; i++)
    {
        res *= i;
    }

    return res;
}

//. ********************************************************************************************

int fact_trailing_zeros(int n)
{
    int res = 0;

    for (int i = 5; i <= n; i *= 5)
    {
        res += n / i;
    }

    return res;
}

//. **********************************************************************************************

bool palindrome_number(int n)
{
    int num = n;
    int res = 0;
    while (n != 0)
    {
        res = res * 10 + (n % 10);
        n /= 10;
    }

    // cout<<res<<endl;

    if(res == num)
        return true;
    else
        return false;
}