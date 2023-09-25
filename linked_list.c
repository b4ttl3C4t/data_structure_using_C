#include <stdio.h>
#include "linked_list.h"

int main(void)
{
    puts("asdf");
    return 0;
}





/*----------------------------------------function *insert_head* begin----------------------------------------*/
static inline void singly_insert_head     (Node *node);
static inline void polynomial_insert_head (Node *node);
static inline void doubly_insert_head     (Node *node);
static inline void circular_insert_head   (Node *node);

static void (*insert_head_choose[LIST_TYPE_SIZE])(Node *node) = 
{ 
    singly_insert_head, polynomial_insert_head, doubly_insert_head, circular_insert_head
};

void insert_head(Node *node)
{
    ;
}

static inline void singly_insert_head(Node *node)
{
    ;
}

static inline void polynomial_insert_head(Node *node)
{
    ;
}

static inline void doubly_insert_head(Node *node)
{
    ;
}

static inline void circular_insert_head(Node *node)
{
    ;
}
/*----------------------------------------function *insert_head* end  ----------------------------------------*/





/*----------------------------------------function *insert_tail* begin----------------------------------------*/
static inline void singly_insert_tail     (Node *node);
static inline void polynomial_insert_tail (Node *node);
static inline void doubly_insert_tail     (Node *node);
static inline void circular_insert_tail   (Node *node);

static void (*insert_tail_choose[LIST_TYPE_SIZE])(Node *node) = 
{ 
    singly_insert_tail, polynomial_insert_tail, doubly_insert_tail, circular_insert_tail
};

void insert_tail(Node *node)
{
    ;
}

static inline void singly_insert_tail(Node *node)
{
    ;
}

static inline void polynomial_insert_tail(Node *node)
{
    ;
}

static inline void doubly_insert_tail(Node *node)
{
    ;
}

static inline void circular_insert_tail(Node *node)
{
    ;
}
/*----------------------------------------function *insert_tail* end  ----------------------------------------*/





/*----------------------------------------function *delete_head* begin----------------------------------------*/
static inline void singly_delete_head     (Node *node);
static inline void polynomial_delete_head (Node *node);
static inline void doubly_delete_head     (Node *node);
static inline void circular_delete_head   (Node *node);

static void (*delete_head_choose[LIST_TYPE_SIZE])(Node *node) = 
{ 
    singly_delete_head, polynomial_delete_head, doubly_delete_head, circular_delete_head
};

void delete_head(Node *node)
{
    ;
}

static inline void singly_delete_head(Node *node)
{
    ;
}

static inline void polynomial_delete_head(Node *node)
{
    ;
}

static inline void doubly_delete_head(Node *node)
{
    ;
}

static inline void circular_delete_head(Node *node)
{
    ;
}
/*----------------------------------------function *delete_head* end  ----------------------------------------*/





/*----------------------------------------function *delete_tail* begin----------------------------------------*/
static inline void singly_delete_tail     (Node *node);
static inline void polynomial_delete_tail (Node *node);
static inline void doubly_delete_tail     (Node *node);
static inline void circular_delete_tail   (Node *node);

static void (*delete_tail_choose[LIST_TYPE_SIZE])(Node *node) = 
{ 
    singly_delete_tail, polynomial_delete_tail, doubly_delete_tail, circular_delete_tail
};

void delete_tail(Node *node)
{
    ;
}

static inline void singly_delete_tail(Node *node)
{
    ;
}

static inline void polynomial_delete_tail(Node *node)
{
    ;
}

static inline void doubly_delete_tail(Node *node)
{
    ;
}

static inline void circular_delete_tail(Node *node)
{
    ;
}
/*----------------------------------------function *delete_tail* end  ----------------------------------------*/





/*----------------------------------------function *display* begin----------------------------------------*/
static inline void singly_display     (Node *node);
static inline void polynomial_display (Node *node);
static inline void circular_display   (Node *node);

static void (*display_choose[LIST_TYPE_SIZE])(Node *node) = 
{ 
    singly_display, polynomial_display, singly_display, circular_display
};

void display(Node *node)
{
    if(node->type >= LIST_TYPE_SIZE)
    {
        printf("%s", "It's not a booked type.");
        return ;
    }
    display_choose[node->type](node);
    //Resetting the sentinel node by NULL (or nil).
    sentinel_node = NULL;
    puts("");
}

static inline void singly_display(Node *node)
/*Both singly linked list and doubly linked list could be displayed step by step,
 *not having to care the minute difference between them in most of the time.
 */
{
    sentinel_node = NULL;
    do
    {
        printf("%d ", node->singly->data);
        node->singly = node->singly->next;
    } while (node->singly != NULL);
}

static inline void polynomial_display(Node *node)
/*All the type of linked list except circular linked list could be displayed step by step,
 *not having to care the minute difference between them in most of the time.
 */
{
    sentinel_node = NULL;
    do
    {
        printf("%dx^%d", node->polynomial->coefficient, node->polynomial->power);
        node->polynomial = node->polynomial->next;
    } while (node->polynomial != NULL);
}

static inline void circular_display(Node *node)
{
    sentinel_node = node;
    /*The node means some node you want to begin with,
     *and the function could traverse all the node until
     *meeting with the beginning node again.
     *(Don't forget that it is a *circular* linked list.)
     */

    do
    {
        printf("%d ", node->circular->data);
        node->circular = node->circular->next;
    } while (node->circular != sentinel_node->circular);
}
/*----------------------------------------function *display* end  ----------------------------------------*/





/*----------------------------------------function *insert* begin----------------------------------------*/
static inline void singly_insert     (Node *node, unsigned int index);
static inline void polynomial_insert (Node *node, unsigned int index);
static inline void doubly_insert     (Node *node, unsigned int index);
static inline void circular_insert   (Node *node, unsigned int index);

static void (*insert_choose[LIST_TYPE_SIZE])(Node *node, unsigned int index) = 
{ 
    singly_insert, polynomial_insert, doubly_insert, circular_insert
};

void insert(Node *node, unsigned int index)
{
    ;
}

static inline void singly_insert(Node *node, unsigned int index)
{
    ;
}

static inline void polynomial_insert(Node *node, unsigned int index)
{
    ;
}

static inline void doubly_insert(Node *node, unsigned int index)
{
    ;
}

static inline void circular_insert(Node *node, unsigned int index)
{
    ;
}
/*----------------------------------------function *insert* end  ----------------------------------------*/





/*----------------------------------------function *delete* begin----------------------------------------*/
static inline void singly_delete     (Node *node, unsigned int index);
static inline void polynomial_delete (Node *node, unsigned int index);
static inline void doubly_delete     (Node *node, unsigned int index);
static inline void circular_delete   (Node *node, unsigned int index);

static void (*delete_choose[LIST_TYPE_SIZE])(Node *node, unsigned int index) = 
{ 
    singly_delete, polynomial_delete, doubly_delete, circular_delete
};

void delete(Node *node, unsigned int index)
{
    ;
}

static inline void singly_delete(Node *node, unsigned int index)
{
    ;
}

static inline void polynomial_delete(Node *node, unsigned int index)
{
    ;
}

static inline void doubly_delete(Node *node, unsigned int index)
{
    ;
}

static inline void circular_delete(Node *node, unsigned int index)
{
    ;
}
/*----------------------------------------function *delete* end  ----------------------------------------*/





/*----------------------------------------function *search* begin----------------------------------------*/
static inline int singly_search     (Node *node, unsigned int index);
static inline int polynomial_search (Node *node, unsigned int index);
static inline int doubly_search     (Node *node, unsigned int index);
static inline int circular_search   (Node *node, unsigned int index);

static int (*search_choose[LIST_TYPE_SIZE])(Node *node, unsigned int index) = 
{ 
    singly_search, polynomial_search, doubly_search, circular_search
};

int search(Node *node, unsigned int index)
{
    ;
}

static inline int singly_search(Node *node, unsigned int index)
{
    ;
}

static inline int polynomial_search(Node *node, unsigned int index)
{
    ;
}

static inline int doubly_search(Node *node, unsigned int index)
{
    ;
}

static inline int circular_search(Node *node, unsigned int index)
{
    ;
}
/*----------------------------------------function *search* end  ----------------------------------------*/