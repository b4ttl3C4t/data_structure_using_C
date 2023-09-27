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
    signed long long int data;
    signed long long int :0;
    Node *next;
};

/*The definition of singly listed list .
 *(The data is set by type *int* .)
 */
struct PolynomialLinkedList
{
    unsigned long long int power;
    double coefficient;
    Node *next;
};

/*The definition of doubly listed list.
 *(The data is set by type *int* .)
 */
struct DoublyLinkedList
{
    signed long long int data;
    signed long long int :0;
    Node *next;
    Node *prev;
};

/*The definition of circular listed list definition.
 *(The data is set by type *int* .)
 */
struct CircularLinkedList
{
    signed long long int data;
    signed long long int :0;
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

//function prototype for operation of linked list:
Node *  initialization  (void);
void    control_table   (Node *);
void    input_data      (Node *);
void    insert_head     (Node *);
void    insert_tail     (Node *);
void    delete_head     (Node *);
void    delete_tail     (Node *);
void    display         (Node *);
void    insertion       (Node *, unsigned int);
void    deletion        (Node *, unsigned int);
int     search          (Node *, unsigned int);