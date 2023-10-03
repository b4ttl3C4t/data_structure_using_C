#define LIST_SIZE 50
#define LIST_TYPE_SIZE 4
#define MALLOC_ERROR    "The memory allocation for linked list aborts."
#define MODE_ERROR      "The mode is not accessible."
#define OPCODE_ERROR    "The opcode is not accessible."
#define INDEX_ERROR     "The node does not exist."

struct SinglyLinkedList;
struct PolynomialLinkedList;
struct DoublyLinkedList;
struct CircularLinkedList;
struct l_Node;

typedef struct l_Node l_Node;

//The *sentinel node* means the end of a linked list.
static l_Node *sentinel_node;

/*You should set the mode for the newer node (as following)
 *whenever you construst it.
 */
static enum LinkedListType
{
    singly      = 0,
    polynomial  = 1,
    doubly      = 2,
    circular    = 3,
};

/*The definition of singly listed list .
 *(The data is set by type *int* .)
 */
static struct SinglyLinkedList
{
    int64_t data;
    int64_t :0;
    l_Node *next;
};

/*The definition of singly listed list .
 *(The data is set by type *int* .)
 */
static struct PolynomialLinkedList
{
    double coefficient;
    uint64_t power;
    l_Node *next;
};

/*The definition of doubly listed list.
 *(The data is set by type *int* .)
 */
static struct DoublyLinkedList
{
    int64_t data;
    int64_t :0;
    l_Node *next;
    l_Node *prev;
};

/*The definition of circular listed list definition.
 *(The data is set by type *int* .)
 */
static struct CircularLinkedList
{
    int64_t data;
    int64_t :0;
    l_Node *next;
    l_Node *prev;
};
/*The circular_linked_list is as singly_linked_list or doubly_linked_list,
 *but there is no NULL to be linked, instead of 
 *linking the head node and the tail node together,
 *and we construct the circular_linked_list type based on doubly linked list.
 */

//Constructing compound linked list type, then setting the mode by variable *type* .
struct l_Node
{
    enum LinkedListType type;
    
    union
    {
        struct SinglyLinkedList      singly;
        struct PolynomialLinkedList  polynomial;
        struct DoublyLinkedList      doubly;
        struct CircularLinkedList    circular;
    };
};

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
//void     l_delete_tail      (l_Node *);

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