#include <iostream>
#include <list>
// #include<bits/c++.h>
using namespace std;

struct my_hash //                             Using Dobuly linked list
{
    int bucket;       //                         array size
    list<int> *table; //                     linked list

    my_hash(int b) //                      initializing array of linked list
    {
        bucket = b;
        table = new list<int>[bucket]; //.                             Table is array of linked list
    }

    int hash(int key) //                    hash function
    {
        return (key % bucket); //.                         Returns index
    }

    bool search(int key)
    {
        int i = hash(key);

        for (auto x : table[i])
        {
            if (x == key)
                return true;
        }
        return false;
    }

    void insert(int key)
    {
        int i = hash(key);
        table[i].push_back(key);
    }

    void remove(int key)
    {
        int i = hash(key);
        table[i].remove(key);
    }
};

int main()
{
    ;
    return 0;
}