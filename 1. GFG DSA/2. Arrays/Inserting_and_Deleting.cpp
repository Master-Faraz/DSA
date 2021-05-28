#include <iostream>
using namespace std;

int *insert(int a[], int n, int pos, int last, int size)
{

  int index = pos - 1;

  if (last == size)
    return 0;
  for (int i = last - 1; i >= index; i--)
  {
    if (i == index)
      a[i] = n;

    else
    {
      a[last + 1] = a[last];
      last = last - 1;
    }
  }

  return a;
}

int main()
{
  int a[5] = {1, 2, 3, 5};
  // int *x=NULL;

  // x=insert(a,5,4,4,5);
  // cout<<x<<endl;

  int pos = 4, index = 4, last = 4, size = 5, n = 5;
  index = pos - 1;

  if (last == size)
    cout << "Not possible" << endl;
  for (int i = last - 1; i >= index; i--)
  {
    if (i == index)
      a[i] = n;

    else
    {
      a[last + 1] = a[last];
      last = last - 1;
    }
  }

  for (int i = 0; i < 5; i++)
  {
    cout << a[i] << endl;
  }

  return 0;
}