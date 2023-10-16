#include <stdio.h>
#include "array.h"
#include "doubly_circular_xor_linked_list.h"
#include "stack.h"

#define STACK_MAX_SIZE 100

void l_s_peek       (l_List *list);
void l_s_pop        (l_List *list);
void l_s_push       (l_List *list);
void l_s_is_empty   (l_List *list);
void l_s_is_full    (l_List *list);

void a_s_peek       (a_Array *arr);
void a_s_pop        (a_Array *arr);
void a_s_push       (a_Array *arr);
void a_s_is_empty   (a_Array *arr);
void a_s_is_full    (a_Array *arr);