#include <iostream>
#include <algorithm>

int water(int a[], int n)
{
  int res = 0;
  int r_max[n], l_max[n];

  l_max[0] = a[0]; //.           Pre-Computing L_Max
  for (int i = 1; i < n; i++)
    l_max[i] = std::max(a[i], l_max[i - 1]);

  r_max[n - 1] = a[n - 1]; //.           Pre-Computing R_Max
  for (int i = n - 2; i >= 0; i--)
    r_max[i] = std::max(a[i], r_max[i + 1]);

  for (int i = 1; i < n - 1; i++) //.             Corner element doesn't hold water
  {
    res += (std::min(l_max[i], r_max[i]) - a[i]);
  }
  return res;
}

using namespace std;

int main()
{
  int a[] = {5, 0, 6, 2, 3};
  int size = sizeof(a) / sizeof(int);

  cout<<water(a,size)<<endl;

  return 0;
}

// #include <iostream>
// using namespace std;

// int water(int a[], int size)
// {
//     int low = a[0], high, low_index = 0, high_index, area = 0, sum = low;

//     for (int i = 1; i < size; i++)
//     {
//         sum -= a[i];

//         if (a[i] > low)
//         {
//             low = a[i];
//             low_index = i;
//         }

//         if ((sum <= 0) && (a[i] != a[i - 1]))
//         {
//             high = a[i];
//             high_index = i;

//             for (int j = low_index + 1; j < high_index; j++)
//             {
//                 area += (low - a[j]);
//             }

//             low=high;
//             low_index=high_index;
//             sum=low;
//         }
//     }
//     return area;
// }

// int main()
// {
//     int a[] = {3, 0, 4, 2, 5};
//     int size = sizeof(a) / sizeof(int);

//     cout << water(a, size) << endl;
//     return 0;
// }