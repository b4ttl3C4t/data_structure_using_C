#define LIST_SIZE 50
#define LIST_TYPE_SIZE 4



enum LIST_TYPE
{
    singly      = 0,
    polynomial  = 1,
    doubly      = 2,
    circular    = 3,
};


/*The definition of singly listed list .
 *(The data is set by type *int* .)
 */
typedef struct SINGLY_LINKED_LIST
{
    int data;
    struct SINGLY_LINKED_LIST *next;
}singly_linked_list;



/*The definition of singly listed list .
 *(The data is set by type *int* .)
 */
typedef struct POLYNOMIAL_LINKED_LIST
{
    int coefficient;
    int power;
    struct POLYNOMIAL_LINKED_LIST *next;
}polynomial_linked_list;



/*The definition of doubly listed list.
 *(The data is set by type *int* .)
 */
typedef struct DOUBLY_LINKED_LIST
{
    int data;
    struct DOUBLY_LINKED_LIST *prev;
    struct DOUBLY_LINKED_LIST *next;
}doubly_linked_list;



/*The definition of circular listed list definition.
 *(The data is set by type *int* .)
 */
typedef struct CIRCULAR_LINKED_LIST
{
    int data;
    struct CIRCULAR_LINKED_LIST *prev;
    struct CIRCULAR_LINKED_LIST *next;
}circular_linked_list;
/*The circular_linked_list is as singly_linked_list or doubly_linked_list,
 *but there is no NULL to be linked, instead of 
 *linking the head node and the tail node together,
 *and we construct the circular_linked_list type based on doubly linked list.
 */



//Constructing compound linked list type, then setting the mode by variable *type* .
typedef struct NODE
{
    enum LIST_TYPE type;
    union
    {
        singly_linked_list      *singly;
        polynomial_linked_list  *polynomial;
        doubly_linked_list      *doubly;
        circular_linked_list    *circular;
    };
}Node;


//The *sentinel node* means the end of a linked list.
static Node *sentinel_node;


//function prototype for operation of linked list:
void    insert_head (Node *);
void    insert_tail (Node *);
void    delete_head (Node *);
void    delete_tail (Node *);
void    display     (Node *);
void    insert      (Node *, unsigned int);
void    delete      (Node *, unsigned int);
int     search      (Node *, unsigned int);