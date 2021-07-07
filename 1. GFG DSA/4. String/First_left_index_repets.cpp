#include <iostream>
#include <string>
using namespace std;

void repeats(string s)
{
    int arr[256] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        arr[s[i]]++;
        if (arr[s[i]] > 1)
        {
            cout << s[i] << endl;
            break;
        }
    }
}

int main()
{
    repeats("gfgasdf");
    return 0;
}