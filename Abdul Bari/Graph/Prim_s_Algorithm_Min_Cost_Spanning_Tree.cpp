#include <iostream>
using namespace std;
int main()
{
    int arr[8][8] = {INT32_MAX}; //.        Maximum number so that it doesn't affect the algorithm
    arr[1][2] = arr[2][1] = 25;
    arr[2][3] = arr[3][2] = 12;
    arr[3][4] = arr[4][3] = 8;
    arr[4][5] = arr[5][4] = 16;
    arr[6][5] = arr[5][6] = 20;
    arr[6][1] = arr[1][6] = 5;
    arr[5][7] = arr[7][5] = 18;
    arr[4][7] = arr[7][4] = 14;
    arr[2][7] = arr[7][2] = 10;

    return 0;
}