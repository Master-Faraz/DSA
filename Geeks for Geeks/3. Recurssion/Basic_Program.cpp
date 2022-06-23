#include <iostream>
#include <algorithm>
using namespace std;

// int printing_reverse(int n)   //.               Tail Recurssion
// {
//     if (n == 0)
//         return 0;
//     else
//     {
//         cout << n << "  ";
//         printing_reverse(n - 1);
//     }
// }

// int printing_forward(int n)
// {
//     if (n == 0)
//         return 0;
//     else
//     {
//         printing_forward(n - 1);
//         cout << n << "  ";
//     }
// }

// bool palindrome(string s, int i, int f)
// {
//     if (s[i] != s[f])
//         return false;
//     else if ((i > f)||(i==f))
//         return true;
//     else
//         return palindrome(s,i+1,f-1);
// }

int sum_of_digits(int n)
{
    if (n == 0)
        return 0;
    else
        return (n % 10 + sum_of_digits(n / 10));
}
// int sum_of_digits_Iterative(int n, int size)
// {
//     int total = 0;
//     for (int i = 0; i < size; i++)
//     {
//         total += (n % 10);
//         n = n / 10;
//     }
//     return total;
// }

int rope(int n, int a, int b, int c)
{
    int final = INT16_MIN, mini = INT16_MIN;
    int counter=1;

    if ((n % a == 0) && (n / a > mini))
    {
        final = a;
        mini = n/a;
        counter=1;
    }
    if ((n % b == 0) && (n / b > mini))
    {
        final = b;
        mini = n/b;
        counter=1;
    }
    if ((n % c == 0) && (n / c > mini))
    {
        final = c;
        mini = n/c;
        counter=1;
    }
    if ((n % (a + b) == 0) && (n / (a + b) > mini))
    {
        final = (a + b);
        mini = n/(a + b);
        counter=2;
    }
    if ((n % (c + b) == 0) && (n / (c + b) > mini))
    {
        final = (c + b);
        mini = n/(c + b);
        counter=2;
    }
    if ((n % (a + c) == 0) && (n / (a + c) > mini))
    {
        final = (a + c);
        mini = n/(a + c);
        counter=2;
    }
    if ((n % (a + c + b) == 0) && (n / (a + c + b) > mini))
    {
        final = (a + c + b);
        mini = n/(a + c + b);
        counter=3;
    }

    if(final==INT16_MIN)
        return -1;

    return (n/final * counter);
}

int main()
{
    // printing_forward(5);
    // printing_reverse(5);
    // cout<<palindrome("naman",0,4)<<endl;
    // cout<<palindrome("nammn",0,4)<<endl;
    // cout<<sum_of_digits(123)<<endl;
    cout<<rope(5,2,5,1)<<endl;
    cout<<rope(23,12,9,11)<<endl;
    cout<<rope(5,4,2,6)<<endl;

    return 0;
}