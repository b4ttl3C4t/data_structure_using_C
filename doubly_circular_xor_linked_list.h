#ifndef DOUBLY_CIRCULAR_XOR_LINKED_LIST_H
#define DOUBLY_CIRCULAR_XOR_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

//Function prototype for operation of linked list:
void l_control_table    (l_List **, uint64_t);

void l_construction     (l_List *);
//void l_insertion        (l_List *, uint64_t);
//void l_insert_head      (l_List *);
//void l_insert_tail      (l_List *);

//void l_destruction      (l_List *);
//void l_deletion         (l_List *, uint64_t);
//void l_delete_head      (l_List *);
//void l_delete_tail      (l_List *);

//Useful operation and algorithm based on divergent linked list type.
//void l_search           (l_List *, uint64_t);
//void l_display          (l_List *);
//void l_sort             (l_List *);
//void l_reverse          (l_List *);
//bool l_is_list_empty    (l_List *);
/*
//The following algorithm is only for polynomial linked list.
l_List * polynomial_addition          (l_List *, l_List *);
l_List * polynomial_subtraction       (l_List *, l_List *);
l_List * polynomial_multiplication    (l_List *, l_List *);
l_List * polynomial_division          (l_List *, l_List *);*/

#endif