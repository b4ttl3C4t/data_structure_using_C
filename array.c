#include "array.h"

#define FREE_MEMORY_ERROR   "The pointer to the memory is NULL."
#define INDEX_ERROR         "The memory corresponding the index is not accessible."



//The interface of the internal function.
static inline void  input_data  (a_Data *);
static inline void  output_data (a_Data);
static bool         is_empty    (a_Array *);
static bool         is_full     (a_Array *);

void main(void)
{
    a_Array * arr;
}

void a_construction(a_Array *arr)
{
    arr = (a_Array *)malloc(1 * sizeof(uint64_t) + ARRAY_MAX_SIZE * sizeof(a_Data));
}

void a_destruction(a_Array *arr)
{
    if(arr == NULL)
    {
        fprintf(stderr, "\n%s%s", "> destruction: ", FREE_MEMORY_ERROR);
        return NULL;
    }

    free(arr);
}

//print each element of array:
void a_traverse(a_Array *arr)
{
    for(uint64_t each = 0; each < arr->length; ++each)
    {
        printf("%3d ", arr[each]);
    }
    printf("\n");
}

//insert an element at a specific index.
//iterate each element from last to first to match the index.
void a_insertion(a_Array *arr, uint64_t index)
{
    if(index > arr->length)
    {
        fprintf(stderr, "\n%s%s", "> insertion: ", INDEX_ERROR);
        return;
    }
    
    uint64_t each;
    for(each = arr->length; each >= index; --each)
    {
        arr->element[each + 1] = arr->element[each];
    }

    printf("\n%s", "> insertion: Please set the data for the element:");
    input_data(&arr->element[index]);
}

//insert an element at a specific index.
//iterate each element from first to last to match the index.
void a_deletion(a_Array *arr, uint64_t index)
{
    if(index > arr->length)
    {
        fprintf(stderr, "\n%s%s", "> insertion: ", INDEX_ERROR);
        return;
    }

    for(uint64_t each = 0; each < arr->length - 1; ++each)
    {
        if(each >= index)
        {
            arr->element[each] = arr->element[each + 1];
        }
    }
}

//search an element at a specific index.
//operation of array supports for direct access.
void a_search(a_Array *arr, uint64_t index)
{
    if(index >= arr->length)
    {
        fprintf(stderr, "\n%s%s", "> a_search: ", INDEX_ERROR);
        return;
    }

    printf("\n%s", "> a_search: The data of the element corresponding the index is as following:");
    output_data(arr->element[index]);
}

//update an element at a specific index.
//operation of array supports for direct access.
void a_update(a_Array *arr, uint64_t index)
{
    if(index >= arr->length)
    {
        fprintf(stderr, "\n%s%s", "> a_update: ", INDEX_ERROR);
        return;
    }

    printf("\n%s", "> a_update: Please set the data for the element:");
    input_data(&arr->element[index]);
}

void a_is_empty(a_Array *arr)
{
    if(arr->length == 0)
    {
        printf("\n%s", "> a_is_empty: The array is empty now.");
    }
    else
    {
        printf("\n%s", "> a_is_empty: The array is not empty now.");
    }
}

void a_is_full(a_Array *arr)
{
    if(arr->length == ARRAY_MAX_SIZE)
    {
        printf("\n%s", "> a_is_full: The array is full now.");
    }
    else
    {
        printf("\n%s", "> a_is_full: The array is not full now.");
    }
}



//The implementation of the internal function.
static inline void input_data(a_Data *element)
{
    scanf("%lf", &element->data);
    getchar();
}

static inline void output_data(a_Data element)
{
    printf(" %lf", element.data);
}

static inline bool is_empty(a_Array *arr)
{
    if(arr->length == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

static inline bool is_full(a_Array *arr)
{
    if(arr->length == ARRAY_MAX_SIZE)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}