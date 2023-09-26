#define LIST_SIZE 50
#define LIST_TYPE_SIZE 4
#define LINKED_LIST_MALLOC_ERROR "The memory allocation for linked list aborts."

enum   LinkedListType;
struct SinglyLinkedList;
struct PolynomialLinkedList;
struct DoublyLinkedList;
struct CircularLinkedList;

//Constructing compound linked list type, then setting the mode by variable *type* .
typedef struct Node
{
    enum LinkedListType type;
    
    union
    {
        struct SinglyLinkedList      singly;
        struct PolynomialLinkedList  polynomial;
        struct DoublyLinkedList      doubly;
        struct CircularLinkedList    circular;
    };
}Node;

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
    int data;
    Node *next;
};

/*The definition of singly listed list .
 *(The data is set by type *int* .)
 */
struct PolynomialLinkedList
{
    double coefficient;
    unsigned int power;
    Node *next;
};

/*The definition of doubly listed list.
 *(The data is set by type *int* .)
 */
struct DoublyLinkedList
{
    int data;
    Node *prev;
    Node *next;
};

/*The definition of circular listed list definition.
 *(The data is set by type *int* .)
 */
struct CircularLinkedList
{
    int data;
    Node *prev;
    Node *next;
};
/*The circular_linked_list is as singly_linked_list or doubly_linked_list,
 *but there is no NULL to be linked, instead of 
 *linking the head node and the tail node together,
 *and we construct the circular_linked_list type based on doubly linked list.
 */



//function prototype for operation of linked list:
void    input_data  (Node *);
void    insert_head (Node *);
void    insert_tail (Node *);
void    delete_head (Node *);
void    delete_tail (Node *);
void    display     (Node *);
void    insertion   (Node *, unsigned int);
void    deletion    (Node *, unsigned int);
int     search      (Node *, unsigned int);