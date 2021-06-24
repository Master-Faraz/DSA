#include <iostream>
using namespace std;

void TOH(int n, string start, string aux, string end)
{
    if(n==1)
    {
        cout<<start<<"\t"<<end<<endl;
        return;
    }

    TOH(n - 1, start,end,aux);
    cout << start << "\t" << end << endl;
    TOH(n - 1, aux,start,end);
}

int main()
{
    string a = "A", b = "B", c = "C";
    TOH(3, a, b, c);
    return 0;
}