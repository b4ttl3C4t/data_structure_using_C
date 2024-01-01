#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include "node_data.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

struct node
{
    data_ptr_t data;
    struct node *next;
};

typedef struct node node_t;
typedef struct node *node_ptr_t;

void insertion(node_ptr_t *, data_t);
void deletion(node_ptr_t *, data_t);
void reverse(node_ptr_t *);
bool is_empty(node_ptr_t);
void print_list(node_ptr_t);

#endif
