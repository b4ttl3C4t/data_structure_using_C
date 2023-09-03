#include <stdio.h>

#define BUF_SIZE 50

//function prototype for operation of array:
void    traverse(int, int *);
void    insertion(int, int *, int, int);
void    deletion(int, int *, int);
int     search(int, int *, int);
void    update(int, int *, int, int);

int main(void)
{
    int arr[BUF_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
    traverse(15, arr);
    
    insertion(15, arr, 5, 99);
    traverse(16, arr);
    
    deletion(16, arr, 5);
    traverse(15, arr);
    
    printf("%d \n", search(16, arr, 5));
    
    update(16, arr, 10, 100);
    traverse(15, arr);

    return 0;
}

//print each element of array:
void traverse(int length, int *arr)
{
    for(int each = 0; each < length; ++each)
    {
        printf("%3d ", arr[each]);
    }
    printf("\n");
}

//insert an element at a specific index.
//iterate each element from last to first to match the index.
void insertion(int length, int *arr, int index, int data)
{
    int each = length;

    if(index > length)
    {
        return;
    }
    for(each = length; each >= index; --each)
    {
        arr[each + 1] = arr[each];
    }
    arr[each + 1] = data;
}

//insert an element at a specific index.
//iterate each element from first to last to match the index.
void deletion(int length, int *arr, int index)
{
    if(index > length)
    {
        return;
    }
    for(int each = 0; each < length - 1; ++each)
    {
        if(each >= index)
        {
            arr[each] = arr[each + 1];
        }
    }
}

//search an element at a specific index.
//operation of array supports for direct access.
int search(int length, int *arr, int index)
{
    if(index >= length)
    {
        return -1;
    }
    return arr[index];
}

//search an element at a specific index.
//operation of array supports for direct access.
void update(int length, int *arr, int index, int data)
{
    if(index >= length)
    {
        return;
    }
    arr[index] = data;
}