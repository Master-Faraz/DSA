#include <stdio.h>
#include <stdlib.h>

int get_index(int arr[], int key, int size); //    Getting index of given key
int set_index(int *arr, int index, int key, int size);
int max(int arr[], int size);
int min(int arr[], int size);
int sum(int arr[], int size);
int avg(int arr[], float size);
void printing(int arr[], int size);

int reverse(int *arr, int length);
int linear_search(int arr[], int key, int length);
int Binary_Search(int arr[], int key, int length);
void insert_Sorted(int *arr, int key, int Elements);
int merge_sorted(int arr_1[], int arr_2[], int len_1, int len_2);

void Intersection(int arr_1[], int arr_2[], int len_1, int len_2);
int *Union(int arr_1[], int arr_2[], int len_1, int len_2);

int *merge_arr; // .                                Pointer which stores merged array
int *ptr;
int size;

int main()
{
    // int arr[6] = {1, 2, 4, 5};

    // get_index(arr , 3 , 5);
    // set_index(arr , 0 ,100 , 5);
    // max(arr , 5);
    // min(arr , 5);
    // sum(arr , 5);
    // avg(arr , 5);

    // reverse(arr , 5);

    // linear_search(arr , 3 ,5);
    // linear_search(arr , 31 ,5);
    // Binary_Search(arr, 5, 5);
    // Binary_Search(arr, 45, 5);

    // insert_Sorted(arr, 3, 4);
    // printing(arr, 5);

    int arr_1[] = {1, 3, 5, 7};
    int arr_2[] = {2, 3, 5, 8};
    // merge_sorted(arr_1, arr_2, 4, 4);
    // printing(merge_arr, 8);
    Union(arr_1, arr_2, 4, 4);
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", ptr[i]);
    }
    printf("Size is %d\n", size);
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

void printing(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
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
    int high = arr[l];
    int mid;

    while (low < high)
    {
        mid = (low + high) / 2;
        if (arr[mid] > key)
        {
            high = mid - 1;
        }
        else if (arr[mid] == key)
        {
            printf("Key is found at index %d\n", mid);
            return mid;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
    }

    printf("Key is not found \n");
    return -1;
}

void insert_Sorted(int *arr, int key, int elements)
{
    int i = elements - 1;
    for (i; i >= 0; i--)
    {
        if (arr[i] > key)
        {
            arr[i + 1] = arr[i];
        }
        else if (arr[i] < key)
        {
            arr[i + 1] = key;
            break;
        }
    }
}

int merge_sorted(int arr_1[], int arr_2[], int len_1, int len_2)
{
    size = len_1 + len_2 - 1;
    merge_arr = (int *)malloc(size * sizeof(int));

    int i = 0, j = 0, k = 0;

    while (i < len_1 && j < len_2)
    {
        if (arr_1[i] < arr_2[j])
        {
            merge_arr[k] = arr_1[i];
            i++;
            k++;
        }
        else if (arr_1[i] > arr_2[j])
        {
            merge_arr[k] = arr_2[j];
            j++;
            k++;
        }
        else
        {
            merge_arr[k] = arr_1[i];
            i++;
            j++;
            k++;
            size--;
        }
    }

    while (i < len_1)
    {
        merge_arr[k] = arr_1[i];
        k++;
        i++;
    }
    while (j < len_2)
    {
        merge_arr[k] = arr_2[j];
        k++;
        j++;
    }
}

void Intersection(int arr_1[], int arr_2[], int len_1, int len_2)
{

    for (int i = 0; i < len_1; i++)
    {
        for (int j = 0; j < len_2; j++)
        {
            if (arr_1[i] == arr_2[j])
                printf("%d\n", arr_1[i]);
        }
    }
}

int *Union(int arr_1[], int arr_2[], int len_1, int len_2)
{
    int k = 0, i = 0, j = 0;
    size = len_1 + len_2;
    printf("\n");
    ptr = (int *)malloc(size * sizeof(int));

    while (i < len_1 && j < len_2)
    {
        if (arr_1[i] < arr_2[j])
        {
            ptr[k] = arr_1[i];
            i++;
            k++;
        }
        else if (arr_1[i] > arr_2[j])
        {
            ptr[k] = arr_2[j];
            j++;
            k++;
        }
        else if (arr_1[i] == arr_2[j])
        {
            ptr[k] = arr_1[i];
            i++;
            j++;
            k++;
            size--;
        }
    }
    while (i < len_1)
    {
        ptr[k++] = arr_1[i++];
    }
    while (j < len_2)
    {
        ptr[k++] = arr_2[j++];
    }

    printf("\nValue of I is %d and j is %d \n\n", i, j);
}