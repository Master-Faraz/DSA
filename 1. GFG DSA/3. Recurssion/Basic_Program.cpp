#include <iostream>
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

bool palindrome(string s, int i, int f)
{
    if (s[i] != s[f])
        return false;
    else if (i > f)
        return true;
    else
        return palindrome(s,i+1,f-1);
}

int main()
{
    // printing_forward(5);
    // printing_reverse(5);
    cout<<palindrome("naman",0,4)<<endl;
    cout<<palindrome("nammn",0,4)<<endl;
    return 0;
}