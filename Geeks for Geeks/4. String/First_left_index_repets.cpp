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

void non_repeats(string s) //.                   First non repeating charactor
{
    int arr[256] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        arr[s[i]]++;
    }

    for (int i = 0; i < s.length(); i++)
    {
        if ((arr[s[i]] == 1))
        {
            cout << s[i] << endl;
            break;
        }
    }
}

int main()
{
    // non_repeats("gfgsadf");
    cout<<("ab">"ba")<<endl;
    cout<<("ab"<"ba")<<endl;
    return 0;
}