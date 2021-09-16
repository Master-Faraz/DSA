#include <stdio.h>

int get_index(int arr[], int key, int size); //    Getting index of given key
int set_index(int *arr, int index, int key, int size);
int max(int arr[], int size);
int min(int arr[], int size);
int sum(int arr[], int size);
int avg(int arr[], float size);

int reverse(int *arr, int length);
int linear_search(int arr[], int key, int length);
int Binary_Search(int arr[], int key, int length);

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    // get_index(arr , 3 , 5);
    // set_index(arr , 0 ,100 , 5);
    // max(arr , 5);
    // min(arr , 5);
    // sum(arr , 5);
    // avg(arr , 5);

    // reverse(arr , 5);
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%d\n" , arr[i]);
    // }

    // linear_search(arr , 3 ,5);
    // linear_search(arr , 31 ,5);
    // Binary_Search(arr , 4 ,5);
    Binary_Search(arr , 45,5);
}

int get_index(int arr[], int key, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
            printf("%d\n", i);
    }
}

int set_index(int *arr, int index, int key, int size)
{
    arr[index] = key;
}

int max(int arr[], int size)
{
    int temp = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > temp)
            temp = arr[i];
    }
    printf("%d\n", temp);
}

int min(int arr[], int size)
{
    int temp = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < temp)
            temp = arr[i];
    }
    printf("%d\n", temp);
}

int sum(int arr[], int size)
{
    int temp = arr[0];
    for (int i = 0; i < size; i++)
    {
        temp += i;
    }
    printf("%d\n", temp);
}

int avg(int arr[], float size)
{
    float temp = arr[0];
    float avg;
    for (int i = 0; i < size; i++)
    {
        temp += i;
    }
    avg = (temp / size);
    printf("%f\n", avg);
}

int reverse(int *arr, int length)
{
    int left = 0, right = length - 1;
    while (left < right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }
}

int linear_search(int arr[], int key, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == key)
        {
            printf("Key is found at index %d\n", i);
            return 0;
        }
    }
    printf("Key is not found -_- \n");
}

int Binary_Search(int arr[], int key, int length)
{
    int l = length - 1;
    int low = arr[0];
    int  high = arr[l];
    int mid = (low + high) / 2;

    if (arr[mid] > key)
    {
        high = mid - 1;
        mid = (low + high) / 2;
    }
    else if (arr[mid] == key)
    {
        printf("Key is found at index %d\n", mid);
        // return 0;
    }
    else if (arr[mid] < key)
    {
        low = mid + 1;
        mid = (low + high) / 2;
    }


    if(low>high)
    {
        printf("Key is not found \n");
    }
}