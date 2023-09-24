#define LIST_SIZE 50



/*The definition of singly listed list .
 *(The data is set by type *int* .)
 */
typedef struct SINGLY_LINKED_LIST
{
    int data;
    struct SINGLY_LINKED_LIST *next;
}singly_linked_list;



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
    unsigned int type;
    union
    {
        singly_linked_list   *singly;
        doubly_linked_list   *doubly;
        circular_linked_list *circular;
    };
}node;



//function prototype for operation of linked list:
void    display(int, node *);
void    insertion(int, node *, int, int);
void    deletion(int, node *, int);
int     search(int, node *, int);
void    update(int, node *, int, int);