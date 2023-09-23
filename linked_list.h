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
 *so we take the circular_linked_list type based on doubly linked list.
 */



//function prototype for operation of linked list:
void    display(int, int *);
void    insertion(int, int *, int, int);
void    deletion(int, int *, int);
int     search(int, int *, int);
void    update(int, int *, int, int);