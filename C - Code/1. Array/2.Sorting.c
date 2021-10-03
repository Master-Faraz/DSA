#include <stdio.h>

void printing(int arr[], int size);
void Swap(int *a, int *b);

// .                    ********        Sorting Algorithms        ******

void Bubble_Sort(int arr[], int size);
void Insertion_Sort(int arr[], int size);
void Selection_Sort(int arr[], int size);


// .                    ********        Application         ******

void Finding_nth_largest_element(int arr[], int size, int n);
void Finding_nth_smallest_element(int arr[], int size, int n);

int main()
{
    int arr[] = {8, 5, 7, 3, 2};
    int size = sizeof(arr) / sizeof(int);

    // Swap(&arr[0],&arr[1]);
    // Bubble_Sort(arr, size);
    // Finding_nth_largest_element(arr, size, 3);
    // Insertion_Sort(arr, size);
    

    printing(arr, size);

    return 0;
}

// .                    ********       Algorithms Defination        ******

void printing(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", arr[i]);
    }
}

void Swap(int *a, int *b) //.                           Passing Address
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Bubble_Sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                Swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void Insertion_Sort(int arr[], int size)
{
    for (int i = 1; i < size; i++) 
    {
        if (arr[i] < arr[i - 1])
        {
            int j = i - 1;
            int temp = arr[i];

            while ((j > -1) && (arr[j] > temp))
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;
        }
    }
}


void Selection_Sort(int arr[], int size)
{
    for(int i=0;i<size;i++)
    {
        
    }
}


// .                    ********        Application         ******

void Finding_nth_largest_element(int arr[], int size, int n)
{
    int s = size - n;
    Bubble_Sort(arr, size);
    printf("The %drd largest element is %d\n", n, arr[s]);
}