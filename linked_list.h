#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

struct node
{
    char data;
    struct node *next;
};

typedef struct node node_t;
typedef struct node *node_ptr_t;

void insertion(node_ptr_t *, char);
void deletion(node_ptr_t *, char);
void reverse(node_ptr_t *);
bool is_empty(node_ptr_t);
void print_list(node_ptr_t);

#endif
