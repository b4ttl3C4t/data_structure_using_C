#ifdef LINKED_LIST_H

/*You should set the mode for the newer node (as following)
 *whenever you construst it.
 */
static enum LinkedListType
{
    normal      = 0,
    polynomial  = 1,
};

//The definition of data for polynomials.
static struct polynomial_data
{
    double coefficient;
    uint64_t power;
};

//The definition of data for the normal node.
static struct node_data
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

//The *sentinel node* means the end of a linked list.
l_Node *sentinel_node;

//Function prototype for operation of linked list:
void     l_control_table    (l_Node **, uint64_t);
l_Node * l_initialization   (void);

//l_Node * l_construction     (l_Node *);
//l_Node * l_insertion        (l_Node *, uint64_t);
l_Node * l_insert_head      (l_Node *);
//void     l_insert_tail      (l_Node *);

//void     l_destruction      (l_Node *);
//l_Node * l_deletion         (l_Node *, uint64_t);
l_Node * l_delete_head      (l_Node *);
void     l_delete_tail      (l_Node *);

//Useful operation and algorithm based on divergent linked list type.
//l_Node * l_search           (l_Node *, uint64_t);
void     l_display          (l_Node *);
//l_Node * l_sort             (l_Node *);
//l_Node * l_reverse          (l_Node *);
//bool     l_is_list_empty    (l_Node *);
/*
//The following algorithm is only for polynomial linked list.
void   polynomial_addition          (l_Node *, l_Node *);
void   polynomial_subtraction       (l_Node *, l_Node *);
void   polynomial_multiplication    (l_Node *, l_Node *);
void   polynomial_division          (l_Node *, l_Node *);*/