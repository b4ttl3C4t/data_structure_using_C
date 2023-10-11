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

//The definition of data for polynomials.
struct polynomial_data
{
    double coefficient;
    uint64_t power;
};

//The definition of data for the normal node.
struct node_data
{
    uint64_t integer;
};

//Constructing compound linked list type, then setting the mode by variable *type* .
typedef struct LINKED_LIST_NODE
{
    enum LinkedListType type;
    
    union
    {
        struct polynomial_data polynomial;
        struct node_data data;
    };

    struct LINKED_LIST_NODE *link;
} l_Node;

typedef struct LINKED_LIST
{
    l_Node *left;
    l_Node *right;
} l_List;

//The *sentinel node* means the end of a linked list.
l_Node *sentinel_node;

//Function prototype for operation of linked list:
void l_control_table    (l_List **, uint64_t);

//void l_construction     (l_List *);
//void l_insertion        (l_List *, uint64_t);
void l_insert_head      (l_List *);
//void l_insert_tail      (l_List *);

//void l_destruction      (l_List *);
//void l_deletion         (l_List *, uint64_t);
void l_delete_head      (l_List *);
void l_delete_tail      (l_List *);

//Useful operation and algorithm based on divergent linked list type.
//void l_search           (l_List *, uint64_t);
void l_display          (l_List *);
//void l_sort             (l_List *);
//void l_reverse          (l_List *);
//bool l_is_list_empty    (l_List *);
/*
//The following algorithm is only for polynomial linked list.
l_List * polynomial_addition          (l_List *, l_List *);
l_List * polynomial_subtraction       (l_List *, l_List *);
l_List * polynomial_multiplication    (l_List *, l_List *);
l_List * polynomial_division          (l_List *, l_List *);*/