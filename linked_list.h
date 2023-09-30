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
struct Node;

typedef struct Node Node;

//The *sentinel node* means the end of a linked list.
Node *sentinel_node;

/*You should set the mode for the newer node (as following)
 *whenever you construst it.
 */
enum LinkedListType
{
    singly      = 0,
    polynomial  = 1,
    doubly      = 2,
    circular    = 3,
};

/*The definition of singly listed list .
 *(The data is set by type *int* .)
 */
struct SinglyLinkedList
{
    int64_t data;
    int64_t :0;
    Node *next;
};

/*The definition of singly listed list .
 *(The data is set by type *int* .)
 */
struct PolynomialLinkedList
{
    double coefficient;
    uint64_t power;
    Node *next;
};

/*The definition of doubly listed list.
 *(The data is set by type *int* .)
 */
struct DoublyLinkedList
{
    int64_t data;
    int64_t :0;
    Node *next;
    Node *prev;
};

/*The definition of circular listed list definition.
 *(The data is set by type *int* .)
 */
struct CircularLinkedList
{
    int64_t data;
    int64_t :0;
    Node *next;
    Node *prev;
};
/*The circular_linked_list is as singly_linked_list or doubly_linked_list,
 *but there is no NULL to be linked, instead of 
 *linking the head node and the tail node together,
 *and we construct the circular_linked_list type based on doubly linked list.
 */

//Constructing compound linked list type, then setting the mode by variable *type* .
struct Node
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
void   l_control_table   (Node **, uint64_t);
Node * l_initialization  (void);
void   l_termination     (Node *);

//Node * l_construction    (Node *);
//Node * l_insertion       (Node *, uint64_t);
//Node * l_insert_head     (Node *);
//void   l_insert_tail     (Node *);

//void   l_destruction     (Node *);
//Node * l_deletion        (Node *, uint64_t);
//Node * l_delete_head     (Node *);
//void   l_delete_tail     (Node *);

//Useful operation and algorithm based on divergent linked list type.
//Node * l_search          (Node *, uint64_t);
void   l_display         (Node *);
//Node * l_sort            (Node *);
//Node * l_reverse         (Node *);
//bool   l_is_list_empty   (Node *);
/*
//The following algorithm is only for polynomial linked list.
void   polynomial_addition          (Node *, Node *);
void   polynomial_subtraction       (Node *, Node *);
void   polynomial_multiplication    (Node *, Node *);
void   polynomial_division          (Node *, Node *);*/