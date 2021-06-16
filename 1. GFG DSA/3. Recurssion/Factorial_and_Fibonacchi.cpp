#include <iostream>
using namespace std;

int fact(int n);
int fact_tail_recurssion(int n, int k);
int fibo(int n);

int main()
{
    // int n = 10;
    // cout << fact(5) << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << fibo(i) << "   ";
    // }

    cout<<fact_tail_recurssion(5,1)<<endl;

    return 0;
}

int fact(int n)
{
    if (n == 0)
        return 1;
    else
        return (n * fact(n - 1));
}

int fact_tail_recurssion(int n, int k)
{
    if (n == 0)
        return k;
    else
        return fact_tail_recurssion(n - 1, n * k);
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