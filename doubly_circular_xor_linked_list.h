#ifndef DOUBLY_CIRCULAR_XOR_LINKED_LIST_H
#define DOUBLY_CIRCULAR_XOR_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

/*You should set the mode for the newer node (as following)
 *whenever you construst it.
 */
enum LinkedListType
{
    normal      = 0,
    polynomial  = 1,
};

/*The node type is for doubly circular xor linked list.*/
typedef struct Linked_List_Node_s
{
    struct Linked_List_Data_s *data;
    struct Linked_List_Node_s *link;
} l_Node;
/*The pointer to data is used to promote the code flexiblity, 
 *when you swap the data within two node, or change the data setting.
 */

//The linked list type
typedef struct Linked_List_s
{
    enum LinkedListType type;
    l_Node *head_node;
    l_Node *sentinel_node;
    l_Node *dummy_node;
} l_List;
//Constructing compound linked list type, then setting the mode by variable *type* .
//The *head node* means the beginning of the linked list.
//The *sentinel node* means the check point of the linked list.
/*The *dummy node* can avoid the special operation to the head node.
 *and let the code more clear and promote its readness.
 */

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