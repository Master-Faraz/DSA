#include <iostream>
using namespace std;

int fact(int n);
int fibo(int n);

int main()
{
    int n = 10;
    // cout << fact(5) << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << fibo(i) << "   ";
    }

    return 0;
}

int fact(int n)
{
    if (n == 0)
        return 1;
    else
        return (n * fact(n - 1));
}

int fibo(int n)
{
    if (n == 1)
        return 0;
    else if (n == 2)
        return 1;
    else if (n > 2)
    {
        return (fibo(n - 1) + fibo(n - 2));
    }
}