#include <iostream>
using namespace std;
int main()
{
    int x = 0, n, count = 0;
    cout << "Enter a number : " << endl;
    cin >> n;

    while (n != 0)
    {
        if (n & 1 == 1)
            count++;

        n = (n >> 1);
    }
    cout << count << endl;

    return 0;
}