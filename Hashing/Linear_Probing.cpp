//                                   Linear Probing of size 10
#include <iostream>
#define Size 10
using namespace std;

int Hash(int key)
{
    return (key % Size);
}

int probe(int h[], int key)
{
    int index = Hash(key);
    int i = 0;

    while (h[(index + i) % Size] != 0)
    {
        i++;
    }

    return (index + i) % Size;
}

void insert(int h[], int key)
{
    int index = Hash(key);

    if (h[index] != 0)
        index = probe(h, key);
    h[index] = key;
}

int search(int h[], int key)
{
    int index = Hash(key);
    int i = 0;

    while (h[(index + i) % Size] != key)
        i++;

    return (index + i) % Size;
}

int main()
{
    int h[10] = {0};

    insert(h,25);
    insert(h,35);
    insert(h,26);
    insert(h,12);

    return 0;
}