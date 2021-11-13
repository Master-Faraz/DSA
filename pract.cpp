#include <iostream>
using namespace std;

void merge(int a[], int s1, int b[], int s2, int c[]);
void print(int a[], int size);
void merge_arr(int a[], int l, int m, int h);

int main()
{
  // int a[] = {1, 3, 5, 7, 9}, b[] = {2, 4, 6, 8, 10}, c[10];
  // int s1 = sizeof(a) / sizeof(int);
  // int s2 = sizeof(b) / sizeof(int);

  int a[] = {101, 2, 3, 88, 11, 55, 6};
  int s = sizeof(a) / sizeof(int);

  // merge(a, s1, b, s2, c);
  merge_arr(a,0,3,s-1);
  print(a, s);

  return 0;
}

void merge(int a[], int s1, int b[], int s2, int c[])
{
  int i = 0, j = 0, k = 0;

  while ((i < s1) && (j < s2))
  {
    if (a[i] < b[j])
    {
      c[k] = a[i];
      i++;
      k++;
    }
    else if (a[i] > b[j])
    {
      c[k] = b[j];
      j++;
      k++;
    }
    else if (a[i] = b[j])
    {
      c[k] = b[j];
      j++;
      k++;
      i++;
    }
  }
  while (i < s1)
  {
    c[k] = a[i];
    k++, i++;
  }
  while (j < s2)
  {
    c[k] = b[j];
    k++, j++;
  }
}

void print(int a[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << a[i] << endl;
  }
}

void merge_arr(int a[], int l, int m, int h)
{
  int i = l, j = m + 1, k;
  int b[h + 1];

  while ((i <= m) && (j <= h))
  {
    if (a[i] < a[j])
      b[k++] = a[i++];
    else if (a[i] == a[j])
    {
      b[k++] = a[j++];
      i++;
    }
    else
      b[k++] = a[j++];
  }

  while (i <= m)
  {
    b[k++] = a[i++];
  }
  while (j <= h)
  {
    b[k++] = a[j++];
  }

  for (i = l; i <= h; i++)
  {
    a[i] = b[i];
  }
}