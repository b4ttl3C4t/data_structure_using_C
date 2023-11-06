#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>



//Setting the mode for the newer node (as following) whenever you construst it.
enum LinkedListType
{
    normal      = 0,
    polynomial  = 1,
};

//The definition of data for polynomials.
struct polynomial_data
{
    double   coefficient;
    uint64_t power;
};

//The definition of data for the normal node.
struct normal_data
{
    int64_t integer;
};

//Constructing the data of compound linked list type.
typedef struct Linked_List_Data_s
{
    union
    {
        struct polynomial_data polynomial;
        struct normal_data     default_data;
    };
} l_Data;

//The node type is for doubly circular xor linked list.
typedef struct Linked_List_Node_s
{
    struct Linked_List_Data_s *data;
    struct Linked_List_Node_s *prev;
    struct Linked_List_Node_s *next;
} l_Node;
/*The pointer to data is used to promote the code flexiblity, 
 *when you swap the data within two node, or change the data setting. */

//The doubly circular linked list type.
typedef struct Linked_List_s
{
    uint64_t                   size;
    enum   LinkedListType      type;
    struct Linked_List_Node_s *head;
    struct Linked_List_Node_s *tail;
    struct Linked_List_Node_s *current;
} l_List;
/*Constructing compound linked list type, then setting the mode by variable *type* . */
/*The *head node* means the start of the linked list. */
/*The *tail node* means the end of the linked list. */
/*Temporary node type:
 *The *previous node* , *current node* , and *temporary node* record the status of the node,
 *you can only use the foremost one whem you construct the doubly linked list.
 *The *sentinel node* means the check point of the linked list. */
/*Special operational node type (not in the structure):
 *The *dummy node* can avoid the special operation to the head node.
 *and let the code more clear and promote its readness. 
 *Those two can merge together, since the function of them is similar. 
 *(Actually, the *dummy node* only would be used to singly linked list
 * and could be replaced by *previous node* ,
 * moreover, the *sentinel node* could be replaced as well.) */



//Function prototype for operation of linked list:
int8_t   l_control_table    (l_List *);
l_List * l_initialization   (void);

void l_construction     (l_List *);
void l_insertion        (l_List *, uint64_t);
void l_insert_head      (l_List *);
void l_insert_tail      (l_List *);

void l_destruction      (l_List *);
//void l_deletion         (l_List *, uint64_t);
//void l_delete_head      (l_List *);
//void l_delete_tail      (l_List *);

//Useful operation and algorithm based on divergent linked list type.
void l_search           (l_List *, uint64_t);
void l_display          (l_List *);
//void l_sort             (l_List *);
//void l_reverse          (l_List *);
void l_is_empty         (l_List *);
/*
//The following algorithm is only for polynomial linked list.
l_List * polynomial_addition          (l_List *, l_List *);
l_List * polynomial_subtraction       (l_List *, l_List *);
l_List * polynomial_multiplication    (l_List *, l_List *);
l_List * polynomial_division          (l_List *, l_List *);*/

#endif