#include <iostream>
#include <string>
using namespace std;

bool anagram(string a, string b)        //.                 O(n)
{
    if (a.length() != b.length())
        return false;

    int count =0;

    for(int i=0;i<a.length();i++)
        count += a[i];

    for(int i=0;i<a.length();i++)
        count -= b[i];


    if(count !=0)
        return false;
    else
        return true;
}

int main()
{
    cout<<anagram("Faraz","Ali")<<endl;
    cout<<anagram("faraz","zaraf")<<endl;     //      1  --> True
    return 0;
}