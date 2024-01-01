#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdint.h>
#include "array.h"
#include "circular_doubly_linked_list.h"



typedef struct Array_Stack_s
{
    int8_t  top;
    a_Array container;
} a_Stack;

typedef struct List_Stack_s
{
    int8_t  top;
    l_List  container;
} l_Stack;



void a_s_construction   (a_Stack *);
void a_s_destruction    (a_Stack *);
void a_s_peek           (a_Stack *);
void a_s_pop            (a_Stack *);
void a_s_push           (a_Stack *);
void a_s_is_empty       (a_Stack *);
void a_s_is_full        (a_Stack *);
void a_s_print          (a_Stack *);

void l_s_construction   (l_Stack *);
void l_s_destruction    (l_Stack *);
void l_s_peek           (l_Stack *);
void l_s_pop            (l_Stack *);
void l_s_push           (l_Stack *);
void l_s_is_empty       (l_Stack *);
void l_s_is_full        (l_Stack *);
void l_s_print          (l_Stack *);

#endif